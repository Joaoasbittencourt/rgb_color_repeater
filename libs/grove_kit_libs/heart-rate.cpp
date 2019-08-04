////INCLUDE STATEMENTS
// Including the header files for libraries with the functions we need for this library
#include "heart-rate.h"

//Heart-rate monitor functions and variables
int sampleSize;
unsigned long hrIntervals[100];
int hrSamples;
int hrSampleCount;
unsigned long hrLastBeat;
bool hrIntervalsReady=false;
bool hrReset=false;

#ifndef digitalPinToInterrupt
#define digitalPinToInterrupt(pin) pin
#endif

/*Function: Interrupt service routine.Get the sigal from the external interrupt*/
void interrupt()
{
	unsigned long interval = millis()- hrLastBeat;
	
	if(interval > 2000)//set 2 seconds as max heart pluse duty
	{
		Serial.println("Reset");
		hrReset=true;//need to reset
		hrIntervalsReady = false;
		hrSampleCount=0;
		for(int i=0;i < hrSamples;i ++)
		{
			hrIntervals[i]=0;
		}
		hrLastBeat = millis();
	}
	else if (hrSampleCount < hrSamples) //Need more samples
	{
	  Serial.println("More samples");
	  hrReset=false;
	  hrIntervalsReady=false;
	  hrIntervals[hrSampleCount] = interval;
	  hrLastBeat = millis();
	  hrSampleCount++;
	}
	else //Have required samples, need to shift samples in array
	{
		Serial.println("Have samples");
		hrIntervalsReady = false;
		for(unsigned char i=1;i < hrSamples;i ++)
		{
			hrIntervals[i-1]=hrIntervals[i];
		}
		hrIntervals[hrSamples-1] = interval;
		hrLastBeat = millis();
		hrIntervalsReady = true;
	}
}


/**
Initialises HR monitor so it can be used - call in initProject()
*/
void hrInit(int inputPort, int sampleCount)
{
	Serial.begin(9600);
	hrSamples = sampleCount;
	attachInterrupt(digitalPinToInterrupt(inputPort), interrupt, RISING);//set interrupt 0,digital port 2
	for(int i=0;i < hrSamples;i ++)
    {
        hrIntervals[i]=0;
    }
	hrLastBeat = millis();
	
	Serial.println("Setup complete");
}

/**
If enough heart rate samples available, populates array passed in with intervals between heartbeats
*/
bool hrGetIntervals(unsigned long intervals[])
{
	for (int i = 0; i < hrSamples; i++)
		intervals[i] = hrIntervals[i];
	
	return hrIntervalsReady;
}


