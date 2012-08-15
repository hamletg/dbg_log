#include "log_ice_dbg/log_ice_dbg_prec.h"
#include "log_ice_dbg/registeredproc.h"

RegisteredProc::RegisteredProc()
{
}

RegisteredProc::~RegisteredProc()
{
}

void RegisteredProc::SetName(std::string name)
{
	m_name=name;
}

std::string RegisteredProc::GetName()
{
	return m_name;
}

void RegisteredProc::SetId(int id)
{
	m_id=id;
}

int RegisteredProc::GetId()
{
	return m_id;
}