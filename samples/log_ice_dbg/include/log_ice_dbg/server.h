#ifndef __PRINTER_SERVER_H__
#define __PRINTER_SERVER_H__

#include <Ice/Ice.h>
#include <wx/thread.h>
#include <wx/textctrl.h>
#include "log_ice_dbg/sqlitectrli.h"
#include "log_ice_dbg/printeri.h"
#include "log_ice_dbg/loggerctrli.h"
#include "log_ice_dbg/dbgclasseventifi.h" 

class server:public wxThread
{
public:
    server(wxTextCtrl *text,wxThreadKind kind = wxTHREAD_DETACHED);
    virtual ~server();

    virtual wxThread::ExitCode Entry();

    void SetTextCtrl(wxTextCtrl *text);
    sqlitectrlI *GetSQLiteCtrl();

    Ice::CommunicatorPtr m_ic;
    Ice::ObjectAdapterPtr m_adapter;
    int m_argc;
    char **m_argv;
    wxTextCtrl *m_text;
	Ice::ObjectPtr m_sqlite_ctrlPtr;
    sqlitectrlI *m_sqlite_ctrl;
	Ice::ObjectPtr m_printeriPtr;
    PrinterI *m_printeri;
	Ice::ObjectPtr m_loggerctrliPtr;
    loggerctrlI *m_loggerctrli;
	//dbgclasseventifI *m_dbgclassevti;
	Ice::ObjectPtr m_dbgclassevtiPtr;
	dbgclasseventifI *m_dbgclassevtifi;
	Ice::ObjectPtr m_loggerevtiPtr;
	Ice::ObjectPtr m_optionevtiPtr;
	int m_status;
};

#endif
