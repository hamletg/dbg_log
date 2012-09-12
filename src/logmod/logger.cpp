#include "logmod/logmod_prec.h"
#include "logmod/logger.h"
#include "logmod/wxtextctrlts.h"

#include <wx/thread.h>
#include <wx/textctrl.h>

#ifdef WIN32
#include <sys/types.h> 
#include <sys/timeb.h>
#else
#include <stdlib.h>
#include <sys/time.h>
#endif

#include <ios>

namespace logmod
{

logger_mutex_api::~logger_mutex_api()
{
}

class my_mutex: public logger_mutex_api
{
public:
	my_mutex()
#ifdef LOGGER_WITH_WXMUTEX
        :m_mutex(wxMUTEX_RECURSIVE)
#endif
    {
    }
    virtual ~my_mutex()
    {
    }

    virtual int Lock()
    {
        int result=0;
#ifdef LOGGER_WITH_WXMUTEX
        result=m_mutex.Lock(); 
#endif
        return result;
    }
    virtual int Unlock()
    {
        int result=0;
#ifdef LOGGER_WITH_WXMUTEX
        result=m_mutex.Unlock(); 
#endif
        return result;
    }
#ifdef LOGGER_WITH_WXMUTEX
    wxMutex m_mutex;
#endif
};

#ifdef LOGGER_WITH_WXMUTEX
class my_mutex_locker: public wxMutexLocker
{
public:
    my_mutex_locker(my_mutex &mux):wxMutexLocker(mux.m_mutex)
    {
    }
    virtual ~my_mutex_locker()
    {
    }
};
#else
class my_mutex_locker
{
public:
    my_mutex_locker(my_mutex &mux)
    {
    }
    virtual ~my_mutex_locker()
    {
    }
};
#endif

const int logger::m_time_mode=std::ios_base::xalloc();
const int logger::m_add_depth=std::ios_base::xalloc();
bool logger::m_old_way=true;

logger::logger()
	: m_os(NULL),m_streambuf(NULL),m_text_ctrl(NULL),m_ofs(NULL)
	,  m_static_header_size(0), m_depth(0), m_depth_size(0), m_static_footer_size(0)
{
	m_transaction_mutex=new my_mutex();
}

logger::~logger()
{
	if (m_transaction_mutex!=NULL)
        delete m_transaction_mutex;
}

void logger::SetTextCtrl(wxTextCtrlTS *text)
{
	if (m_ofs!=NULL)
		SetOfstream(NULL);

	m_text_ctrl=text;
	if (text!=NULL)
	{
		if (m_os==NULL)
			m_os=new std::ostream(text);
		else
			m_os->rdbuf(text);
	}
	else
	{
		if (m_os!=NULL)
		{
			delete m_os;
			m_os=NULL;
		}
	}
}

wxTextCtrlTS *logger::GetTextCtrl()
{
	return m_text_ctrl;
}

void logger::SetOfstream(std::ofstream *ofs)
{
	if (m_text_ctrl!=NULL)
		SetTextCtrl(NULL);

	m_os=(std::ostream *)ofs;
	m_ofs=ofs;
}

std::ofstream *logger::GetOfstream()
{
	return m_ofs;
}

void logger::SetOstream(std::ostream *os)
{
	m_os=os;
}

std::ostream *logger::GetOstream()
{
	return m_os;
}

void logger::Begin()
{
#ifdef LOGGER_WITH_WXMUTEX
    m_transaction_mutex->Lock();    
#endif
}

void logger::End()
{
#ifdef LOGGER_WITH_WXMUTEX
    m_transaction_mutex->Unlock();    
#endif
}

logger &begin(logger &mylog)
{
    mylog.Begin();

    return mylog;
}

logger &end(logger &mylog)
{
    mylog.End();

    return mylog;
}

// Operator overloads

/*! \fn logger& logger::operator<<(ostream &os)
 *
 * operator<< definition for logger class. The input parameter is
 * printed out through ostream << if m_must_log flag is set.

 * \param[in] ostream &os Stream to be printed to m_ofs.
 */
logger& logger::operator<< (std::ostream &os)
{
    my_mutex_locker lock(*(my_mutex *)m_transaction_mutex);

    //if (m_must_log == true)
	if (this->m_os!=NULL)
    {
        *(this->m_os) << os;
    }
    return *this;
}

logger& logger::operator<< (std::ostream& (*op)(std::ostream&))
{
    my_mutex_locker lock(*(my_mutex *)m_transaction_mutex);

    /*int aaa,size;
    logger *_llog;
    std::ostream *_os;

    if (m_must_log == true)
    {
        if (m_own_ofs!=NULL)
            (*op)(*(this->m_own_ofs));
        else
            (*op)(*(this->m_ofs));

        size=this->m_borrow_logger.size();

        for (aaa=0;aaa<size;aaa++)
        {
            _llog=this->m_borrow_logger.at(aaa);

            if (_llog!=NULL)
                (*_llog) << op;
        }

        size=m_borrow_os.size();

        for (aaa=0;aaa<size;aaa++)
        {
            _os=m_borrow_os.at(aaa);

            if (_os!=NULL)
                (*_os) << op;		//ATTENTION: quite dangerous because of loop which could be created!!!
        }
    } */
    return *this;
}

logger& logger::operator<< (logger& (*op)(logger& os))
{
    my_mutex_locker lock(*(my_mutex *)m_transaction_mutex);

    return (*op)(*(this));
}

void logger::SetDepth(int depth)
{
	m_depth=depth;
}

void logger::SetDepthSize(int size)
{
	m_depth_size=size;
}

void logger::SetStaticHeaderSize(int size)
{
	 m_static_header_size=size;
}

void logger::SetStaticFooterSize(int size)
{
	 m_static_footer_size=size;
}

void logger::HeaderEnable(bool enable)
{
	m_enable_header=enable;
}

bool logger::GetHeaderEnable()
{
	return m_enable_header;
}

void logger::AddDepth(std::string &str,bool with_static_header)
{
	wxString src(str.c_str()),dst,depth;
	
	if (with_static_header==true)
		dst.Append(' ',m_static_header_size);
	depth.Append("\n");
	depth.Append(' ',m_depth*m_depth_size);
	src.Replace("\n",depth);
	dst.Append(src);

	str.assign(dst.GetData().AsChar());
}

}
