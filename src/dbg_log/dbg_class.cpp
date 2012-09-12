#include "dbg_log/dbg_log_prec.h"

#include "dbg_log/dbg_class.h"

#include <wx/string.h>
#include <wx/thread.h>

#ifdef WIN32
#include <sys/types.h> 
#include <sys/timeb.h>
#else
#include <stdlib.h>
#include <sys/time.h>
#endif

#include <ios>
#include <sstream>

namespace dbg_log
{

//wxTextCtrl *dbg_class::m_text=NULL;

bool dbg_class::m_diff_thread=false;
int dbg_class::m_depth=0;
logmod::logger *dbg_class::m_dft_logger=NULL;
logmod::event_logger *dbg_class::m_dft_event_logger=NULL;

int dbg_class::m_thread_count=0;
int dbg_class::m_thread_name_width=8;
std::map<uint64_t,dbg_class_thread> dbg_class::m_named_threads;

bool old_way=true;

dbg_class::dbg_class(const char *name,bool print_state)
	: m_dbg_class(NULL), m_end(false), m_return(NULL), m_print_state(false)
	, m_name(name), m_logger(NULL)
{
	int aaa;
	
	//m_my_depth=dbg_class::m_depth;
	m_my_depth=dbg_class::Depth(&m_thread_info);

	dbg_class::IncDepth(m_thread_info);

	//(*logger) << logmod::time;
    m_os_str.str(""); 
	if (old_way)
		PrintDepth(m_os_str);
	//PrintProcessId(m_os_str);
	m_os_str << "[" << name << "] enters" << std::endl;

	if (m_logger!=NULL)
	{
		m_logger->Begin();
#ifndef __GNUC__
		(*m_logger) << (m_os_str.str());
#else
		(*m_logger) << (m_os_str.str());
#endif
		m_logger->End();
	}
	if (m_dft_logger!=NULL)
	{
		m_dft_logger->Begin();
		if (!old_way)
		{
			m_dft_logger->SetDepth(m_my_depth);
			m_dft_logger->SetDepthSize(4);
			m_dft_logger->SetStaticHeaderSize(7);
			m_dft_logger->HeaderEnable(false);
		}
#ifndef __GNUC__
		(*m_dft_logger) << m_os_str.str();
#else
		(*m_dft_logger) << m_os_str.str();
#endif
		if (!old_way)
			m_dft_logger->HeaderEnable(true);
		m_dft_logger->End();
	}
	if (m_dft_event_logger!=NULL)
    {
        //m_os_str << std::endl;
		/*m_event.SetDepth(m_my_depth);
        m_event.SetCallTxt((char *)m_os_str.str().c_str());
		m_event.SetSubType(dbg_class_event::START_FCT_CALL);
        //m_event.SetTS(logmod::logger::GetTimeStamp());
        //m_event.SetElapsedTime(cur_time-m_start_time);
        m_dft_event_logger->Send(&m_event); */
    }
}

dbg_class::dbg_class(dbg_class *dbg)
	: m_dbg_class(dbg), m_end(true), m_return(NULL), m_print_state(false)
	, m_logger(NULL)
    , m_fct_info(NULL)
{
	m_name=dbg->m_name;
   
	if (dbg!=NULL)
    {
        m_my_depth=dbg->m_my_depth;
		m_thread_info=dbg->m_thread_info;
        m_print_state=dbg->m_print_state;

        m_logger=dbg->m_logger;    
        //m_event_logger=dbg->m_event_logger;
        m_return=dbg->m_return;
   
        m_name=dbg->m_name;
        //m_os_str.str(dbg->m_os_str.str());
    }
    else
    {
        m_name="";
    }
    //m_start_time=logmod::event::GetCurTime(); 
}

dbg_class::~dbg_class()
{
	int aaa,size;
	dbg_class_param_base *param;
    uint64_t cur_time;

	if (m_end==false)
    {
        dbg_class::DecDepth(m_thread_info);
        return; 
    }

	m_os_str.str("");
	if (old_way)
		PrintDepth(m_os_str);
	//PrintProcessId(m_os_str);
	m_os_str << "[" << m_name << "] exits" << std::endl;

	size=m_dbg_class->m_params.size();
    for (aaa=0;aaa<size;aaa++)
    {
        param=m_dbg_class->m_params.at(aaa);
        if (param->IsOutput())
        {
            PrintParamHeader(m_os_str);
            param->Print(m_os_str,false);
        }
    }

	if (m_return!=NULL)
    {
		PrintReturnHeader(m_os_str);
		m_return->Print(m_os_str);
    }
    if (m_print_state)
    {
        /*if (m_dbg_class->m_module!=NULL)
            m_dbg_class->m_module->PrintState(*logger,m_my_depth);
        if (m_dbg_class->m_api!=NULL)
            m_dbg_class->m_api->PrintState(*logger,m_my_depth); */
        
    }
	m_os_str << std::endl;

	if (m_logger!=NULL)
	{
		m_logger->Begin();
#ifndef __GNUC__
		(*m_logger) << m_os_str.str();
#else
		(*m_logger) << m_os_str.str();
#endif
		m_logger->End();
	}
	if (m_dft_logger!=NULL)
	{
		m_dft_logger->Begin();
		if (!old_way)
		{
			m_dft_logger->SetDepth(m_my_depth);
			m_dft_logger->HeaderEnable(false);
		}
#ifndef __GNUC__
		(*m_dft_logger) << (m_os_str.str());
#else
		(*m_dft_logger) << (m_os_str.str());
#endif
		if (!old_way)
			m_dft_logger->HeaderEnable(true);
		m_dft_logger->End();
	}
	if (m_dft_event_logger!=NULL)
    {
        //m_os_str << std::endl;
        m_event.SetCallTxt((char *)m_os_str.str().c_str());
        m_event.SetSubType(dbg_class_event::END_FCT_CALL);
        //m_event.SetTS(logmod::logger::GetTimeStamp());
        //m_event.SetElapsedTime(cur_time-m_start_time);
        m_dft_event_logger->Send(&m_event);
    }

}

void dbg_class::MessageF(const char *format, ...)
{
#ifdef _MSC_VER
	char result[500];

	va_list args;
    va_start(args, format);

    vsprintf(result, format, args);

    va_end(args);
	Message(result);

#else

#endif
}

void dbg_class::Message(const char *msg)
{
	std::ostringstream os_str;

    if ((m_dft_event_logger!=NULL)||(m_dft_logger!=NULL))
	{
		os_str.str("");
		os_str << "[" << m_name << "] message: " << std::endl;
        os_str << "    " << msg << std::endl;
	}

	if (m_dft_logger!=NULL)
#ifndef __GNUC__
		(*m_dft_logger) << os_str.str();
#else
		(*m_dft_logger) << os_str.str();
#endif

    if (m_dft_event_logger!=NULL)
    {
        m_event.SetDepth(m_my_depth);
        //m_event.SetTS(logmod::logger::GetTimeStamp());
        m_event.SetSubType(dbg_log::dbg_class_event::MSG);   
        m_event.SetCallTxt((char *)os_str.str().c_str());        
        m_dft_event_logger->Send(&m_event);
    }
}

void dbg_class::SetFunctionInfo(dbg_class_function_info *info)
{
	m_fct_info=info;
}

void dbg_class::AllParamAdded()
{
	int aaa,size;
	dbg_class_param_base *param;
	std::string s;
	//m_os_str.str("");
	
    size=m_params.size();
    for (aaa=0;aaa<size;aaa++)
    {
		param=m_params.at(aaa);
		if (old_way)
			PrintParamHeader(m_os_str);
		else
		{
			s.assign("              Param: ");
			s.size();
		}
        //m_os_str << "    Param: ";
		param->Print(m_os_str,true);
    }
    m_os_str << std::endl;
    if (m_logger!=NULL)
	{
		m_logger->Begin();
		(*m_logger) << m_os_str.str();
		m_logger->End();
	}
	if (m_dft_logger!=NULL)
	{
		m_dft_logger->Begin();
		std::string s=m_os_str.str();
#ifndef __GNUC__
		(*m_dft_logger) << m_os_str.str();
#else
		(*m_dft_logger) << m_os_str.str();
#endif
		m_dft_logger->End();
	}
	if (m_dft_event_logger!=NULL)
	{
		m_event.SetDepth(m_my_depth);
        //m_event.SetTS(logmod::logger::GetTimeStamp());
        m_event.SetSubType(dbg_log::dbg_class_event::START_FCT_CALL);
		m_event.SetCallTxt((char *)m_os_str.str().c_str());        
        m_dft_event_logger->Send(&m_event);
	}
    
}

void dbg_class::AddParam(dbg_class_param_base *param)
{
	//Is active or not, the param are printed as well?
	m_params.push_back(param);
}

void dbg_class::SetReturn(dbg_class_param_base *ret)
{
    m_return=ret;
}

void dbg_class::PrintBlankHeader(std::ostream &os)
{
	os << "       ";
}

void dbg_class::PrintParamHeader(std::ostream &os)
{
	int aaa;
	
	PrintBlankHeader(os);

	for (aaa=0;aaa<m_my_depth;aaa++)
		os << "    ";
    os << "              Param: ";
}

void dbg_class::PrintReturnHeader(std::ostream &os)
{
	int aaa;

	PrintBlankHeader(os);

	for (aaa=0;aaa<m_my_depth;aaa++)
		os << "    ";
	os << "              Return: ";
}

void dbg_class::PrintCurTime(std::ostream &os)
{
	os << "[";
	os.width(15);
	os.fill('0');
	os << std::right << dbg_class::GetCurTime();
	os.width();
	os << "]";
}

void dbg_class::PrintDepth(std::ostream &os)
{
	int aaa;

	os << "[";
	os.width(5);
	os.fill(' ');
	os << std::right << m_my_depth;
	os.width(0);
	os << "]";

	for (aaa=0;aaa<dbg_class::m_depth;aaa++)
		os << "    ";
}

void dbg_class::PrintRegId(std::ostream &os, int id)
{
	int aaa;

	os << "[";
	os.width(2);
	os.fill(' ');
	os << std::right << id;
	os.width(0);
	os << "]";
}

void dbg_class::PrintThreadName(std::ostream &os)
{
	if (m_diff_thread==false)
		return;
	if (m_thread_info==NULL)
		return;
	os << "[";
	os.width(m_thread_name_width);
	os.fill(' ');
	os << std::right << m_thread_info->GetName();
	os.width(0);
	os << "]";

}

int dbg_class::GetDepth()
{
    return dbg_class::m_depth;
}

void dbg_class::IncDepth(dbg_class_thread *thread_info)
{
	if (thread_info==NULL)
		dbg_class::m_depth++;
	else
		thread_info->IncDepth();
}

void dbg_class::DecDepth(dbg_class_thread *thread_info)
{
	if (thread_info==NULL)
		dbg_class::m_depth--;
	else
		thread_info->DecDepth();
}

void dbg_class::ResetDepth()
{
    dbg_class::m_depth=0;
}

int dbg_class::Depth(dbg_class_thread **thread_info)
{
	if (m_diff_thread==false)
	{
		if (thread_info!=NULL)
			*thread_info=NULL;
		return dbg_class::m_depth;
	}

	std::map<uint64_t,dbg_class_thread>::iterator it;
	uint64_t id=wxThread::GetCurrentId();

	it=m_named_threads.find(id);
	if (it!=m_named_threads.end())
	{
		if (thread_info!=NULL)
			*thread_info=&(*it).second;
		return (*it).second.GetDepth();
	}
	std::ostringstream oss;
	dbg_class_thread thread;

	oss << "Thread";
	oss.width(2);
	oss.fill('0');
	oss << m_thread_count;
	thread.SetName(oss.str());
	thread.SetId(id);
	m_named_threads[id]=thread;
	if (thread_info!=NULL)
		*thread_info=&m_named_threads[id];
	return 0;
}

/*void dbg_class::SetStaticTextCtrl(wxTextCtrl *text)
{
	dbg_class::m_text=text;
} */

/*wxTextCtrl *dbg_class::GetStaticTextCtrl()
{
	return dbg_class::m_text;
} */

void dbg_class::SetThreadName(const char *name)
{
	std::map<uint64_t,dbg_class_thread>::iterator it; // m_named_threads
	uint64_t id=wxThread::GetCurrentId();
	dbg_class_thread thread;

	thread.SetId(id);
	thread.SetName(name);

	it=m_named_threads.find(id);

	if (it==m_named_threads.end())
	{
		m_named_threads[id]=thread;	
	}
	else
	{
		m_named_threads[id]=thread;
	}

}

uint64_t dbg_class::GetCurTime()
{
    uint64_t result;
#ifdef WIN32
    
    _timeb tb_time;

    _ftime(&tb_time);
    result=tb_time.time;
    result=result*1000+tb_time.millitm;
#else
    struct timeval tv;
    struct timezone tz;
     
    gettimeofday(&tv, &tz);
    result=tv.tv_sec;
    result=result*1000+(tv.tv_usec/1000);
#endif

    return result;
}

uint32_t dbg_class::GetCurThreaId()
{
	return wxThread::GetCurrentId();
}

void dbg_class::SetDifferentiateThread(bool value)
{
	m_diff_thread=value;
}

void dbg_class::SetDefaultLogger(logmod::logger *logger)
{
	dbg_class::m_dft_logger=logger;
}

void dbg_class::SetDefaultEventLogger(logmod::event_logger *log)
{
    m_dft_event_logger=log;
}

logmod::logger *dbg_class::GetDefaultLogger()
{
	return dbg_class::m_dft_logger;
}

void dbg_class::SetThreadNameWidth(int size)
{
	m_thread_name_width=size;
}

int dbg_class::GetThreadNameWidth()
{
	return m_thread_name_width;
}

}