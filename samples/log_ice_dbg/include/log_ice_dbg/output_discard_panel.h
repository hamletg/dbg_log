/*!
 * \file log_ice_dbg/output_discard_panel.h
 * \brief Defines the panel showing output SDL message which were discarded
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

#ifndef __OUTPUT_DISCARD_PANEL_H__
#define __OUTPUT_DISCARD_PANEL_H__

#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/grid.h>

//#include "unipro_sdl/up_sdl_event.h"

class output_discard_panel: public wxPanel
{
 public:
	output_discard_panel(wxWindow* parent, wxWindowID id = -1,const wxString& name = wxT(""),const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxTAB_TRAVERSAL);
	virtual ~output_discard_panel();

	//void AddEvent(up_sdl::up_sdl_event *evt);

 protected:
	wxSizer *m_main_sizer;
	wxSizer *m_grid_sizer;
	wxGrid *m_evt_grid;
 private:
	DECLARE_EVENT_TABLE()
};

#endif

