#include "OledMenuScreen.h"

#include <OledAnimations.h>

U8X8_SSD1306_128X64_NONAME_SW_I2C OledMenuScreen::u8x8(/*clock=*/14, /*data=*/12, /*reset=*/U8X8_PIN_NONE);

const int contentStartY = 2;
const int maxWidth = OledMenuScreen::getU8x8().getCols();
const int maxHeight = OledMenuScreen::getU8x8().getRows();

const uint8_t* fonts[] = {
    u8x8_font_amstrad_cpc_extended_f,
    u8x8_font_victoriabold8_r,
    u8x8_font_torussansbold8_r,
    u8x8_font_chroma48medium8_r,
    u8x8_font_px437wyse700a_2x2_r,
    u8x8_font_pressstart2p_r,
};
OledMenuScreen::OledMenuScreen() {
    getU8x8().begin();
}
void OledMenuScreen::drawHeaderText(const String &headerText) {
    getU8x8().setFont(u8x8_font_torussansbold8_r);
    getU8x8().setInverseFont(0);
    getU8x8().draw1x2String(maxWidth/2 - headerText.length()/2, 0 , headerText.c_str());
    getU8x8().println();
}
void OledMenuScreen::drawContentTextLeft(const int row, const String &contentText) {
    getU8x8().setFont(u8x8_font_amstrad_cpc_extended_f);
    getU8x8().setCursor(0, contentStartY + row);
    getU8x8().print(contentText.c_str());
}
void OledMenuScreen::drawContentTextRight(const int row, const String &contentText) {
    getU8x8().setFont(u8x8_font_amstrad_cpc_extended_f);
    getU8x8().setCursor(maxWidth - contentText.length(), contentStartY + row);
    getU8x8().print(contentText.c_str());
}

U8X8_SSD1306_128X64_NONAME_SW_I2C& OledMenuScreen::getU8x8() {
    return u8x8;
}