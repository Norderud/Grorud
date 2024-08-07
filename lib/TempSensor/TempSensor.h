// TempSensor.h
#ifndef TEMPSENSOR_H
#define TEMPSENSOR_H

#include <DHT.h>

class TempSensor {
public:
    TempSensor(uint8_t pin);
    void begin();
    float readTemp();
    float readHumidity();

private:
    DHT dht;
};

#endif // TEMPSENSOR_H

