/*******************************************
 * Buzzer.hpp
 * Created by Frazer Bayley and Brian Davis
 * The header file for our sound sensor
 * referenced SeeedStudio starter code
 *******************************************/

#ifndef BUZZER_HPP
#define BUZZER_HPP
#include "Arduino.h"

class Buzzer
{
    public:
        Buzzer();
        void soundAlarm();
        virtual ~Buzzer();
    protected:
    private:
        int buzzerPin;                        
        int noises[2] = {1136, 1915};         //the frequencies for making sound
};

#endif // BUZZER_H

