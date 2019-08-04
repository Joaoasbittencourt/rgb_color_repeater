////INCLUDE STATEMENTS
// Including the header files for libraries with the functions we need for this library
#include "segment-display.h"
#include "Grove_4Digital_Display/TM1637.h"

////GLOBAL VARIABLES
TM1637 * segDisplay; //4-digit 7-segment display

/**
Required to initialize display - call in initProject()

*/
void segmentInit(int pin)
{
	segDisplay = new TM1637(pin, pin+1);
	segDisplay->init();
	segDisplay->set(BRIGHT_TYPICAL);//BRIGHT_TYPICAL = 2,BRIGHT_DARKEST = 0,BRIGHTEST = 7;
}

/**
Display character (can be number or letter) in location on display

@param loc - which spot on display to show character
	@pre: 0 <= loc <= 3
	
@param data - character/digit you want to display

@modifies	Display
*/
void segmentDisplayDigit(unsigned int loc, unsigned int data)
{
	segDisplay->display(loc, (int8_t)data);
}

/**
Display characters (can be number or letter) on display

@param data - characters/digits you want to display, in order in array you want to display them
	@pre: length(data) == 4

@modifies	Display
*/
void segmentDisplayAll(unsigned int  data[])
{
	for (int i = 0; i < 4; i++)	
		segDisplay->display(i, (int8_t)data[i]);
}

/**
Clears display

@modifies	Display
*/
void segmentClear()
{
	segDisplay->clearDisplay();
}

/**
Turns ":" on in display NEXT TIME character(s) is(are) displayed (ie displayXX function is called)

@modifies	Display ":"
*/
void segmentPointOn()
{
	segDisplay->point(true);
}

/**
Turns ":" off in display NEXT TIME character(s) is(are) displayed (ie displayXX function is called)


@modifies	Display ":"
*/
void segmentPointOff()
{
	segDisplay->point(true);
}


