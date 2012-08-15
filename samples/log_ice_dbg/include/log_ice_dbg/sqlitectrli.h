#ifndef __SQLITECTRLI_H__
#define __SQLITECTRLI_H__

#ifdef WIN32
#define _WINSOCKAPI_ 
#endif

#include <Ice/Ice.h>
#include <wx/textctrl.h>
#include <string>
#include "log_ice_dbg/ice/logicedbgctrlif.h"
#include "log_sqlite/event_logger.h"
#include "log_sqlite/db_file.h"

class sqlitectrlI : public logicedbg::sqlitectrl 
{
public:
    sqlitectrlI(wxTextCtrl *text);
    virtual ~sqlitectrlI();
    virtual void SetDbName(const std::string & s,bool in_mem,const Ice::Current &cur=::Ice::Current());
    virtual void Enable(bool val,const Ice::Current &);

	bool GetProcCurState(int64_t key,wxString &name);
	
	log_sqlite::event_logger *GetSQLiteLogger();

	int Open(wxString filename);
	log_sqlite::db_file *GetDB();

    wxTextCtrl *m_text;

    bool m_enable;
    std::string m_db_name;
    log_sqlite::event_logger *m_sqlite_log;
	log_sqlite::db_file *m_db;
};

#endif

