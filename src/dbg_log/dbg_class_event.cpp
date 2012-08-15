/**
 * \file dbg_log/dbg_class_event.cpp
 * \brief Declare the event used by the dbg_class
 *
 * \cond
 *__legal_b__
 *__legal_e__
 * \endcond
 */

#include "dbg_log/dbg_log_prec.h"
#include "dbg_log/dbg_class_event.h"
#include "logmod/event_types.h"

#include "dbg_log/dbg_class.h"

namespace dbg_log
{

dbg_class_event::dbg_class_event():logmod::event(&logmod::evt_typ::EVT_DBG_CLASS)
{
    m_sub_type=NONE;
    m_dbg_class=NULL;
}

dbg_class_event::~dbg_class_event()
{
}
    
dbg_class *dbg_class_event::GetDbgClass()
{
    return m_dbg_class;
}

void dbg_class_event::SetDbgClass(dbg_class *dbg)
{
    m_dbg_class=dbg;
}

uint32_t dbg_class_event::GetDepth()
{
    return m_depth;
}

void dbg_class_event::SetDepth(uint32_t depth)
{
    m_depth=depth;
}

const char *dbg_class_event::GetCallTxt()
{
    return m_call_txt.c_str();
}

void dbg_class_event::SetCallTxt(char *txt)
{
    m_call_txt=txt;
}

dbg_class_event::sub_type dbg_class_event::GetSubType()
{
    return m_sub_type;
}

void dbg_class_event::SetSubType(dbg_class_event::sub_type s_type)
{
    m_sub_type=s_type;
}

void dbg_class_event::SetElapsedTime(uint64_t time)
{
    m_elapsed_time=time;
}

uint64_t dbg_class_event::GetElapsedTime()
{
    return m_elapsed_time;
}

}


