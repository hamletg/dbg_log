/**
 * \file log_ice/ice/loggerctrl.ice
 * \brief ICE Definition of the dbg_class event
 *
 *__legal_b__
 *__legal_e__
 *
 */

#ifndef __LOG_ICE_LOGGERCTRL_ICE__
#define __LOG_ICE_LOGGERCTRL_ICE__

module loggerice
{

interface loggerctrl
{
	int Register(string name);
	void SetName(int id, string name);
};

};


#endif

