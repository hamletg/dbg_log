/**
 * \file logmod/event.cpp
 * \brief Defines the events which can be logged
 *
 * \ cond
 *__legal_b__
 *__legal_e__
 * \endcond
 */

#include "logmod/logmod_prec.h"

#include "logmod/event.h"
#include <wx/thread.h>
#include <wx/utils.h> 

#ifdef WIN32
#include <sys/types.h> 
#include <sys/timeb.h>
#else
#include <stdlib.h>
#include <sys/time.h>
#endif

namespace logmod
{

uint64_t event::GetCurThreadId()
{
	return wxThread::GetCurrentId();
}

uint64_t event::GetCurProcessId()
{
	return wxGetProcessId();
}

event::event(event_type *type)
	: m_type(type), m_thread_id(0), m_process_id(0)
{
    m_event_kind=NONE;
    m_src_id=0;
    m_src_type=0;
    m_ts=0;
    m_key=-1;
    m_time_ms=0;
}

event::~event()
{
}

event_type *event::GetType()
{
    return m_type;
}

void event::SetType(event_type *type)
{
    m_type=type;
}

uint64_t event::GetTS()
{
    return m_ts;
}

void event::SetTS(uint64_t ts)
{
    m_ts=ts;
}

uint32_t event::GetSrcType()
{
    return m_src_type;
}

void event::SetSrcType(uint32_t type)
{
    m_src_type=type;
}

uint32_t event::GetSrcId()
{
    return m_src_id;
}

void event::SetSrcId(uint32_t id)
{
    m_src_id=id;
}

event::event_kind event::GetKind()
{
    return m_event_kind;
}

void event::SetKind(event_kind kind)
{
    m_event_kind=kind;
}

int64_t event::GetKey()
{
    return m_key;
}

void event::SetKey(int64_t key)
{
    m_key=key;
}

uint64_t event::GetCurTime()
{
    uint64_t result;
#ifdef WIN32
    
    _timeb tb_time;

    _ftime(&tb_time);
    result=tb_time.time;
    result=result*1000+tb_time.millitm;
#else
    struct timeval tv;
    struct timezone tz;
     
    gettimeofday(&tv, &tz);
    result=tv.tv_sec;
    result=result*1000+(tv.tv_usec/1000);
#endif

    return result;
}

int32_t event::GetRegId()
{
	return m_reg_id;
}

void event::SetRegId(int32_t id)
{
	m_reg_id=id;
}

void event::MarkWithCurTime()
{
    m_time_ms=GetCurTime();
}

uint64_t event::GetTime()
{
    return m_time_ms;
}

void event::SetTime(uint64_t time)
{
    m_time_ms=time;
}

uint32_t event::GetThreadId()
{
	return m_thread_id;
}

void event::SetThreadId(uint32_t thread_id)
{
	m_thread_id=thread_id;
}

void event::CaptureThreadId()
{
	m_thread_id=wxThread::GetCurrentId();
}

void event::CaptureProcessId()
{
	m_process_id=wxGetProcessId();
}

std::ostream &event::PrintString(std::ostream &os)
{
	return os;
}

}

