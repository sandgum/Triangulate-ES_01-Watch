#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <stddef.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_sleep.h"
#include "esp_log.h"
#include "esp_rom_sys.h"

#include "driver/gpio.h"
#include "driver/spi_master.h"
#include "driver/i2c.h"

#include "lvgl.h"
#include "esp_timer.h"

#include "epd_ssd1681.h"
#include "ft6336.h"

#include "esp_lcd_panel_io.h"
#include "esp_lcd_panel_ssd1306.h"
#include "esp_lcd_panel_vendor.h"
#include "esp_lcd_panel_ops.h"

#include "max30102.h"

#include "BHI260AP.fw.h"
#include "bhy2.h"
#include "bhy2_defs.h"

#include "bmp5.h"
#include "bmp5_defs.h"

#include "drv2605.h"

/* =======================
 *  Display (SPI / EPD)
 * ======================= */

#define PIN_NUM_MOSI   23
#define PIN_NUM_CLK    18
#define PIN_NUM_CS      5
#define PIN_NUM_DC     17
#define PIN_NUM_RST    16
#define PIN_NUM_BUSY    4

#define OLED1_ADDR 0x3C
#define OLED2_ADDR 0x3D

/* =======================
 *  Touch (I2C / FT6336)
 * ======================= */

#define I2C_PORT I2C_NUM_0
#define I2C_SDA  GPIO_NUM_8
#define I2C_SCL  GPIO_NUM_9
#define I2C_FREQ 400000

/* =======================
 *  Sensors
 * ======================= */

 #define HR_FREQUENCY_HZ 50
 #define HR_TIME_WINDOW_MS 6000
 #define HR_SAMPLES (HR_FREQUENCY_HZ * HR_TIME_WINDOW_MS / 1000)
 #define HR_MIN_INTERVAL_MS   300     // 200 BPM max
 #define HR_MAX_INTERVAL_MS  2000     // 30 BPM min
 #define AC_WINDOW_SAMPLES   (HR_FREQUENCY_HZ * 2)   // 2 seconds
 #define X 2
 #define Y 1
 #define Z 0

 #define BHI260_INT_GPIO  GPIO_NUM_7

 #define SEC_BTW_MEAS_IN_SLEEP 60 // The time in seconds between the ESP32 waking up to take HR measurements while it is sleeping
 #define INACTIVE_SEC_BEFORE_SLEEP 10 // Time in seconds of touch inactivity on E-ink display before going to sleep

/* =======================
 *  Globals
 * ======================= */

static spi_device_handle_t spi;
static epd_t epd;
static lv_display_t *e_ink_disp;
static esp_lcd_panel_io_handle_t io_hndl_oled1 = NULL;
static esp_lcd_panel_handle_t oled1 = NULL;
static esp_lcd_panel_io_handle_t io_hndl_oled2 = NULL;
static esp_lcd_panel_handle_t oled2 = NULL;
static max30102_t hr_sensor;
static float heart_rate = 0.0;
volatile bool hr_resuming = true;

static bool just_woke_up = false;

static TaskHandle_t hr_task_handle;
static TaskHandle_t lvgl_task_handle;

struct bhy2_dev bhi260ap;
uint8_t work_buffer[2048]; // FIFO data buffer
uint8_t gesture_code; // BHI260AP wrist turn gesture code

uint32_t steps; // Total step count since BHI260 reset

typedef struct {
    int16_t x;
    int16_t y;
    int16_t z;
    int16_t w;
    uint16_t accuracy; // estimated accuracy in radians * 2^14 (sometimes reserved)
} bhy2_data_quaternion;

float euler_angles[3] = {0.0f, 0.0f, 0.0f}; // Euler angles that were converted from quaternions

SemaphoreHandle_t i2c_mux;

struct bmp5_dev bmp585;

struct bmp5_sensor_data bmp585_data;

/* ==========================================
 *  OLED flush callbacks forward declarations
 * ========================================== */

