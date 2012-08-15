#ifndef __DBG_CLASS_FUNCTION_INFO_H__
#define __DBG_CLASS_FUNCTION_INFO_H__

#include "dbg_log/dbg_log_defs.h"
#include "dbg_log/inttypes.h"

namespace dbg_log
{

class DBG_LOG_API dbg_class_function_info
{
 public:
    dbg_class_function_info(const char *name,bool isnew=true);
    virtual ~dbg_class_function_info();

    uint32_t GetId();

 protected:
    static uint32_t m_count;
    uint32_t m_id;
    static dbg_class_function_info *m_first;
    dbg_class_function_info *m_next;
    const char *m_name;
    bool m_is_new;
};

}

#endif

