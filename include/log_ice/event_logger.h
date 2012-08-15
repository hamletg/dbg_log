/**
 * \file log_ice/event_logger.h
 * \brief Defines the events logger using ICE
 *
 * \cond
 *__legal_b__
 *__legal_e__
 * \endcond
 */

#ifndef __LOG_ICE_EVENT_LOGGER_H__
#define __LOG_ICE_EVENT_LOGGER_H__

#include "log_ice/log_ice_defs.h"
#include "logmod/logmod_defs.h"
#include "logmod/event_logger.h"

#include "logmod/option_event.h"
#include "logmod/logger_event.h"
#include "logmod/event_types.h"

#include <string>

namespace log_ice
{

class event_logger_impl;

class LOG_ICE_API event_logger: public logmod::event_logger
{
 public:
    event_logger();
    virtual ~event_logger();
	
	void SetName(std::string name);
	std::string GetName();

	virtual int Connect(const char *ip_address=NULL,unsigned int port=0);
	virtual int Shutdown();

    virtual void Send(logmod::event *evt);

	virtual void HandleDbgClassEvent(logmod::event *evt);
	virtual void HandleLoggerEvent(logmod::event *evt);
	virtual void HandleOptionEvent(logmod::event *evt);

protected:
	event_logger_impl *m_impl;
	bool m_bool;
	//int GetProxyString(std::string &result,std::string adapter, std::string ip, unsigned short port=0);
	int m_argc;
	char **m_argv;
	std::string m_name;
	int m_id;
};

}

#endif

