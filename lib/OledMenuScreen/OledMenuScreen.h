#ifndef OLEDMENUSCREEN_H
#define OLEDMENUSCREEN_H
#include <OledAnimations.h>
#include <U8g2lib.h>
#include <WString.h>

class OledMenuScreen {
public:
    OledMenuScreen();

    void drawHeaderText(const String &headerText = "Vannerud");

    void drawContentTextLeft(int row, const String &contentText);

    void drawContentTextRight(int row, const String &contentText);

    static U8X8_SSD1306_128X64_NONAME_SW_I2C& getU8x8();

private:
    static U8X8_SSD1306_128X64_NONAME_SW_I2C u8x8;
};
#endif
