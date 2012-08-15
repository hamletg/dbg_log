/*!
 * \file log_ice_dbg/nbr_event_panel.cpp
 * \brief Declares the panel showing the number of events received
 *
 * \cond
 *__legal_b__
 *__legal_e__
 * \endcond
 */

//<tags> tester,gui </tags>
#include "log_ice_dbg/log_ice_dbg_prec.h"

#include <wx/log.h>
#include "log_ice_dbg/nbr_event_panel.h"
#include "logmod/event_type.h"

BEGIN_EVENT_TABLE(nbr_event_panel, wxPanel)	
	//EVT_PAINT(proto_panel::OnPaint)
END_EVENT_TABLE()

nbr_event_panel::nbr_event_panel(wxWindow* parent, wxWindowID id,const wxString& name,const wxPoint& pos, const wxSize& size, long style)
    :wxPanel(parent,id,pos,size,style|wxBORDER_SIMPLE )
{	
	int idx;
	logmod::event_type *evt_type;

    m_main_sizer=new wxBoxSizer(wxHORIZONTAL);

	m_num_rows=logmod::event_type::GetCount();
	m_event_grid=new wxGrid(this,-1);
	m_event_grid->CreateGrid(m_num_rows,2);
	m_main_sizer->Add(m_event_grid,1,wxEXPAND);
	m_main_sizer->FitInside(m_event_grid);

	m_event_grid->SetColLabelValue(0,"Events");
	m_event_grid->SetColLabelValue(1,"Count");

	evt_type=logmod::event_type::GetFirst();
	
	while (evt_type!=NULL)
	{
		idx=evt_type->GetId();
		m_event_grid->SetCellValue(idx,0,evt_type->GetName());
		
		evt_type=evt_type->GetNext();
	}
	ResetCounts();
	m_event_grid->AutoSizeColumns();
	m_event_grid->SetRowLabelSize(0);
    /*m_ts=new wxStaticText(this,-1,"1234567890123456 ns");
    m_main_sizer->Add(m_ts,0,wxEXPAND|wxALL,5);
    m_type=new wxStaticText(this,-1,"UNK ");
    m_main_sizer->Add(m_type,0,wxEXPAND|wxALL,5);
    m_dir=new wxStaticText(this,-1,"UNK");
    m_main_sizer->Add(m_dir,0,wxEXPAND|wxALL,5); */

    SetSizer(m_main_sizer);
    m_main_sizer->SetSizeHints(this);
	//SetBackgroundColour(*wxWHITE);
}

nbr_event_panel::~nbr_event_panel()
{
}

void nbr_event_panel::ResetCounts()
{
	int idx;

	for (idx=0;idx<m_num_rows;idx++)
		m_event_grid->SetCellValue(idx,1,wxT("0"));
}

void nbr_event_panel::SetCount(int idx,int count)
{
	wxString str;
	bool ismain=wxThread::IsMain();

	if ((idx<0)||(idx>=m_num_rows))
		return;

	if (!ismain) wxMutexGuiEnter();
	str.Printf("%i",count);
	m_event_grid->SetCellValue(idx,1,str);
	if (!ismain) wxMutexGuiLeave();

}

