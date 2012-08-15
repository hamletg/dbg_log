/*!
 * \file log_ice_dbg/process_tree_panel.cpp
 * \brief Declares the panel showing the number of events received
 *
 * \cond
 *__legal_b__
 *__legal_e__
 * \endcond
 */

//<tags> tester,gui </tags>

#include <wx/log.h>
#include "log_ice_dbg/process_tree_panel.h"
#include "log_ice_dbg/appdata.h"
#include "log_ice_dbg/sqlitectrli.h"
#include "logmod/event_type.h"

process_tree_panel_itemdata::process_tree_panel_itemdata():wxTreeItemData()
{
	m_key=0;
	m_process=NULL;
	m_event_id=-1;
}

process_tree_panel_itemdata::~process_tree_panel_itemdata()
{
	if (m_process!=NULL)
		delete m_process;
}

void process_tree_panel_itemdata::SetKey(int64_t key)
{
	m_key=key;
}

int64_t process_tree_panel_itemdata::GetKey()
{
	return m_key;
}

void process_tree_panel_itemdata::SetSDLProcess(log_sqlite::sdl_process *proc)
{
	m_process=proc;
}

void process_tree_panel_itemdata::SetEventID(int64_t event_id)
{
	m_event_id=event_id;
}

int64_t process_tree_panel_itemdata::GetEventID()
{
	return m_event_id;
}

log_sqlite::sdl_process *process_tree_panel_itemdata::GetSDLProcess()
{
	return m_process;
}

BEGIN_EVENT_TABLE(process_tree_panel, wxPanel)	
	//EVT_PAINT(proto_panel::OnPaint)
	EVT_TREE_SEL_CHANGED(-1, process_tree_panel::OnTreeSelChanged)
END_EVENT_TABLE()

process_tree_panel::process_tree_panel(wxWindow* parent, wxWindowID id,const wxString& name,const wxPoint& pos, const wxSize& size, long style)
    :wxPanel(parent,id,pos,size,style|wxBORDER_SIMPLE )
{	
	int idx;
	logmod::event_type *evt_type;
	
	m_grid_table=appdata::Get()->GetEvtGridTable();

    m_main_sizer=new wxBoxSizer(wxHORIZONTAL);

	m_splitwin=new wxSplitterWindow(this,-1,wxDefaultPosition,wxDefaultSize,wxSP_3D);
	m_main_sizer->Add(m_splitwin,1,wxEXPAND);
	m_process_tree=new wxTreeCtrl(m_splitwin,-1,wxDefaultPosition,wxSize(200,-1),wxTR_HAS_BUTTONS);
	//m_text=new wxTextCtrl(m_splitwin,-1,"",wxDefaultPosition,wxDefaultSize,wxTE_MULTILINE);	
	m_tran_panel=new process_tran_panel(m_splitwin,-1);
	m_tran_panel->SetGridTable(m_grid_table);
	m_splitwin->SplitVertically(m_process_tree,m_tran_panel,200);


	m_process_tree->AddRoot("SDL Processes");

	/*m_num_rows=logmod::event_type::GetCount();
    m_ts=new wxStaticText(this,-1,"1234567890123456 ns");
    m_main_sizer->Add(m_ts,0,wxEXPAND|wxALL,5);
    m_type=new wxStaticText(this,-1,"UNK ");
    m_main_sizer->Add(m_type,0,wxEXPAND|wxALL,5);
    m_dir=new wxStaticText(this,-1,"UNK");
    m_main_sizer->Add(m_dir,0,wxEXPAND|wxALL,5); */

    SetSizer(m_main_sizer);
    m_main_sizer->SetSizeHints(this);
	//SetBackgroundColour(*wxWHITE);
}

process_tree_panel::~process_tree_panel()
{
	//if (m_grid_table!=NULL)
	//	delete m_grid_table;
}

