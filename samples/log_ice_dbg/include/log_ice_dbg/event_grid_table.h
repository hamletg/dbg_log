/*!
 * \file log_ice_dbg/event_grid_table.h
 * \brief Defines the 
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

#ifndef __EVENT_GRID_TABLE_H__
#define __EVENT_GRID_TABLE_H__

#include <wx/grid.h>


class event_grid_table:public wxGridTableBase
{
 public:
	event_grid_table();
	virtual ~event_grid_table();

	virtual int GetNumberRows();
    virtual int GetNumberCols();
    virtual bool IsEmptyCell( int row, int col );
    virtual wxString GetValue( int row, int col );
    virtual void SetValue( int row, int col, const wxString& value );
    
private:
	int m_nbr_rows;
	int m_nbr_cols;
};

#endif