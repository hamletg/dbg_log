/*!
 * \file logmod/logger_event.h
 * \brief Defines a logger event which can be logged
 *
 * \cond
 *__legal_b__
 *__legal_e__
 * \endcond
 */

#ifndef __LOGMOD_LOGMOD_EVENT_H__
#define __LOGMOD_LOGMOD_EVENT_H__

#include "logmod/logmod_defs.h"
#include "logmod/event.h"
#include "logmod/event_types.h"

#include <string>

namespace logmod
{

/*! \class logger_event logmod/logger_event.h "logmod/logger_event.h"
 *  \brief A logger event
 *
 */
class LOGMOD_API logger_event: public event
{
 public:
    logger_event();
    virtual ~logger_event();
 
    void SetSubType(uint32_t sub_type);
	uint32_t GetSubType();

	void SetValue(uint32_t value);
	uint32_t GetValue();

	void SetName(char *name);
	const char *GetName();

	void NamedThread();
	void EndOfThread();
    void Error();

	virtual std::ostream &PrintString(std::ostream &os);

	enum
	{
		UNKNOWN=0,
		NAMED_THREAD,
		THREAD_END,
        ERROR_MSG
	};
 protected:    
    uint32_t m_sub_type;
	uint32_t m_value;
	std::string m_name;
};

}

#endif
