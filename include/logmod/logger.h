#ifndef __LOGGER_LOGGER_H__
#define __LOGGER_LOGGER_H__

#include "logmod/logmod_defs.h"
#include "logmod/inttypes.h"

#include <ostream>
#include <sstream>

class wxTextCtrl;

namespace logmod
{

class logger_mutex_api
{
public:
    virtual ~logger_mutex_api();
    virtual int Lock()=0;
    virtual int Unlock()=0;
};

class LOGMOD_API logger
{
public:
	template<class T> friend logger& operator<< (logger& os,T& val);
	template<class T> friend logger& operator<< (logger& os,const T& val);
	logger();
	virtual ~logger();

	void SetTextCtrl(wxTextCtrl *text);
	wxTextCtrl *GetTextCtrl();

	void SetOfstream(std::ofstream *ofs);
	std::ofstream *GetOfstream();

	virtual void Begin();
    virtual void End();

	inline logger_mutex_api *GetTransactionMutex()
	{
		return m_transaction_mutex;
	}

	logger& operator<< (std::ostream &os);
    logger& operator<< (std::ostream& (*op)(std::ostream&));
    logger& operator<< (logger& (*op)(logger& os));

	virtual void SetDepth(int depth);
	virtual void SetDepthSize(int size);
	virtual void SetStaticHeaderSize(int size);
	virtual void SetStaticFooterSize(int size);
	virtual void HeaderEnable(bool enable=true);
	virtual bool GetHeaderEnable();
	void AddDepth(std::string &str,bool with_static_header=false);
protected:
	logger_mutex_api *m_transaction_mutex;
	static const int m_time_mode;
	static const int m_add_depth;
	std::ostream *m_os;
	std::ofstream *m_ofs;
	std::streambuf *m_streambuf;
	wxTextCtrl *m_text_ctrl;
	int m_depth;
	int m_depth_size;
	int m_static_header_size;
	int m_static_footer_size;
	bool m_enable_header;
	static bool m_old_way;
};

/*! \brief Mark the beginning of a log transaction
 * A log transaction is atomic, meaning that it will be logged in one block, even if multiple threads use the same
 * logger.
 */
LOGMOD_API logger &begin(logger &mylog);
/*! \brief Mark the end of a log transaction
 * A log transaction is atomic, meaning that it will be logged in one block, even if multiple threads use the same
 * logger.
 */
LOGMOD_API logger &end(logger &mylog);

//Following needed by GCC
template<class T>
logmod::logger& operator<< (logmod::logger& os, const T &val)
{
	if (logmod::logger::m_old_way)
	{
		if (os.m_os!=NULL)
			(*os.m_os) << val;
	}
	return os;
}

template<class T>
logmod::logger& operator<< (logmod::logger& os, T &val)
{
	std::ostringstream os_str;
	std::string str;

	if (logmod::logger::m_old_way)
	{
		if (os.m_os!=NULL)
			(*os.m_os) << val;
	}
	else
	{
		if (os.m_os!=NULL)
		{
			os_str << val;
			str=os_str.str();
			os.AddDepth(str,os.GetHeaderEnable());
			(*os.m_os) << os_str.str();
		}
	}
    return os;
}

}




#endif
