/************************************************************
 * HomeAlert.iso
 * Created by Frazer Bayley and Brian Davis
 * Buzzer: D3
 * Button: D6
 * LED: D5
 * Temp: A0
 * Sound Sensor: A1
 * Twitter: UserName: @FrazerDavis
 * Password: HomeAlert!2016
 * 
 * Token 703748793221525505-fhPUkF509Ze8vymTC29sMTjbGZlXEfD
 ************************************************************/

#include "TemperatureSensor.hpp"
#include "SoundSensor.hpp"
#include "Buzzer.hpp"
#include "LED.hpp"
#include "LCDScreen.hpp"
#include "Arduino.h"
#include <SPI.h>
#include <WiFi.h>
#include <Twitter.h>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <cmath>
#include <sstream>

/********************************************
 * Global instances of classes and variables
 ********************************************/
Twitter twitter("703748793221525505-fhPUkF509Ze8vymTC29sMTjbGZlXEfD");
LCDScreen screen;
time_t initTime = 0;
time_t currentTime = 0;
time_t startTime = 0;
float initTemp = 0;
bool isHome = false;
bool posting = true;
bool tempTweet = false;


void setup() {
Serial.begin(9600);
pinMode(3, OUTPUT);
pinMode(5, OUTPUT);
pinMode(6, INPUT);
time(&initTime);
time(&currentTime);
time(&startTime);
TemperatureSensor temp;
initTemp = temp.getTemp();
Serial.println("Made it to the bottom of setup");
}

void loop() {

  /**********************************************************
   * At the start of each loop we detect whether or not the 
   * device is going to be armed or disarmed depending on the 
   * button press
   **********************************************************/
if (digitalRead(6)){
  delay(500);
  if( isHome == true){                                //if isHome is set to true it means we are home so when button is pressed it means we are arming it and isHome is set to false
    Serial.println("DEVICE IS ARMED");
    isHome = false;
    screen.awayDisplay();
  }
  else if(isHome == false){                            //if isHome is set to false it means we are away so when button is pressed it means we are disarming it and isHome is set to true
    Serial.println("DEVICE IS DISARMED");
    isHome = true;
    screen.homeDisplay();
  }
}
/*******************************
 * Creating instances of classes
 *******************************/
SoundSensor theSound;
LED theLED;
//Buzzer theBuzz;
TemperatureSensor newTemp;    

/************************************
 * Initializing temperature variables
 ************************************/
float currentTemp = newTemp.getTemp();
int intCurrentTemp = (int) currentTemp;
String strCurrentTemp = String(intCurrentTemp);                           //Doing a conversion from int to string
String msgCurrentTemp = strCurrentTemp + " Degrees F";

/**********************************************************
 * The basic print statements for temps and sound threshold
 **********************************************************/
Serial.print("The message current temp is:");
Serial.println(msgCurrentTemp);
Serial.print("                           The INITIAL temp is: ");
Serial.println(initTemp);
Serial.print("                                                The CURRENT temp is: ");
Serial.println(currentTemp);
/*****************************************************
 * Detecting the voltage of any sound via sound sensor
 *****************************************************/
double sound = theSound.getSound();
Serial.print("                                                                        The volts are: ");
Serial.println(sound);


int msgCurrentLength = msgCurrentTemp.length();
char msgCurrentBuf[msgCurrentLength];
msgCurrentTemp.toCharArray(msgCurrentBuf, msgCurrentLength+1);
screen.tempDisplay(msgCurrentBuf);

time(&currentTime);

if (!isHome){
  time_t nowTime;
  time(&nowTime);
  /*************************************************
   * Every 163 seconds we will tweet the temperature
   *************************************************/
  if ((nowTime - startTime) >= 79){
   /*********************************************************************
    * Twitter won't allow us to tweet messages with content that is very
    * similar so we have a boolean posting to switch messages every other
    * time
    *********************************************************************/
   /* if (!posting){
      Serial.println("Now sending twitter post temp");
      float floatTemp = newTemp.getTemp();
      int intTemp = (int) floatTemp;
      String strTemp = String(intTemp);
      String msgTemp = "It's : " + strTemp + " degrees fahrenheit!";
      int msgLength = msgTemp.length();
      char buf[msgLength];
      msgTemp.toCharArray(buf, msgLength+1);
      twitter.post(buf);
      posting = true;
    }*/
    if(!tempTweet){
      Serial.println("Now sending twitter post temp");
      float floatTemp = newTemp.getTemp();
      int intTemp = (int) floatTemp;
      String strTemp = String(intTemp);
      String msgTemp = "Why did the chicken cross the road? because it's: " + strTemp + " degrees fahrenheit??";
      int msgLength = msgTemp.length();
      char buf[msgLength];
      msgTemp.toCharArray(buf, msgLength+1);
      twitter.post(buf);
      tempTweet = true;
    }
    time(&startTime);                                   //reset the start time for another 163 seconds
  }
  
/****************************************************************************************
 * If a sound is over a certain voltage it will trip the alarm and post to the LED screen
 ****************************************************************************************/
  if (sound > 725){
    Buzzer theBuzz;
    screen.audioDisplay();
    theBuzz.soundAlarm();
    //twitter.post("There was a loud noise.");
  }
}
Serial.print("The current time is: ");
Serial.println(currentTime);
Serial.print("                      The initial time is: ");
Serial.println(initTime);

/****************************************************************************************************************
 * For in class purposes we check the current temperature vs the initial temperature to detect if the degrees has
 * increased to a point that would indicate a fire. If we were to put this product out we would do a 
 * difference in temperature of 10 degrees over 1 minute
 ****************************************************************************************************************/
if (currentTime - initTime >= 30){
  if (currentTemp - initTemp > 3){                                 //checking for temp change indicating a fire
    Buzzer theBuzz;
    Serial.println("Danger! Fire");           
    twitter.post("STOP.. DROP.. SHUT EM DOWN THERES A FIRE IN YOUR HOME SHOP");
    screen.fireDisplay();
   /* if (twitter.post("Fire! At your house! Right meow!")) {
    // Specify &Serial to output received response to Serial.
    // If no output is required, you can just omit the argument, e.g.
    // int status = twitter.wait();
    int status = twitter.wait(&Serial);
      if (status == 200) {
        Serial.println("OK.");
      } 
      else {
        Serial.print("failed : code ");
        Serial.println(status);
      }
    } 
    else {
      Serial.println("connection failed.");
    }*/

    /**********************************************************************************
     * If a fire is detected set off the alarm 5 times and put a message on LED display
     **********************************************************************************/
    for (int i = 0; i < 5; i++){
      theLED.fireFlashOn();
      theBuzz.soundAlarm();
      theLED.fireFlashOff();
      delay(500);
    }  
  }
  else{
    Serial.println("POLLING intitTemp");
    initTemp = newTemp.getTemp();
  }
  time(&initTime);
  
}                                          //End of fire monitor
//delay (2000);
}
