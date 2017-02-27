/**********************************************
 * TemperatureSensor.cpp
 * Created by Frazer Bayley and Brian Davis
 * The cpp file for our the temperature sensor
 * referenced SeeedStudio starter code
 **********************************************/

#include "TemperatureSensor.hpp"
#include "Arduino.h"
TemperatureSensor::TemperatureSensor()
{
    B = 3975;                                                   //value of the thermistor
    baseTemp = 0;
}
/**********************************
 * setTemp is called during startup
 ***********************************/
void TemperatureSensor::setTemp()
{
    int val = analogRead(pinTemp);                               // get analog value
    resistance = (float)(1023-val)*10000/val;                      // get resistance
    baseTemp = 1/(log(resistance/10000)/B+1/298.15)-273.15;     // calc temperature
    //Serial.println(temperature);

}
/******************************************************
 * getTemp is called every loop to set the current temp
 * and then gets called to set initial temps 
 ******************************************************/
float TemperatureSensor::getTemp()
{
    int val = analogRead(pinTemp);                               // get analog value
    resistance = (float)(1023-val)*10000/val;                      // get resistance
    temperature = 1/(log(resistance/10000)/B+1/298.15)-273.15;     // calc temperature
    //Serial.println(temperature);
    temperature = temperature * (9/5) + 32;                     //celsius to fahrenheit conversion
    return temperature;

}
TemperatureSensor::~TemperatureSensor()
{
    //dtor
}
