/*!
 * \file log_ice_dbg/nbr_event_panel.h
 * \brief Defines the panel showing the number of events received
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

#ifndef __NBR_EVENT_PANEL_H__
#define __NBR_EVENT_PANEL_H__

//#include "wxconf_test01/wxconf_test01_defs.h"
#include "logmod/event.h"

#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/dcclient.h>
#include <wx/grid.h>

class nbr_event_panel : public wxPanel
{
 public:
	nbr_event_panel(wxWindow* parent, wxWindowID id = -1,const wxString& name = wxT(""),const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxTAB_TRAVERSAL);
    virtual ~nbr_event_panel();
	
	void ResetCounts();
	void SetCount(int idx,int count);
 protected:
    wxSizer *m_main_sizer;
	wxGrid *m_event_grid;
	int m_num_rows;
 private:
	DECLARE_EVENT_TABLE()
};

#endif
