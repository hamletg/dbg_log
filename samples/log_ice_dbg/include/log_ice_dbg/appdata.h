#ifndef __APPDATA_H__
#define __APPDATA_H__

#include "logmod/event_type.h"
#include "logmod/event_utils.h"

//#include "log_ice_dbg/store_event.h"
//#include "log_ice_dbg/process_tree_panel.h"
#include "log_ice_dbg/event_grid_table.h"


class MyFrame;
class sqlitectrlI;
class output_discard_panel;

class appdata
{
public:
	appdata();
	virtual ~appdata();

	void SetFrame(MyFrame *f);
	void NewEvent(logmod::event_type *evt_type);
	logmod::event_utils *GetEventUtils();

	/*void SetOutputDiscardPanel(output_discard_panel *panel);
	output_discard_panel *GetOutputDiscardPanel(); */

	void SetSQLite(sqlitectrlI *sqlite);
	sqlitectrlI *GetSQLite();

	void wxPrint(const char *txt);

	//event_grid_table *GetEvtGridTable();

	static appdata *Get();
	
protected:
	static appdata m_app_data;
	MyFrame *m_frame;
	//process_tree_panel *m_process_panel;
	//output_discard_panel *m_output_discard_panel;
	int *m_event_counters;
	int m_nbr_counters;
	logmod::event_utils m_evt_utils;
	sqlitectrlI *m_sqlite;
	//event_grid_table m_evt_grid_table;
};

#endif
