#ifndef __LOGMODEVENTIFI_H__
#define __LOGMODEVENTIFI_H__

#ifdef WIN32
#define _WINSOCKAPI_ 
#endif
#include "log_ice/log_ice_defs.h"

#include <Ice/Ice.h>
#include <wx/textctrl.h>
#include <string>
#include "log_ice/ice/logger_event.h"
#include "log_ice_dbg/sqlitectrli.h"

class loggereventifI: public loggerice::loggereventif
{
 public:
    loggereventifI(wxTextCtrl *text,sqlitectrlI *sqllite);
    virtual ~loggereventifI();

    virtual void sendevent(const ::loggerice::loggereventPtr& s, const ::Ice::Current& );

    wxTextCtrl *m_text;
    sqlitectrlI *m_sqlite;
    std::ostream *m_ofs;
	logmod::logger_event m_evt;
};

#endif

