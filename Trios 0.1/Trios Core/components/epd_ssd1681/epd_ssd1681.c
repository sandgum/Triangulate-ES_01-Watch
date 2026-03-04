#include "epd_ssd1681.h"
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

// Helper functions taken from Arduino example code from GooDisplay
static inline void epd_delay_ms(int ms)
{
    vTaskDelay(pdMS_TO_TICKS(ms));
}

static void epd_wait_busy(epd_t *epd)
{
    while (gpio_get_level(epd->pin_busy) == 1) {
        epd_delay_ms(10);
    }
}

// Low-level SPI write functions (switching between command/data)
static void epd_write_cmd(epd_t *epd, uint8_t cmd)
{
    gpio_set_level(epd->pin_dc, 0);
    gpio_set_level(epd->pin_cs, 0);

    spi_transaction_t t = {
        .length = 8,
        .tx_buffer = &cmd
    };
    spi_device_transmit(epd->spi, &t);

    gpio_set_level(epd->pin_cs, 1);
}

static void epd_write_data(epd_t *epd, const uint8_t *data, size_t len)
{
    gpio_set_level(epd->pin_dc, 1);
    gpio_set_level(epd->pin_cs, 0);

    spi_transaction_t t = {
        .length = len * 8,
        .tx_buffer = data
    };
    spi_device_transmit(epd->spi, &t);

    gpio_set_level(epd->pin_cs, 1);
}

// Reset and initialize the EPD
void epd_init(epd_t *epd)
{
    gpio_set_level(epd->pin_rst, 0);
    epd_delay_ms(10);
    gpio_set_level(epd->pin_rst, 1);
    epd_delay_ms(10);

    epd_wait_busy(epd);

    epd_write_cmd(epd, 0x01); // POWER SETTING
    uint8_t pwr[] = {0x27, 0x01, 0x00};
    epd_write_data(epd, pwr, sizeof(pwr));

    epd_write_cmd(epd, 0x11); // DATA ENTRY MODE
    uint8_t data_entry = 0x03;
    epd_write_data(epd, &data_entry, 1);

    epd_write_cmd(epd, 0x44); // X RAM RANGE
    uint8_t x_range[] = {0x00, (EPD_WIDTH / 8) - 1};
    epd_write_data(epd, x_range, 2);

    epd_write_cmd(epd, 0x45); // Y RAM RANGE
    uint8_t y_range[] = {
        0x00, 0x00,
        (EPD_HEIGHT - 1) & 0xFF,
        (EPD_HEIGHT - 1) >> 8
    };
    epd_write_data(epd, y_range, 4);

    epd_clear(epd);
}

// Clear the display to white
void epd_clear(epd_t *epd)
{
    uint8_t white = 0xFF;

    epd_write_cmd(epd, 0x24); // WRITE RAM

    for (int i = 0; i < (EPD_WIDTH * EPD_HEIGHT) / 8; i++) {
        epd_write_data(epd, &white, 1);
    }

    epd_refresh_full(epd);
}

// Full refresh of the E-ink display (takes approx. 2 seconds, so it's only done sparingly)
void epd_refresh_full(epd_t *epd)
{
    epd_write_cmd(epd, 0x22);
    uint8_t mode = 0xF7;
    epd_write_data(epd, &mode, 1);

    epd_write_cmd(epd, 0x20);
    epd_wait_busy(epd);
}

// Partial refresh of the E-ink display 
// Much faster at 0.3 seconds, but may leave ghosting so is only limited to small areas and a max of 20 times before a full refresh is needed
void epd_refresh_partial(epd_t *epd)
{
    epd_write_cmd(epd, 0x22);
    uint8_t mode = 0xFF;
    epd_write_data(epd, &mode, 1);

    epd_write_cmd(epd, 0x20);
    epd_wait_busy(epd);
}

// Fast refresh of the E-ink display (takes 1.5 seconds, but can result in ghosting so its max usage counter is the same as partial refresh)
void epd_refresh_fast(epd_t *epd)
{
    epd_write_cmd(epd, 0x22);
    uint8_t mode = 0xC7;
    epd_write_data(epd, &mode, 1);

    epd_write_cmd(epd, 0x20);
    epd_wait_busy(epd);
}

// Taking the window for LVGL to make changes, and using that as the area for partial refreshes
void epd_set_window(epd_t *epd,
                    uint16_t x,
                    uint16_t y,
                    uint16_t w,
                    uint16_t h)
{
    uint16_t x_end = x + w - 1;
    uint16_t y_end = y + h - 1;

    epd_write_cmd(epd, 0x44);
    uint16_t x_byte_start = x & ~0x7;
    uint16_t x_byte_end   = (x_end + 7) & ~0x7;
    uint8_t x_data[] = {x_byte_start / 8, x_byte_end / 8};
    epd_write_data(epd, x_data, 2);

    epd_write_cmd(epd, 0x45);
    uint8_t y_data[] = {
        y & 0xFF, y >> 8,
        y_end & 0xFF, y_end >> 8
    };
    epd_write_data(epd, y_data, 4);

    epd_write_cmd(epd, 0x4E);
    uint8_t x_ptr = x / 8;
    epd_write_data(epd, &x_ptr, 1);

    epd_write_cmd(epd, 0x4F);
    epd_write_data(epd, (uint8_t *)&y_data[0], 2);
}

// The actual data that LVGL draws on the display
void epd_write_bitmap(epd_t *epd,
                      const uint8_t *data,
                      uint32_t length)
{
    epd_write_cmd(epd, 0x24);
    epd_write_data(epd, data, length);
}

// The final flush adapter between LVGL and the E-ink display functions
void epd_lvgl_flush(epd_t *epd,
                    int x1, int y1,
                    int x2, int y2,
                    const uint8_t *bitmap)
{
    int w = x2 - x1 + 1;
    int h = y2 - y1 + 1;

    epd_set_window(epd, x1, y1, w, h);
    uint32_t bytes_per_row = (w + 7) / 8;
    uint32_t len = bytes_per_row * h;
    epd_write_bitmap(epd, bitmap, len);

    // Decide on refresh type based on area and count
    static uint32_t partial_refresh_count = 0;
    uint32_t area = w * h;

    if (partial_refresh_count >= 20) {
        partial_refresh_count = 0;
        epd_refresh_full(epd);
        return;
    } else if (area > 12000) {
        partial_refresh_count++;
        epd_refresh_fast(epd);
        return;
    } else {
        epd_refresh_partial(epd);
    }
}