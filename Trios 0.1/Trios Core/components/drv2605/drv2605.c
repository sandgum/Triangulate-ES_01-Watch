#include "drv2605.h"
#include "driver/i2c.h"
#include "freertos/FreeRTOS.h"
#include "freertos/semphr.h"

#define DRV2605_ADDR 0x5A

#define DRV2605_REG_STATUS     0x00
#define DRV2605_REG_MODE       0x01
#define DRV2605_REG_RTP_INPUT  0x02
#define DRV2605_REG_WAVESEQ1   0x04
#define DRV2605_REG_GO         0x0C
#define DRV2605_REG_FEEDBACK   0x1A
#define DRV2605_REG_CONTROL1   0x1B
#define DRV2605_REG_CONTROL2   0x1C
#define DRV2605_REG_CONTROL3   0x1D
#define DRV2605_REG_CONTROL4   0x1E

extern SemaphoreHandle_t i2c_mux;

/* ---------- Internal no-lock I2C helpers ---------- */

static esp_err_t drv2605_write_nolock(i2c_port_t port, uint8_t reg, uint8_t val)
{
    uint8_t buf[2] = { reg, val };
    return i2c_master_write_to_device(port, DRV2605_ADDR, buf, 2, pdMS_TO_TICKS(50));
}

static esp_err_t drv2605_read_nolock(i2c_port_t port, uint8_t reg, uint8_t *val)
{
    return i2c_master_write_read_device(port, DRV2605_ADDR,
                                        &reg, 1, val, 1,
                                        pdMS_TO_TICKS(50));
}

/* ---------- Public API ---------- */

esp_err_t drv2605_init(i2c_port_t port)
{
    if (xSemaphoreTake(i2c_mux, pdMS_TO_TICKS(200)) != pdTRUE)
        return ESP_ERR_TIMEOUT;

    esp_err_t ret = ESP_OK;

    ret |= drv2605_write_nolock(port, DRV2605_REG_MODE, 0x00);     // Exit standby
    ret |= drv2605_write_nolock(port, DRV2605_REG_FEEDBACK, 0x80); // LRA mode
    ret |= drv2605_write_nolock(port, DRV2605_REG_CONTROL1, 0x93);
    ret |= drv2605_write_nolock(port, DRV2605_REG_CONTROL2, 0xF5);
    ret |= drv2605_write_nolock(port, DRV2605_REG_CONTROL3, 0xA3);
    ret |= drv2605_write_nolock(port, DRV2605_REG_CONTROL4, 0x20);

    xSemaphoreGive(i2c_mux);
    return ret;
}

esp_err_t drv2605_autocalibrate(i2c_port_t port)
{
    if (xSemaphoreTake(i2c_mux, pdMS_TO_TICKS(500)) != pdTRUE)
        return ESP_ERR_TIMEOUT;

    drv2605_write_nolock(port, DRV2605_REG_MODE, 0x07);
    drv2605_write_nolock(port, DRV2605_REG_GO, 1);

    uint8_t go;
    do {
        vTaskDelay(pdMS_TO_TICKS(10));
        drv2605_read_nolock(port, DRV2605_REG_GO, &go);
    } while (go & 0x01);

    uint8_t status;
    drv2605_read_nolock(port, DRV2605_REG_STATUS, &status);

    xSemaphoreGive(i2c_mux);
    return (status & 0x08) ? ESP_FAIL : ESP_OK;
}

esp_err_t drv2605_play_effect(i2c_port_t port, uint8_t effect)
{
    if (xSemaphoreTake(i2c_mux, pdMS_TO_TICKS(200)) != pdTRUE)
        return ESP_ERR_TIMEOUT;

    drv2605_write_nolock(port, DRV2605_REG_MODE, 0x00);
    drv2605_write_nolock(port, DRV2605_REG_WAVESEQ1, effect);
    drv2605_write_nolock(port, DRV2605_REG_WAVESEQ1 + 1, 0);
    esp_err_t ret = drv2605_write_nolock(port, DRV2605_REG_GO, 1);

    xSemaphoreGive(i2c_mux);
    return ret;
}

esp_err_t drv2605_set_rtp(i2c_port_t port, uint8_t strength)
{
    if (xSemaphoreTake(i2c_mux, pdMS_TO_TICKS(200)) != pdTRUE)
        return ESP_ERR_TIMEOUT;

    drv2605_write_nolock(port, DRV2605_REG_MODE, 0x05);
    esp_err_t ret = drv2605_write_nolock(port, DRV2605_REG_RTP_INPUT, strength);

    xSemaphoreGive(i2c_mux);
    return ret;
}
