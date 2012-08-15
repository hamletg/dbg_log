/**
 * \file dbg_log/dbg_class_event.h
 * \brief Defines the event used by the dbg_class
 *
 * \cond
 *__legal_b__
 *__legal_e__
 * \endcond
 */

#ifndef __DBG_CLASS_EVENT_H__
#define __DBG_CLASS_EVENT_H__

#include "dbg_log/dbg_log_defs.h"
#include "logmod/event.h"

#include <string>

namespace dbg_log
{

class DBG_LOG_API dbg_class;

class DBG_LOG_API dbg_class_event:public logmod::event
{
public:
    enum sub_type
    {
        NONE,
        START_FCT_CALL,
        END_FCT_CALL,
        MSG
    };

    dbg_class_event();
    virtual ~dbg_class_event();
    
    dbg_class *GetDbgClass();
    void SetDbgClass(dbg_class *dbg);

    uint32_t GetDepth();
    void SetDepth(uint32_t depth);

    const char *GetCallTxt();
    void SetCallTxt(char *txt);
    
    dbg_class_event::sub_type GetSubType();
    void SetSubType(dbg_class_event::sub_type s_type);
    
    void SetElapsedTime(uint64_t time);
    uint64_t GetElapsedTime();

protected:
    uint32_t m_depth;           //!< The depth of call imbrication
    std::string m_call_txt;     //!< The string storing the information about the function call
    sub_type m_sub_type;        
    dbg_class *m_dbg_class;
    uint64_t m_elapsed_time;
};

}

#endif

