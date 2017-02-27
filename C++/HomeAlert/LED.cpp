/*******************************************
 * LED.cpp
 * Created by Frazer Bayley and Brian Davis
 * The cpp file for our LED
 * referenced SeeedStudio starter code
 *******************************************/

#include "LED.hpp"
#include "Arduino.h"

LED::LED()
{
    //ctor
}
/************************************************
 * fireFlashOn is called when a fire is detected
 * and turns the light on
 *************************************************/
void LED::fireFlashOn()
{
    analogWrite(LEDPin, 255);
}
/************************************************
 * fireFlashOff is called when a fire is detected
 * and turns the light off
 *************************************************/
void LED::fireFlashOff()
{
    analogWrite(LEDPin, 0);
}
LED::~LED()
{
    //dtor
}

