#include "upremdbg/store_event.h"


store_event::store_event()
{
}

store_event::~store_event()
{
	int index;

	for (index=0;index<m_events.size();index++)
	{
		if (m_events.at(index)!=NULL)
			delete m_events.at(index);
	}
}

void store_event::AddEvent(up_sdl::up_sdl_event *evt)
{
	__up_sdl_event_id evt_id;
	up_sdl::up_sdl_event *evt_;

	if (evt==NULL)
		return;

	evt_=evt->CloneT();
	evt_id.m_index=m_events.size();
	evt_id.m_evt=evt_;
	m_events.push_back(evt_);
	m_up_sdl_events.push_back(evt_id);

	if (evt_->GetSubType()==up_sdl::up_sdl_event::SDL_STRUCT)
		m_up_sdl_evt_structs.push_back(evt_id);

}

int64_t store_event::GetIDNextEvt()
{
	return m_up_sdl_evt_structs.size();
}

