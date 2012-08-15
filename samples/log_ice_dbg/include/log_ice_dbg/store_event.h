#ifndef __STORE_EVENT_H__
#define __STORE_EVENT_H__

#include <vector>
#include "logger/event.h"

class store_event
{
 public:
	store_event();
	virtual ~store_event();

	int64_t GetIDNextEvt();

 protected:
	struct __up_sdl_event_id
	{
		
		int m_index;
	};
	std::vector<logger::event *> m_events;
	std::vector<__up_sdl_event_id> m_up_sdl_events;
	std::vector<__up_sdl_event_id> m_up_sdl_evt_structs;
};

#endif
