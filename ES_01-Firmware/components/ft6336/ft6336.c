#include "ft6336.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include <string.h>

#define FT6336_ADDR_DEFAULT 0x38

// Registers
#define FT6336_TD_STATUS    0x02
#define FT6336_TOUCH1_XH    0x03

static ft6336_config_t dev;

// ---------------- I2C helpers ----------------

static esp_err_t ft_i2c_read(uint8_t reg, uint8_t *buf, size_t len)
{
    return i2c_master_write_read_device(
        dev.i2c_port,
        dev.i2c_addr,
        &reg,
        1,
        buf,
        len,
        pdMS_TO_TICKS(100)
    );
}

static esp_err_t ft_i2c_write(uint8_t reg, const uint8_t *buf, size_t len)
{
    uint8_t tmp[len + 1];
    tmp[0] = reg;
    memcpy(&tmp[1], buf, len);

    return i2c_master_write_to_device(
        dev.i2c_port,
        dev.i2c_addr,
        tmp,
        len + 1,
        pdMS_TO_TICKS(100)
    );
}

// ---------------- Public API ----------------

esp_err_t ft6336_init(const ft6336_config_t *cfg)
{
    dev = *cfg;
    if (dev.i2c_addr == 0) {
        dev.i2c_addr = FT6336_ADDR_DEFAULT;
    }

    if (dev.rst_gpio != GPIO_NUM_NC) {
        gpio_config_t io = {
            .pin_bit_mask = 1ULL << dev.rst_gpio,
            .mode = GPIO_MODE_OUTPUT
        };
        gpio_config(&io);

        gpio_set_level(dev.rst_gpio, 0);
        vTaskDelay(pdMS_TO_TICKS(10));
        gpio_set_level(dev.rst_gpio, 1);
        vTaskDelay(pdMS_TO_TICKS(100));
    }

    // Sanity check: try reading TD_STATUS
    uint8_t tmp;
    return ft_i2c_read(FT6336_TD_STATUS, &tmp, 1);
}

uint8_t ft6336_get_touch_count(void)
{
    uint8_t status = 0;
    if (ft_i2c_read(FT6336_TD_STATUS, &status, 1) != ESP_OK) {
        return 0;
    }
    return status & 0x0F;
}

bool ft6336_get_touch(uint16_t *x, uint16_t *y)
{
    uint8_t buf[4];

    if (ft6336_get_touch_count() == 0) {
        return false;
    }

    if (ft_i2c_read(FT6336_TOUCH1_XH, buf, 4) != ESP_OK) {
        return false;
    }

    uint16_t rx = ((buf[0] & 0x0F) << 8) | buf[1];
    uint16_t ry = ((buf[2] & 0x0F) << 8) | buf[3];

    if (x) *x = rx;
    if (y) *y = ry;

    return true;
}