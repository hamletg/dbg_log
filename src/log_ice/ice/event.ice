/**
 * \file logmod/ice/event.ice
 * \brief ICE Definition of the events which can be logged
 *
 *__legal_b__
 *__legal_e__
 *
 */

#ifndef __LOGGER_EVENT_ICE__
#define __LOGGER_EVENT_ICE__

module loggerice
{

class event
{
	int type;        
    long ts;         
    int srctype;    
    int srcid;      
    int kind;
    long key;
    long timeMs;  
	long threadId;
	int procId;
};

};

#endif
