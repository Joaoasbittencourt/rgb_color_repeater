////INCLUDE STATEMENTS
// Including the header files for libraries with the functions we need for this library
#include "barometer.h"
#include "Grove_BMP280/Seeed_BMP280.h"


////GLOBAL VARIABLES
BMP280 *barometer; //Barometer

/**
 * Set up the barometer for use.
 *
 * This function must be called before any of the other barometer functions will work.
 */
void bmpInit()
{
	barometer = new BMP280();	
	barometer->init();
}

/**
Gets temperature reading in Celsius from barometer

@returns	Value representing temperature in Celsius
*/
float bmpGetTemperature()
{
	return (barometer->getTemperature());
}

/**
Gets pressure reading in Pa from barometer

@returns	Value representing pressure in Pa
*/
unsigned int bmpGetPressure()
{
	return (barometer->getPressure());
}

/**
Gets altitude reading in m from barometer
@ param pressure - pressure reading from barometer (or other source)

@returns	Value representing altitude in m
*/
float bmpCalcAltitude(float pressure)
{
	return (barometer->calcAltitude(pressure));
}
