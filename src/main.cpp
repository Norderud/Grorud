#include <Arduino.h>
#include <config.h>


const int dry = 1024;
const int wet = 600;
void setup() {
    Serial.begin(115200);
    Serial.println("Hello, world!");
}

void loop() {
    int sensorVal = analogRead(MOISTURE_SENSOR_PIN);

    int moisture = map(sensorVal, wet, dry, 100, 0);
    Serial.println(moisture);
    delay(1000);
}