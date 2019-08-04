////INCLUDE STATEMENTS
// Including the header files for libraries with the functions we need for this library
#include "real-time-clock.h"
#include "RTC_DS1307/DS1307.h"


////GLOBAL VARIABLES
DS1307 * rtClock; //Real-time clock

/**
Required to initialize real-time - call in initProject()

*/
void rtcInit()
{
	rtClock->begin();
}

/**
Set initial time in rtc - will track from there

@param year

@param month
	@pre: 1 <= month <= 12
@param day
	@pre: 1 <= day <= 31
@param dow - day of week
	@pre: 1 <= dow <= 7
@param hour
	@pre: 0 <= hour <= 23
@param minute
	@pre: 0 <= minute <= 59
@param second
		@pre: 0 <= second <= 59

@modifies	  Time stored in RTC
*/
void rtcSetTimeDate(unsigned int year, unsigned int month, unsigned int day, unsigned int dow, unsigned int hour, unsigned int minute, unsigned int second)
{
	rtClock->fillByYMD(year,month,day);
	rtClock->fillByHMS(hour,minute,second);//15:28 30"
	rtClock->fillDayOfWeek(dow);
	rtClock->setTime();//write time to the RTC chip
}

/**
Get  date from rtc 

@param year

@param month
	@pre: 1 <= month <= 12
@param day
	@pre: 1 <= day <= 31
@param dow - day of week
	@pre: 1 <= dow <= 7


@modifies	Variables passed in to store respective info
*/
void rtcGetDate(unsigned int& year, unsigned int& month, unsigned int& day, unsigned int& dow)
{
	rtClock->getTime();
	year = rtClock->year+2000;
	month = rtClock->month;
	day = rtClock->dayOfMonth;
	dow = rtClock->dayOfWeek;
}

/**
Get  time from rtc 


@param hour
	@pre: 0 <= hour <= 23
@param minute
	@pre: 0 <= minute <= 59
@param second
		@pre: 0 <= second <= 59

@modifiesVariables passed in to store respective info
*/
void rtcGetTime(unsigned int& hour, unsigned int& minute, unsigned int& second)
{
	rtClock->getTime();
	
	hour = rtClock->hour;
	minute = rtClock->minute;
	second = rtClock->second;
}
