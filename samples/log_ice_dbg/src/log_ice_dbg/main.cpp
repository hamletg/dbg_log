#include "log_ice_dbg/log_ice_dbg_prec.h"
 
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

// ----------------------------------------------------------------------------
// resources
// ----------------------------------------------------------------------------

// the application icon (under Windows and OS/2 it is in resources and even
// though we could still include the XPM here it would be unused)
#if !defined(__WXMSW__) && !defined(__WXPM__)
    #include "../../res/log_ice_dbg.xpm"
#endif

#include <wx/sizer.h>
#include <wx/filedlg.h>

#include "log_ice_dbg/myframe.h"
#include "log_ice_dbg/appdata.h"
#include "log_ice_dbg/server.h"
#include "log_ice_dbg/sqlitectrli.h"
#include "log_ice_dbg/nbr_event_panel.h"
#include "log_ice_dbg/output_discard_panel.h"
#include "log_ice_dbg/enable_sqlite_dlg.h"
#include "wx/textdlg.h"

#include "log_ice_dbg/myapp.h"

// ----------------------------------------------------------------------------
// private classes
// ----------------------------------------------------------------------------

// Define a new application type, each program should derive a class from wxApp


// Define a new frame type: this is going to be our main frame


// ----------------------------------------------------------------------------
// constants
// ----------------------------------------------------------------------------

// IDs for the controls and the menu commands
enum
{
    // menu items
    Minimal_Quit = wxID_EXIT,

    // it is important for the id corresponding to the "About" command to have
    // this standard value as otherwise it won't be handled properly under Mac
    // (where it is special and put into the "Apple" menu)
    Minimal_About = wxID_ABOUT,
    ENABLE_SQLITE = wxID_HIGHEST+1,
	CLOSE_SQLITE,
	LOAD_SQLITE
};

// ----------------------------------------------------------------------------
// event tables and other macros for wxWidgets
// ----------------------------------------------------------------------------

// the event tables connect the wxWidgets events with the functions (event
// handlers) which process them. It can be also done at run-time, but for the
// simple menu events like this the static method is much simpler.
BEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_MENU(Minimal_Quit,  MyFrame::OnQuit)
    EVT_MENU(Minimal_About, MyFrame::OnAbout)
    EVT_MENU(ENABLE_SQLITE, MyFrame::OnEnableSQLite)
	EVT_MENU(CLOSE_SQLITE, MyFrame::OnCloseSQLite)
	EVT_MENU(LOAD_SQLITE, MyFrame::OnLoadDatabase)
END_EVENT_TABLE()

// Create a new application object: this macro will allow wxWidgets to create
// the application object during program execution (it's better than using a
// static object for many reasons) and also implements the accessor function
// wxGetApp() which will return the reference of the right type (i.e. MyApp and
// not wxApp)
IMPLEMENT_APP(MyApp)

// ============================================================================
// implementation
// ============================================================================

// ----------------------------------------------------------------------------
// the application class
// ----------------------------------------------------------------------------

MyApp::MyApp():wxApp(),m_port(10999)
{
}

// 'Main program' equivalent: the program execution "starts" here
bool MyApp::OnInit()
{
    // call the base class initialization method, currently it only parses a
    // few common command-line options but it could be do more in the future
    if ( !wxApp::OnInit() )
        return false;

    // create the main application window
    MyFrame *frame = new MyFrame(_T("Log ICE Dbg"));

	appdata::Get()->SetFrame(frame);
    // and show it (the frames, unlike simple controls, are not shown when
    // created initially)
    frame->Show(true);

    // success: wxApp::OnRun() will be called which will enter the main message
    // loop and the application will run. If we returned false here, the
    // application would exit immediately.
    return true;
}

void MyApp::OnInitCmdLine(wxCmdLineParser & parser)
{
	wxApp::OnInitCmdLine(parser);

	parser.AddOption("p","port","listen on given port (default 10000)",wxCMD_LINE_VAL_NUMBER);
}

bool MyApp::OnCmdLineParsed(wxCmdLineParser& parser)
{
	long port;
    
	if (parser.Found("p", &port))
    {
        if ( port <= 0 || port > USHRT_MAX )
        {
            wxLogError("Invalid port number %ld, must be in 0..%u range.", port, USHRT_MAX);
            return false;
        }

        m_port = static_cast<unsigned short>(port);
        //wxLogMessage("Will connect to ClientDaemon on port %u", m_port);
    }
	return wxApp::OnCmdLineParsed(parser);
}

// ----------------------------------------------------------------------------
// main frame
// ----------------------------------------------------------------------------

