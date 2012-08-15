/**
 * \file log_ice/ice/option_event.ice
 * \brief ICE Definition of the option event
 *
 *__legal_b__
 *__legal_e__
 *
 */

#ifndef __LOGGER_OPTION_EVENT_ICE__
#define __LOGGER_OPTION_EVENT_ICE__

#include <log_ice/ice/event.ice>

module loggerice
{

class optionevent extends event
{
	long subType;
	long value;
	string name;
	string strVal;	
};

interface optioneventif
{
	void sendevent(optionevent theevent);
};

};


#endif

