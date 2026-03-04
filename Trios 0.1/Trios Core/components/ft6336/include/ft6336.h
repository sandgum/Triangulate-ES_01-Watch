#pragma once

#include <stdint.h>
#include <stdbool.h>
#include "driver/i2c.h"
#include "esp_err.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    i2c_port_t i2c_port;
    uint8_t    i2c_addr;
    gpio_num_t rst_gpio;
    gpio_num_t int_gpio;   // optional, can be GPIO_NUM_NC
    uint16_t   x_max;
    uint16_t   y_max;
} ft6336_config_t;

esp_err_t ft6336_init(const ft6336_config_t *cfg);
bool      ft6336_get_touch(uint16_t *x, uint16_t *y);
uint8_t   ft6336_get_touch_count(void);

#ifdef __cplusplus
}
#endif