/*!
 * \file log_ice_dbg/output_discard_panel.cpp
 * \brief Declares the panel showing output SDL message which were discarded
 *
 * \cond
 *__legal_b__
 *__legal_e__
 * \endcond
 */

#include "log_ice_dbg/output_discard_panel.h"
#include "log_ice_dbg/appdata.h"
#include "log_ice_dbg/sqlitectrli.h"
#include "logmod/event_type.h"


BEGIN_EVENT_TABLE(output_discard_panel, wxPanel)	
	//EVT_PAINT(proto_panel::OnPaint)
	//EVT_TREE_SEL_CHANGED(-1, process_tran_panel::OnTreeSelChanged)
	//EVT_RADIOBOX(-1, process_tran_panel::OnDisplayTranChanged)
END_EVENT_TABLE()

output_discard_panel::output_discard_panel(wxWindow* parent, wxWindowID id,const wxString& name,const wxPoint& pos, const wxSize& size, long style)
	: wxPanel(parent,id,pos,size,style|wxBORDER_SIMPLE )
{
	m_main_sizer=new wxBoxSizer(wxVERTICAL);

	m_grid_sizer=new wxBoxSizer(wxHORIZONTAL);
	m_main_sizer->Add(m_grid_sizer,1,wxEXPAND /*| wxALIGN_TOP */,5);

	m_evt_grid=new wxGrid(this,-1);
	m_evt_grid->AutoSize();
	m_grid_sizer->Add(m_evt_grid,1,wxALL | wxEXPAND /*| wxALIGN_LEFT*/,5);
	m_evt_grid->CreateGrid(0, 8, wxGrid::wxGridSelectCells);
	m_evt_grid->SetColLabelValue(0,"Time");
	m_evt_grid->SetColLabelValue(1,"TimeStamp");
	m_evt_grid->SetColLabelValue(2,"Process");
	m_evt_grid->SetColLabelValue(3,"State");
	m_evt_grid->SetColLabelValue(4,"Input");
	m_evt_grid->SetColLabelValue(5,"NextState");
	m_evt_grid->SetColLabelValue(6,"Output");
	m_evt_grid->SetColLabelValue(7,"Process fullname");

	SetSizer(m_main_sizer);
    m_main_sizer->SetSizeHints(this);
}

output_discard_panel::~output_discard_panel()
{
}

void output_discard_panel::AddEvent(up_sdl::up_sdl_event *evt)
{
	int row;
	wxString str;
	int64_t tran_key;

	log_sqlite::sdl_process *process;
	up_sdl::up_sdl_event tran_evt;

	process=appdata::Get()->GetSQLite()->GetDB()->GetSDLProcess(evt->GetSenderKey());
	tran_key=evt->GetTransitionKey();
	if (tran_key!=-1)
		appdata::Get()->GetSQLite()->GetDB()->GetSDLTransition(tran_key,&tran_evt);
	
	row=m_evt_grid->GetNumberRows();

	m_evt_grid->AppendRows();
	str.Printf(wxT("%I64u ms"),evt->GetTime());
	m_evt_grid->SetCellValue(row,0,str);

	str.Printf(wxT("%I64u ns"),evt->GetTS());
	m_evt_grid->SetCellValue(row,1,str);

	str.Printf(wxT("%s"),process->GetName());
	m_evt_grid->SetCellValue(row,2,str);

	if (tran_key!=-1)
		process->GetStateNameByStructRef(str,tran_evt.GetStartState());	
	else
		str=wxT("ERROR");
	m_evt_grid->SetCellValue(row,3,str);

	if (tran_key!=-1)
		process->GetSignalNameByStructRef(str,tran_evt.GetSignalKey());	
	else
		process->GetSignalNameByStructRef(str,evt->GetSignalKey());	
	m_evt_grid->SetCellValue(row,4,str);

	if (tran_key!=-1)
		process->GetStateNameByStructRef(str,tran_evt.GetNextState());	
	else
		str=wxT("ERROR");
	m_evt_grid->SetCellValue(row,5,str);

	process->GetSignalNameByStructRef(str,evt->GetSignalKey());	
	m_evt_grid->SetCellValue(row,6,str);

	str.Printf(wxT("%s"),process->GetFullName());
	m_evt_grid->SetCellValue(row,7,str);

	m_evt_grid->Freeze();
	m_evt_grid->AutoSize();
	m_evt_grid->Thaw();
}


