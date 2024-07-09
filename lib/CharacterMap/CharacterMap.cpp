#include <U8g2lib.h>
#include <Arduino.h>
#include <CharacterMap.h>
#define BUTTON_PIN 5  // Button connected to GPIO 5 (D1)

struct Chars;
U8X8_SSD1306_128X64_NONAME_SW_I2C u8x8(/*clock=*/14, /*data=*/12, /*reset=*/U8X8_PIN_NONE);

int topRows = 2;
int rows = u8x8.getRows() - topRows;
int cols = u8x8.getCols();
bool inverse = false;

void changeInverse() {
    inverse = !inverse;
}

char getChar(int x) {
    if (inverse) {
        return (x <= cols / 2) ? Chars::downRightLeftUp : Chars::downLeftUpRight;
    }
    return (x <= cols / 2) ? Chars::downLeftUpRight : Chars::downRightLeftUp;
}

void drawTriangle() {
    u8x8.drawString(1, 0, ("Inverse: "));
    u8x8.drawString(1, 1, (inverse == 0 ? "False" : "True"));
    int y = topRows;
    for (int row = 0; row <= rows - topRows; ++row) {
        int width;
        inverse ? width = 1 + 2 * (rows - topRows - row) : width = 1 + 2 * row;
        int startCol = (cols / 2) - width / 2;
        int x = startCol;
        for (int col = startCol; col < startCol + width; ++col) {
            u8x8.drawGlyph(x++, y, getChar(col));
            delay(20);
        }
        y++;
    }
    changeInverse();
}

void pipeAnimation() {
    static int x = cols / 2, y = rows / 2;
    static int xDir = 1, yDir = -1;

    x += xDir;
    y += yDir;
    if (y > rows || y < 2) yDir *= -1;
    if (x > cols || x <= 1) xDir *= -1;

    u8x8.drawGlyph(x, y, getChar(xDir));
    delay(100);
}

void setup() {
    // u8x8.begin();
    // Serial.begin(115200);
    // u8x8.setBusClock(400000);
    // u8x8.setFont(u8x8_font_amstrad_cpc_extended_f);
    // u8x8.setFont(u8x8_font_saikyosansbold8_u);
}

void loopTriangle() {
    for (int i = 0; i < 3; i++) {
        drawTriangle();
        delay(2000);
        u8x8.clearDisplay();
    }
}

// void loop() {
//     loopTriangle();
//     u8x8.setInverseFont(1);
//     loopTriangle();
//     u8x8.fillDisplay();
//     loopTriangle();
//     drawTriangle();
//     u8x8.fillDisplay();
//     u8x8.setInverseFont(0);
//     drawTriangle();
//     u8x8.setInverseFont(1);
//     drawTriangle();
//     u8x8.clearDisplay();
//     pipeAnimation();
// }

// bool buttonState = LOW;
// int lastButtonState = buttonState;
// unsigned long lastDebounceTime = 0;
// unsigned long debounceDelay = 20;

// void readButton(){
//   int reading = digitalRead(BUTTON_PIN);
//   if (reading != lastButtonState) {
//     lastDebounceTime = millis();
//   }
//   if ((millis() - lastDebounceTime) > debounceDelay) {
//     if (reading != buttonState) {
//       buttonState = reading;
//       if (buttonState == HIGH) {
//         pipeAnimation();
//       }
//     }
//   }
//   lastButtonState = reading;
// }
//
//
// int topClearSpeed = 2;
// void drawTopAnimation() {
//   (xDirection >= 0) ? u8x8.drawGlyph(x, 2, drawChars[rightArrow]) : u8x8.drawGlyph(x, 3, drawChars[leftArrow]);
//   if (timer % 3) {
//     u8x8.clearLine(0);
//   }
// }
//
// void nextTopChar() {
//   topChar = (topChar + 1) >= 6 ? topChar = 2 : topChar = topChar + 1;
// }
//
// void changeScene() {
//   u8x8.setFont(u8x8_font_open_iconic_play_2x2);
//   for (int i = 0; i <= rows; i++) {
//     for (int j = 0; j <= cols; j++) {
//       u8x8.drawGlyph(i, j, drawChars[stop]);
//     }
//     delay(20);
//   }
// }

// void resetScreen() {
//   for (uint8_t i = 0; i <= rows; i++) {
//     u8x8.clearLine(0);
//     delay(300);
//   }
// }
//   void switchTheme() {
//     Serial.print("Switch theme: ");
//     resetScreen();
//     currentTheme = (currentTheme + 1) % themeLength;
//     Serial.println(currentTheme);
//     changeScene();
//   }
