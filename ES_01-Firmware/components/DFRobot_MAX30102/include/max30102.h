#pragma once

#include "driver/i2c.h"
#include "esp_err.h"
#include <stdint.h>
#include <math.h>

#define MAX30102_I2C_ADDR 0x57

#define MAX30102_REG_MODE_CONFIG   0x09
#define MAX30102_SHDN_BIT          0x80

typedef struct {
    i2c_port_t i2c_port;
} max30102_t;

esp_err_t max30102_init(max30102_t *dev, i2c_port_t port);
esp_err_t max30102_configure(max30102_t *dev,
                             uint8_t led_brightness,
                             uint8_t sample_average,
                             uint8_t led_mode,
                             uint8_t sample_rate,
                             uint8_t pulse_width,
                             uint8_t adc_range);

esp_err_t max30102_read_red(max30102_t *dev, uint32_t *red);
esp_err_t max30102_read_ir(max30102_t *dev, uint32_t *ir);
esp_err_t max30102_read_temperature(max30102_t *dev, float *temp_c);
esp_err_t max30102_shutdown(max30102_t *dev);
esp_err_t max30102_wakeup(max30102_t *dev);