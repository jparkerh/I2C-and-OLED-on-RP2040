#include "ScrollingTextBox.h"
#include <string.h>

/**
 * @brief Construct a new Scrolling Text Box:: Scrolling Text Box object
 * 
 * @note All ScrollingTextBox objects use the same MicroOled instance at this point.
 *  clears the screen and set the new device up!
 *  
 */
ScrollingTextBox::ScrollingTextBox() {

    // Initialize OLED object and clear the screen
    
    oled = new MicroOLEDWithHeight(64,64,9,1); //Example I2C declaration
    oled->begin();
    oled->clear(0);

    // Start at the bottom line
    topLine = -1;
}

/**
 * @brief rotate screen so oldest line is erased and becomes new line on the screen
 * 
 * Rather than redrawing the full screen gdram each time, we shift the screen
 * row_offset by one char height (7 + 1 padding = 8)
 * Since this call is shifting to the old line, make sure to clear that PAGE of data
 * 
 * @note (7+1padding=8) line height was chosen because this aligns perfectly with
 * each page of data in gdram
 * 
 */
void ScrollingTextBox::showNewLine( void ) {

    // Move to the next line, 
    topLine++;
    topLine%=8;

    // Adjust current line pointer
    currentLine = (topLine + 7) % 8;

    // Send command to the screen to set "top" pointer
    oled->command(SETDISPLAYOFFSET); // 0xD3
	oled->command(topLine * 8); // offset of next page
}

/**
 * @brief write a buffer of characters to the current top line of the screen
 * 
 * @param line buffer of characters to write
 * @param numChars number of characters to write from the buffer
 */
void ScrollingTextBox::writeLine( const char *line, int numChars ) {

    // Erase line
    oled->setColor(BLACK);
    oled->rectFill(0, (currentLine * 8), oled->getLCDWidth(), 8);
    oled->setColor(WHITE);

    // Write characters
    for (int idx=0; idx<numChars; idx++)
        oled->drawChar(idx * 5, (currentLine * 8), line[idx]);

    // Move buffer out to GDRAM
    oled->display();
}

/**
 * @brief write the next line to the screen
 * 
 * @param line buffer to write
 * @param numChars number of characters in the buffer
 */
void ScrollingTextBox::writeNewLine ( std::string newline) {

    showNewLine ();
    writeLine (newline.c_str(), newline.length());

}

