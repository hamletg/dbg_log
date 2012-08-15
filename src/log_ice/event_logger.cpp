/**
 * \file logmod/event_logger.cpp
 * \brief Defines the events logger
 *
 * \cond
 *__legal_b__
 *__legal_e__
 * \endcond
 */
#include "log_ice/log_ice_prec.h"

#include "log_ice/event_logger.h"
#include "dbg_log/dbg_class_event.h"

#include "log_ice/ice/dbg_class_event.h"
#include "log_ice/ice/logger_event.h"
#include "log_ice/ice/option_event.h"
#include "log_ice/event_logger_impl.h"

#include <string>
#include <sstream>

//using namespace Demo;
using namespace loggerice;

namespace log_ice
{

event_logger::event_logger():logmod::event_logger()
{
    m_impl=new event_logger_impl();
}

event_logger::~event_logger()
{
	if (m_impl!=NULL)
		delete m_impl;
}

void event_logger::SetName(std::string name)
{
	m_name=name;
}

std::string event_logger::GetName()
{
	return m_name;
}

int event_logger::Connect(const char *ip_address,unsigned int port)
{
	std::string s;
	std::ostringstream os;

	m_ok=true;

    m_argc=0;
    m_argv=NULL;
    if ((ip_address==NULL) && (port==NULL))
		os << "DbgClassEvents:default -p 10999";
	if (ip_address!=NULL)
		os << "-h " << ip_address << " ";
	if (port!=0)
		os << "-p " << port << " ";
	s=os.str();

    try 
    {
        m_impl->m_ic = Ice::initialize(m_argc, m_argv);

		m_impl->m_base_dbg_class=m_impl->m_ic->stringToProxy(s.c_str());
        m_impl->m_dbg_class_if=dbgclasseventifPrx::checkedCast(m_impl->m_base_dbg_class);

        if (!m_impl->m_dbg_class_if)
            throw "Invalid proxy";
        m_impl->my_dbg_class_event=new dbgclassevent;

		m_impl->m_base_logger=m_impl->m_ic->stringToProxy("LoggerEvents:default -p 10999");
        m_impl->m_logger_if=loggereventifPrx::checkedCast(m_impl->m_base_logger);

        if (!m_impl->m_logger_if)
            throw "Invalid proxy";
		m_impl->my_logger_event=new loggerevent;

		m_impl->m_base_option=m_impl->m_ic->stringToProxy("OptionEvents:default -p 10999");
        m_impl->m_option_if=optioneventifPrx::checkedCast(m_impl->m_base_option);

        if (!m_impl->m_option_if)
            throw "Invalid proxy";
        m_impl->my_option_event=new optionevent;

		m_impl->m_base_loggerctrl=m_impl->m_ic->stringToProxy("LoggerCtrl:default -p 10999");
        m_impl->m_loggerctrl_if=loggerctrlPrx::checkedCast(m_impl->m_base_loggerctrl);

        if (!m_impl->m_loggerctrl_if)
            throw "Invalid proxy";
    } 
    catch (const Ice::Exception & ex) 
    {
        m_ok=false;
        SetError(ex.ice_name().c_str());
		std::cerr << ex << std::endl;
    } 
    catch (const Ice::ConnectionRefusedException &ex)
    {
        m_ok=false;
        SetError(ex.ice_name().c_str());
		std::cerr << ex << std::endl;
    }
    catch (const char * msg) 
    {
        m_ok=false;
        SetError(msg);
		std::cerr << msg << std::endl;
    }
	if (m_ok==false)
		return -1;
	
	m_ok=true;

	try 
    {
		m_id=m_impl->m_loggerctrl_if->Register(GetName());
	}
	catch (const Ice::Exception & ex) 
    {
        m_ok=false;
        SetError(ex.ice_name().c_str());
		std::cerr << ex << std::endl;
    } 
	if (m_ok==false)
		return -1;
	return 0;
}

int event_logger::Shutdown()
{
	return 0;
}

void event_logger::Send(logmod::event *evt)
{
    logmod::event_type *event_t=NULL;

    if (evt==NULL)
    {
        ///\todo throw an exception
        return;
    }

	if (IsEnabled()==false)
		return;

    event_t=evt->GetType();
	evt->SetProcId(m_id);

	if (event_t->GetId()==logmod::evt_typ::EVT_DBG_CLASS.GetId())
	{		        
		HandleDbgClassEvent(evt); 
	}
	else if (event_t->GetId()==logmod::evt_typ::EVT_LOGGER_EVENT.GetId())
	{		        
		HandleLoggerEvent(evt); 
	}
    else if (event_t->GetId()==logmod::evt_typ::EVT_OPTION_EVENT.GetId())
	{		        
		HandleOptionEvent(evt); 
	}

}

void event_logger::HandleDbgClassEvent(logmod::event *evt)
{
	dbg_log::dbg_class_event *_evt;

	_evt=dynamic_cast<dbg_log::dbg_class_event *>(evt);

	if (_evt==NULL)
         return;

	m_impl->my_dbg_class_event->type=_evt->GetType()->GetId();
	m_impl->my_dbg_class_event->ts=_evt->GetTS();
    m_impl->my_dbg_class_event->srctype=_evt->GetSrcType();
    m_impl->my_dbg_class_event->srcid=_evt->GetSrcId();
    m_impl->my_dbg_class_event->kind=_evt->GetKind();
	m_impl->my_dbg_class_event->key=_evt->GetKey();
	m_impl->my_dbg_class_event->timeMs=_evt->GetTime();  
	m_impl->my_dbg_class_event->threadId=_evt->GetThreadId();
	m_impl->my_dbg_class_event->procId=_evt->GetProcId();

	m_impl->my_dbg_class_event->depth=_evt->GetDepth();
	m_impl->my_dbg_class_event->callTxt=_evt->GetCallTxt();
	m_impl->my_dbg_class_event->subType=_evt->GetSubType();
    //dbg_class *m_dbg_class;
	m_impl->my_dbg_class_event->elapsedTime=_evt->GetElapsedTime();
	
	try
    {
       m_impl->m_dbg_class_if->sendevent(m_impl->my_dbg_class_event);
    }
    catch (const Ice::Exception & ex) 
    {
		std::cerr << ex << std::endl;
    } 
    catch (const char * msg) 
    {
		std::cerr << msg << std::endl;
	}

}

void event_logger::HandleLoggerEvent(logmod::event *evt)
{
	logmod::logger_event *_evt;
    const char *txt;

	_evt=dynamic_cast<logmod::logger_event *>(evt);

	if (_evt==NULL)
         return;

	m_impl->my_logger_event->type=_evt->GetType()->GetId();
	m_impl->my_logger_event->ts=_evt->GetTS();
	m_impl->my_logger_event->srctype=_evt->GetSrcType();
    m_impl->my_logger_event->srcid=_evt->GetSrcId();
    m_impl->my_logger_event->kind=_evt->GetKind();
	m_impl->my_logger_event->key=_evt->GetKey();
	m_impl->my_logger_event->timeMs=_evt->GetTime();  
	m_impl->my_logger_event->threadId=_evt->GetThreadId();

	m_impl->my_logger_event->subType=_evt->GetSubType();
	m_impl->my_logger_event->value=_evt->GetValue();
    txt=_evt->GetName();
    if (txt!=NULL)
	    m_impl->my_logger_event->name=txt;

	try
    {
       m_impl->m_logger_if->sendevent(m_impl->my_logger_event);
    }
    catch (const Ice::Exception & ex) 
    {
		std::cerr << ex << std::endl;
    } 
    catch (const char * msg) 
    {
        std::cerr << msg << std::endl;
	}
}

void event_logger::HandleOptionEvent(logmod::event *evt)
{
	logmod::option_event *_evt;
	std::string str;

	_evt=dynamic_cast<logmod::option_event *>(evt);

	if (_evt==NULL)
         return;

	m_impl->my_option_event->type=_evt->GetType()->GetId();
	m_impl->my_option_event->ts=_evt->GetTS();
	m_impl->my_option_event->srctype=_evt->GetSrcType();
    m_impl->my_option_event->srcid=_evt->GetSrcId();
    m_impl->my_option_event->kind=_evt->GetKind();
	m_impl->my_option_event->key=_evt->GetKey();
	m_impl->my_option_event->timeMs=_evt->GetTime();  
	m_impl->my_option_event->threadId=_evt->GetThreadId();

	m_impl->my_option_event->subType=_evt->GetSubType();
	m_impl->my_option_event->value=_evt->GetValue();
	m_impl->my_option_event->name=_evt->GetOption();
	_evt->GetValue(str);
	m_impl->my_option_event->strVal=str.c_str();

	try
    {
       m_impl->m_option_if->sendevent(m_impl->my_option_event);
    }
    catch (const Ice::Exception & ex) 
    {
        std::cerr << ex << std::endl;
    } 
    catch (const char * msg) 
    {
        std::cerr << msg << std::endl;
	}
}



}



