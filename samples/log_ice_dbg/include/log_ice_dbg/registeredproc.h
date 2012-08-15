#ifndef __REGISTEREDPROC_H__
#define __REGISTEREDPROC_H__

#include <string>

class RegisteredProc
{
public:
	RegisteredProc();
	virtual ~RegisteredProc();

	void SetName(std::string name);
	std::string GetName();
	void SetId(int id);
	int GetId();
protected:
	std::string m_name;
	int m_id;
};

#endif
