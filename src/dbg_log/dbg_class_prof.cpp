#include "dbg_log/dbg_log_prec.h"

#include "dbg_log/dbg_class_prof.h"

#include <stddef.h>

namespace dbg_log
{

uint32_t dbg_class_prof::m_counter=0;
dbg_class_prof* dbg_class_prof::m_first=NULL;
bool dbg_class_prof::m_enable_prof=false;

dbg_class_prof::dbg_class_prof(const char *name)
{
    m_next=m_first;
    m_first=this;
    m_id=m_counter;
    m_counter++;
    m_name=name;
    m_nbr_of_calls=0;
    m_acc_time=0;
    m_wait=0;
}
 
dbg_class_prof::~dbg_class_prof()
{
}

uint64_t dbg_class_prof::RDTSC()
{
        //RDTSC exists only on intel platform starting from Pentium CPU it seems, should be fine for
        // x86 platform even under Linux but need to have proper inline assembly following GNU format
        // Can't be used for Solaris platform
        #ifdef _MSC_VER
            _asm  _emit 0x0F
            _asm  _emit 0x31
        #else
            return 0;
        #endif
}

void dbg_class_prof::Enable(bool val)
{
    m_enable_prof=val;
}

dbg_class_prof* dbg_class_prof::GetFirst()
{
    return m_first;
}

dbg_class_prof* dbg_class_prof::GetNext()
{
    return m_next;
}

const char* dbg_class_prof::GetName()
{
    return m_name;
}

uint32_t dbg_class_prof::GetNbrCalls()
{
    return m_nbr_of_calls;
}

uint64_t dbg_class_prof::GetTime()
{
    return m_acc_time;
}

uint32_t dbg_class_prof::GetWaits()
{
    return m_wait;
}

}
