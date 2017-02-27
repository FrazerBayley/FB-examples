/*******************************************
 * SoundSensor.hpp
 * Created by Frazer Bayley and Brian Davis
 * The header file for our the audio sensor
 * referenced SeeedStudio starter code
 *******************************************/

#ifndef SOUNDSENSOR_HPP
#define SOUNDSENSOR_HPP
#include "Arduino.h"

class SoundSensor
{
    public:
        SoundSensor();
        double getSound();
        virtual ~SoundSensor();
    protected:
    private:
        const int sampleWindow = 50;            // Sample window width in mS (50 mS = 20Hz)
        unsigned int temp;
        unsigned long startMillis= millis();    // Start of sample window
        unsigned int peakToPeak = 0;            // peak-to-peak level
        unsigned int maximum = 0;
        unsigned int minimum = 1024;
};

#endif // SOUNDSENSOR_H

