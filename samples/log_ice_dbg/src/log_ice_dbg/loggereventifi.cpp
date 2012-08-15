#include "log_ice_dbg/log_ice_dbg_prec.h"
#include "log_ice_dbg/loggereventifi.h"
#include "log_ice_dbg/appdata.h"

#include "log_ice/event_logger.h"
#include "log_ice/event_logger_impl.h"

loggereventifI::loggereventifI(wxTextCtrl *text,sqlitectrlI *sqlite):loggerice::loggereventif()
{
    m_text=text;
    m_sqlite=sqlite;
    m_ofs=new std::ostream(m_text);
}

loggereventifI::~loggereventifI()
{
    if (m_ofs!=NULL)
        delete m_ofs;
}

void loggereventifI::sendevent(const ::loggerice::loggereventPtr& s, const ::Ice::Current& )
{
	appdata *ap=appdata::Get();
	logmod::event_utils *evt_utils=ap->GetEventUtils();
	std::ostringstream oss;

	ap->NewEvent(&logmod::evt_typ::EVT_LOGGER_EVENT);

	log_ice::event_logger_impl::SetLoggerEvent(s,&m_evt);

	if (m_text!=NULL)
    {
		evt_utils->PrintKey(oss,&m_evt);
		evt_utils->PrintTime(oss,&m_evt);
		evt_utils->PrintTS(oss,&m_evt);
		//evt_utils.PrintDevice(oss,&m_evt);
		evt_utils->PrintThreadID(oss,&m_evt);
		m_evt.PrintString(oss);
		ap->wxPrint(oss.str().c_str());
	}
    
    if (m_sqlite==NULL)
        return;
    if (m_sqlite->m_sqlite_log==NULL)
        return;    
    m_sqlite->m_sqlite_log->Send(&m_evt);
}
