#include "max30102.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

extern SemaphoreHandle_t i2c_mux;

static esp_err_t write_reg(i2c_port_t port, uint8_t reg, uint8_t val)
{
    uint8_t data[2] = { reg, val };
    xSemaphoreTake(i2c_mux, portMAX_DELAY);
    esp_err_t ret = i2c_master_write_to_device(
        port,
        MAX30102_I2C_ADDR,
        data,
        sizeof(data),
        pdMS_TO_TICKS(100)
    );
    xSemaphoreGive(i2c_mux);
    return ret;
}

static esp_err_t read_regs(i2c_port_t port, uint8_t reg, uint8_t *buf, size_t len)
{
    xSemaphoreTake(i2c_mux, portMAX_DELAY);
    esp_err_t ret = i2c_master_write_read_device(
        port,
        MAX30102_I2C_ADDR,
        &reg,
        1,
        buf,
        len,
        pdMS_TO_TICKS(100)
    );
    xSemaphoreGive(i2c_mux);
    return ret;
}

esp_err_t max30102_init(max30102_t *dev, i2c_port_t port)
{
    dev->i2c_port = port;

    uint8_t part_id;
    esp_err_t err = read_regs(port, 0xFF, &part_id, 1);
    if (err != ESP_OK) {
        return err;
    }

    if (part_id != 0x15) {
        return ESP_ERR_NOT_FOUND;
    }

    return ESP_OK;
}

esp_err_t max30102_configure(max30102_t *dev,
                             uint8_t led_brightness,
                             uint8_t sample_average,
                             uint8_t led_mode,
                             uint8_t sample_rate,
                             uint8_t pulse_width,
                             uint8_t adc_range)
{
    write_reg(dev->i2c_port, 0x09, led_brightness);
    write_reg(dev->i2c_port, 0x0A, (sample_average << 5) | (led_mode << 1));
    write_reg(dev->i2c_port, 0x0C,
              (adc_range << 5) | (sample_rate << 2) | pulse_width);

    return ESP_OK;
}

esp_err_t max30102_read_red(max30102_t *dev, uint32_t *red)
{
    uint8_t buf[3];
    esp_err_t err = read_regs(dev->i2c_port, 0x03, buf, 3);
    if (err != ESP_OK) return err;

    *red = ((uint32_t)buf[0] << 16) |
           ((uint32_t)buf[1] << 8)  |
           buf[2];

    return ESP_OK;
}

esp_err_t max30102_read_ir(max30102_t *dev, uint32_t *ir)
{
    uint8_t buf[3];
    esp_err_t err = read_regs(dev->i2c_port, 0x04, buf, 3);
    if (err != ESP_OK) return err;

    *ir = ((uint32_t)buf[0] << 16) |
          ((uint32_t)buf[1] << 8)  |
          buf[2];

    return ESP_OK;
}

esp_err_t max30102_read_temperature(max30102_t *dev, float *temp_c)
{
    uint8_t buf[2];
    esp_err_t err = read_regs(dev->i2c_port, 0x1F, buf, 2);
    if (err != ESP_OK) return err;

    *temp_c = (int8_t)buf[0] + buf[1] * 0.0625f;
    return ESP_OK;
}

esp_err_t max30102_shutdown(max30102_t *dev)
{
    uint8_t reg;
    esp_err_t err = read_regs(dev->i2c_port,
                              MAX30102_REG_MODE_CONFIG,
                              &reg,
                              1);
    if (err != ESP_OK) return err;

    reg |= MAX30102_SHDN_BIT;

    return write_reg(dev->i2c_port,
                     MAX30102_REG_MODE_CONFIG,
                     reg);
}

esp_err_t max30102_wakeup(max30102_t *dev)
{
    uint8_t reg;
    esp_err_t err = read_regs(dev->i2c_port,
                              MAX30102_REG_MODE_CONFIG,
                              &reg,
                              1);
    if (err != ESP_OK) return err;

    reg &= ~MAX30102_SHDN_BIT;

    err = write_reg(dev->i2c_port,
                    MAX30102_REG_MODE_CONFIG,
                    reg);
    if (err != ESP_OK) return err;

    // Datasheet recommends a small delay after wake
    vTaskDelay(pdMS_TO_TICKS(10));

    return ESP_OK;
}

