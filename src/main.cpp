#include <header.h>

SoilMoistureSensor sms= SoilMoistureSensor();
TempSensor ts = TempSensor();
OledMenuScreen screen = OledMenuScreen();
OledAnimations animations = OledAnimations(OledMenuScreen::getU8x8());

void setup() {
    OledMenuScreen::getU8x8().setFont(u8x8_font_victoriabold8_r);
    Serial.begin(115200);
    delay(500);
    animations.loopPipeAnimation(200);
    delay(500);
    animations.drawDick();
    delay(2000);
    animations.removeAnimation();
    delay(500);
    animations.drawAnimation();
    delay(500);
    animations.removeAnimation();
    delay(500);
    animations.loopTriangle(5);
    delay(1000);

    screen.drawHeaderText("Vannerud");
    String moistureString = "Moisture:";
    screen.drawContentTextLeft(1, moistureString);
    String temperatureString = "Temp:";
    screen.drawContentTextLeft(3, temperatureString);
}
String digitStringPadding(int digit, const String &text) {
    String moistureStr = String(digit) + text;
    if (digit < 10) { // Only 1 digit
        return "  " + moistureStr; // Add two spaces
    }
    return moistureStr;
}
void loop() {
    int moisturePercentage = sms.readMoisturePercentage();
    String moistureString = digitStringPadding(moisturePercentage, "% ");
    screen.drawContentTextRight(1, moistureString);
    delay(100);
    float temp = ts.readTemp();
    Serial.println(temp);
    String temperatureString = String(temp, 1) + "C ";
    screen.drawContentTextRight(3, temperatureString);
    delay(5000);
}

