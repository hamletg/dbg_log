/**
 * \file log_sqlite/event_logger.h
 * \brief Defines the events logger using Sqlite
 *
 *  \cond
 *__legal_b__
 *__legal_e__
 * \endcond
 */

#ifndef __LOG_SQLITE_EVENT_LOGGER_H__
#define __LOG_SQLITE_EVENT_LOGGER_H__

#include "logmod/logmod_defs.h"
#include "logmod/event_logger.h"
#include "log_sqlite/db_file.h"
#include <string>

namespace log_sqlite
{

class LOG_SQLITE_API event_logger: public logmod::event_logger
{
 public:
    event_logger();
    virtual ~event_logger();

    virtual void Send(logmod::event *evt);

    void SetDbName(char *name,bool in_mem=false);
	log_sqlite::db_file *GetDb();
    void CloseDb();

 protected:
    int m_argc;
    char **m_argv;
    log_sqlite::db_file *m_db;
    std::string m_name;
    bool m_in_mem;
};

}

#endif