// frame constructor
MyFrame::MyFrame(const wxString& title)
       : wxFrame(NULL, wxID_ANY, title)
{
    // set the frame icon
    SetIcon(wxICON(log_ice_dbg));

#if wxUSE_MENUS
    // create a menu bar
    wxMenu *fileMenu = new wxMenu;

    // the "About" item should be in the help menu
    wxMenu *helpMenu = new wxMenu;
    helpMenu->Append(Minimal_About, _T("&About...\tF1"), _T("Show about dialog"));

    fileMenu->Append(Minimal_Quit, _T("E&xit\tAlt-X"), _T("Quit this program"));
    m_dbMenu = new wxMenu;
	m_dbMenu->Append(LOAD_SQLITE, _T("&Load Database ...\tAlt-C"), _T("Load Database")); 
    m_dbMenu->AppendCheckItem(ENABLE_SQLITE, _T("&Enable ...\tAlt-E"), _T("Enable SQLLite"));
	m_dbMenu->Append(CLOSE_SQLITE, _T("&Close\tAlt-C"), _T("Close SQLLite"));
	m_dbMenu->Enable(CLOSE_SQLITE,false);
    // now append the freshly created menu to the menu bar...
    m_menuBar = new wxMenuBar();
    m_menuBar->Append(fileMenu, _T("&File"));
    m_menuBar->Append(m_dbMenu, _T("&SQLite"));
    m_menuBar->Append(helpMenu, _T("&Help"));

    // ... and attach this menu bar to the frame
    SetMenuBar(m_menuBar);
#endif // wxUSE_MENUS

#if wxUSE_STATUSBAR
    // create a status bar just for fun (by default with 1 pane only)
    CreateStatusBar(2);
    SetStatusText(_T("Welcome to the UniPro Remote Logger!"));
#endif // wxUSE_STATUSBAR

	 m_main_sizer=new wxBoxSizer(wxHORIZONTAL);

	m_treebook=new wxTreebook(this,-1,wxDefaultPosition, wxDefaultSize,wxNB_LEFT);
	m_treebook->SetMinSize(wxSize(600,600));
	m_main_sizer->Add(m_treebook,1,wxEXPAND);

    m_text=new wxTextCtrl(m_treebook,-1,"",wxDefaultPosition,wxSize(800,600),wxTE_MULTILINE);
	m_treebook->AddPage(m_text,"Events Text");

	/*m_process_tree_panel=new process_tree_panel(m_treebook,-1,"",wxDefaultPosition,wxSize(800,600),wxTE_MULTILINE);
	m_treebook->AddPage(m_process_tree_panel,"SDL Processes Tree");

	appdata::Get()->SetProcessPanel(m_process_tree_panel);

	m_output_discard_panel=new output_discard_panel(m_treebook,-1,wxT(""),wxDefaultPosition,wxSize(200,600));
	m_treebook->AddPage(m_output_discard_panel,"Discarded ouputs"); 

	appdata::Get()->SetOutputDiscardPanel(m_output_discard_panel); */

	m_nbr_event_panel=new nbr_event_panel(this,-1,"",wxDefaultPosition,wxSize(200,600));
	m_nbr_event_panel->SetMinSize(wxSize(200,600));
	m_main_sizer->Add(m_nbr_event_panel);
	m_main_sizer->SetItemMinSize(m_nbr_event_panel,200,600);
	m_main_sizer->FitInside(m_nbr_event_panel);
	
    m_server=new server(m_text);
	if (m_server->m_status==0)
	{
		wxString str;

		str.Printf("Listening on port %i\n",wxGetApp().m_port);
		m_text->AppendText(str);
	}
	else
		m_text->AppendText("ERROR: couldn't create the server.\n");

    //m_server->m_text=m_text;
    m_sqlite_ctrl=m_server->GetSQLiteCtrl();
	appdata::Get()->SetSQLite(m_sqlite_ctrl);

    m_server->Create();
    m_server->Run();

	SetSizer(m_main_sizer);
    m_main_sizer->SetSizeHints(this);
}


// event handlers

void MyFrame::OnQuit(wxCommandEvent& WXUNUSED(event))
{
    // true is to force the frame to close
    Close(true);
}

void MyFrame::OnLoadDatabase(wxCommandEvent& WXUNUSED(event))
{
	wxFileDialog *dlg;
	int result;
	wxString file_name;

	dlg=new wxFileDialog(this, "Choose the Database file", /*defaultDir =*/ "", /*const wxString& defaultFile =*/ "", /*const wxString& wildcard =*/ "*.db", wxFD_DEFAULT_STYLE);
	result=dlg->ShowModal();

	if (result!=wxID_OK)
		return;

	file_name=dlg->GetPath();
	
	m_sqlite_ctrl->Open(file_name);

	//m_process_tree_panel->LoadedDB(m_sqlite_ctrl->GetDB());

	delete dlg;
}

void MyFrame::OnEnableSQLite(wxCommandEvent& WXUNUSED(event))
{
    wxString str;

    if (m_menuBar->IsChecked(ENABLE_SQLITE))
    {
        if (m_sqlite_ctrl->m_sqlite_log==NULL)
        {
			enable_sqlite_dlg dlg(this,-1,"Enable SQLite Database");
			int result;
			
			result=dlg.ShowModal();
			if (result==wxID_OK)
			{
				m_sqlite_ctrl->SetDbName(dlg.GetFileName().GetData().AsChar(),dlg.IsInMemory());
				m_dbMenu->Enable(CLOSE_SQLITE,true);
				m_dbMenu->Enable(ENABLE_SQLITE,false);
				//str=wxGetTextFromUser("What's the name of the SQLite database to create?","Database name","db01.db",NULL);
				//m_sqlite_ctrl->SetDbName(str.c_str());
			}
        }
    }
    else
    {
    }
}

void MyFrame::OnCloseSQLite(wxCommandEvent& event)
{
	m_dbMenu->Enable(CLOSE_SQLITE,false);
	m_dbMenu->Enable(ENABLE_SQLITE,true);

}

void MyFrame::OnAbout(wxCommandEvent& WXUNUSED(event))
{
    wxMessageBox(wxString::Format(
                    _T("Remote Log Dbg\n")
					_T("using %s\n")
                    _T("running under %s."),
                    wxVERSION_STRING,
                    wxGetOsDescription().c_str()
                 ),
                 _T("About Remote Dbg"),
                 wxOK | wxICON_INFORMATION,
                 this);
}
