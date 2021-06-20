#include "TwoWire.h"

TwoWire::TwoWire () {
    i2c_inst = i2c0;
    i2c_init(i2c_inst, 100 * 1000);
    gpio_set_function(PICO_DEFAULT_I2C_SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(PICO_DEFAULT_I2C_SCL_PIN, GPIO_FUNC_I2C);
    gpio_pull_up(PICO_DEFAULT_I2C_SDA_PIN);
    gpio_pull_up(PICO_DEFAULT_I2C_SCL_PIN);
}

void TwoWire::beginTransmission(uint8_t addr) {
    address = addr;
}

uint8_t TwoWire::endTransmission() {
    return 0;
}

uint8_t TwoWire::endTransmission(bool in) {
    return 0;
}

void TwoWire::write(uint8_t writeData) {
    uint8_t tmpData = writeData;
    int ret = i2c_write_blocking (i2c_inst,
       address,
       &writeData,
       1,
       0);
}

uint8_t TwoWire::write(uint8_t *writeData, uint8_t numData) {
    return i2c_write_blocking (i2c_inst,
       address,
       writeData,
       numData,
       0);
}