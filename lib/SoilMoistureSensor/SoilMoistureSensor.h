#ifndef SOILMOISTURESENSOR_H
#define SOILMOISTURESENSOR_H
#include <Arduino.h>

constexpr int dry = 1024;
constexpr int wet = 420;

class SoilMoistureSensor {
public:
    explicit SoilMoistureSensor(int pin);

    String readMoisturePercentage();

    int readMoisturePercentageInt();

private:
    static String digitStringPadding(int digit, const String &text);

    int pin;
};

#endif