static void lv_oled1_flush_cb(lv_display_t *disp, const lv_area_t *area, uint8_t *px_map);
static void lv_oled2_flush_cb(lv_display_t *disp, const lv_area_t *area, uint8_t *px_map);

/* ==========================
 *  Signal processing helpers
 * ========================== */

static float mean_u32(const uint32_t *buf, int len)
{
    uint64_t sum = 0;
    for (int i = 0; i < len; i++) {
        sum += buf[i];
    }
    return (float)sum / len;
}

static float rms_u32(const uint32_t *buf, int len, float mean)
{
    float sum_sq = 0.0f;
    for (int i = 0; i < len; i++) {
        float v = buf[i] - mean;
        sum_sq += v * v;
    }
    return sqrtf(sum_sq / len);
}

float fixed_to_float(int16_t val) {
    return val / 16384.0f; // 2^14
}

/* =======================
 *  I2C init
 * ======================= */

static void i2c_init(void)
{
    i2c_mux = xSemaphoreCreateMutex();
    configASSERT(i2c_mux);

    if (i2c_mux == NULL) {
        printf("Failed to create I2C mutex\n");
        while(1) {
            vTaskDelay(pdMS_TO_TICKS(1000));
        }
    }

    i2c_config_t cfg = {
        .mode = I2C_MODE_MASTER,
        .sda_io_num = I2C_SDA,
        .scl_io_num = I2C_SCL,
        .sda_pullup_en = GPIO_PULLUP_ENABLE,
        .scl_pullup_en = GPIO_PULLUP_ENABLE,
        .master.clk_speed = I2C_FREQ
    };

    i2c_param_config(I2C_PORT, &cfg);
    i2c_driver_install(I2C_PORT, cfg.mode, 0, 0, 0);
}

/* =======================
 *  Touch → LVGL callback
 * ======================= */

static void touch_read_cb(lv_indev_t *indev, lv_indev_data_t *data)
{
    static uint16_t last_x;
    static uint16_t last_y;

    uint16_t x, y;

    if (ft6336_get_touch(&x, &y)) {
        last_x = x;
        last_y = y;

        data->state = LV_INDEV_STATE_PRESSED;
        data->point.x = x;
        data->point.y = y;
    } else {
        data->state = LV_INDEV_STATE_RELEASED;
        data->point.x = last_x;
        data->point.y = last_y;
    }
}

static void lvgl_touch_init(void)
{
    lv_indev_t *indev = lv_indev_create();
    lv_indev_set_type(indev, LV_INDEV_TYPE_POINTER);
    lv_indev_set_read_cb(indev, touch_read_cb);
}

/* =======================
 *  SPI init
 * ======================= */

static void spi_init(void)
{
    spi_bus_config_t buscfg = {
        .mosi_io_num = PIN_NUM_MOSI,
        .miso_io_num = -1,
        .sclk_io_num = PIN_NUM_CLK,
        .quadwp_io_num = -1,
        .quadhd_io_num = -1,
        .max_transfer_sz = 4096,
    };

    spi_device_interface_config_t devcfg = {
        .clock_speed_hz = 4 * 1000 * 1000,
        .mode = 0,
        .spics_io_num = -1,
        .queue_size = 1,
    };

    spi_bus_initialize(SPI2_HOST, &buscfg, SPI_DMA_CH_AUTO);
    spi_bus_add_device(SPI2_HOST, &devcfg, &spi);
}

/* =======================
 *  GPIO init
 * ======================= */

static void gpio_init(void)
{
    gpio_config_t out_cfg = {
        .mode = GPIO_MODE_OUTPUT,
        .pin_bit_mask =
            (1ULL << PIN_NUM_CS) |
            (1ULL << PIN_NUM_DC) |
            (1ULL << PIN_NUM_RST),
    };
    gpio_config(&out_cfg);

    gpio_config_t in_cfg = {
        .mode = GPIO_MODE_INPUT,
        .pin_bit_mask = (1ULL << PIN_NUM_BUSY),
    };
    gpio_config(&in_cfg);

    gpio_set_level(PIN_NUM_CS, 1);
}

