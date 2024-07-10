
#ifndef SOILMOISTURESENSOR_H
#define SOILMOISTURESENSOR_H
#include <WString.h>
#include <Arduino.h>

constexpr int dry = 1024;
constexpr int wet = 605;

class SoilMoistureSensor {
public:
    SoilMoistureSensor();

    static int readMoisturePercentage();
    String formatMoisturePercentage(int moisture);
};

#endif //SOILMOISTURESENSOR_H
