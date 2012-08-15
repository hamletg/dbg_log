/**
 * \file log_ice/ice/logger_event.ice
 * \brief ICE Definition of the logger event
 *
 *__legal_b__
 *__legal_e__
 *
 */

#ifndef __LOGGER_LOGGER_EVENT_ICE__
#define __LOGGER_LOGGER_EVENT_ICE__

#include <log_ice/ice/event.ice>

module loggerice
{

class loggerevent extends event
{
	long subType;
	long value;
	string name;	
};

interface loggereventif
{
	void sendevent(loggerevent theevent);
};

};


#endif

