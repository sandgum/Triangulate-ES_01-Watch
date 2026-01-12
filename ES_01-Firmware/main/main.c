#include <stdio.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

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
 *  Globals
 * ======================= */

static spi_device_handle_t spi;
static epd_t epd;
static lv_display_t *e_ink_disp;
static esp_lcd_panel_io_handle_t io_hndl_oled1 = NULL;
static esp_lcd_panel_handle_t oled1 = NULL;
static esp_lcd_panel_io_handle_t io_hndl_oled2 = NULL;
static esp_lcd_panel_handle_t oled2 = NULL;

/* ===============================
 *  OLED flush callbacks forward declarations
 * =============================== */

static void lv_oled1_flush_cb(lv_display_t *disp, const lv_area_t *area, uint8_t *px_map);
static void lv_oled2_flush_cb(lv_display_t *disp, const lv_area_t *area, uint8_t *px_map);

/* =======================
 *  I2C init
 * ======================= */

static void i2c_init(void)
{
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

/* =======================
 *  app_main
 * ======================= */

void app_main(void)
{
    gpio_init();
    spi_init();
    epd_driver_init();

    i2c_init();
    touch_init();

    oled1_init();
    oled2_init();

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

    ui_init();

    xTaskCreate(
        lvgl_task,
        "lvgl",
        4096,
        NULL,
        5,
        NULL
    );
}