/* =======================
 *  EPD driver init
 * ======================= */

static void epd_driver_init(void)
{
    epd.spi = spi;
    epd.pin_cs = PIN_NUM_CS;
    epd.pin_dc = PIN_NUM_DC;
    epd.pin_rst = PIN_NUM_RST;
    epd.pin_busy = PIN_NUM_BUSY;

    epd_init(&epd);
}

/* =======================
 *  LVGL flush callback
 * ======================= */

static void lvgl_flush_cb(lv_display_t *disp,
                          const lv_area_t *area,
                          uint8_t *px_map)
{
    epd_lvgl_flush(&epd,
                   area->x1, area->y1,
                   area->x2, area->y2,
                   px_map);

    lv_display_flush_ready(disp);
}

/* =======================
 *  LVGL display init
 * ======================= */

static void lvgl_displays_init(void)
{
    static lv_draw_buf_t draw_buf_ep;
    static lv_color_t buf1[EPD_WIDTH * 40];   // 40 lines buffer

    static lv_draw_buf_t draw_buf_oled1;
    static lv_color_t buf_oled1[128 * 32]; // 128 x 32 oled

    static lv_draw_buf_t draw_buf_oled2;
    static lv_color_t buf_oled2[128 * 32]; // 128 x 32 oled

    lv_draw_buf_init(
        &draw_buf_ep,
        EPD_WIDTH,
        40,
        LV_COLOR_FORMAT_NATIVE,
        EPD_WIDTH * sizeof(lv_color_t),
        buf1,
        sizeof(buf1)
    );

    lv_draw_buf_init(
        &draw_buf_oled1,
        128,
        32,
        LV_COLOR_FORMAT_NATIVE,
        128 * sizeof(lv_color_t),
        buf_oled1,
        sizeof(buf_oled1)
    );

    lv_draw_buf_init(
        &draw_buf_oled2,
        128,
        32,
        LV_COLOR_FORMAT_NATIVE,
        128 * sizeof(lv_color_t),
        buf_oled2,
        sizeof(buf_oled2)
    );

    e_ink_disp = lv_display_create(EPD_WIDTH, EPD_HEIGHT);
    lv_display_set_draw_buffers(e_ink_disp, &draw_buf_ep, NULL);
    lv_display_set_flush_cb(e_ink_disp, lvgl_flush_cb);

    lv_display_t *oled1_disp = lv_display_create(128, 32);
    lv_display_set_draw_buffers(oled1_disp, &draw_buf_oled1, NULL);
    lv_display_set_flush_cb(oled1_disp, lv_oled1_flush_cb);

    lv_display_t *oled2_disp = lv_display_create(128, 32);
    lv_display_set_draw_buffers(oled2_disp, &draw_buf_oled2, NULL);
    lv_display_set_flush_cb(oled2_disp, lv_oled2_flush_cb);
}

/* =======================
 *  FT6336 init
 * ======================= */

static void touch_init(void)
{
    ft6336_config_t cfg = {
        .i2c_port = I2C_PORT,
        .i2c_addr = 0x38,
        .rst_gpio = GPIO_NUM_10,
        .int_gpio = GPIO_NUM_NC,
        .x_max = 320,
        .y_max = 240
    };

    ESP_ERROR_CHECK(ft6336_init(&cfg));
}

/* =======================
 *  OLED1 init
 * ======================= */

