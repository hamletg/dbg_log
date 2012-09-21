#include "log_ice_dbg/log_ice_dbg_prec.h"
#include "log_ice_dbg/registeredproc.h"

RegisteredProc::RegisteredProc()
{
}

RegisteredProc::~RegisteredProc()
{
	std::map<uint64_t,RegisteredThread *>::iterator it;

	for (it=m_threads.begin();it!=m_threads.end();it++)
	{
		delete (*it).second;
	}
}

void RegisteredProc::SetName(std::string name)
{
	m_name=name;
}

void RegisteredProc::SetThreadName(uint64_t id, std::string name)
{
	std::map<uint64_t,RegisteredThread *>::iterator it;
	RegisteredThread *thread;

	it=m_threads.find(id);

	if (it==m_threads.end())
	{
		thread=new RegisteredThread();
		m_threads[id]=thread;
	}
	else
	{
		thread=(*it).second;
	}
	thread->SetId(id);
	thread->SetName(name);
}

int RegisteredProc::GetThreadName(uint64_t id, std::string &name)
{
	std::map<uint64_t,RegisteredThread *>::iterator it;
	RegisteredThread *thread;

	it=m_threads.find(id);

	if (it==m_threads.end())
	{
		return -1;
	}
	thread=(*it).second;
	name=thread->GetName();
	return 0;
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