/**
 * \file log_sqlite/db_file.h
 * \brief Defines the database format
 *
 * \cond
 *__legal_b__
 *__legal_e__
 * \endcond
 */

#ifndef __LOG_SQLITE_DB_FILE_H__
#define __LOG_SQLITE_DB_FILE_H__

#include <wx/string.h>		//needed to avoid problems with library using db_file.h

#include <string>
#include <vector>
#include "log_sqlite/log_sqlite_defs.h"

#include "dbg_log/dbg_class_event.h"
#include "dbg_log/inttypes.h"
#include "logmod/blob_event.h"
#include "logmod/logger_event.h"
#include "logmod/option_event.h"

#include <wx/thread.h>

class wxSQLite3Database;
class wxSQLite3Table;

namespace log_sqlite
{

class LOG_SQLITE_API sdl_process;

class LOG_SQLITE_API db_file
{
public:
    db_file(char *name=NULL);
    virtual ~db_file();

    bool Open(char *name=NULL);
    bool Create(char *name=NULL);
    bool CreateTables();

    void AddModule(char *name,char *basename,uint32_t uid,char *type);
    void AddModule(char *name,char *basename,uint32_t uid,uint32_t parentuid,char *type);

    void AddEvent(dbg_log::dbg_class_event *evt);

    void AddEvent(logmod::blob_event *evt);

	void AddEvent(logmod::logger_event *evt);

	void AddEvent(logmod::option_event *evt);

    void AddOption(char *option,char *value);
    void AddOption(char *option,int value);

    void Close();

    uint32_t GetNbrConfTest();
    bool GetConfTestName(uint32_t index, std::string &name);
    uint32_t GetNbrEventsOfTest(uint32_t index);
    void FilterAllTests();
    void FilterOneTest(uint32_t index);
    logmod::event *GetEvent(uint32_t event_index);
	void ShowEvent(logmod::event_type &evt_type,bool show=true);
	void AddEventTypes();

	//int GetProcCurState(int64_t key,std::string &name);

    void Backup(char *name);

	wxSQLite3Database *GetDB();

protected:
	const char *_build_where();
    std::string m_name;
    std::string m_build_where;
    wxSQLite3Database *m_db;
    wxSQLite3Table *m_table_results;
    bool m_table_results_has_data;
    wxMutex m_db_mutex;
    int64_t m_cur_test_key;
    bool m_all_test;
    bool m_filter_one_test;
    uint32_t m_filter_one_test_idx;
	std::vector<bool> m_show_events;
};

}

#endif
