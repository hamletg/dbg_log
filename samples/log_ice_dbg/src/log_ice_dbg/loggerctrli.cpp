#include "log_ice_dbg/log_ice_dbg_prec.h"
#include "log_ice_dbg/loggerctrli.h"

#include <sstream>

int loggerctrlI::m_count=0;

loggerctrlI::loggerctrlI(wxTextCtrl *text):loggerice::loggerctrl(),m_text(text)
{
}

loggerctrlI::~loggerctrlI()
{
	int idx;

	for (idx=0;idx<m_v_reg_procs.size();idx++)
		delete m_v_reg_procs[idx];
}

::Ice::Int loggerctrlI::Register(const ::std::string &name, const ::Ice::Current&)
{
	RegisteredProc *proc;

	proc=new RegisteredProc();
	proc->SetName(name);
	proc->SetId(m_count);
	
	m_v_reg_procs.push_back(proc);
	m_reg_procs[m_count]=proc;

	if (m_text!=NULL)
	{
		std::ostringstream os;

		os << "Process " << name << " registered" << std::endl << "    given id = " << m_count << std::endl;
		m_text->AppendText(os.str());
	}
	return m_count++;
}

void loggerctrlI::SetName(::Ice::Int id, const ::std::string &name, const ::Ice::Current&)
{
	std::map<int,RegisteredProc *>::iterator it;

	it=m_reg_procs.find(id);

	if (it!=m_reg_procs.end())
	{
		if ((*it).second!=NULL)
			(*it).second->SetName(name);
	}
}

int loggerctrlI::GetName(int id,std::string &name)
{
	if ((id<0) || (id>=m_v_reg_procs.size()))
		return -1;
	name=m_v_reg_procs[id]->GetName();
	return 0;
}