#include "SFE_MicroOLED.h"
#include <stdio.h>
#include "pico/stdlib.h"

int main () {

    stdio_init_all();
    sleep_ms(5000);

    MicroOLED oled(9, 1); //Example I2C declaration
    oled.begin();
    oled.clear(0);
    printf("After init and clear\n");

    oled.display();

    int MIDDLE_X = oled.getLCDWidth() / 2; // Find the centre of the display
    int MIDDLE_Y = oled.getLCDHeight() / 2;

    oled.circle(MIDDLE_X, MIDDLE_Y, 20);
    oled.display();

    printf("After display\n");

    while (1) {}

    return 0;
}