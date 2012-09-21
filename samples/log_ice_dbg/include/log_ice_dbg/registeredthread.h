#ifndef __REGISTEREDTHREAD_H__
#define __REGISTEREDTHREAD_H__

#include <string>
#include "logmod/inttypes.h"

class RegisteredThread
{
public:
	RegisteredThread();
	virtual ~RegisteredThread();

	void SetName(std::string name);
	std::string GetName();
	void SetId(uint64_t id);
	uint64_t GetId();
protected:
	std::string m_name;
	uint64_t m_id;	
};

#endif
