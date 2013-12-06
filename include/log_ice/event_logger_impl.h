#ifndef __EVENT_LOGGER_IMPL_H_
#define __EVENT_LOGGER_IMPL_H__

#include <Ice/Ice.h>

#include "log_ice/log_ice_defs.h"
#include "log_ice/ice/dbg_class_event.h"
#include "log_ice/ice/logger_event.h"
#include "log_ice/ice/option_event.h"
#include "log_ice/ice/loggerctrl.h"
#include "logmod/logger_event.h"
#include "logmod/option_event.h"

#include <string>

namespace log_ice
{

class LOG_ICE_API event_logger_impl
{
public:
	event_logger_impl();
	virtual ~event_logger_impl();

	static void SetLoggerEvent(const ::loggerice::loggereventPtr& s,logmod::logger_event *evt);
	static void SetOptionEvent(const ::loggerice::optioneventPtr& s,logmod::option_event *evt);

	int GetProxyString(std::string &result,std::string adapter, std::string ip, unsigned short port=0);
	int m_argc;
	char **m_argv;
	//<commentout>
	Ice::CommunicatorPtr m_ic;

	Ice::ObjectPrx m_base_dbg_class;
	loggerice::dbgclasseventifPrx m_dbg_class_if;
	loggerice::dbgclasseventPtr my_dbg_class_event;

	Ice::ObjectPrx m_base_logger;
	loggerice::loggereventifPrx m_logger_if;
	loggerice::loggereventPtr my_logger_event;

	Ice::ObjectPrx m_base_option;
	loggerice::optioneventifPrx m_option_if;
	loggerice::optioneventPtr my_option_event;

	Ice::ObjectPrx m_base_loggerctrl;
	loggerice::loggerctrlPrx m_loggerctrl_if;

//</commentout>
};

}


#endif
