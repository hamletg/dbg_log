#include "dbg_log/dbg_log_prec.h"

#include "dbg_log/dbg_class_function_info.h"

#include <stddef.h>

namespace dbg_log
{

uint32_t dbg_class_function_info::m_count=0;
dbg_class_function_info *dbg_class_function_info::m_first=NULL;

dbg_class_function_info::dbg_class_function_info(const char *name,bool isnew)
    :m_name(name)
    ,m_is_new(isnew)
{
    if (m_is_new)
    {
        m_next=m_first;
        m_first=this;
        m_id=m_count;
        m_count++;
    }
    else
    {
    }
}

dbg_class_function_info::~dbg_class_function_info()
{
}

uint32_t dbg_class_function_info::GetId()
{
    return m_id;
}

}
