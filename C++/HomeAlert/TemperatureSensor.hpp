/************************************************
 * TemperatureSensor.hpp
 * Created by Frazer Bayley and Brian Davis
 * The header file for our the temperature sensor
 * referenced SeeedStudio starter code
 ************************************************/

#ifndef TEMPERATURESENSOR_HPP
#define TEMPERATURESENSOR_HPP
#include "Arduino.h"

class TemperatureSensor
{
    public:
        TemperatureSensor();
        void setTemp();
        float getTemp();
        virtual ~TemperatureSensor();
    protected:
    private:
        float temperature, resistance, baseTemp;
        int B;
        bool setAlarm;
        const int pinTemp = A0;                   // pin of temperature sensor
};

#endif // TEMPERATURESENSOR_H
