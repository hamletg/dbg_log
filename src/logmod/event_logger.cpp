/**
 * \file logmod/event_logger.cpp
 * \brief Defines the events logger
 *
 * \cond
 *__legal_b__
 *__legal_e__
 */
#include "logmod/logmod_prec.h"

#include "logmod/event_logger.h"

namespace logmod
{

event_logger::event_logger():m_enabled(false),m_log_thread_id(false)
{
}

event_logger::~event_logger()
{
}

void event_logger::SetName(std::string name)
{
	m_name=name;
}

std::string event_logger::GetName()
{
	return m_name;
}

void event_logger::SetThreadName(uint64_t id,std::string name)
{
}

void event_logger::MarkStartTime()
{
    m_start_time=event::GetCurTime();
}

uint64_t event_logger::GetStartTime()
{
    return m_start_time;
}

void event_logger::Enable(bool enable)
{
	m_enabled=enable;
}

bool event_logger::IsEnabled()
{
	return m_enabled;
}

void event_logger::LogThreadId(bool enable)
{
	m_log_thread_id=enable;
}

bool event_logger::IsOk()
{
    return m_ok;
}
 
void event_logger::SetOk(bool val)
{
    m_ok=val;
}

const char *event_logger::GetError()
{
    return m_error.c_str();
}

void event_logger::SetError(const char *error)
{
    if (error!=NULL)
        m_error=error;
    else
        m_error="Unknown Error";
}

}



