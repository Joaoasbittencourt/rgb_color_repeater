#include "gesture-sensor.h"

#include "Gesture_PAJ7620/paj7620.h"

/**
Initialiazes gesture sensor
**/
unsigned int gestureInit()
{
	paj7620Init();
}

/**
Reads gesture sensor and returns value of gesture (or 0 if no gesture detected)
	For more info see: http://wiki.seeedstudio.com/Grove-Gesture_v1.0/

@returns	data = 0 if no gesture detected, otherwise the value of one of the constants below
	Up Gesture, data = GES_UP_FLAG
	Down Gesture, data = GES_DOWN_FLAG
	Left Gesture, data = GES_LEFT_FLAG
	Right Gesture, data = GES_RIGHT_FLAG
	Forward Gesture, data = GES_FORWARD_FLAG
	Backward Gesture, data = GES_BACKWARD_FLAG
	Clockwise Gesture, data = GES_CLOCKWISE_FLAG
	Count Clockwise Gesture, data = GES_COUNT_CLOCKWISE_FLAG
	Wave Gesture, data = GES_WAVE_FLAG			

*/
unsigned int gestureRead()
{
	unsigned char gestureData = 0;  // Read Bank_0_Reg_0x43/0x44 for gesture result.

    paj7620ReadReg(0x43, 1, &gestureData);  // When different gestures be detected, the variable 'data' will be set to different values by paj7620ReadReg(0x43, 1, &data).
	
	if (gestureData == 0) //check for wave
	paj7620ReadReg(0x44, 1, &gestureData);
		
	return gestureData;
}
