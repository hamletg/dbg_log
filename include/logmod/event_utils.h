/*!
 * \file logmod/event_utils.h
 * \brief Defines some utilities to handle events
 *
 * \cond
 *__legal_b__
 *__legal_e__
 * \endcond
 */

#ifndef __LOGGER_EVENT_UTILS_H__
#define __LOGGER_EVENT_UTILS_H__

#include "logmod/logmod_defs.h"
#include "logmod/event.h"
#include "logmod/inttypes.h"

#include <ostream>

namespace logmod
{

class LOGMOD_API event_utils
{
 public:
	event_utils();
	virtual ~event_utils();

	virtual std::ostream &PrintTime(std::ostream &os,logmod::event *evt);
	virtual std::ostream &PrintKey(std::ostream &os,logmod::event *evt);
	virtual std::ostream &PrintTS(std::ostream &os,logmod::event *evt);
	virtual std::ostream &PrintThreadID(std::ostream &os,logmod::event *evt);

	enum
	{
		EVT_TIME_ABSOLUTE,
		EVT_TIME_DELTA,
		EVT_TIME_DELTA_TEST
	};
	enum
	{
		EVT_THREAD_ID=0,
		EVT_THREAD_ID_KEY,
		EVT_THREAD_ID_FULL_NAME,
		EVT_THREAD_ID_CROP_NAME
	};
 protected:
	int m_display_time_kind;
	bool m_display_time;	
	uint64_t m_start_time;
	int m_time_width;

	bool m_display_key;
	int m_key_width;

	bool m_display_ts;
	int m_ts_width;

	bool m_display_thread_id;
	int m_thread_id_width[4];
	int m_display_thread_id_kind;
};

}

#endif

