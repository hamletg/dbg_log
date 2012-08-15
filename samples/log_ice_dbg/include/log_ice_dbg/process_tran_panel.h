/*!
 * \file log_ice_dbg/process_tran_panel.h
 * \brief Defines the panel showing the transitions of a SDL processes
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

#ifndef __PROCESS_TRAN_PANEL_H__
#define __PROCESS_TRAN_PANEL_H__

//#include "wxconf_test01/wxconf_test01_defs.h"
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/radiobox.h>
#include <wx/checkbox.h>
#include <wx/choice.h>
#include <wx/grid.h>

#include "logmod/event.h"

//#include <wx/statbox.h>
//#include <wx/stattext.h>
//#include <wx/dcclient.h>
//#include <wx/splitter.h>
#include <map>

#include "log_ice_dbg/event_grid_table.h"

class process_tran_panel : public wxPanel
{
 public:
	process_tran_panel(wxWindow* parent, wxWindowID id = -1,const wxString& name = wxT(""),const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxTAB_TRAVERSAL);
    virtual ~process_tran_panel();

	void OnDisplayTranChanged(wxCommandEvent &evt);
	
	void UpdateDisplayState(int state);
	void SetProcess(log_sqlite::sdl_process *proc);
	void SetGridTable(event_grid_table *grid_table);

	void BuildGrid();

	enum
	{
		DISP_NONE=0,
		DISP_ALL,
		DISP_FILTER,
		DISP_HIGHLIGHT
	};
 protected:	
	int m_display_state;
    wxSizer *m_main_sizer;
	wxRadioBox *m_disp_tran;
	wxStaticBoxSizer *m_static_box;
	wxFlexGridSizer *m_filter_sizer;
	wxCheckBox *m_in_sigs_chk;
	wxChoice *m_in_sigs_choice;
	wxGrid *m_evt_grid;
	log_sqlite::sdl_process *m_proc;
	event_grid_table *m_grid_table;
	wxGridCellAttr *m_ts_col;
	wxGridCellAttr *m_time_col;
	//wxTreeCtrl *m_process_tree;
	//wxTextCtrl *m_text;
	//_map_tree_item m_map_tree_items;
 private:
	DECLARE_EVENT_TABLE()
};

#endif
