#include "dbg_log/dbg_log_prec.h"

#include "dbg_log/dbg_class_param.h"

namespace dbg_log
{

dbg_class_param<const std::wstring &>::dbg_class_param(char *name,const std::wstring &value,bool output)
    :dbg_class_param_base(name,output),m_value(value)
{}

dbg_class_param<const std::wstring &>::dbg_class_param(const char *name,const std::wstring &value,bool output)
    :dbg_class_param_base(name,output),m_value(value)
{}

dbg_class_param<const std::wstring &>::dbg_class_param(char *name,const std::wstring &value,int len,bool output)
    :dbg_class_param_base(name,len,output),m_value(value)
{}
    
dbg_class_param<const std::wstring &>::~dbg_class_param()
{}

void dbg_class_param<const std::wstring &>::Print(logmod::logger &os,bool enters)
{
    std::string v;

    StrConvert(v,m_value);
    if (enters)
    {
        if (!IsOutput())
            os << m_name << " = " << v; // << std::endl;
        else
            os << m_name << " = " << v; // << std::endl;        
    }
    else
    {
        if (!IsOutput())
            os << m_name << " = " << v; // << std::endl;
        else
            os << m_name << " = " << v; // << std::endl;
    }
}

void dbg_class_param<const std::wstring &>::Print(std::ostream &os,bool enters)
{    
    std::string v;

    StrConvert(v,m_value);
    if (enters)
    {        
        if (!IsOutput())
            os << m_name << " = " << v; // << std::endl;
        else
            os << m_name << " = " << v; // << std::endl;        
    }
    else
    {        
        if (!IsOutput())
            os << m_name << " = " << v; // << std::endl;
        else
            os << m_name << " = " << v; // << std::endl;        
    }
}

dbg_class_param< std::wstring &>::dbg_class_param(char *name, std::wstring &value,bool output)
    :dbg_class_param_base(name,output),m_value(value)
{}

dbg_class_param< std::wstring &>::dbg_class_param(const char *name, std::wstring &value,bool output)
    :dbg_class_param_base(name,output),m_value(value)
{}

dbg_class_param< std::wstring &>::dbg_class_param(char *name, std::wstring &value,int len,bool output)
    :dbg_class_param_base(name,len,output),m_value(value)
{}
    
dbg_class_param< std::wstring &>::~dbg_class_param()
{}

void dbg_class_param< std::wstring &>::Print(logmod::logger &os,bool enters)
{
    std::string v;

    StrConvert(v,m_value);
    if (enters)
    {
        if (!IsOutput())
            os << m_name << " = " << v; // << std::endl;
        else
            os << m_name << " = " << v; // << std::endl;        
    }
    else
    {
        if (!IsOutput())
            os << m_name << " = " << v; // << std::endl;
        else
            os << m_name << " = " << v; // << std::endl;
    }
}

void dbg_class_param< std::wstring &>::Print(std::ostream &os,bool enters)
{    
    std::string v;

    StrConvert(v,m_value);
    if (enters)
    {        
        if (!IsOutput())
            os << m_name << " = " << v; // << std::endl;
        else
            os << m_name << " = " << v; // << std::endl;        
    }
    else
    {        
        if (!IsOutput())
            os << m_name << " = " << v; // << std::endl;
        else
            os << m_name << " = " << v; // << std::endl;        
    }
}

}

