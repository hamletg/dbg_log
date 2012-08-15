/*!
 * \file logmod/option_event.h
 * \brief Defines a logger event which can be logged
 *
 * \cond
 *__legal_b__
 *__legal_e__
 * \endcond
 */

#ifndef __LOGGER_OPTION_EVENT_H__
#define __LOGGER_OPTION_EVENT_H__

#include "logmod/logmod_defs.h"
#include "logmod/event.h"
#include "logmod/event_types.h"
#include "logmod/inttypes.h"

#include <string>

namespace logmod
{

/*! \class option_event logmod/option_event.h "logmod/option_event.h"
 *  \brief A logger event
 *
 */
class LOGMOD_API option_event: public event
{
 public:
    option_event();
    virtual ~option_event();
 
    void SetSubType(uint32_t sub_type);
	uint32_t GetSubType();

	void SetValue(uint32_t value);
	uint32_t GetValue();

	void SetOption(char *name);
	const char *GetOption();

	void SetValue(char *val);
	bool GetValue(std::string &str);

	void Normal();

	enum
	{
		UNKNOWN=0,
		NORMAL,
	};
	
 protected:
	uint32_t m_sub_type;
	uint32_t m_value;
	std::string m_name;
	std::string m_str_val;
};

}

#endif
