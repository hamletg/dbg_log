#include "log_ice_dbg/log_ice_dbg_prec.h"
#include "log_ice_dbg/loggerctrli.h"

#include <sstream>
#include <wx/string.h>

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
	proc->SetId(loggerctrlI::m_count);
	
	m_v_reg_procs.push_back(proc);
	m_reg_procs[loggerctrlI::m_count]=proc;

	if (m_text!=NULL)
	{
		std::ostringstream os;

		os << "Process " << name << " registered" << std::endl << "    given id = " << loggerctrlI::m_count << std::endl;
		m_text->AppendText(os.str());
	}
	return loggerctrlI::m_count++;
}

void loggerctrlI::SetName(::Ice::Int id, const ::std::string &name, const ::Ice::Current&)
{
	wxString str;

	std::map<int,RegisteredProc *>::iterator it;

	it=m_reg_procs.find(id);

	if (it!=m_reg_procs.end())
	{
		if ((*it).second!=NULL)
		{
			str.Printf("[loggerctrlI::SetName] process id=%i old_name=",id);
			str.Append((*it).second->GetName().c_str());
			str.Append(" name=");
			str.Append(name.c_str());
			str.Append("\n");
			m_text->AppendText(str);

			(*it).second->SetName(name);
		}
	}
}

int loggerctrlI::GetName(int id,std::string &name)
{
	if ((id<0) || (id>=m_reg_procs.size()))
		return -1;
	name=m_reg_procs[id]->GetName();
	return 0;
}