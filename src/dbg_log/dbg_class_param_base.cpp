#include "dbg_log/dbg_log_prec.h"

#include "dbg_log/dbg_class_param_base.h"

namespace dbg_log
{

dbg_class_param_base::dbg_class_param_base(char *name,bool output)
    :m_name(name),m_output_param(output),m_is_array(false),m_array_len(0)
{}

dbg_class_param_base::dbg_class_param_base(char *name,int len,bool output)
    :m_name(name),m_output_param(output),m_is_array(true),m_array_len(len)
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

}
