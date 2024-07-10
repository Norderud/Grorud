#include <OledAnimations.h>

struct Chars;
int topRows = 2;
int rows;
int cols;
bool inverse = false;

OledAnimations::OledAnimations(U8X8_SSD1306_128X64_NONAME_SW_I2C &u8x8): u8x8(u8x8) {
    rows = u8x8.getRows();
    cols = u8x8.getCols();
    u8x8.begin();
    u8x8.setFont(u8x8_font_amstrad_cpc_extended_f);
}

uint8_t blackBoxTile[16] = {
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
};

void OledAnimations::drawDick() {
    u8x8.setFont(u8x8_font_amstrad_cpc_extended_f);
    String s = "GRORUD";
    u8x8.draw2x2String((cols / 2) - s.length(), 4, "GRORUD");
    delay(2000);
    u8x8.clearDisplay();
}

void OledAnimations::drawAnimation() {
    static int prevX = -1, prevY = -1; // Initialize with out-of-bounds values for the first run
    bool toggle = false; // Toggle between drawing and erasing tiles
    for (int y = 0; y < u8x8.getRows(); y++) {
        toggle = !toggle; // Toggle at the start of each row for the checkerboard pattern
        for (int x = 0; x < u8x8.getCols(); x++) {
            bool drawTile = (x % 2 == 0) ? toggle : !toggle;
            if (drawTile) {
                u8x8.drawTile(x, y, 1, blackBoxTile); // Adjust the width if necessary
            }
            prevX = x;
            prevY = y;
            delay(20); // Adjust delay as needed for smoother animation
        }
    }
    if (!toggle) {
        u8x8.drawTile(prevX, prevY, 1, blackBoxTile);
    }
}

void OledAnimations::removeAnimation() {
    for (int y = 0; y < u8x8.getRows(); y++) {
        for (int x = 0; x < u8x8.getCols(); x++) {
            u8x8.drawTile(x, y, 1, blackBoxTile);
            delay(10); // Adjust delay as needed for smoother animation
        }
    }
    u8x8.clearDisplay();
}

void changeInverse() {
    inverse = !inverse;
}

char getChar(int x) {
    if (x < cols / 2) {
        return inverse ? Chars::downRightLeftUp : Chars::downLeftUpRight;
    }
    return inverse ? Chars::downLeftUpRight : Chars::downRightLeftUp;
}

void OledAnimations::drawTriangle() {
    int y = topRows;
    for (int row = topRows; row <= rows - 1; ++row) {
        int width;
        inverse ? width = 1 + 2 * (rows - topRows - row) : width = 1 + 2 * (row - topRows);
        int startCol = (cols / 2) - (width / 2) - 1;
        int x = startCol;
        for (int col = startCol; col <= startCol + width; ++col) {
            u8x8.drawGlyph(x++, y, getChar(col));
            delay(20);
        }
        y++;
    }
    changeInverse();
}

void OledAnimations::loopTriangle(int times) {
    u8x8.drawString(1, 0, ("Pyramide: "));
    u8x8.drawString(0, 1, "----------------");
    for (int i = 0; i < times; i++) {
        drawTriangle();
        delay(500);
        for (int i = 2; i <= rows; i++) {
            u8x8.clearLine(i);
        }
    }
    u8x8.clear();
}

char getPipeChar(int xDir, int yDir) {
    if (xDir == 0) {
        return Chars::vertical; // Assuming this is the character for horizontal movement
    }
    if (yDir == 0) {
        return Chars::horizontalMid; // Assuming this is the character for vertical movement
    }
    return (xDir > 0) == (yDir > 0) ? Chars::downRightLeftUp : Chars::downLeftUpRight;
}

bool trailing = true;

String nextDot() {
    static int i = 0;
    String dots = "";
    for (int j = 0; j < i; j++) {
        dots += ".";
    }
    for (int x = dots.length(); x <= 3; x++) {
        dots += " ";
    }
    i = (i + 1) % 4;
    return dots;
}

void OledAnimations::pipeAnimation() {
    static int prevX = -1, prevY = -1;
    static int x = (cols / 2) - 4, y = rows / 2 + 1;
    static int xDir = 1, yDir = -1;
    if (x % 6 == 0) {
        u8x8.drawString(8, 0, nextDot().c_str());
        int direction = random(0, 8); // Simplified random direction choice
        xDir = (direction == 2) ? -1 : (direction == 3) ? 1 : 0;
        yDir = (direction == 0) ? -1 : (direction == 1) ? 1 : 0;
        if (direction >= 4) {
            xDir = xDir == 0 ? (random(0, 2) * 2 - 1) : xDir;
            yDir = yDir == 0 ? (random(0, 2) * 2 - 1) : yDir;
        }
    }
    prevX = x;
    prevY = y;
    if(y >= rows - 1) {
        yDir = -1;
    }
    if (y <= topRows) {
        yDir = 1;
    }
    if(x >= cols - 1) {
        xDir = -1;
    }
    if(x <= 0 + 1) {
        xDir = 1;
    }
    x += xDir;
    y += yDir;

    u8x8.drawGlyph(x, y, getPipeChar(xDir, yDir));
    if (!trailing) {
        u8x8.drawGlyph(prevX, prevY, ' ');
    }
    delay(50);
}

void OledAnimations::loopPipeAnimation(int times) {
    u8x8.drawString(1, 0, ("Loading"));
    for (int i = 0; i < times; i++) {
        pipeAnimation();
    }
    trailing = !trailing;
    for (int i = 0; i < times; i++) {
        pipeAnimation();
    }
}
