#include "hardware/i2c.h"
#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <cstdio>

class TwoWire {

    uint8_t address;
    uint8_t* data;
    uint32_t size;
    i2c_inst_t *i2c_inst;

    public:
        TwoWire ();
        void beginTransmission(uint8_t);
        void write(uint8_t);
        uint8_t write(uint8_t *, uint8_t);
        void read(uint8_t);
        void printTransmission();

        uint8_t endTransmission();
        uint8_t endTransmission(bool);

};