#include "dbg_log/dbg_log_prec.h"

#include "dbg_log/dbg_class_prof_bug.h"

namespace dbg_log
{

dbg_class_prof_bug::dbg_class_prof_bug(dbg_class_prof *prof)
{
    m_prof=prof;
}

dbg_class_prof_bug::~dbg_class_prof_bug()
{
    m_prof->End();
}

}
