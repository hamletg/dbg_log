#include "log_ice_dbg/log_ice_dbg_prec.h"

#include "log_ice_dbg/registeredthread.h"

RegisteredThread::RegisteredThread()
{
}

RegisteredThread::~RegisteredThread()
{
}

void RegisteredThread::SetName(std::string name)
{
	m_name=name;
}

std::string RegisteredThread::GetName()
{
	return m_name;
}

void RegisteredThread::SetId(uint64_t id)
{
	m_id=id;
}

uint64_t RegisteredThread::GetId()
{
	return m_id;
}

