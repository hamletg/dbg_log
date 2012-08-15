/*!
 * \file logmod/event_type.h
 * \brief Define the type of event
 *
 * \cond
 *__legal_b__
 *__legal_e__
 * \endcond
 */

#include "logmod/logmod_prec.h"

#include "logmod/event_type.h"

#include <stdlib.h>     //needed for the definition of NULL

namespace logmod
{

event_type::event_type(const char *name,const char *cpp_namespace,const char *include)
{
    m_next=m_first;
    m_first=this;
    m_index=m_count;
    m_count++;
    m_name=name;
    m_cpp_namespace=cpp_namespace;
    m_cpp_include_file=include;
    m_event_type_id=m_event_type_id_cur;
    m_event_type_id_cur++;
}

event_type::event_type(const char *name,uint32_t id,const char *cpp_namespace,const char *include)
{
    m_next=m_first;
    m_first=this;
    m_index=m_count;
    m_count++;
    m_name=name;
    m_cpp_namespace=cpp_namespace;
    m_cpp_include_file=include;
    m_event_type_id=id;
    m_event_type_id_cur=id+1;
}

event_type::~event_type()
{
}

uint32_t event_type::m_event_type_id_cur=0;
uint32_t event_type::m_count=0;
event_type *event_type::m_first=NULL;

uint32_t event_type::GetId()
{
    return m_event_type_id;
}

uint32_t event_type::GetIndex()
{
    return m_index;
}

event_type *event_type::GetNext()
{
    return m_next;
}

const char *event_type::GetName()
{
    return m_name;
}

const char *event_type::GetCppNameSpace()
{
    return m_cpp_namespace;
}
const char *event_type::GetIncludeFile()
{
    return m_cpp_include_file;
}

event_type *event_type::GetFirst()
{
    return m_first;
}

uint32_t event_type::GetCount()
{
    return m_count;
}

bool event_type::operator==( event_type &type) const
{
    return (type.m_event_type_id==m_event_type_id);
}

}

