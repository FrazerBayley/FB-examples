/*******************************************
 * Buzzer.cpp
 * Created by Frazer Bayley and Brian Davis
 * The cpp file for our sound sensor
 * referenced SeeedStudio starter code
 *******************************************/

#include "Buzzer.hpp"
#include "LED.hpp"
#include "Arduino.h"

Buzzer::Buzzer()
{
    buzzerPin = 3;
}
/*
 * When soundAlarm is called the buzzer goes off at the frequency we set it to 
 */
void Buzzer::soundAlarm()
{
   for (long i = 0; i < 300*1000L; i += noises[0] * 2 )
    {
      for (int j = 0; j < 3; j++){
        digitalWrite(buzzerPin, HIGH);
        delayMicroseconds(noises[0]);
        digitalWrite(buzzerPin, LOW);
        delayMicroseconds(noises[0]);
      }
    }


}

Buzzer::~Buzzer()
{
    //dtor
}

