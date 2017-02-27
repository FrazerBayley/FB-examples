/*******************************************
 * SoundSensor.cpp
 * Created by Frazer Bayley and Brian Davis
 * The cpp file for our the audio sensor
 * referenced SeeedStudio starter code
 *******************************************/

#include "SoundSensor.hpp"
#include "Arduino.h"

SoundSensor::SoundSensor()
{
    //ctor
}
/********************************************************
 * getSound is called every loop and returns the voltage
 * of whatever sound was detected
 ********************************************************/
double SoundSensor::getSound()
{
    while (millis() - startMillis < sampleWindow){
      temp = analogRead(A1);
      if (temp < 1024){
        if (temp > maximum){
          maximum = temp;
        }
        else if (temp < minimum){
          minimum = temp;
        }
      }
    }
    peakToPeak = maximum - minimum;                 // max - min = peak-peak amplitude
    double volts = peakToPeak;
    return volts;

}
SoundSensor::~SoundSensor()
{
    //dtor
}

