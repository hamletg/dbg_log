#include "dbg_log/dbg_log_prec.h"

#include "dbg_log/dbg_class_param_base.h"

#include <wx/string.h>

namespace dbg_log
{

dbg_class_param_base::dbg_class_param_base(char *name,bool output)
    : m_name(name), m_output_param(output), m_is_array(false), m_array_len(0), m_dbg_class(0)
{}

dbg_class_param_base::dbg_class_param_base(const char *name,bool output)
    : m_name(name), m_output_param(output), m_is_array(false), m_array_len(0), m_dbg_class(0)
{}

dbg_class_param_base::dbg_class_param_base(char *name,int len,bool output)
    : m_name(name), m_output_param(output), m_is_array(true), m_array_len(len), m_dbg_class(0)
{}

dbg_class_param_base::~dbg_class_param_base()
{}

/*void dbg_class_param_base::Print(logmod::logger &os,bool enters)
{} */

bool dbg_class_param_base::IsOutput()
{
    return m_output_param;
}

void dbg_class_param_base::SetOuput(bool value)
{
    m_output_param=value;
}

void dbg_class_param_base::SetDbgClass(dbg_class *dbgclass)
{
    m_dbg_class=dbgclass;
}

dbg_class *dbg_class_param_base::GetDbgClass()
{
    return m_dbg_class;
}

void dbg_class_param_base::StrConvert(std::string &v,const std::wstring &value)
{
    wxString wx_str;

    wx_str=value;

    v=wx_str.c_str().AsChar();
}

void dbg_class_param_base::StrConvert(std::string &v, std::wstring &value)
{
    wxString wx_str;

    wx_str=value;

    v=wx_str.c_str().AsChar();
}

}
