#include "log_ice_dbg/log_ice_dbg_prec.h"
#include "log_ice_dbg/dbgclasseventifi.h"
#include "log_ice_dbg/appdata.h"

dbgclasseventifI::dbgclasseventifI(wxTextCtrl *text,sqlitectrlI *sqlite,loggerctrlI *logctrl)
	: loggerice::dbgclasseventif(), m_print_proc(PROC_NO_PRINT), m_print_thread(THREAD_NO_PRINT)
{
    m_text=text;
    m_sqlite=sqlite;
	m_logger_ctrl=logctrl;
    m_ofs=new std::ostream(m_text);
}

dbgclasseventifI::~dbgclasseventifI()
{
    if (m_ofs!=NULL)
        delete m_ofs;
}

void dbgclasseventifI::SetPrintProcName(bool print)
{
	if (print)
		m_print_proc=PROC_NAME;
	else
		m_print_proc=PROC_NO_PRINT;
}

void dbgclasseventifI::SetPrintProcId(bool print)
{
	if (print)
		m_print_proc=PROC_ID;
	else
		m_print_proc=PROC_NO_PRINT;
}

void dbgclasseventifI::SetPrintThreadName(bool print)
{
	if (print)
		m_print_thread=THREAD_NAME;
	else
		m_print_thread=THREAD_NO_PRINT;
}

void dbgclasseventifI::SetPrintThreadId(bool print)
{
	if (print)
		m_print_thread=THREAD_ID;
	else
		m_print_thread=THREAD_NO_PRINT;
}

void dbgclasseventifI::sendevent(const ::loggerice::dbgclasseventPtr& s, const ::Ice::Current& )
{
	std::ostringstream os;
	std::string name;

	appdata *ap=appdata::Get();

	ap->NewEvent(&logmod::evt_typ::EVT_DBG_CLASS);
  
    uint32_t raw;
	int result;

    if (m_text!=NULL)
    {
		switch (m_print_proc)
		{
			case PROC_ID:
				os << "[proc ";
				os.width(2);
				os << s->regId;
				os.width(0);
				os << "]";
				break;
			case PROC_NAME:
				
				m_logger_ctrl->GetName(s->regId,name);
				os << "[";
				os.width(10);
				os << name;
				os.width(0);
				os << "]";
			default:
				;
		}
		switch (m_print_thread)
		{
			case THREAD_ID:
				os << "[thread ";
				os.width(2);
				os << s->threadId;
				os.width(0);
				os << "]";
				break;
			case THREAD_NAME:				
				result=m_logger_ctrl->GetThreadName(s->regId,s->threadId,name);
				if (result<0)
					name.assign("??");
				os << "[";
				os.width(10);
				os << name;
				os.width(0);
				os << "]";
			default:
				;
		}
		m_text->AppendText(os.str());
		m_text->AppendText(s->callTxt);
        /*raw=s->rawsymb;
        symb.SetData(&raw,1);
        symb.Parse();
        symb.Print(m_ofs);
        //m_text->AppendText("Received a l2_symbol");
        m_text->AppendText("\n"); */
    }
    /*if (m_sqlite==NULL)
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
    m_sqlite->m_sqlite_log->Send(&m_evt);	*/
}