static void oled1_init(void)
{
    esp_lcd_panel_io_i2c_config_t io_i2c_cfg_oled1 = {
        .dev_addr = OLED1_ADDR,
        .control_phase_bytes = 1,
    };
    esp_lcd_new_panel_io_i2c(I2C_PORT, &io_i2c_cfg_oled1, &io_hndl_oled1);
    
    esp_lcd_panel_dev_config_t oled_cfg = {
        .bits_per_pixel = 1,
    };

    ESP_ERROR_CHECK(
        esp_lcd_new_panel_ssd1306(io_hndl_oled1, &oled_cfg, &oled1)
    );

    esp_lcd_panel_reset(oled1);
    esp_lcd_panel_init(oled1);
}

/* =======================
 *  OLED2 init
 * ======================= */

static void oled2_init(void)
{
    esp_lcd_panel_io_i2c_config_t io_i2c_cfg_oled2 = {
    .dev_addr = OLED2_ADDR,
    .control_phase_bytes = 1,
};
    esp_lcd_new_panel_io_i2c(I2C_PORT, &io_i2c_cfg_oled2, &io_hndl_oled2);

    esp_lcd_panel_dev_config_t oled_cfg = {
        .bits_per_pixel = 1,
    };
    ESP_ERROR_CHECK(
        esp_lcd_new_panel_ssd1306(io_hndl_oled2, &oled_cfg, &oled2)
    );

    esp_lcd_panel_reset(oled2);
    esp_lcd_panel_init(oled2);
}

/* ===============================
 *  OLED flush callbacks for LVGL
 * =============================== */

static void lv_oled1_flush_cb(lv_display_t *disp,
                              const lv_area_t *area,
                              uint8_t *px_map)
{
    esp_lcd_panel_draw_bitmap(oled1,
                               area->x1, area->y1,
                               area->x2+1, area->y2+1,
                               px_map);
    lv_display_flush_ready(disp);
}

static void lv_oled2_flush_cb(lv_display_t *disp,
                              const lv_area_t *area,
                              uint8_t *px_map)
{
    esp_lcd_panel_draw_bitmap(oled2,
                               area->x1, area->y1,
                               area->x2+1, area->y2+1,
                               px_map);
    lv_display_flush_ready(disp);
}

/* =======================
 *  UI
 * ======================= */

static void ui_init(void)
{
    lv_obj_t *label = lv_label_create(lv_scr_act());
    lv_label_set_text(label, "Hello e-paper");
    lv_obj_center(label);
}

/* =======================
 *  LVGL tick callback
 * ======================= */

static void lv_tick_cb(void *arg)
{
    lv_tick_inc(1);
}

/* =======================
 *  LVGL task
 * ======================= */

static void lvgl_task(void *arg)
{
    while (1) {
        lv_timer_handler();
        vTaskDelay(pdMS_TO_TICKS(5));
    }
}

/* ======================
*  Heart Rate Init
*  ====================== */

static void heart_rate_init(void)
{
    esp_err_t err = max30102_init(&hr_sensor, I2C_PORT);
    if (err != ESP_OK) {
        printf("Failed to initialize MAX30102 sensor\n");
        vTaskDelete(NULL);
        return;
    }

    max30102_configure(&hr_sensor,
                       0x1F, // LED brightness
                       4, // Sample average
                       3, // LED mode
                       3, // Sample rate
                       3, // Pulse width
                       3  // ADC range
    );
}

/* ========================
*  Heart Rate Reading Task
*  ======================== */

