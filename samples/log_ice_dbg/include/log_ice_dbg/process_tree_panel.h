/*!
 * \file log_ice_dbg/process_tree_panel.h
 * \brief Defines the panel showing the tree of SDL processes
 *
 * \cond
 *       MIPI/UniPro simulation
 *
 *__legal_b__
 *
 * The following code is derived, directly or indirectly, from the MIPI UniPro
 * source code Copyright (c) 2004-2005 by all Contributors.
 * All Rights reserved.
 *
 * The contents of this file are subject to the restrictions and limitations
 * set forth by the MIPI alliance http://www.mipi.org/;
 * You may not use this file except in compliance with such restrictions and
 * limitations. Software distributed by Contributors
 * is distributed on an "AS IS" basis, WITHOUT WARRANTY OF
 * ANY KIND, either express or implied.
 *
 *__legal_e__
 * \endcond
 */

#ifndef __PROCESS_TREE_PANEL_H__
#define __PROCESS_TREE_PANEL_H__

//#include "wxconf_test01/wxconf_test01_defs.h"
#include "logmod/event.h"

#include <wx/panel.h>
#include <wx/sizer.h>
//#include <wx/stattext.h>
//#include <wx/dcclient.h>
#include <wx/splitter.h>
#include <wx/treectrl.h>
#include <map>

#include "log_ice_dbg/process_tran_panel.h"
#include "log_sqlite/db_file.h"

class process_tree_panel_itemdata : public wxTreeItemData
{
 public:
	process_tree_panel_itemdata();
	virtual ~process_tree_panel_itemdata();

	void SetKey(int64_t key);
	int64_t GetKey();

	void SetSDLProcess(log_sqlite::sdl_process *proc);
	log_sqlite::sdl_process *GetSDLProcess();

	void SetEventID(int64_t event_id);
	int64_t GetEventID();

 protected:
	int64_t m_key;
	int64_t m_event_id;
	log_sqlite::sdl_process *m_process;

};

class process_tree_panel : public wxPanel
{
 public:
	process_tree_panel(wxWindow* parent, wxWindowID id = -1,const wxString& name = wxT(""),const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxTAB_TRAVERSAL);
    virtual ~process_tree_panel();
	
	void OnTreeSelChanged(wxTreeEvent &event);

	//void AddSDLProcess(up_sdl::up_sdl_event *evt,int64_t event_id=-1);
	void LoadedDB(log_sqlite::db_file *db);
 protected:
	typedef std::map<std::string,wxTreeItemId> _map_tree_item;
    typedef std::pair<std::string,wxTreeItemId> _entry_tree_item;
    typedef std::map<std::string,wxTreeItemId>::iterator _iter_tree_item;

    wxSizer *m_main_sizer;
	wxSplitterWindow *m_splitwin;
	wxTreeCtrl *m_process_tree;
	//wxTextCtrl *m_text;
	process_tran_panel *m_tran_panel;
	_map_tree_item m_map_tree_items;
	event_grid_table *m_grid_table;
 private:
	DECLARE_EVENT_TABLE()
};

#endif
