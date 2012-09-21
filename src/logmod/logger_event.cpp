/*!
 * \file logmod/logger_event.cpp
 * \brief Declares a logger event which can be logged
 *
 * \cond
 *__legal_b__
 *__legal_e__
 * \endcond
 */

#include "logmod/logmod_prec.h"
#include "logmod/logger_event.h"

#include <sstream>
#include <iomanip>

namespace logmod
{

logger_event::logger_event():event(&logmod::evt_typ::EVT_LOGGER_EVENT),m_sub_type(UNKNOWN),m_value(0)
{
}

logger_event::~logger_event()
{
}

void logger_event::SetSubType(uint32_t sub_type)
{
	m_sub_type=sub_type;
}

uint32_t logger_event::GetSubType()
{
	return m_sub_type;
}

void logger_event::SetValue(uint32_t value)
{
	m_value=value;
}

uint32_t logger_event::GetValue()
{
	return m_value;
}

void logger_event::SetName(char *name)
{
	if (name==NULL)
		m_name="";
	else
		m_name=name;
}

const char *logger_event::GetName()
{
	if (m_name.empty())
		return NULL;
	return m_name.c_str();
}

void logger_event::NamedThread()
{
	m_sub_type=NAMED_THREAD;		
}

void logger_event::EndOfThread()
{
	m_sub_type=THREAD_END;
}

void logger_event::Error()
{
    m_sub_type=ERROR_MSG;
}

std::ostream &logger_event::PrintString(std::ostream &os)
{
	std::ostringstream oss;

	/*if self.m_sub_type<len(self.m_sub_type_names):
            sub_type_name=self.m_sub_type_names[self.m_sub_type]
            sub_type=self.m_sub_type
        else:
            sub_type_name=self.m_sub_type_names[0]+("(%i)" % self.m_sub_type)
            sub_type=0
        
        value=("%i" %self.m_value).ljust(7)
        result=sub_type_name.ljust(16)+" ThreadID="+value+" Name="+self.m_name+"\n"
        return result */
	oss << std::setiosflags(std::ios::left) << std::setw(16);
        
	switch (m_sub_type)
	{
		case UNKNOWN:
			oss << "UNK_SUB_TYPE";
			break;
		case NAMED_THREAD:
			oss << "NAMED_THREAD";
			break;
		case THREAD_END:
			oss << "THREAD_END";
			break;
		case ERROR_MSG:
			oss << "ERROR_MSG";
			break;
	}
	oss << " ThreadID=";
	oss << std::setiosflags(std::ios::right) << std::setw(7) << m_value << " Name=" << m_name;

	os << oss.str();
	return os;
}

}


