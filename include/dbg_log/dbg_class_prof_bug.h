#ifndef __DBG_CLASS_PROF_BUG_H__
#define __DBG_CLASS_PROF_BUG_H__

#include "dbg_log/dbg_log_defs.h"
#include "dbg_log/inttypes.h"

#include "dbg_log/dbg_class_prof.h"

namespace dbg_log
{

class DBG_LOG_API dbg_class_prof_bug
{
public:
    dbg_class_prof_bug(dbg_class_prof *prof);
    virtual ~dbg_class_prof_bug();

    dbg_class_prof *m_prof;
};

}

#endif