void process_tree_panel::OnTreeSelChanged(wxTreeEvent &event)
{
	wxTreeItemId item_id;
	process_tree_panel_itemdata *item_data;
	wxString state_name;
	bool result;

	item_id=m_process_tree->GetSelection();
	item_data=(process_tree_panel_itemdata *)m_process_tree->GetItemData(item_id);

	if (item_data==NULL)
		return;
			
	m_tran_panel->SetProcess(item_data->GetSDLProcess());
	//result=appdata::Get()->GetSQLite()->GetProcCurState(item_data->GetKey(),state_name);	
}

void process_tree_panel::LoadedDB(log_sqlite::db_file *db)
{
	int result,index;
	up_sdl::up_sdl_event evt;

	result=db->SelectALLSDLProcess();
	if (result<0)
		return;

	for (index=0;index<result;index++)
	{
		db->GetSDLEvent(&evt,index);
		AddSDLProcess(&evt);
	}

}

void process_tree_panel::AddSDLProcess(up_sdl::up_sdl_event *evt,int64_t event_id)
{
	const char *name;
	const char *fullname;
	std::string s_fullname;
	std::string s_index;
	std::string s_path;
	std::string s_item;
	int pos_b,pos_e,pos;
	wxTreeItemId item;
	process_tree_panel_itemdata *item_data;

	item=m_process_tree->GetRootItem();

	name=evt->GetName();
	s_fullname=evt->GetFullName();
	pos_b=s_fullname.find("<<");
	pos_e=s_fullname.find(">>");

	bool ismain=wxThread::IsMain();

	if (!ismain) wxMutexGuiEnter();
		
	if (pos_b!=-1)
		s_fullname=s_fullname.substr(pos_b+2,pos_e-2);
	else
	{
		item_data=new process_tree_panel_itemdata();
		item_data->SetKey(evt->GetKey());
		item_data->SetSDLProcess(appdata::Get()->GetSQLite()->GetDB()->GetSDLProcess(evt->GetKey()));
		m_process_tree->AppendItem(item,name,-1,-1,item_data);
		if (!ismain) wxMutexGuiLeave();
		return;
	}
	
	s_index=s_fullname;
	

	if (m_map_tree_items.find(s_index)!=m_map_tree_items.end())
	{
		item_data=new process_tree_panel_itemdata();
		item_data->SetKey(evt->GetKey());
		item_data->SetSDLProcess(appdata::Get()->GetSQLite()->GetDB()->GetSDLProcess(evt->GetKey()));
		m_process_tree->AppendItem(m_map_tree_items[s_index],name,-1,-1,item_data);
		if (!ismain) wxMutexGuiLeave();
		return;
	}
	
	pos=0;
	while (!s_index.empty())
	{		
		pos_e=s_index.find("/",pos);
		if (pos_e!=-1)
		{
			s_item=s_index.substr(pos,pos_e-pos);
			s_path=s_index.substr(0,pos_e);
			if (m_map_tree_items.find(s_path)!=m_map_tree_items.end())
				item=m_map_tree_items[s_path];
			else
			{
				item_data=new process_tree_panel_itemdata();
				item_data->SetKey(evt->GetKey());
				item=m_process_tree->AppendItem(item,s_item.c_str(),-1,-1,item_data);			
				m_map_tree_items[s_path]=item;
			}
		}
		else
		{			
			s_item=s_index.substr(pos);
			s_path=s_index;
			if (m_map_tree_items.find(s_path)!=m_map_tree_items.end())
				item=m_map_tree_items[s_path];
			else
			{
				item_data=new process_tree_panel_itemdata();
				item_data->SetKey(evt->GetKey());
				item=m_process_tree->AppendItem(item,s_item.c_str(),-1,-1,item_data);
				m_map_tree_items[s_path]=item;
			}
			s_index="";
		}
		pos=pos_e+1;
	}
	item_data=new process_tree_panel_itemdata();
	item_data->SetKey(evt->GetKey());
	item_data->SetSDLProcess(appdata::Get()->GetSQLite()->GetDB()->GetSDLProcess(evt->GetKey()));
	m_process_tree->AppendItem(item,name,-1,-1,item_data);	

	m_process_tree->Expand(m_process_tree->GetRootItem());

	if (!ismain) wxMutexGuiLeave();
}


