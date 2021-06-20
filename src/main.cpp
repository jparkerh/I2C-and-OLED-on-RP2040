#include "SFE_MicroOLED.h"

int main () {

    MicroOLED oled(13, 0); //Example I2C declaration
    oled.begin();
    oled.clear(ALL);
    oled.display();

    return 0;
}