static void heart_rate_task(void *arg)
{
    uint32_t ir_buf[HR_SAMPLES] = {0};
    int buf_idx = 0;
    bool buffer_filled = false;

    uint32_t last_peak_time = 0;
    float bpm_sum = 0.0f;
    int bpm_count = 0;

    uint32_t prev_ir = 0;
    uint32_t curr_ir = 0;

    while (1) {
        if (hr_resuming) {
            buffer_filled = false;
            buf_idx = 0;
            last_peak_time = 0;
            bpm_sum = 0;
            bpm_count = 0;
            hr_resuming = false;
        }
        // Sample IR
        if (max30102_read_ir(&hr_sensor, &curr_ir) != ESP_OK) {
            vTaskDelay(pdMS_TO_TICKS(20));
            continue;
        }

        ir_buf[buf_idx++] = curr_ir;
        if (buf_idx >= HR_SAMPLES) {
            buf_idx = 0;
            buffer_filled = true;
        }

        if (buffer_filled) {
            // DC over full window
            float dc = mean_u32(ir_buf, HR_SAMPLES);

            // AC over shorter window
            int ac_start = (buf_idx - AC_WINDOW_SAMPLES + HR_SAMPLES) % HR_SAMPLES;
            uint32_t ac_buf[AC_WINDOW_SAMPLES];

            for (int i = 0; i < AC_WINDOW_SAMPLES; i++) {
                ac_buf[i] = ir_buf[(ac_start + i) % HR_SAMPLES];
            }

            float ac_rms = rms_u32(ac_buf, AC_WINDOW_SAMPLES, dc);

            // Signal quality check
            if ((ac_rms / dc) > 0.005f) {
                float threshold = 0.5f * ac_rms;

                float prev_ac = (float)prev_ir - dc;
                float curr_ac = (float)curr_ir - dc;

                uint32_t now = esp_timer_get_time() / 1000; // ms

                // Peak detection
                if (prev_ac < threshold && curr_ac >= threshold) {
                    if (last_peak_time != 0) {
                        uint32_t interval = now - last_peak_time;

                        if (interval > HR_MIN_INTERVAL_MS &&
                            interval < HR_MAX_INTERVAL_MS) {

                            float bpm = 60000.0f / interval;

                            bpm_sum += bpm;
                            bpm_count++;

                            if (bpm_count >= 3) {
                                heart_rate = bpm_sum / bpm_count;
                                bpm_sum = 0;
                                bpm_count = 0;
                                printf("Heart rate: %.2f bpm\n", heart_rate); // For debugging
                            }
                        }
                    }
                    last_peak_time = now;
                }
            }
        }

        prev_ir = curr_ir;
        vTaskDelay(pdMS_TO_TICKS(1000 / HR_FREQUENCY_HZ));
    }
}

/* ===========================
*  Stop heart rate measurement
*  =========================== */

void stop_hr_measurement(void)
{
    vTaskSuspend(hr_task_handle);
    max30102_shutdown(&hr_sensor);
}

/* =============================
*  Resume heart rate measurement
*  ============================= */

void resume_hr_measurement(void)
{
    hr_resuming = true;
    max30102_wakeup(&hr_sensor);
    max30102_configure(&hr_sensor,
                   0x1F,
                   4,
                   3,
                   3,
                   3,
                   3);
    vTaskResume(hr_task_handle);
}


/* ======================
*  Orientation callback
*  ====================== */

void orientation_callback(const struct bhy2_fifo_parse_data_info *callback_info, void *callback_ref) {
    bhy2_data_quaternion *quat_data = (bhy2_data_quaternion *)callback_info->data_ptr;
    
    float x = fixed_to_float(quat_data->x);
    float y = fixed_to_float(quat_data->y);
    float z = fixed_to_float(quat_data->z);
    float w = fixed_to_float(quat_data->w);

    printf("Orientation (quat): X:%.2f, Y:%.2f, Z:%.2f, W:%.2f\n", x, y, z, w);


    // Convert from quaternion to Euler angles (in radians)

    // X-axis
    double sinr_cosp = 2 * (w * x + y * z);
    double cosr_cosp = 1 - 2 * (x * x + y * y);
    euler_angles[X] = atan2(sinr_cosp, cosr_cosp);

    // Y-axis
    double sinp = 2 * (w * y - z * x);
    if (fabs(sinp) >= 1) {
        euler_angles[Y] = copysign(M_PI / 2, sinp);
    } else {
        euler_angles[Y] = asin(sinp);
    }

    // Z-axis
    double siny_cosp = 2 * (w * z + x * y);
    double cosy_cosp = 1 - 2 * (y * y + z * z);
    euler_angles[Z] = atan2(siny_cosp, cosy_cosp);
}

