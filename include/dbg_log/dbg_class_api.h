#ifndef __DBG_CLASS_API_H__
#define __DBG_CLASS_API_H__

#include "dbg_log/cloudice_defs.h"
//#include "logmod/logger.h"
//#include "logmod/event_logger.h"

namespace dbg
{

class DBG_LOG_API dbg_class_class_info;

class DBG_LOG_API dbg_class_api
{
public:
    virtual ~dbg_class_api();

	virtual void PrintState() const=0;
    //virtual void PrintState(logmod::logger &os,int count=-1) const=0;
    //virtual logmod::logger*GetLogger() const=0;
    //virtual logmod::event_logger *GetEventLogger() const=0;
    //virtual void SetEventLogger(logmod::event_logger *evt_logger)=0;
    //virtual void SetLogger(logmod::logger *logger)=0;

    virtual up_c::dbg_class_class_info *__get_dbg_class_class_info();
};

}

#include "dbg_log/dbg_class.h"

#endif
