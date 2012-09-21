#include "log_ice_dbg/log_ice_dbg_prec.h"

#ifdef WIN32
#define _WINSOCKAPI_ 
#endif
#include "log_ice_dbg/server.h"

#include "log_ice_dbg/ice/logicedbgctrlif.h"
#include "log_ice/ice/logger_event.h"
#include "log_ice/ice/option_event.h"

#include "log_ice_dbg/dbgclasseventifi.h"
#include "log_ice_dbg/loggereventifi.h"
#include "log_ice_dbg/optioneventifi.h"
#include "log_ice_dbg/loggerctrli.h"

#include "log_ice_dbg/myapp.h"

server::server(wxTextCtrl *text,wxThreadKind kind):wxThread(kind)
{
    m_argc=0;
    m_argv=NULL;
    m_text=text;
    m_sqlite_ctrl=NULL;

	m_status=0;
	std::ostringstream os;

    try 
    {
        m_ic = Ice::initialize(m_argc, m_argv);
        //Ice::ObjectAdapterPtr adapter
		os << "default -p " << wxGetApp().m_port;
		m_adapter= m_ic->createObjectAdapterWithEndpoints("SimplePrinterAdapter", os.str());
        
        m_sqlite_ctrl=new sqlitectrlI(m_text);
        m_sqlite_ctrlPtr=m_sqlite_ctrl;//new sqlitectrlI(m_text);
        m_adapter->add(m_sqlite_ctrlPtr,m_ic->stringToIdentity("SQLiteCtrl"));        

		m_printeri=new PrinterI(m_text);
        m_printeriPtr=m_printeri;
        m_adapter->add(m_printeriPtr,m_ic->stringToIdentity("SimplePrinter"));        
       
		m_loggerevtiPtr=new loggereventifI(m_text,m_sqlite_ctrl);		
		m_adapter->add(m_loggerevtiPtr,m_ic->stringToIdentity("LoggerEvents"));

		m_optionevtiPtr=new optioneventifI(m_text,m_sqlite_ctrl);		
		m_adapter->add(m_optionevtiPtr,m_ic->stringToIdentity("OptionEvents"));

		m_loggerctrli=new loggerctrlI(m_text);		
		m_loggerctrliPtr=m_loggerctrli;
		m_adapter->add(m_loggerctrliPtr,m_ic->stringToIdentity("LoggerCtrl"));

		m_dbgclassevtifi=new dbgclasseventifI(m_text,m_sqlite_ctrl,m_loggerctrli);
		m_dbgclassevtiPtr=m_dbgclassevtifi;
		m_adapter->add(m_dbgclassevtiPtr,m_ic->stringToIdentity("DbgClassEvents"));

		m_dbgclassevtifi->SetPrintProcName();
		m_dbgclassevtifi->SetPrintThreadId();
        
    } 
    catch (const Ice::Exception & e) 
    {
        cerr << e << endl;
        m_status = -1;
    } 
    catch (const char * msg) 
    {
        cerr << msg << endl;
        m_status = -1;
    }
}

server::~server()
{
}

void server::SetTextCtrl(wxTextCtrl *text)
{
    m_text=text;
    m_printeri->m_text=text;
}

sqlitectrlI *server::GetSQLiteCtrl()
{
    return m_sqlite_ctrl;
}

wxThread::ExitCode server::Entry()
{
    int status = 0;
    //Ice::CommunicatorPtr m_ic;
    try 
    {
/*        m_ic = Ice::initialize(m_argc, m_argv);
        //Ice::ObjectAdapterPtr adapter
        m_adapter= m_ic->createObjectAdapterWithEndpoints("SimplePrinterAdapter", "default -p 10000");
        Ice::ObjectPtr object = new PrinterI(m_text);
        m_adapter->add(object,m_ic->stringToIdentity("SimplePrinter"));
        object=new l2symboleventifI(m_text,m_sqlite_ctrl);
        m_adapter->add(object,m_ic->stringToIdentity("L2SymbolsEvents"));
        object=new l3pdueventifI(m_text,m_sqlite_ctrl);
        m_adapter->add(object,m_ic->stringToIdentity("L3PDUsEvents"));
        object=new uniprocoreeventifI(m_text,m_sqlite_ctrl);
        m_adapter->add(object,m_ic->stringToIdentity("UniProCoreEvents"));
        m_sqlite_ctrl=new sqlitectrlI(m_text);
        object=m_sqlite_ctrl;//new sqlitectrlI(m_text);
        m_adapter->add(object,m_ic->stringToIdentity("SQLiteCtrl")); */
        m_adapter->activate();
        m_ic->waitForShutdown();
    } 
    catch (const Ice::Exception & e) 
    {
        cerr << e << endl;
        status = 1;
    } 
    catch (const char * msg) 
    {
        cerr << msg << endl;
        status = 1;
    }
    if (m_ic) 
    {
        try 
        {
            m_ic->destroy();
        } 
        catch (const Ice::Exception & e) 
        {
            cerr << e << endl;
            status = 1;
        }
    }
    return (wxThread::ExitCode)status;
}
