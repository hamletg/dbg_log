#include "log_ice_dbg/log_ice_dbg_prec.h"
#include "log_ice_dbg/appdata.h"
#include "log_ice_dbg/myframe.h"
#include "log_ice_dbg/output_discard_panel.h"

appdata::appdata():m_frame(NULL),m_sqlite(NULL)
{
	int idx;

	m_nbr_counters=logmod::event_type::GetCount();
	m_event_counters=new int[m_nbr_counters];

	for (idx=0;idx<m_nbr_counters;idx++)
		m_event_counters[idx]=0;
}

appdata::~appdata()
{
	if (m_event_counters!=NULL)
		delete m_event_counters;
}

void appdata::SetFrame(MyFrame *f)
{
	m_frame=f;
}

void appdata::NewEvent(logmod::event_type *evt_type)
{
	uint32_t id;
	
	id=evt_type->GetId();

	if (id>=m_nbr_counters)
		return;
	m_event_counters[id]++;
	m_frame->m_nbr_event_panel->SetCount(id,m_event_counters[id]);
}

logmod::event_utils *appdata::GetEventUtils()
{
	return &m_evt_utils;
}

/*store_event *appdata::GetStoreEvent()
{
	return &m_store_event;
}

void appdata::SetProcessPanel(process_tree_panel *panel)
{
	m_process_panel=panel;
}

process_tree_panel *appdata::GetProcessPanel()
{
	return m_process_panel;
}

void appdata::SetOutputDiscardPanel(output_discard_panel *panel)
{
	m_output_discard_panel=panel;
}

output_discard_panel *appdata::GetOutputDiscardPanel()
{
	return m_output_discard_panel;
} */

void appdata::SetSQLite(sqlitectrlI *sqlite)
{
	m_sqlite=sqlite;
}

sqlitectrlI *appdata::GetSQLite()
{
	return m_sqlite;
}

/*event_grid_table *appdata::GetEvtGridTable()
{
	return &m_evt_grid_table;
}*/

void appdata::wxPrint(const char *txt)
{
	wxString str(txt,wxConvUTF8);
	
	wxMutexGuiEnter();

	m_frame->m_text->AppendText(str);
	m_frame->m_text->AppendText("\n");

	wxMutexGuiLeave();

}

appdata *appdata::Get()
{
	return &m_app_data;
}

appdata appdata::m_app_data;
	
