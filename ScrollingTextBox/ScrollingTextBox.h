#ifndef SCROLLTEXTBOX_H
#define SCROLLTEXTBOX_H

#include "SFE_MicroOLED.h"
#include <string>

class MicroOLEDWithHeight: public MicroOLED {

public: 

    MicroOLEDWithHeight(int width, int height, uint8_t rst, uint8_t dc): 
        MicroOLED(rst, dc) {
            LCDWIDTH = width;
            LCDHEIGHT = height;
        };
};

class ScrollingTextBox {

    MicroOLED *oled; //Example I2C declaration
    
    int topLine;
    int currentLine;

public: 

    ScrollingTextBox();

    void showNewLine( void );
    void writeLine( const char *line, int numChars );
    void writeNewLine( std::string newline );
};

#endif