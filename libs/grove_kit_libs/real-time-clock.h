#include <Wire.h>
#include <math.h>
#include <Servo.h>
#include <SoftwareSerial.h>
#include "Arduino.h"






void rtcInit();

void rtcSetTimeDate(unsigned int year, unsigned int month, unsigned int day, unsigned int dow, unsigned int hour, unsigned int minute, unsigned int second);

void rtcGetTime(unsigned int& hour, unsigned int& minute, unsigned int& second);

void rtcGetDate(unsigned int& year, unsigned int& month, unsigned int& day, unsigned int& dow);
