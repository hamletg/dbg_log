#ifndef __DBGCLASSEVENTIFI_H__
#define __DBGCLASSEVENTIFI_H__

#ifdef WIN32
#define _WINSOCKAPI_ 
#endif

#include <Ice/Ice.h>
#include <wx/textctrl.h>
#include <string>
#include "log_ice/ice/dbg_class_event.h"
#include "log_ice_dbg/sqlitectrli.h"
#include "log_ice_dbg/loggerctrli.h"

class dbgclasseventifI: public loggerice::dbgclasseventif
{
 public:
    dbgclasseventifI(wxTextCtrl *text,sqlitectrlI *sqllite,loggerctrlI *logctrl);
    virtual ~dbgclasseventifI();

    virtual void sendevent(const ::loggerice::dbgclasseventPtr& s, const ::Ice::Current& );
	
	void SetPrintProcName(bool print=true);
	void SetPrintProcId(bool print=true);

	enum
	{
		PROC_NO_PRINT,
		PROC_NAME,
		PROC_ID
	};
    wxTextCtrl *m_text;
    sqlitectrlI *m_sqlite;
	loggerctrlI *m_logger_ctrl;
    std::ostream *m_ofs;
	dbg_log::dbg_class_event m_evt;
	int m_print_proc;
};

#endif

