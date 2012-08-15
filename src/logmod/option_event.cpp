/*!
 * \file logmod/option_event.cpp
 * \brief Declares a logger event which can be logged
 *
 * \cond
 *__legal_b__
 *__legal_e__
 * \endcond
 */

#include "logmod/logmod_prec.h"
#include "logmod/option_event.h"

namespace logmod
{

option_event::option_event():event(&logmod::evt_typ::EVT_OPTION_EVENT),m_sub_type(UNKNOWN),m_value(0)
{
}

option_event::~option_event()
{
}
 
void option_event::SetSubType(uint32_t sub_type)
{
	m_sub_type=sub_type;
}

uint32_t option_event::GetSubType()
{
	return m_sub_type;
}

void option_event::SetValue(uint32_t value)
{
	m_value=value;
}

uint32_t option_event::GetValue()
{
	return m_value;
}

void option_event::SetOption(char *name)
{
	if (name==NULL)
		m_name="";
	else
		m_name=name;
}

const char *option_event::GetOption()
{
	if (m_name.empty())
		return NULL;
	return m_name.c_str();
}

void option_event::SetValue(char *val)
{
	if (val!=NULL)
		m_str_val=val;
}
bool option_event::GetValue(std::string &str)
{
	if (m_str_val.empty())
		return false;
	str=m_str_val;
	return true;
}

void option_event::Normal()
{
	m_sub_type=NORMAL;
}


}


