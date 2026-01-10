#pragma once

#include <stdint.h>
#include <stdbool.h>
#include "driver/spi_master.h"

#define EPD_WIDTH   200
#define EPD_HEIGHT  200

typedef struct {
    spi_device_handle_t spi;
    int pin_cs;
    int pin_dc;
    int pin_rst;
    int pin_busy;
} epd_t;

/* Public API */
void epd_init(epd_t *epd);
void epd_clear(epd_t *epd);
void epd_refresh_full(epd_t *epd);
void epd_refresh_partial(epd_t *epd);
void epd_refresh_fast(epd_t *epd);

void epd_set_window(epd_t *epd,
                    uint16_t x,
                    uint16_t y,
                    uint16_t w,
                    uint16_t h);

void epd_write_bitmap(epd_t *epd,
                      const uint8_t *data,
                      uint32_t length);

/* LVGL flush hook */
void epd_lvgl_flush(epd_t *epd,
                    int x1, int y1,
                    int x2, int y2,
                    const uint8_t *bitmap);