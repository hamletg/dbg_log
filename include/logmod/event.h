/*!
 * \file logmod/event.h
 * \brief Defines the events which can be logged
 *
 * \cond
 *__legal_b__
 *__legal_e__
 * \endcond
 */

#ifndef __LOGGER_EVENT_H__
#define __LOGGER_EVENT_H__

#include "logmod/logmod_defs.h"
#include "logmod/event_types.h"

#include <ostream>

namespace logmod
{

/*! \class event logmod/event.h "logmod/event.h"
 *  \brief The base class of all logging or reporting events
 *
 * It's an abstract representation of an event according to the model:
 * - a logger user is an entity which can generate events and each such source of event has an unique address
 *   stored in m_src_id; but also a type stored in m_src_type
 * - an event is just a means to convey or report of an action taken or to be taken, a change of state, the
 *   reception or transmission of a message, etc. 
 * - an event can have various type
 * - an event has a event_type, either INPUT, OUTPUT, state
 */
class LOGMOD_API event
{
 public:
	event(event_type *type=&logmod::evt_typ::EVT_NONE);
    virtual ~event();
    
    enum event_kind
    {
        NONE=-1,
        INPUT=0,                //!< This event marks the reception of something by the user of the logger
        OUTPUT,                 //!< This event marks the transmission of something by the user of the logger
        STATE,                  //!< This event contains a state information of the user of the logger
    };

    event_type *GetType();
    void SetType(event_type *type);
    uint64_t GetTS();
    void SetTS(uint64_t type);
    uint32_t GetSrcType();
    void SetSrcType(uint32_t type);
    uint32_t GetSrcId();
    void SetSrcId(uint32_t type);
    event_kind GetKind();
    void SetKind(event_kind kind);
    int64_t GetKey();
    void SetKey(int64_t key);
    
    static uint64_t GetCurTime();
    void MarkWithCurTime();

    uint64_t GetTime();
    void SetTime(uint64_t time);
	
	int32_t GetRegId();
	void SetRegId(int32_t id);
	
	int64_t GetProcessId();
	void SetProcessId(int64_t id);

	uint64_t GetThreadId();
	void SetThreadId(uint64_t thread_id);
	void CaptureThreadId();
	void CaptureProcessId();

	virtual std::ostream &PrintString(std::ostream &os);

	static uint64_t GetCurThreadId();
	static uint64_t GetCurProcessId();
 protected:
    event_type *m_type;         //!< Type of event, every derivate class will must have a different number
    uint64_t m_ts;              //!< Timestamp in ps
    uint32_t m_src_type;        //!< Type of source, the user of the logger
    uint32_t m_src_id;          //!< Unique number identifying the Source of the event
    event_kind m_event_kind;    //!< Tells the kind event: input, output, state, etc.
    int64_t m_key;              //!< Used by some event to return the key of the posted event
    uint64_t m_time_ms;         //!< PC time in ms
	uint64_t m_thread_id;
	uint32_t m_reg_id;
	uint64_t m_process_id;
};

}

#endif
