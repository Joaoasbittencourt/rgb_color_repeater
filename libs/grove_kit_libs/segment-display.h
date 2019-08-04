#include <Wire.h>
#include <math.h>
#include <Servo.h>
#include <SoftwareSerial.h>
#include "Arduino.h"





//Segmented display functions and variables


void segmentInit(int pin);
void segmentDisplayDigit(unsigned int loc, unsigned int data);
void segmentDisplayAll(unsigned int data[]);
void segmentClear();
void segmentPointOn();
void segmentPointOff();
