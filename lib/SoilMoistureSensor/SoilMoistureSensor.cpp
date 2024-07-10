#include "SoilMoistureSensor.h"
#include "config.h"

SoilMoistureSensor::SoilMoistureSensor() {
    pinMode(MOISTURE_SENSOR_PIN, INPUT);
}

int SoilMoistureSensor::readMoisturePercentage() {
    int moistureSensorVal = analogRead(MOISTURE_SENSOR_PIN);
    return map(moistureSensorVal, wet, dry, 100, 0);
}
