/*******************************************
 * LCDScreen.hpp
 * Created by Frazer Bayley and Brian Davis
 * The header file for our LCD display
 * referenced SeeedStudio starter code
 *******************************************/

#ifndef LCDSCREEN_HPP
#define LCDSCREEN_HPP
#include <Wire.h>
#include "rgb_lcd.h"
#include "Arduino.h"

class LCDScreen
{
    public:
        LCDScreen();
        rgb_lcd lcd;
        void audioDisplay();
        void fireDisplay();
        void tempDisplay(char* msg);
        void homeDisplay();
        void awayDisplay();
        virtual ~LCDScreen();
    protected:
    private:
        const int colorR = 255;               //this will give us the full red color on the display
        const int colorG = 255;               //this will give us the full green color on the display
        const int colorB = 255;               //this will give us the full blue color on the display
};

#endif // LCDSCREEN_HPP
