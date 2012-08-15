/*!
 * \file log_ice_dbg/enable_sqlite_dlg.h
 * \brief Defines the dialog box to setup the SQLite DDB
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

#ifndef __ENABLE_SQLITE_DLG_H__
#define __ENABLE_SQLITE_DLG_H__

#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/textctrl.h>
#include <wx/checkbox.h>

class enable_sqlite_dlg: public wxDialog
{
 public:
	enable_sqlite_dlg(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE);
	virtual ~enable_sqlite_dlg();

	wxString &GetFileName();
	bool IsInMemory();

 protected:
	wxSizer *m_main_sizer;	
	wxTextCtrl *m_db_filename;
	wxCheckBox *m_db_in_mem;
	wxString m_file_name;
	bool m_in_mem;
};


#endif

