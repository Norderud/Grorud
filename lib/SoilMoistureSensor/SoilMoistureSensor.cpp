#include "SoilMoistureSensor.h"
#include "config.h"

SoilMoistureSensor::SoilMoistureSensor(int pin) {
    this->pin = pin;
    pinMode(pin, OUTPUT);
}

String SoilMoistureSensor::digitStringPadding(int digit, const String &text) {
    String moistureStr = String(digit) + text;
    if (digit < 10) {
        // Only 1 digit
        return "  " + moistureStr; // Add two spaces
    }
    return moistureStr;
}

int SoilMoistureSensor::readMoisturePercentageInt() {
    if(pin == 0) {
        digitalWrite(pin, HIGH);
        digitalWrite(2, LOW);
    } else {
        digitalWrite(pin, LOW);
        digitalWrite(2, HIGH);
    }
    int moistureSensorVal = analogRead(A0);
    Serial.println("VAL: " + String(moistureSensorVal) + " " + pin);
    delay(1000);
    return map(moistureSensorVal, wet, dry, 100, 0);
}

String SoilMoistureSensor::readMoisturePercentage() {
    return digitStringPadding(readMoisturePercentageInt(), "%");
}
