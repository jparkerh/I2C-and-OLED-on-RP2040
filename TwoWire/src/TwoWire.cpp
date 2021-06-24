#include "TwoWire.h"

const int DEBUG=0;

TwoWire::TwoWire () {
    i2c_inst = i2c1;
    i2c_init(i2c_inst, 100000);
    gpio_set_function(2, GPIO_FUNC_I2C);
    gpio_set_function(3, GPIO_FUNC_I2C);
}

void TwoWire::beginTransmission(uint8_t addr) {
    address = addr;
    size = 0;
    data = new uint8_t[32];
}

void TwoWire::printTransmission() {
    printf("----NewTransmission----\n");
    printf("size: %i\n", size);
    for (int byte=0; byte<size; byte++) {
        printf("    %2x\n", data[byte]);
    }
}

uint8_t TwoWire::endTransmission() {
    if (DEBUG)
        printTransmission();

    i2c_write_blocking (i2c_inst,
       address,
       data,
       size,
       0);

    delete[] data;
    return 0;
}

uint8_t TwoWire::endTransmission(bool in) {
    if (DEBUG)
        printTransmission();

    i2c_write_blocking (i2c_inst,
       address,
       data,
       size,
       !in);

    delete[] data;
    return 0;
}

void TwoWire::write(uint8_t writeData) {
    data[size] = writeData;
    size++;
}

uint8_t TwoWire::write(uint8_t *writeData, uint8_t numData) {
    for (int _byte = 0; _byte<numData; _byte++) {
        data[size] = writeData[_byte];
        size++;
    }

    return numData;
}