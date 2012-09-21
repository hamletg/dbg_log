
#ifndef __LOGGERCTRLI_H__
#define __LOGGERCTRLI_H__

#ifdef WIN32
#define _WINSOCKAPI_ 
#endif

#include <Ice/Ice.h>
#include <wx/textctrl.h>
#include <string>
#include <map>
#include <vector>

#include "log_ice/ice/loggerctrl.h"
#include "log_ice_dbg/registeredproc.h"
#include "logmod/inttypes.h"

class loggerctrlI: public loggerice::loggerctrl
{
 public:
    loggerctrlI(wxTextCtrl *text);
    virtual ~loggerctrlI();

	virtual ::Ice::Int Register(const ::std::string &name, const ::Ice::Current&);
    virtual void SetName(::Ice::Int req_id, const ::std::string &name, const ::Ice::Current&);
	virtual void SetThreadName(::Ice::Int req_id, ::Ice::Long thread_id, const ::std::string &name, const ::Ice::Current&);

	int GetName(int id,std::string &name);
	int GetThreadName(int reg_id,uint64_t thread_id, std::string &name);
protected:
	wxTextCtrl *m_text;
	static int m_count;
	std::map<int,RegisteredProc *> m_reg_procs;
	std::vector<RegisteredProc *> m_v_reg_procs;
};

#endif

   
