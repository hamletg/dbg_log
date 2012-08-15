/*!
 * \file log_ice_dbg/process_tran_panel.cpp
 * \brief Declares the panel showing the transitions of a process
 *
 * \cond
 *__legal_b__
 *__legal_e__
 * \endcond
 */

//<tags> tester,gui </tags>

#include <wx/log.h>
#include "log_ice_dbg/process_tran_panel.h"
#include "log_ice_dbg/appdata.h"
#include "log_ice_dbg/sqlitectrli.h"
#include "logmod/event_type.h"


BEGIN_EVENT_TABLE(process_tran_panel, wxPanel)	
	//EVT_PAINT(proto_panel::OnPaint)
	//EVT_TREE_SEL_CHANGED(-1, process_tran_panel::OnTreeSelChanged)
	EVT_RADIOBOX(-1, process_tran_panel::OnDisplayTranChanged)
END_EVENT_TABLE()

const wxString g_radio_disp_tran[]=
{
	"None",
	"All",
	"Filter",
	"Highlight"
};

process_tran_panel::process_tran_panel(wxWindow* parent, wxWindowID id,const wxString& name,const wxPoint& pos, const wxSize& size, long style)
    : wxPanel(parent,id,pos,size,style|wxBORDER_SIMPLE )
	, m_proc(NULL)
{	
	int idx;
	logmod::event_type *evt_type;
	
	m_grid_table=NULL;

    m_main_sizer=new wxBoxSizer(wxVERTICAL);

	m_disp_tran=new wxRadioBox(this,-1,"Display transitions",wxDefaultPosition,wxDefaultSize,4,g_radio_disp_tran);
	m_main_sizer->Add(m_disp_tran,0,wxALL,5);

	m_static_box=new wxStaticBoxSizer(wxVERTICAL,this,"Filters");
	m_main_sizer->Add(m_static_box,0,wxALL,5);

	m_filter_sizer=new wxFlexGridSizer(2);
	m_static_box->Add(m_filter_sizer);
	
	

	m_in_sigs_chk=new wxCheckBox(this,-1,"Input Signals");
	m_filter_sizer->Add(m_in_sigs_chk);

	m_in_sigs_choice=new wxChoice(this,-1,wxDefaultPosition,wxDefaultSize,0);
	m_filter_sizer->Add(m_in_sigs_choice);

	m_evt_grid=new wxGrid(this,-1);
	//m_evt_grid->SetTable(m_grid_table/*,true*/);

	m_time_col=new wxGridCellAttr();
	m_time_col->SetAlignment(wxALIGN_RIGHT,wxALIGN_CENTRE);
	m_time_col->IncRef();
	//m_evt_grid->SetColAttr(0,m_time_col);

	m_ts_col=new wxGridCellAttr();
	m_ts_col->SetAlignment(wxALIGN_RIGHT,wxALIGN_CENTRE);
	m_ts_col->IncRef();
	//m_evt_grid->SetColAttr(1,m_ts_col);	

	m_main_sizer->Add(m_evt_grid,1,wxALL | wxEXPAND,5);

    SetSizer(m_main_sizer);
    m_main_sizer->SetSizeHints(this);
	//SetBackgroundColour(*wxWHITE);

	UpdateDisplayState(DISP_NONE);
}

process_tran_panel::~process_tran_panel()
{
	m_time_col->DecRef();
	m_ts_col->DecRef();
	/*if (m_grid_table!=NULL)
	{
		delete m_grid_table;
		m_grid_table=NULL;
	}*/
}

void process_tran_panel::SetGridTable(event_grid_table *grid_table)
{
	m_grid_table=grid_table;
	m_evt_grid->SetTable(m_grid_table/*,true*/);
}

void process_tran_panel::OnDisplayTranChanged(wxCommandEvent &evt)
{
	UpdateDisplayState(m_disp_tran->GetSelection());
}

void process_tran_panel::UpdateDisplayState(int state)
{
	m_display_state=state;

	switch (m_display_state)
	{
		case DISP_NONE:
		case DISP_ALL:
			m_in_sigs_chk->Disable();
			m_in_sigs_choice->Disable();
			break;
		case DISP_FILTER:
		case DISP_HIGHLIGHT:
			m_in_sigs_chk->Enable();
			m_in_sigs_choice->Enable();
			break;
	}
}

void process_tran_panel::BuildGrid()
{

}

void process_tran_panel::SetProcess(log_sqlite::sdl_process *proc)
{
	m_proc=proc;
	if (proc==NULL)
		return;

    m_grid_table->SetProcess(proc);	
	m_evt_grid->SetTable(m_grid_table/*,true*/);
	m_time_col->IncRef();
	m_evt_grid->SetColAttr(0,m_time_col);
	m_ts_col->IncRef();
	m_evt_grid->SetColAttr(1,m_ts_col);	
	m_evt_grid->ForceRefresh();

	//m_evt_grid->Freeze();
	m_evt_grid->AutoSize();
	//m_evt_grid->Thaw();
}



