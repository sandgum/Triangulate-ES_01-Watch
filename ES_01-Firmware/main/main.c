#include <stdio.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "driver/gpio.h"
#include "driver/spi_master.h"
#include "driver/i2c.h"

#include "lvgl.h"

#include "epd_ssd1681.h"
#include "ft6336.h"

/* =======================
 *  Display (SPI / EPD)
 * ======================= */

#define PIN_NUM_MOSI   23
#define PIN_NUM_CLK    18
#define PIN_NUM_CS      5
#define PIN_NUM_DC     17
#define PIN_NUM_RST    16
#define PIN_NUM_BUSY    4

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
static lv_display_t *disp;

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

static void lvgl_display_init(void)
{
    static lv_draw_buf_t draw_buf;
    static lv_color_t buf1[EPD_WIDTH * 40];   // 40 lines buffer

    lv_draw_buf_init(
        &draw_buf,
        EPD_WIDTH,            // buffer width
        40,                   // buffer height (lines)
        LV_COLOR_FORMAT_NATIVE,
        EPD_WIDTH * sizeof(lv_color_t), // stride in bytes
        buf1,                 // primary buffer
        0                     // no second buffer
    );

    disp = lv_display_create(EPD_WIDTH, EPD_HEIGHT);
    lv_display_set_draw_buffers(disp, &draw_buf, NULL);
    lv_display_set_flush_cb(disp, lvgl_flush_cb);
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
 *  UI
 * ======================= */

static void ui_init(void)
{
    lv_obj_t *label = lv_label_create(lv_scr_act());
    lv_label_set_text(label, "Hello e-paper");
    lv_obj_center(label);
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

    lv_init();
    lvgl_display_init();
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