/*!
 * \file log_ice_dbg/event_grid_table.cpp
 * \brief Defines the 
 *
 * \cond
 *__legal_b__
 *__legal_e__
 * \endcond
 */
#include "log_ice_dbg/log_ice_dbg_prec.h"
#include "log_ice_dbg/event_grid_table.h"
#include "log_sqlite/db_file.h"

event_grid_table::event_grid_table()
	: wxGridTableBase()
	//, m_proc(NULL)
	, m_nbr_rows(0)
	, m_nbr_cols(5)
{
}

event_grid_table::~event_grid_table()
{
}

int event_grid_table::GetNumberRows()
{
	return m_nbr_rows;
}

int event_grid_table::GetNumberCols()
{
	return m_nbr_cols;
}

bool event_grid_table::IsEmptyCell( int row, int col )
{
	if (m_proc==NULL)
		return true;
	return false;
}

wxString event_grid_table::GetValue( int row, int col )
{
	log_sqlite::db_file *db;
	up_sdl::up_sdl_event evt;
	wxString str;
	int64_t key;

	if (m_proc==NULL)
		return wxString(wxT("ERROR"));

	if ((row<0) || (col<0))
		return wxT("");
	if ((row>m_nbr_rows) || (col>m_nbr_cols))
		return wxT("");

	db=m_proc->GetDB();
	db->GetSDLEvent(&evt,row);

	switch (col)
	{
		case 0:
			str.Printf("%I64u ms",evt.GetTime());			
			break;
		case 1:
			str.Printf("%I64u ns",evt.GetTS());			
			break;
		case 2:	//State
			key=evt.GetStartState();
			if (key==0)
				return wxT("start state");
			m_proc->GetStateNameByStructRef(str,key);
			break;
		case 3: //Signal
			key=evt.GetSignalKey();
			m_proc->GetSignalNameByStructRef(str,key);
			break;
		case 4: // NextState
			key=evt.GetNextState();
			m_proc->GetStateNameByStructRef(str,key);
			break;

	}
	return str;
}

void event_grid_table::SetValue( int row, int col, const wxString& value )
{
}

void event_grid_table::SetProcess(log_sqlite::sdl_process *proc)
{
	log_sqlite::db_file *db;
	int result;

	m_proc=proc;

	if (proc==NULL)
		return;

	db=m_proc->GetDB();

	result=db->SelectSDLTran(proc->GetSDLStructKey());
	if (result<0)
	{
		m_nbr_rows=0;
		m_nbr_cols=0;
		return;
	}
	m_nbr_rows=result;
	//m_nbr_cols=??
	
}