#include "log_ice_dbg/log_ice_dbg_prec.h"
#include "log_ice_dbg/sqlitectrli.h"

sqlitectrlI::sqlitectrlI(wxTextCtrl *text):logicedbg::sqlitectrl()
{
    m_text=text;
    m_enable=false;
    m_sqlite_log=NULL;
	m_db=NULL;
}

sqlitectrlI::~sqlitectrlI()
{
    if (m_sqlite_log!=NULL)
        delete m_sqlite_log;
	if (m_db!=NULL)
		delete m_db;
}

int sqlitectrlI::Open(wxString filename)
{
	if (m_db==NULL)
	{
		m_db=new log_sqlite::db_file();

		if (m_db->Open((char *)filename.GetData().AsChar()))
			return 0;
		return 1;
	}
	return -1;
}

log_sqlite::db_file *sqlitectrlI::GetDB()
{
	if (m_sqlite_log!=NULL)
		return m_sqlite_log->GetDb();
	return m_db;
}

void sqlitectrlI::SetDbName(const std::string & s,bool in_mem,const Ice::Current &)
{
    m_db_name.assign(s);
    if (m_sqlite_log==NULL)
	{
        m_sqlite_log=new log_sqlite::event_logger();
		m_sqlite_log->Enable(true);
	}
    m_sqlite_log->SetDbName((char *)s.c_str(),in_mem);
}

void sqlitectrlI::Enable(bool val,const Ice::Current &)
{
    m_enable=val;
    if (m_sqlite_log==NULL)
        m_sqlite_log=new log_sqlite::event_logger();
	m_sqlite_log->Enable(val);
}

bool sqlitectrlI::GetProcCurState(int64_t key,wxString &name)
{
	log_sqlite::db_file *db;
	std::string state_name;
	int result=-1;

	if (m_sqlite_log==NULL)
		return false;
	db=m_sqlite_log->GetDb();
	//result=db->GetProcCurState(key,state_name);
	if (result!=0)
		return false;
	name=wxString(state_name.c_str(), wxConvUTF8);
	return true;
}

log_sqlite::event_logger *sqlitectrlI::GetSQLiteLogger()
{
	return m_sqlite_log;
}

