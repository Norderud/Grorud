#include "TempSensor.h"

#include "config.h"
OneWire oneWire(TEMPERATURE_SENSOR_PIN);
DallasTemperature sensors(&oneWire);


TempSensor::TempSensor() {
    sensors.begin();
}

float TempSensor::readTemp() {
    sensors.requestTemperatures();
    return sensors.getTempCByIndex(0);
}
