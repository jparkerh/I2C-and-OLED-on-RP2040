#include "ScrollingTextBox.h"
#include <stdio.h>
#include "pico/stdlib.h"

void testWrappingInt (ScrollingTextBox &term) {

    for (int i = 0; i<256; i++){
        term.writeNewLine(std::to_string(i));
    }
}

int main () {

    stdio_init_all();
    sleep_ms(2000);

    ScrollingTextBox term;

    // quick testbench, shows the wrap around of the gdram buffer
    testWrappingInt(term);
    
    // busy exit, keeps USB peripheral up
    while (1) {}

    return 0;
}