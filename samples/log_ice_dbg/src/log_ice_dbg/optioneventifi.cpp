#include "log_ice_dbg/log_ice_dbg_prec.h"
#include "log_ice_dbg/optioneventifi.h"
#include "log_ice_dbg/appdata.h"

optioneventifI::optioneventifI(wxTextCtrl *text,sqlitectrlI *sqlite):optioneventif()
{
    m_text=text;
    m_sqlite=sqlite;
    m_ofs=new std::ostream(m_text);
}

optioneventifI::~optioneventifI()
{
    if (m_ofs!=NULL)
        delete m_ofs;
}

void optioneventifI::sendevent(const ::loggerice::optioneventPtr& s, const ::Ice::Current& )
{
	appdata *ap=appdata::Get();

	ap->NewEvent(&logmod::evt_typ::EVT_OPTION_EVENT);
    /*up_sock::l2_symbol symb;
    //up::l2_symbol l2_symb;

    uint32_t raw;

    if (m_text!=NULL)
    {
        raw=s->rawsymb;
        symb.SetData(&raw,1);
        symb.Parse();
        symb.Print(m_ofs);
        //m_text->AppendText("Received a l2_symbol");
        m_text->AppendText("\n");
    }
    if (m_sqlite==NULL)
        return;
    if (m_sqlite->m_sqlite_log==NULL)
        return;
    m_evt.SetRawSymbol(s->rawsymb);
    //m_evt.SetUID(s->
    m_evt.SetTS(s->ts);
    //m_evt.SetType(s->type);    
	m_evt.SetKind((logmod::event::event_kind)s->kind);
	m_evt.SetType(&logmod::evt_typ::EVT_L2_SYMBOL);
    m_evt.SetSrcType(s->srctype);
    m_evt.SetSrcId(s->srcid);
    //m_evt.SetEventType(s->eventtype);
    m_sqlite->m_sqlite_log->Send(&m_evt); */	
}
