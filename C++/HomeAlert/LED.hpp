/*******************************************
 * LED.hpp
 * Created by Frazer Bayley and Brian Davis
 * The header file for our LED
 * referenced SeeedStudio starter code
 *******************************************/

#ifndef LED_HPP
#define LED_HPP
#include "Arduino.h"

class LED
{
    public:
        LED();
        void fireFlashOn();
        void fireFlashOff();
        virtual ~LED();
    protected:
    private:
        int LEDPin = 5;
};

#endif // LED_H