/* ======================
*  Step counter callback
*  ====================== */

void step_counter_callback(const struct bhy2_fifo_parse_data_info *callback_info, void *callback_ref) {
    
    
    // Copy the data from the FIFO pointer to our variable
    // The driver usually provides 4 bytes for the step count
    memcpy(&steps, callback_info->data_ptr, sizeof(steps));

    printf("Total Steps: %lu\n", (unsigned long)steps);
}

/* ======================
*  Wrist wakeup callback
*  ====================== */

void wrist_callback(const struct bhy2_fifo_parse_data_info *callback_info, void *callback_ref) {
    // The data_ptr points to a 1-byte value for this sensor
    gesture_code = *callback_info->data_ptr;

    /* * Standard Bosch Gesture Codes:
     * 0x01: Wrist Up (User looking at watch)
     * 0x02: Wrist Down (User moved arm away)
     */
    if (gesture_code == 0x01) {
        printf("Wrist Flick UP detected!\n");
    } else if (gesture_code == 0x02) {
        printf("Wrist Flick DOWN detected!\n");
    }
}

/* ================================
*  Inertial measurement unit setup
*  ================================ */

void bhi260_setup(void)
{
    bhy2_init(BHY2_I2C_INTERFACE,
            bhi260_i2c_read,
            bhi260_i2c_write,
            bhi260_delay_us,
            256,
            NULL,
            &bhi260ap);
    
    bhy2_soft_reset(&bhi260ap);
    bhy2_upload_firmware_to_ram(bhy2_firmware_image, sizeof(bhy2_firmware_image), &bhi260ap);
    bhy2_boot_from_ram(&bhi260ap);
    bhy2_update_virtual_sensor_list(&bhi260ap);

    uint8_t ornt_snsr_id = BHY2_SENSOR_ID_GAMERV;
    bhy2_register_fifo_parse_callback(ornt_snsr_id, orientation_callback, NULL, &bhi260ap);

    if (bhy2_is_sensor_available(ornt_snsr_id, &bhi260ap)) {
        bhy2_set_virt_sensor_cfg(ornt_snsr_id, 100.0f, 0, &bhi260ap);
        printf("Orientation sensor available\n");
    } else {
        printf("Error: Sensor not available\n");
    }

    uint8_t step_snsr_id = BHY2_SENSOR_ID_STC;

    bhy2_register_fifo_parse_callback(step_snsr_id, step_counter_callback, NULL, &bhi260ap);

    bhy2_set_virt_sensor_cfg(step_snsr_id, 1.0f, 0, &bhi260ap);

    // BHY2_SENSOR_ID_WRIST_WEAR_WAKE_UP is usually ID 46
    uint8_t wrist_snsr_id = BHY2_PHYS_SENSOR_ID_WRIST_WEAR_WAKEUP;

    // 1. Register a callback (useful if the ESP32 is already awake)
    bhy2_register_fifo_parse_callback(wrist_snsr_id, wrist_callback, NULL, &bhi260ap);

    // 2. Enable the sensor
    // Being a gesture sensor, the sample rate is often ignored, but set to 1.0Hz
    bhy2_set_virt_sensor_cfg(wrist_snsr_id, 1.0f, 0, &bhi260ap);
}

/* ========================
*  Puts ESP32 in light sleep
*  ======================== */

void go_to_sleep() {
    // 1. Configure the pin as a wakeup source
    // BHI260AP HIRQ is usually active HIGH (1.8V -> 3.3V via shifter)
    
    gpio_wakeup_enable(BHI260_INT_GPIO, GPIO_INTR_HIGH_LEVEL);
    esp_sleep_enable_gpio_wakeup();
    printf("Entering light sleep. Flick wrist to wake!\n");
    
    // 2. Enter light sleep
    esp_light_sleep_start();
    
}

