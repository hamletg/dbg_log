#include "dbg_log/dbg_log_prec.h"

#include "dbg_log/dbg_class_class_info.h"

#include <stddef.h>

namespace dbg_log
{

uint32_t dbg_class_class_info::m_count=0;
dbg_class_class_info *dbg_class_class_info::m_first=NULL;

dbg_class_class_info::dbg_class_class_info(const char *name)
{
    m_name=name;
    m_next=m_first;
    m_first=this;
    m_id=m_count;
    m_count++;
}

dbg_class_class_info::~dbg_class_class_info()
{
}

const char *dbg_class_class_info::GetName()
{
    return m_name;
}

uint32_t dbg_class_class_info::GetID()
{
    return m_id;
}

dbg_class_class_info *dbg_class_class_info::GetFirst()
{
    return m_first;
}

dbg_class_class_info *dbg_class_class_info::GetNext()
{
    return m_next;
}

/*void dbg_class_class_info::Add(up_c::dbg_class_api *instance)
{
    m_instances.push_back(instance);
}

uint32_t dbg_class_class_info::GetInstanceCount()
{
    return m_instances.size();
}

up_c::dbg_class_api *dbg_class_class_info::GetInstance(uint32_t index)
{
    if (index>=m_instances.size())
        return NULL;
    return m_instances.at(index);
} */

}

