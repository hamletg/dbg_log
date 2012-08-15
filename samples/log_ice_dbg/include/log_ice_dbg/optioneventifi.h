#ifndef __OPTIONEVENTIFI_H__
#define __OPTIONEVENTIFI_H__

#ifdef WIN32
#define _WINSOCKAPI_ 
#endif

#include <Ice/Ice.h>
#include <wx/textctrl.h>
#include <string>
#include "log_ice/ice/option_event.h"
#include "log_ice_dbg/sqlitectrli.h"


class optioneventifI: public loggerice::optioneventif
{
 public:
    optioneventifI(wxTextCtrl *text,sqlitectrlI *sqllite);
    virtual ~optioneventifI();

    virtual void sendevent(const ::loggerice::optioneventPtr& s, const ::Ice::Current& );

    wxTextCtrl *m_text;
    sqlitectrlI *m_sqlite;
    std::ostream *m_ofs;
	logmod::option_event m_evt;
};

#endif

