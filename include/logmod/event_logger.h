/**
 * \file logmod/event_logger.h
 * \brief Defines the events logger
 *
 * \cond
 *__legal_b__
 *__legal_e__
 * \endcond
 */

#ifndef __LOGGER_EVENT_LOGGER_H__
#define __LOGGER_EVENT_LOGGER_H__

#include "logmod/logmod_defs.h"

#include "logmod/event.h"
#include "logmod/inttypes.h"

#include <string>

namespace logmod
{

class LOGMOD_API event_logger
{
 public:
    event_logger();
    virtual ~event_logger();

    virtual void Send(event *evt)=0;

    void MarkStartTime();
    uint64_t GetStartTime();

	virtual void Enable(bool enable=true);
	bool IsEnabled();

	void LogThreadId(bool enable=true);
    bool IsOk();
    const char *GetError();

 protected:
    void SetOk(bool val);
    void SetError(const char *error);
    uint64_t m_start_time;
	bool m_enabled;
	bool m_log_thread_id;
    bool m_ok;
    std::string m_error;
};

}

#endif

