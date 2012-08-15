#include "log_ice/log_ice_prec.h"

#include "log_ice/event_logger_impl.h"

#include <string>
#include <sstream>

namespace log_ice
{

event_logger_impl::event_logger_impl()
{
}

event_logger_impl::~event_logger_impl()
{
}

void event_logger_impl::SetLoggerEvent(const ::loggerice::loggereventPtr& s,logmod::logger_event *evt)
{
	if (evt==NULL)
		return;

	evt->SetTS(s->ts);
	evt->SetSrcType(s->srctype);
	evt->SetSrcId(s->srcid);
    evt->SetKind((logmod::event::event_kind)s->kind);
	evt->SetKey(s->key);
	evt->SetTime(s->timeMs);  
	evt->SetThreadId(s->threadId);

	evt->SetSubType(s->subType);
	evt->SetValue(s->value);
	evt->SetName((char *)s->name.c_str());
}

void event_logger_impl::SetOptionEvent(const ::loggerice::optioneventPtr& s,logmod::option_event *evt)
{
	if (evt==NULL)
		return;

	evt->SetTS(s->ts);
	evt->SetSrcType(s->srctype);
	evt->SetSrcId(s->srcid);
    evt->SetKind((logmod::event::event_kind)s->kind);
	evt->SetKey(s->key);
	evt->SetTime(s->timeMs);  
	evt->SetThreadId(s->threadId);

	evt->SetSubType(s->subType);
	evt->SetValue((uint32_t)s->value);
	evt->SetOption((char *)s->name.c_str());
	evt->SetValue((char*)s->strVal.c_str());	
}



int event_logger_impl::GetProxyString(std::string &result,std::string adapter, std::string ip, unsigned short port)
{
	std::ostringstream os;

	os << adapter << ":default ";
	if (!ip.empty())
		os << "-h " << ip;
	if (port!=0)
		os << "-p " << port; 
	result=os.str();
	return 0;
}


}