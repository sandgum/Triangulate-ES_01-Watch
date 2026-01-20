#pragma once
#include "driver/i2c.h"
#include "esp_err.h"

esp_err_t drv2605_init(i2c_port_t port);
esp_err_t drv2605_autocalibrate(i2c_port_t port);
esp_err_t drv2605_play_effect(i2c_port_t port, uint8_t effect);
esp_err_t drv2605_set_rtp(i2c_port_t port, uint8_t strength);
