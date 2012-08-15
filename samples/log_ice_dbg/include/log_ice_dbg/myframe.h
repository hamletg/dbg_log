#ifndef __MY_FRAME_H__
#define __MY_FRAME_H__

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"
 
#ifdef __BORLANDC__
    #pragma hdrstop
#endif

// for all others, include the necessary headers (this file is usually all you
// need because it includes almost all "standard" wxWidgets headers)
#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

#include <wx/sizer.h>
#include <wx/treebook.h>
#include <wx/menu.h>

#include "log_ice_dbg/server.h"
#include "log_ice_dbg/sqlitectrli.h"
#include "log_ice_dbg/nbr_event_panel.h"
#include "log_ice_dbg/process_tree_panel.h"
#include "log_ice_dbg/output_discard_panel.h"
#include "wx/textdlg.h"

class MyFrame : public wxFrame
{
public:
    // ctor(s)
    MyFrame(const wxString& title);

    // event handlers (these functions should _not_ be virtual)
    void OnQuit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnEnableSQLite(wxCommandEvent& event);
	void OnCloseSQLite(wxCommandEvent& event);
	void OnLoadDatabase(wxCommandEvent& event);

	wxTreebook *m_treebook;

    wxTextCtrl *m_text;
    server *m_server;
    sqlitectrlI *m_sqlite_ctrl;
    wxMenuBar *m_menuBar;
	nbr_event_panel *m_nbr_event_panel;
	//process_tree_panel *m_process_tree_panel;
	//output_discard_panel *m_output_discard_panel;
	wxSizer *m_main_sizer;
	wxMenu *m_dbMenu;
private:
    // any class wishing to process wxWidgets events must use this macro
    DECLARE_EVENT_TABLE()
};

#endif
