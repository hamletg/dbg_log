/**
 * \file log_sqlite/db_file.cpp
 * \brief Defines the database format
 *
 * \cond
 *__legal_b__
 *__legal_e__
 * \endcond
 */

#include "log_sqlite/log_sqlite_prec.h"

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include "log_sqlite/db_file.h"
#include "logmod/event_types.h"
#include "wx/wxsqlite3.h"

#include <iostream>

namespace log_sqlite
{

db_file::db_file(char *name):m_db_mutex(),m_cur_test_key(-1),m_db(NULL),m_table_results(NULL)
{
	uint32_t index,max;

    m_all_test=true;
    m_filter_one_test=false;
    m_filter_one_test_idx=0;
    m_table_results_has_data=false;

    if (name!=NULL)
    {
        m_name.assign(name);
        Create();
    }

	max=logmod::event_type::GetCount();
	for (index=0;index<max;index++)
		m_show_events.push_back(true);

	m_db=new wxSQLite3Database();
	m_table_results=new wxSQLite3Table();
}

db_file::~db_file()
{
	if (m_db!=NULL)
		delete m_db;
	if (m_table_results!=NULL)
		delete m_table_results;

	try
    {
		wxSQLite3Database::ShutdownSQLite();
	}
	catch (wxSQLite3Exception& e)
    {
        std::cerr << e.GetErrorCode() << ":" << (const char*)(e.GetMessage().mb_str()) << std::endl;     
    }
}

void db_file::AddEventTypes()
{
	int nRows;
	logmod::event_type *evt=logmod::event_type::GetFirst();
	wxString insertCmd;

	try
	{
		while (evt!=NULL)
		{
			insertCmd.Printf(_T("INSERT INTO event_type (evt_type_id,evt_type_name) values(%i,'%s');"),evt->GetId(),evt->GetName());
			nRows = m_db->ExecuteUpdate(insertCmd);
			evt=evt->GetNext();			
		}
	}
	catch (wxSQLite3Exception& e)
    {
        std::cerr << e.GetErrorCode() << ":" << (const char*)(e.GetMessage().mb_str()) << std::endl;     
    }
}

bool db_file::Open(char *name)
{
    wxString file;
    if (name!=NULL)
        file=wxString(name, wxConvUTF8);
    else
    {
        if (m_name.empty()==true)
            return false;
        file=wxString(m_name.c_str(), wxConvUTF8);
    }
 
    try
    {
        wxSQLite3Database::InitializeSQLite();
        int i, fld;
        time_t tmStart, tmEnd;
        
        std::cout << "SQLite3 Version: " << (const char*) m_db->GetVersion().mb_str(wxConvUTF8) << std::endl;

        //remove(file.mb_str());
        if (wxSQLite3Database::HasEncryptionSupport())
        {
            //m_db->Open(gszFile, wxString(_T("password")));
            m_db->Open(file);
        }
        else
        {
            m_db->Open(file);
        }        
    }
    catch (wxSQLite3Exception& e)
    {
        std::cerr << e.GetErrorCode() << ":" << (const char*)(e.GetMessage().mb_str()) << std::endl;
        return false;
    }	
    return true;
}


bool db_file::Create(char *name)
{
    bool result;

    if (name!=NULL)
        remove(name);
    else
    {
        if (m_name.empty()==true)
            return false;
        remove(m_name.c_str());
    }
    if (Open(name)==false)
        return false;
    result=CreateTables();
    if (result)
        AddEventTypes();
    return result;
}


bool db_file::CreateTables()
{    
    try
    {
		m_db->ExecuteUpdate(_T("PRAGMA synchronous = OFF;"));
        m_db->ExecuteUpdate(_T("PRAGMA cache_size = 10000;"));
         
        m_db->ExecuteUpdate(_T("CREATE TABLE format_info(format_key INTEGER PRIMARY KEY,format_opt VARCHAR(64), format_val_int INTEGER, format_val_char VARCHAR(128))"));
        m_db->ExecuteUpdate(_T("CREATE TABLE event_type(evt_type_key INTEGER PRIMARY KEY,evt_type_id INTEGER, evt_type_name VARCHAR(64))"));
        m_db->ExecuteUpdate(_T("CREATE TABLE event(evt_key INTEGER PRIMARY KEY,evt_srcidtype INTEGER, evt_srcid INTEGER, evt_ts INTEGER, evt_type INTEGER, evt_kind INTEGER,evt_index INTEGER,test_ref INTEGER,evt_time INTEGER,thread_id INTEGER, db_id INTEGER)"));
        m_db->ExecuteUpdate(_T("CREATE TABLE basic_data_event(basic_data_evt_key INTEGER PRIMARY KEY, int_ref INTEGER, int_val INTEGER, char_val VARCHAR(128))"));
        m_db->ExecuteUpdate(_T("CREATE TABLE dbg_class_evt(dbg_class_evt_key INTEGER PRIMARY KEY, sub_type INTEGER, depth INTEGER,text VARCHAR(128),elapsed_time INTEGER)"));
        m_db->ExecuteUpdate(_T("CREATE TABLE blob_evt(blob_evt_key INTEGER PRIMARY KEY, blob_type INTEGER, the_blob BLOB,event_ref INTEGER)"));

		m_db->ExecuteUpdate(_T("CREATE TABLE logger_event(logger_evt_key INTEGER PRIMARY KEY, sub_type INTEGER, value INTEGER, name VARCHAR(64), event_ref INTEGER)"));

		m_db->ExecuteUpdate(_T("CREATE TABLE db_src(db_src_key INTEGER PRIMARY KEY, name VARCHAR(64), file_name VARCHAR(256), uuid_info VARCHAR(24))"));
		
		m_db->ExecuteUpdate(_T("CREATE TABLE event_pp(event_pp_key INTEGER PRIMARY KEY, evt_type INTEGER, event_ref INTEGER, evt_ts INTEGER, evt_time INTEGER, test_ref INTEGER)"));

		m_db->ExecuteUpdate(_T("CREATE TABLE option_event(option_evt_key INTEGER PRIMARY KEY, sub_type INTEGER, name VARCHAR(64), value INTEGER, char_value VARCHAR(256), event_ref INTEGER)"));
	}
    catch (wxSQLite3Exception& e)
    {
        std::cerr << e.GetErrorCode() << ":" << (const char*)(e.GetMessage().mb_str()) << std::endl;
        return false;
    }
    return true;
}

void db_file::Close()
{
    wxMutexLocker lock(m_db_mutex);
    m_db->Close();
}

void db_file::AddEvent(dbg_log::dbg_class_event *evt)
{
    wxMutexLocker lock(m_db_mutex);
    wxString insertCmd;
    int nRows;
    wxSQLite3ResultSet q1;
    int64_t index_test;    
    int64_t index;
    uint64_t elapsed_time=0;
	const wxChar *cmd;
	wxString param0;

    if (evt==NULL)
        return;

    m_db->Begin();    
    
	try
	{
		switch (evt->GetSubType())
		{
			case dbg_log::dbg_class_event::START_FCT_CALL:            
				break;
			case dbg_log::dbg_class_event::END_FCT_CALL:
				elapsed_time=evt->GetElapsedTime();
				break;
			case dbg_log::dbg_class_event::MSG:
				break;
		}
#ifdef WIN32
		cmd=wxT("INSERT INTO dbg_class_evt(sub_type,depth,text,elapsed_time) VALUES(%i,%i,'%s',%I64u);");
#else
		cmd=wxT("INSERT INTO dbg_class_evt(sub_type,depth,text,elapsed_time) VALUES(%i,%i,'%s',%llu);");
#endif
		param0=wxString(evt->GetCallTxt(),wxConvUTF8);
		insertCmd.Printf(cmd,evt->GetSubType(),evt->GetDepth(),param0.c_str(),elapsed_time);
		nRows=m_db->ExecuteUpdate(insertCmd);
	                            
		index=m_db->GetLastRowId().GetValue();    
#ifdef WIN32
		cmd=wxT("INSERT INTO event(evt_srcidtype, evt_srcid, evt_ts, evt_type, evt_kind,evt_index,test_ref,evt_time,thread_id) VALUES(%i,%i,%I64u,%i,%i,%I64i,%I64i,%I64i,%i);");
#else
		cmd=wxT("INSERT INTO event(evt_srcidtype, evt_srcid, evt_ts, evt_type, evt_kind,evt_index,test_ref,evt_time,thread_id) VALUES(%i,%i,%llu,%i,%i,%lli,%lli,%lli,%i);");
#endif
		insertCmd.Printf(cmd,evt->GetSrcType(),evt->GetSrcId(),evt->GetTS(),evt->GetType()->GetId(),evt->GetKind(),index,m_cur_test_key,evt->GetTime(),evt->GetThreadId());
		nRows=m_db->ExecuteUpdate(insertCmd);
	}
	catch (wxSQLite3Exception& e)
    {
        std::cerr << e.GetErrorCode() << ":" << (const char*)(e.GetMessage().mb_str()) << std::endl;        
    }
    m_db->Commit();
}

void db_file::AddEvent(logmod::blob_event *evt)
{
    wxMutexLocker lock(m_db_mutex);
    wxSQLite3ResultSet q;
    wxSQLite3Statement stmt;
    wxString insertStmt;
    wxString insertCmd;
    uint8_t *data;
    uint32_t size;
    int64_t index_blob;
    int64_t index;
    int nRows;
	const wxChar *cmd;

    m_db->Begin();

	try
	{
		insertStmt.Printf(wxT("INSERT INTO blob_evt(blob_type,the_blob) VALUES (%i, ?);"),evt->GetBlobType());
		stmt=m_db->PrepareStatement(insertStmt);
		data=evt->Get(size);
		stmt.Bind(1,data,size);
		stmt.ExecuteUpdate();

		index_blob=m_db->GetLastRowId().GetValue();
#ifdef WIN32
		cmd=wxT("INSERT INTO event(evt_srcidtype, evt_srcid, evt_ts, evt_type, evt_kind,evt_index,test_ref,evt_time,thread_id) VALUES(%i,%i,%I64u,%i,%i,%I64i,%I64i,%I64i,%i);");
#else
		cmd=wxT("INSERT INTO event(evt_srcidtype, evt_srcid, evt_ts, evt_type, evt_kind,evt_index,test_ref,evt_time,thread_id) VALUES(%i,%i,%llu,%i,%i,%lli,%lli,%lli,%i);");
#endif
		insertCmd.Printf(cmd,evt->GetSrcType(),evt->GetSrcId(),evt->GetTS(),evt->GetType()->GetId(),evt->GetKind(),index_blob,m_cur_test_key,evt->GetTime(),evt->GetThreadId());
		nRows=m_db->ExecuteUpdate(insertCmd);
	    
		index=m_db->GetLastRowId().GetValue();
#ifdef WIN32
		cmd=wxT("UPDATE blob_evt SET event_ref=%I64i WHERE blob_evt_key=%I64i;");
#else
		cmd=wxT("UPDATE blob_evt SET event_ref=%lli WHERE blob_evt_key=%lli;");
#endif
		insertCmd.Printf(cmd,index,index_blob);
		nRows=m_db->ExecuteUpdate(insertCmd);
	}
	catch (wxSQLite3Exception& e)
    {
        std::cerr << e.GetErrorCode() << ":" << (const char*)(e.GetMessage().mb_str()) << std::endl;       
    }
    m_db->Commit();
	stmt.Finalize();
}

void db_file::AddEvent(logmod::logger_event *evt)
{
	//logger_event(logger_evt_key INTEGER PRIMARY KEY, sub_type INTEGER, value INTEGER, name VARCHAR(64), event_ref INTEGER)"));
	wxMutexLocker lock(m_db_mutex);
	wxString insertCmd;
    int nRows;
	int64_t index;
	int64_t index_event;
	bool added=false;
	const wxChar *cmd;
	wxString param0;
	wxString param1;

	m_db->Begin();

	try
	{
        switch (evt->GetSubType())
        {
            case logmod::logger_event::NAMED_THREAD:
            case logmod::logger_event::THREAD_END:
            case logmod::logger_event::ERROR_MSG:
				param0=wxString(evt->GetName(),wxConvUTF8);
			    insertCmd.Printf(_T("INSERT INTO logger_event(sub_type,value,name) VALUES(%i,%i,'%s');"),evt->GetSubType(),evt->GetThreadId(),param0.c_str());

			    nRows=m_db->ExecuteUpdate(insertCmd);
                
                index=m_db->GetLastRowId().GetValue();
#ifdef WIN32
				cmd=wxT("INSERT INTO event(evt_srcidtype, evt_srcid, evt_ts, evt_type, evt_kind,evt_index,test_ref,evt_time,thread_id) VALUES(%i,%i,%I64u,%i,%i,%I64i,%I64i,%I64i,%i);");
#else
				cmd=wxT("INSERT INTO event(evt_srcidtype, evt_srcid, evt_ts, evt_type, evt_kind,evt_index,test_ref,evt_time,thread_id) VALUES(%i,%i,%llu,%i,%i,%lli,%lli,%lli,%i);");
#endif
			    insertCmd.Printf(cmd,evt->GetSubType(),evt->GetSrcId(),evt->GetTS(),evt->GetType()->GetId(),evt->GetKind(),index,m_cur_test_key,evt->GetTime(),evt->GetThreadId());
		        nRows=m_db->ExecuteUpdate(insertCmd);

		        index_event=m_db->GetLastRowId().GetValue();
#ifdef WIN32
				cmd=wxT("UPDATE logger_event SET event_ref=%I64i WHERE logger_evt_key=%I64i;");
#else
				cmd=wxT("UPDATE logger_event SET event_ref=%lli WHERE logger_evt_key=%lli;");
#endif
		        insertCmd.Printf(cmd,index_event,index);
		        nRows=m_db->ExecuteUpdate(insertCmd);
                break;
		}
	}
	catch (wxSQLite3Exception& e)
    {
        std::cerr << e.GetErrorCode() << ":" << (const char*)(e.GetMessage().mb_str()) << std::endl;        
    }

	m_db->Commit();
}

void db_file::AddEvent(logmod::option_event *evt)
{
	wxMutexLocker lock(m_db_mutex);
	wxString insertCmd;
    int nRows;
	int64_t index;
	int64_t index_event;
	bool added=false;
	std::string str;
	const wxChar *cmd;
	wxString param0;
	wxString param1;

	m_db->Begin();

	try
	{		
		if (evt->GetValue(str))
		{
			cmd=wxT("INSERT INTO option_event(sub_type,name,value,char_value) VALUES(%i,'%s',%i,'%s');");
			param0=wxString(evt->GetOption(),wxConvUTF8);
			param1=wxString(str.c_str(),wxConvUTF8);
			insertCmd.Printf(cmd,evt->GetSubType(),param0.c_str(),evt->GetValue(),param1.c_str());
		}
		else
		{
			cmd=wxT("INSERT INTO option_event(sub_type,name,value) VALUES(%i,'%s',%i);");
			param0=wxString(evt->GetOption(),wxConvUTF8);
			insertCmd.Printf(cmd,evt->GetSubType(),param0.c_str(),evt->GetValue());
		}

		nRows=m_db->ExecuteUpdate(insertCmd);

		index=m_db->GetLastRowId().GetValue();
#ifdef WIN32
		cmd=wxT("INSERT INTO event(evt_srcidtype, evt_srcid, evt_ts, evt_type, evt_kind,evt_index,test_ref,evt_time,thread_id) VALUES(%i,%i,%I64u,%i,%i,%I64i,%I64i,%I64i,%i);");
#else
		cmd=wxT("INSERT INTO event(evt_srcidtype, evt_srcid, evt_ts, evt_type, evt_kind,evt_index,test_ref,evt_time,thread_id) VALUES(%i,%i,%llu,%i,%i,%lli,%lli,%lli,%i);");
#endif
		insertCmd.Printf(cmd,evt->GetSubType(),evt->GetSrcId(),evt->GetTS(),evt->GetType()->GetId(),evt->GetKind(),index,m_cur_test_key,evt->GetTime(),evt->GetThreadId());
		nRows=m_db->ExecuteUpdate(insertCmd);

		index_event=m_db->GetLastRowId().GetValue();
#ifdef WIN32
		cmd=wxT("UPDATE option_event SET event_ref=%I64i WHERE option_evt_key=%I64i;");
#else
		cmd=wxT("UPDATE option_event SET event_ref=%lli WHERE option_evt_key=%lli;");
#endif
		insertCmd.Printf(cmd,index_event,index);
		nRows=m_db->ExecuteUpdate(insertCmd);
	}
	catch (wxSQLite3Exception& e)
    {
        std::cerr << e.GetErrorCode() << ":" << (const char*)(e.GetMessage().mb_str()) << std::endl;        
    }
	m_db->Commit();
}

void db_file::AddOption(char *option,char *value)
{
    wxMutexLocker lock(m_db_mutex);
    wxString insertCmd;
    int nRows;
	wxString param0;
	wxString param1;

	try
	{
		param0=wxString(option,wxConvUTF8);
		param1=wxString(value,wxConvUTF8);
		insertCmd.Printf(_T("INSERT INTO format_info(format_opt,format_val_char) VALUES('%s','%s');"),param0.c_str(),param1.c_str());
		nRows=m_db->ExecuteUpdate(insertCmd);
	}
	catch (wxSQLite3Exception& e)
    {
        std::cerr << e.GetErrorCode() << ":" << (const char*)(e.GetMessage().mb_str()) << std::endl;        
    }
}

void db_file::AddOption(char *option,int value)
{
    wxMutexLocker lock(m_db_mutex);
    wxString insertCmd;
    int nRows;
	wxString param0;

	try
	{
		param0=wxString(option,wxConvUTF8);
		insertCmd.Printf(_T("INSERT INTO format_info(format_opt,format_val_int) VALUES('%s',%i);"),param0.c_str(),value);
		nRows=m_db->ExecuteUpdate(insertCmd);
	}
	catch (wxSQLite3Exception& e)
    {
        std::cerr << e.GetErrorCode() << ":" << (const char*)(e.GetMessage().mb_str()) << std::endl;        
    }
}

uint32_t db_file::GetNbrConfTest()
{
    wxMutexLocker lock(m_db_mutex);
    wxString selectCmd;
    uint32_t nRows;
    wxLongLong count;
    wxSQLite3ResultSet q1;
    int64_t index_test;    
    int64_t index;
    uint64_t elapsed_time=0;
    
    //m_db->Begin();    
    try
	{
		selectCmd.Printf(_T("SELECT COUNT(*) FROM test_run"));
		q1=m_db->ExecuteQuery(selectCmd);
		count=q1.GetInt64(0);
		nRows=count.ToLong();
    
		q1.Finalize();  //needed?
	}
	catch (wxSQLite3Exception& e)
    {
        std::cerr << e.GetErrorCode() << ":" << (const char*)(e.GetMessage().mb_str()) << std::endl;        
    }
    return nRows;
}

bool db_file::GetConfTestName(uint32_t index, std::string &name)
{
    wxMutexLocker lock(m_db_mutex);
    wxString selectCmd;
    uint32_t nRows;
    wxLongLong count;
    wxSQLite3ResultSet q1;
    
    //m_db->Begin();    
    try
	{
		selectCmd.Printf(_T("SELECT * FROM test_run WHERE test_run_key=%i"),index+1);
		q1=m_db->ExecuteQuery(selectCmd);
		if (q1.Eof())
			return false;
		selectCmd=q1.GetString(1);
	}
	catch (wxSQLite3Exception& e)
    {
        std::cerr << e.GetErrorCode() << ":" << (const char*)(e.GetMessage().mb_str()) << std::endl;
        return false;
    }
    name=selectCmd.char_str();
    return true;
}

uint32_t db_file::GetNbrEventsOfTest(uint32_t index)
{
    wxMutexLocker lock(m_db_mutex);
    wxString selectCmd;
    uint32_t nRows;
    wxLongLong count;
    wxSQLite3ResultSet q1;
    
    //m_db->Begin();    
	try
	{
		selectCmd.Printf(_T("SELECT COUNT(*) FROM event WHERE test_ref=%i"),index+1);
		q1=m_db->ExecuteQuery(selectCmd);
		if (q1.Eof())
			return 0;
		count=q1.GetInt64(0);        
		q1.Finalize();  //needed?    
	}
	catch (wxSQLite3Exception& e)
    {
        std::cerr << e.GetErrorCode() << ":" << (const char*)(e.GetMessage().mb_str()) << std::endl;
        return 0;
    }
    return count.ToLong();
}

void db_file::FilterAllTests()
{
    m_all_test=true;
    m_filter_one_test=false;
    if (m_table_results_has_data)
    {
        m_table_results->Finalize();
        m_table_results_has_data=false;
    }
}

void db_file::FilterOneTest(uint32_t index)
{
    m_all_test=false;
    m_filter_one_test=true;
    m_filter_one_test_idx=index+1;
    if (m_table_results_has_data)
    {
        m_table_results->Finalize();
        m_table_results_has_data=false;
    }

}

logmod::event *db_file::GetEvent(uint32_t event_index)
{
    wxString selectCmd;
    wxLongLong event_type_l;
    wxLongLong temp;
    uint32_t event_type;
    wxLongLong index;
    wxSQLite3ResultSet q1;
    logmod::event *r_evt=NULL;

    if (m_table_results_has_data==false)
    {
        if (m_all_test)
            selectCmd.Printf(_T("SELECT * FROM event"));
        else if (m_filter_one_test)
		{
            //selectCmd.Printf(_T("SELECT * FROM event WHERE test_ref=%i"),m_filter_one_test_idx);
			selectCmd.Printf(_T("SELECT * FROM event "));
			selectCmd.Append(wxString(_build_where(),wxConvUTF8));
		}
        *m_table_results=m_db->GetTable(selectCmd);
        m_table_results_has_data=true;
    }
    m_table_results->SetRow(event_index);
    event_type_l=m_table_results->GetInt64(wxT("evt_type"));
    event_type=event_type_l.ToLong();

    if (event_type==logmod::evt_typ::EVT_NONE.GetId())
    {
        
    }
    else if (event_type==logmod::evt_typ::EVT_DBG_CLASS.GetId())
    {
        dbg_log::dbg_class_event *event;

        index=m_table_results->GetInt64(wxT("evt_index"));
        selectCmd.Printf(_T("SELECT * FROM dbg_class_evt WHERE dbg_class_evt_key=%I64u"),index.GetValue());
        q1=m_db->ExecuteQuery(selectCmd);
        if (q1.Eof())
            return NULL;
        event=new dbg_log::dbg_class_event();
        temp=q1.GetInt64(wxT("sub_type"));
        event->SetSubType((dbg_log::dbg_class_event::sub_type)temp.GetValue());
        temp=q1.GetInt64(wxT("depth"));
        event->SetDepth(temp.GetValue());
        selectCmd=q1.GetString(wxT("text"));
        event->SetCallTxt(selectCmd.char_str());
        temp=q1.GetInt64(wxT("elapsed_time"));
        event->SetElapsedTime(temp.GetValue());

        r_evt=event;
    }
    else if (event_type==logmod::evt_typ::EVT_BLOB.GetId())
    {
    }
    
    if (r_evt!=NULL)
    {
        //evt->GetSrcType(),evt->GetSrcId(),evt->GetTS(),evt->GetType()->GetId(),evt->GetKind(),index,m_cur_test_key,evt->GetTime()
        temp=m_table_results->GetInt64(wxT("evt_srcidtype"));
        r_evt->SetSrcType(temp.GetValue());
        temp=m_table_results->GetInt64(wxT("evt_srcid"));
        r_evt->SetSrcId(temp.GetValue());
        temp=m_table_results->GetInt64(wxT("evt_ts"));
        r_evt->SetTS(temp.GetValue());        
        temp=m_table_results->GetInt64(wxT("evt_kind"));
        r_evt->SetKind((logmod::event::event_kind)temp.GetValue());
        temp=m_table_results->GetInt64(wxT("evt_key"));
        r_evt->SetKey(temp.GetValue());
        temp=m_table_results->GetInt64(wxT("evt_time"));
        r_evt->SetTime(temp.GetValue());        
    }
    return r_evt;
}

void db_file::ShowEvent(logmod::event_type &evt_type,bool show)
{
	m_show_events.at(evt_type.GetId())=show;
	if (m_table_results_has_data)
    {
        m_table_results->Finalize();
        m_table_results_has_data=false;
    }
}

const char*db_file::_build_where()
{
	uint32_t index,max;
	wxString str,temp;
	bool added=false;
	max=m_show_events.size();
	for (index=0;index<max;index++)
	{
		if (m_show_events.at(index)==true)
		{
			if (added)
				str.Append(wxT(" OR "));
			temp.Printf(wxT("(evt_type=%i)"),index);
			str.Append(temp);
			added=true;
		}
	}
	if (added==false)
		temp.Printf(wxT("test_ref=%i"),m_filter_one_test_idx);
	else
	{
		temp.Printf(wxT("WHERE ((test_ref=%i) AND ("),m_filter_one_test_idx);
		temp.Append(str);
		temp.Append(wxT("))"));
	}
    m_build_where=temp.char_str();
    return m_build_where.c_str();
}

void db_file::Backup(char *name)
{
    wxString str(name,wxConvUTF8);
	    
    m_db->Backup(str);
}

/*int db_file::GetProcCurState(int64_t key,up_sdl::up_sdl_event *evt)
{
	wxString selectCmd;
	wxSQLite3ResultSet q1;
	int64_t state_key;

	selectCmd.Printf(_T("SELECT * FROM sdl_transition WHERE process_ref = %I64u ORDER BY sdl_tran_key DESC LIMIT 1;"),key);
	        
    try
	{		
		q1=m_db.ExecuteQuery(selectCmd);
		if (q1.Eof())
			return -1;
		state_key=q1.GetInt64(wxT("sub_type"));
	}
	catch (wxSQLite3Exception& e)
    {
        std::cerr << e.GetErrorCode() << ":" << (const char*)(e.GetMessage().mb_str()) << std::endl;
        return false;
    }
    name=selectCmd.char_str(); 
    return -1;
}*/

wxSQLite3Database *db_file::GetDB()
{
	return m_db;
}

}


