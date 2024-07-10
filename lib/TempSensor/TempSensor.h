#ifndef TEMPSENSOR_H
#define TEMPSENSOR_H
#include <DallasTemperature.h>
#include <OneWire.h>

class TempSensor {
public:
    TempSensor();

    static float readTemp();
};

#endif //TEMPSENSOR_H
