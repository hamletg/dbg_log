/*!
 * \file logmod/event_utils.cpp
 * \brief Defines some utilities to handle events
 *
 * \cond
 *__legal_b__
 *__legal_e__
 * \endcond
 */

#include "logmod/logmod_prec.h"
#include "logmod/event_utils.h"

#include <iomanip>
#include <sstream>

namespace logmod
{

event_utils::event_utils()
{
	m_display_time_kind=EVT_TIME_ABSOLUTE;
	m_display_time=true;	
	m_start_time=0;
	m_time_width=11;

	m_display_key=true;
	m_key_width=10;

	m_display_ts=true;
	m_ts_width=13;

	m_display_thread_id=true;
	m_thread_id_width[0]=4;
	m_display_thread_id_kind=EVT_THREAD_ID;
}

event_utils::~event_utils()
{
}

std::ostream &event_utils::PrintTime(std::ostream &os,logmod::event *evt)
{
	uint64_t the_time;
	std::ostringstream oss;

	if ((m_display_time==false)||(evt==NULL))
		return os;
	
	if (m_display_time_kind==EVT_TIME_ABSOLUTE)
	{
		the_time=evt->GetTime();
	}
	else if (m_display_time_kind==EVT_TIME_DELTA)
	{
		the_time=evt->GetTime()-m_start_time;
	}
	else if (m_display_time_kind==EVT_TIME_DELTA_TEST)
	{
      //      start_time=self.GetTestStartTime(evt)
      //      if start_time==None:
      //          txt=""
      //      else:
      //          txt="%i" % (evt.GetTime()-start_time)
	}
	oss << std::setiosflags(std::ios::right) << std::setw(m_time_width) << the_time;
	os << "[" << oss.str().substr(0,m_time_width-3) << " " << oss.str().substr(m_time_width-3) << " ms]";

	return os;
}

std::ostream &event_utils::PrintKey(std::ostream &os,logmod::event *evt)
{
	std::ostringstream oss;

	if ((m_display_key==false)||(evt==NULL))
		return os;
	//if self.m_display_event_key==False:
    //        return ""
    //    txt="%i" % evt.m_key
    //    txt=txt.ljust(10)
    //    return txt
	oss << std::setw(m_key_width) << evt->GetKey();
	os << oss.str();
	return os;
}

std::ostream &event_utils::PrintTS(std::ostream &os,logmod::event *evt)
{
	std::ostringstream oss;

	if ((m_display_ts==false)||(evt==NULL))
		return os;
//if self.m_display_event_ts==False:
//            return ""
//        txt="%s" % evt.GetTS()
//        txt=txt.rjust(13)
//        r=txt[:-9]+" "+txt[-9:-6]+" "+txt[-6:]
//        return "["+r+" ns]"
	oss << std::setiosflags(std::ios::right) << std::setw(m_ts_width) << evt->GetTS();
	os	<< "[" << oss.str().substr(0,m_ts_width-9) << " " << oss.str().substr(m_ts_width-9,3) 
		<< " " << oss.str().substr(m_ts_width-6) << " ns]"; 
	return os;
}

std::ostream &event_utils::PrintThreadID(std::ostream &os,logmod::event *evt)
{
	std::ostringstream oss;

	if ((m_display_thread_id==false)||(evt==NULL))
		return os;
//if self.m_display_thread_id_type==0:
            /*txt="[ThreadId %4i]" % evt.GetThreadId()
        elif self.m_display_thread_id_type==1:
            key=self.GetThreadIDKey(evt)
            txt="[ThreadKey %3i]" % key
        elif self.m_display_thread_id_type==2:
            name=self.GetThreadIDName(evt)
            name=name.ljust(12)
            txt="[Thread "+name+"]"
        elif self.m_display_thread_id_type==3:
            name=self.GetThreadIDName(evt)
            if len(name)>12:
                name=name[0:12]
            name=name.ljust(12)
            txt="[Thread "+name+"]"
        else:
            txt=""
        return txt */
	switch (m_display_thread_id_kind)
	{
		case EVT_THREAD_ID:
			oss << "[ThreadId " << std::setiosflags(std::ios::right) << std::setw(m_thread_id_width[0]) <<  evt->GetThreadId() << "]";
			break;
		case EVT_THREAD_ID_KEY:
			//oss << "[ThreadKey " << std::setiosflags(std::ios::right) << std::setw(m_thread_id_width[0]) <<  evt->GetThreadId() << "]";
			break;
		case EVT_THREAD_ID_FULL_NAME:
			break;
		case EVT_THREAD_ID_CROP_NAME:
			break;
	}
	os << oss.str();
	return os;
}

}