/* ========================
*  IMU task
*  ======================== */

static void bhi260_task(void *arg) {
    while (1) {
        // Only process if the HIRQ pin is high (Level shifter ensures 3.3V logic)
        if (gpio_get_level(BHI260_INT_GPIO)) {
            bhy2_get_and_process_fifo(work_buffer, sizeof(work_buffer), &bhi260ap);
        }
        vTaskDelay(pdMS_TO_TICKS(10)); // Poll every 10ms
    }
}

/* ============================
*  I2C read function for BMP585
*  ============================ */

static int8_t bmp5_i2c_read(uint8_t reg_addr, uint8_t *data, uint32_t len, void *intf_ptr)
{
    i2c_port_t port = *(i2c_port_t *)intf_ptr;

    if (xSemaphoreTake(i2c_mux, pdMS_TO_TICKS(100)) != pdTRUE) {
        return BMP5_E_COM_FAIL;
    }
    esp_err_t err = i2c_master_write_read_device(
        port,
        BMP5_I2C_ADDR_PRIM,
        &reg_addr,
        1,
        data,
        len,
        pdMS_TO_TICKS(100)
    );

    xSemaphoreGive(i2c_mux);

    return (err == ESP_OK) ? BMP5_OK : BMP5_E_COM_FAIL;
}

/* =============================
*  I2C write function for BMP585
*  ============================= */

static int8_t bmp5_i2c_write(uint8_t reg_addr, const uint8_t *data, uint32_t len, void *intf_ptr)
{
    i2c_port_t port = *(i2c_port_t *)intf_ptr;

    uint8_t buf[len + 1];
    buf[0] = reg_addr;
    memcpy(&buf[1], data, len);

    if (xSemaphoreTake(i2c_mux, pdMS_TO_TICKS(100)) != pdTRUE) {
        return BMP5_E_COM_FAIL;
    }

    esp_err_t err = i2c_master_write_to_device(
        port,
        BMP5_I2C_ADDR_PRIM,
        buf,
        len + 1,
        pdMS_TO_TICKS(100)
    );

    xSemaphoreGive(i2c_mux);

    return (err == ESP_OK) ? BMP5_OK : BMP5_E_COM_FAIL;
}

/* ============================
*  Delay function for BMP585
*  ============================ */

static void bmp5_delay_us(uint32_t period, void *intf_ptr)
{
    esp_rom_delay_us(period);
}

/* ============================
*  BMP585 setup function
*  ============================ */

void bmp585_setup(void)
{
    i2c_port_t i2c_port = I2C_PORT;

    bmp585.intf_ptr = &i2c_port;
    bmp585.read = bmp5_i2c_read;
    bmp585.write = bmp5_i2c_write;
    bmp585.delay_us = bmp5_delay_us;

    if (bmp5_init(&bmp585) != BMP5_OK) {
        printf("Failed to initialize BMP585 sensor\n");
        return;
    }
    bmp5_set_power_mode(BMP5_POWERMODE_NORMAL, &bmp585);
    printf("BMP585 initialized successfully\n");
}

/* ============================
*  BMP585 measurement task
*  ============================ */

static void bmp585_task(void *arg) {

    struct bmp5_osr_odr_press_config bmp585_cfg = {
        .osr_t = BMP5_OVERSAMPLING_8X,
        .osr_p = BMP5_OVERSAMPLING_4X,
        .press_en = BMP5_ENABLE, // Enable pressure measurement
        .odr = BMP5_ODR_0_250_HZ // Output data rate at 0.25Hz, once every 4 seconds
    };

    while (1) {

        if (bmp5_get_sensor_data(&bmp585_data, &bmp585_cfg, &bmp585) == BMP5_OK) {
            printf("BMP585 - Pressure: %.2f Pa, Temperature: %.2f °C\n",
                   bmp585_data.pressure,
                   bmp585_data.temperature);
        } else {
            printf("Failed to read BMP585 sensor data\n");
        }
        vTaskDelay(pdMS_TO_TICKS(4000)); // Read every 4 seconds
    }
}

