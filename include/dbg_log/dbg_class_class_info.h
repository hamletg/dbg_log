#ifndef __DBG_CLASS_CLASS_INFO_H__
#define __DBG_CLASS_CLASS_INFO_H__

#include "dbg_log/dbg_log_defs.h"
#include "dbg_log/inttypes.h"

namespace dbg_log
{

class DBG_LOG_API dbg_class_class_info
{
public:
    dbg_class_class_info(const char *name);
    virtual ~dbg_class_class_info();

    const char*GetName();
    uint32_t GetID();

    static dbg_class_class_info *GetFirst();   //!< Return the first class
    dbg_class_class_info *GetNext();           //!< Return the next class

    //void Add(up_c::dbg_class_api *instance);
    //uint32_t GetInstanceCount();
    //up_c::dbg_class_api *GetInstance(uint32_t index);
protected:
    const char *m_name;                     //!< Name of the class
    static uint32_t m_count;                //!< Number of info on classes using dbg_class
    static dbg_class_class_info *m_first;   //!< Pointer to the first class using dbg_class
    dbg_class_class_info *m_next;           //!< Pointer to the next class using dbg_class
    uint32_t m_id;                          //!< Store the value of m_count when this instance was created
    //std::vector<up_c::dbg_class_api *> m_instances;   //!< Store all intances of the same class
};

}

#endif
