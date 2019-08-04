////INCLUDE STATEMENTS
// Including the header files for libraries with the functions we need for this library
#include "speech-recognizer.h"


////GLOBAL VARIABLES
SoftwareSerial *speechRec;

const char * speechCommands[] =
{
  "Turn on the light",
  "Turn off the light",
  "Play music",
  "Pause",
  "Next",
  "Previous",
  "Up",
  "Down",
  "Turn on the TV",
  "Turn off the TV",
  "Increase temperature",
  "Decrease temperature",
  "What's the time",
  "Open the door",
  "Close the door",
  "Left",
  "Right",
  "Stop",
  "Start",
  "Mode 1",
  "Mode 2",
  "Go"
};

/**
Required to initialize speech recognizer - call in initProject()

*/
void speechInit(int rxPin)
{
	speechRec = new SoftwareSerial(rxPin, rxPin + 1);
	speechRec->begin(9600);
	speechRec->listen();
}

/**
Checks if speech recognizer has received a valid command, and if so indicates which

@param command - Variable to hold int value corresponding to command received

@returns	bool indicating if valid command received

@modifies command to hold int value corresponding to command received. Indexing of commands corresponds to list in speechCommands[]
*/
bool speechGetCommand(int& command)
{
	bool available = speechRec->available();
	if (available)
		command = speechRec->read();
	
	return available;
}
