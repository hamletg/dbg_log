/**
 * \file log_ice/ice/dbg_class_event.ice
 * \brief ICE Definition of the dbg_class event
 *
 *__legal_b__
 *__legal_e__
 *
 */

#ifndef __DBG_CLASS_EVENT_ICE__
#define __DBG_CLASS_EVENT_ICE__

#include <log_ice/ice/event.ice>

module loggerice
{

class dbgclassevent extends event
{
	long depth;
    string callTxt;
    int subType;        
    //dbg_class *m_dbg_class;
    long elapsedTime;	
};

interface dbgclasseventif
{
	void sendevent(dbgclassevent theevent);
};

};


#endif

