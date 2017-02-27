/*******************************************
 * LCDScreen.cpp
 * Created by Frazer Bayley and Brian Davis
 * The cpp file for our LCD display
 * referenced SeeedStudio starter code
 *******************************************/
 
#include "LCDScreen.hpp"
#include "Arduino.h"

LCDScreen::LCDScreen()
{
  
}
/**************************************************************
 * audioDisplay is called when HomeAlert detects a noise over 725 volts
 **************************************************************/
void LCDScreen::audioDisplay()
{
    lcd.begin(16, 2);
    lcd.setRGB(colorR, 0, colorB);
    lcd.print("LOUD NOISES");
    delay(1000);
    /*lcd.setCursor(0,1);
    lcd.print("Detected.");*/
}
/**************************************************************
 * fireDisplay is called when HomeAlert detects a change in temp
 * over 3 degrees fahrenheit
 **************************************************************/
void LCDScreen::fireDisplay()
{
    lcd.begin(16, 2);
    lcd.setRGB(colorR, 0, 0);
    lcd.print("Danger! Fire");
    lcd.setCursor(0,1);
    lcd.print("Detected.");
    delay(500);
}
/**************************************************************
 * tempDisplay is called every loop to display the current
 * temperature
 **************************************************************/
void LCDScreen::tempDisplay(char* msg)
{
    lcd.begin(16,2);
    lcd.setRGB(0, 0, colorB);
    lcd.print(msg);
}
/**************************************************************
 * awayDisplay is called when the device is armed via the button
 * sensor
 **************************************************************/
void LCDScreen::awayDisplay()
{
    lcd.begin(16,2);
    lcd.setRGB(colorR, 0, 0);
    lcd.print("Device is now ");
    lcd.setCursor(0,1);
    lcd.print("ARMED.");
    delay(1000);
}
/**************************************************************
 * homeDisplay is called when the device is disarmed via the 
 * button sensor
 **************************************************************/
void LCDScreen::homeDisplay()
{
    lcd.begin(16,2);
    lcd.setRGB(0, colorG, 0);
    lcd.print("Device is now ");
    lcd.setCursor(0,1);
    lcd.print("DISARMED.");
    delay(1000);
}
LCDScreen::~LCDScreen()
{
    //dtor
}

