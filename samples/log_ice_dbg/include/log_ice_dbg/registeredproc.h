#ifndef __REGISTEREDPROC_H__
#define __REGISTEREDPROC_H__

#include <string>
#include <map>

#include "log_ice_dbg/registeredthread.h"

class RegisteredProc
{
public:
	RegisteredProc();
	virtual ~RegisteredProc();

	void SetName(std::string name);
	std::string GetName();

	void SetThreadName(uint64_t id, std::string name);
	int GetThreadName(uint64_t id, std::string &name);

	void SetId(int id);
	int GetId();
protected:
	std::string m_name;
	int m_id;
	std::map<uint64_t,RegisteredThread *> m_threads;
};

#endif