/* ============================
*  DRV2605 Setup
*  ============================ */

void drv2605_setup(void) {

    ESP_ERROR_CHECK(drv2605_init(I2C_PORT));
    ESP_ERROR_CHECK(drv2605_autocalibrate(I2C_PORT));

    // Test pulse
    drv2605_play_effect(I2C_PORT, 1);
}

/* ====================================
*  UI Haptic driver callback (on touch)
*  ==================================== */

void haptic_touch_cb(void) {
    drv2605_play_effect(I2C_PORT, 1);
}

/* ========================
*  Main loop task
*  ======================== */

static void main_loop_task(void* arg)
{
    uint32_t last_wake_time = 0; // Last time the ESP32 woke up from sleep (ms)

    while (1) {

        uint32_t current_time = esp_timer_get_time() / 1000; // ms
        uint32_t inactive_time = 0;

        if (current_time - last_wake_time >= 7000) {
            inactive_time = lv_disp_get_inactive_time(e_ink_disp);
        }

        if (gesture_code == 0x02 || inactive_time >= (INACTIVE_SEC_BEFORE_SLEEP * 1000)) {

            esp_sleep_enable_timer_wakeup(SEC_BTW_MEAS_IN_SLEEP * 1000000);
            stop_hr_measurement();
            just_woke_up = true;
            go_to_sleep();

        } 
        
        if (gesture_code == 0x01 || just_woke_up) {
            resume_hr_measurement();
            just_woke_up = false;
            last_wake_time = esp_timer_get_time() / 1000; // ms
        }

    }
}

/* ==========================
 *  Initialize all components
 * ========================== */

void startup_sequence(void)
{
    gpio_init();
    spi_init();
    epd_driver_init(); // Start main E-ink panel

    i2c_init();
    touch_init(); // Start touch controller on E-ink panel

    oled1_init();
    oled2_init(); // Start both OLED displays

    lv_init();

    const esp_timer_create_args_t lvgl_tick_timer_args = {
        .callback = &lv_tick_cb,
        .name = "lvgl_tick"
    };
    esp_timer_handle_t lvgl_tick_timer;
    esp_timer_create(&lvgl_tick_timer_args, &lvgl_tick_timer);
    esp_timer_start_periodic(lvgl_tick_timer, 1000);

    lvgl_displays_init();
    lvgl_touch_init();

    ui_init(); // Bunch of LVGL initialisation and UI setup

    xTaskCreatePinnedToCore( // Create LVGL task
        lvgl_task,
        "lvgl",
        4096,
        NULL,
        5,
        &lvgl_task_handle,
        1
    ); 

    heart_rate_init(); // Initialize heart rate sensor

    xTaskCreatePinnedToCore( // Create heart rate measurement task (can be suspended/resumed)
        heart_rate_task,
        "heart_rate",
        4096,
        NULL,
        4,
        &hr_task_handle,
        1
    );

    bhi260_setup(); // Initialize inertial measurement unit

    xTaskCreatePinnedToCore( // Create inertial measurement unit task
        bhi260_task,
        "bhi260",
        4096,
        NULL,
        3,
        NULL,
        1
    );

    bmp585_setup(); // Initialize BMP585 sensor

    xTaskCreatePinnedToCore( // Create BMP585 measurement task
        bmp585_task,
        "bmp585",
        4096,
        NULL,
        2,
        NULL,
        1
    );

    drv2605_setup(); // Initialise DRV2605 haptic driver

    xTaskCreatePinnedToCore( // Create main loop task (manages sleep/wake, sensor control)
        main_loop_task,
        "main_loop",
        4096,
        NULL,
        6,
        NULL,
        0
    );

}

/* =======================
 *  app_main
 * ======================= */

void app_main(void)
{
    startup_sequence(); // Start EVERYTHING up
}