/**
 * \file log_sqlite/event_logger.cpp
 * \brief Defines the events logger
 *
 * \cond
 *__legal_b__
 *__legal_e__
 * \endcond
 */

#include "log_sqlite/log_sqlite_prec.h"
#include "log_sqlite/log_sqlite_defs.h"

#include "log_sqlite/event_logger.h"
#include "dbg_log/dbg_class_event.h"
#include "logmod/logger_event.h"
#include "logmod/option_event.h"
#include "logmod/event_types.h"

namespace log_sqlite
{

event_logger::event_logger():logmod::event_logger()
{
    m_argc=0;
    m_argv=NULL;
    m_db=NULL;
    m_in_mem=false;
}

event_logger::~event_logger()
{
    if (m_db!=NULL)
        delete m_db;
}

void event_logger::Send(logmod::event *evt)
{
    dbg_log::dbg_class_event *_dbg_class_event=NULL;
    logmod::blob_event *_blob_event=NULL;
	logmod::logger_event *_logger_event=NULL;
	logmod::option_event *_option_event=NULL;

    logmod::event_type *event_t=NULL;
    
    if (m_db==NULL)
        return;
    if (evt==NULL)
        return;
    
	if (IsEnabled()==false)
		return;

	if (m_log_thread_id==true)
		evt->CaptureThreadId();

    evt->MarkWithCurTime();
    event_t=evt->GetType();
    
	if (event_t->GetId()==logmod::evt_typ::EVT_DBG_CLASS.GetId())
    {
        _dbg_class_event=dynamic_cast<dbg_log::dbg_class_event *>(evt);
        m_db->AddEvent(_dbg_class_event);
    }
    else if (event_t->GetId()==logmod::evt_typ::EVT_BLOB.GetId())
    {
        _blob_event=dynamic_cast<logmod::blob_event *>(evt);
        m_db->AddEvent(_blob_event);
    }
	else if (event_t->GetId()==logmod::evt_typ::EVT_LOGGER_EVENT.GetId())
	{
		_logger_event=dynamic_cast<logmod::logger_event *>(evt);
		m_db->AddEvent(_logger_event);
	}
	else if (event_t->GetId()==logmod::evt_typ::EVT_OPTION_EVENT.GetId())
	{
		_option_event=dynamic_cast<logmod::option_event *>(evt);
		m_db->AddEvent(_option_event);
	}
}

void event_logger::SetDbName(char *name,bool in_mem)
{
    if (name!=NULL)
    {
        if (strcmp(name,m_name.c_str())==0)
            return;
        m_name=name;
    }
    if (m_db!=NULL)
        delete m_db;
    m_in_mem=in_mem;
    if (m_in_mem==false)
        m_db=new log_sqlite::db_file(name);
    else
        m_db=new log_sqlite::db_file(":memory:");
}

log_sqlite::db_file *event_logger::GetDb()
{
	return m_db;
}

void event_logger::CloseDb()
{
    if (m_db!=NULL)
    {
        if (m_in_mem)
            m_db->Backup((char *)m_name.c_str());
        m_db->Close();
        delete m_db;
        m_db=NULL;
    }
}

}



