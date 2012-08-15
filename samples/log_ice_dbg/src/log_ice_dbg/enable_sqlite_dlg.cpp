/*!
 * \file log_ice_dbg/enable_sqlite_dlg.cpp
 * \brief Declares the dialog box to setup the SQLite DDB
 *
 * \cond
 *__legal_b__
 *__legal_e__
 * \endcond
 */
#include "log_ice_dbg/log_ice_dbg_prec.h"
#include "log_ice_dbg/enable_sqlite_dlg.h"

#include <wx/stattext.h>

enable_sqlite_dlg::enable_sqlite_dlg(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style)
	: wxDialog(parent,id,title,pos,size,style)
{
	m_main_sizer=new wxBoxSizer(wxVERTICAL);

	m_main_sizer->Add(new wxStaticText(this,-1,wxT("Database File Name:")),0,wxRIGHT|wxLEFT|wxTOP,5);
	m_db_filename=new wxTextCtrl(this,-1,wxT("db01.db"));
	m_main_sizer->Add(m_db_filename,0,wxALL,5);
	m_db_in_mem=new wxCheckBox(this,-1,"In memory");
	m_main_sizer->Add(m_db_in_mem,0,wxALL,5);

	m_main_sizer->Add(CreateStdDialogButtonSizer(wxOK | wxCANCEL),0,wxALL,5);

	SetSizer(m_main_sizer);
    m_main_sizer->SetSizeHints(this);

}

enable_sqlite_dlg::~enable_sqlite_dlg()
{
}

wxString &enable_sqlite_dlg::GetFileName()
{
	m_file_name=m_db_filename->GetValue();
	return m_file_name;
}

bool enable_sqlite_dlg::IsInMemory()
{
	return m_db_in_mem->IsChecked();
}
 



