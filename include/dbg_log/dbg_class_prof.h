#ifndef __DBG_CLASS_PROF_H__
#define __DBG_CLASS_PROF_H__

#include "dbg_log/dbg_log_defs.h"
#include "dbg_log/inttypes.h"

namespace dbg_log
{

/*! \class dbg_class_prof unipro_core/dbg_class.h "unipro_core/dbg_class.h"
 *  \brief Class implementating a simple form of profiling
 */
class DBG_LOG_API dbg_class_prof
{
public:
    dbg_class_prof(const char *name);
    virtual ~dbg_class_prof();

    static void Enable(bool val=true);
    static dbg_class_prof* GetFirst();
    dbg_class_prof* GetNext();
    const char* GetName();
    
    inline void IncCall()
    {
        m_nbr_of_calls++;
    }

    inline void Start()
    {
        m_start_time=RDTSC();
    }

    inline void End()
    {
        m_end_time=RDTSC();
        m_acc_time+=m_end_time-m_start_time;
    }

    inline void Wait()
    {
        m_wait++;
    }

    static inline bool IsEnabled()
    {
        return m_enable_prof;
    }

    static uint64_t RDTSC();
    
    uint64_t GetTime();
    uint32_t GetNbrCalls();
    uint32_t GetWaits();

protected:
    static uint32_t m_counter;
    uint32_t m_id;
    uint32_t m_nbr_of_calls;
    uint32_t m_wait;
    static dbg_class_prof* m_first;
    dbg_class_prof* m_next;
    const char *m_name;
    static bool m_enable_prof;
    uint64_t m_start_time;
    uint64_t m_end_time;
    uint64_t m_acc_time;        //!< Accumulated time
};

}

#endif
