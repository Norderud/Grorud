// TempSensor.cpp
#include "TempSensor.h"

TempSensor::TempSensor(uint8_t pin) : dht(pin, DHT22) {}

void TempSensor::begin() {
    dht.begin();
}

float TempSensor::readTemp() {
    float t = dht.readTemperature();
    if (isnan(t)) {
        Serial.println("Failed to read temperature from DHT sensor!");
        return -999.0; // Indicate failure
    }
    return t;
}

float TempSensor::readHumidity() {
    float h = dht.readHumidity();
    if (isnan(h)) {
        Serial.println("Failed to read humidity from DHT sensor!");
        return -999.0; // Indicate failure
    }
    return h;
}