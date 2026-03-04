#include "driver/i2c.h"
#include "rom/ets_sys.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "bhy2.h"


// Define your I2C parameters
#define I2C_MASTER_NUM I2C_NUM_0
#define BHI260_ADDR    0x28 // or 0x29, check your schematic

extern SemaphoreHandle_t i2c_mux;

// 1. Read Function Wrapper
int8_t bhi260_i2c_read(uint8_t reg_addr, uint8_t *reg_data, uint32_t length, void *intf_ptr) {
    xSemaphoreTake(i2c_mux, portMAX_DELAY);
    esp_err_t err = i2c_master_write_read_device(I2C_MASTER_NUM,
                                                 BHI260_ADDR,
                                                 &reg_addr, 1,
                                                 reg_data, length,
                                                 pdMS_TO_TICKS(100));
    xSemaphoreGive(i2c_mux);
    return (err == ESP_OK) ? BHY2_OK : BHY2_E_IO;
}

// 2. Write Function Wrapper
int8_t bhi260_i2c_write(uint8_t reg_addr, const uint8_t *reg_data, uint32_t length, void *intf_ptr) {
    // We need to send [Register Address] + [Data] in one transaction
    uint8_t *buffer = malloc(length + 1);
    if (!buffer) return BHY2_E_NULL_PTR;

    buffer[0] = reg_addr;
    memcpy(&buffer[1], reg_data, length);

    xSemaphoreTake(i2c_mux, portMAX_DELAY);
    esp_err_t err = i2c_master_write_to_device(I2C_MASTER_NUM,
                                               BHI260_ADDR,
                                               buffer, length + 1,
                                               pdMS_TO_TICKS(100));
    xSemaphoreGive(i2c_mux);
    free(buffer);
    return (err == ESP_OK) ? BHY2_OK : BHY2_E_IO;
}

// 3. Delay Function Wrapper
void bhi260_delay_us(uint32_t period, void *intf_ptr) {
    if (period < 1000) {
        ets_delay_us(period); // Busy wait for short delays
    } else {
        vTaskDelay(pdMS_TO_TICKS(period / 1000)); // Yield for long delays
    }
}