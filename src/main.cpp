#include <config.h>
#include <header.h>

int LOW_THRESHOLD = 20;
int HIGH_THRESHOLD = 60;
int CHECK_DELAY = 1000;
int PUMP_DURATION = 5000;

char ssid[] = "Waldemars brorskap gang 2.4";
char pass[] = "0173Oslo";

SoftwareSerial softSerial(D1, D2);
BlynkTimer timer;

int status = Offline;

OledMenuScreen screen;
OledAnimations animations(OledMenuScreen::getU8x8());

int moistureValues[4];

String percentagize(int value)
{
    return String(value) + "%";
}


void sendSensorData()
{
    JsonDocument doc;
    deserializeJson(doc, softSerial);
    status = doc["status"];
    JsonArray moistureLevels = doc["moistureLevels"];
    moistureValues[0] = moistureLevels[0];
    moistureValues[1] = moistureLevels[1];
    moistureValues[2] = moistureLevels[2];
    screen.drawContentTextRight(0, percentagize(moistureValues[0]));
    screen.drawContentTextRight(2, percentagize(moistureValues[1]));
    screen.drawContentTextRight(4, percentagize(moistureValues[2]));

    Blynk.virtualWrite(V0, moistureValues[0]);
    Blynk.virtualWrite(V1, moistureValues[1]);
    Blynk.virtualWrite(V2, moistureValues[2]);
    Blynk.virtualWrite(V4, status);
}

void setup()
{
    Serial.begin(115200);
    softSerial.begin(9600);
    while (!softSerial){continue;}

    OledMenuScreen::getU8x8().setFont(u8x8_font_victoriabold8_r);

    screen.drawHeaderText("Vannerud");
    screen.drawContentTextLeft(0, "Plant 1:");
    screen.drawContentTextLeft(2, "Plant 2:");
    screen.drawContentTextLeft(4, "Plant 3:");

    Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
    timer.setInterval(CHECK_DELAY, sendSensorData);
    status = Offline;
}

void loop()
{    
    Blynk.run();
    timer.run();
}