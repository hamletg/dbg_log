#ifndef __DBG_CLASS_PARAM_H__
#define __DBG_CLASS_PARAM_H__

#include <dbg_log/dbg_log_defs.h>
#include <dbg_log/inttypes.h>
#include <dbg_log/dbg_class_param_base.h>
#include <logmod/logger.h>

#include <ostream>
#include <iomanip>
#include <vector>

namespace dbg_log
{

/*! \class dbg_class_param unipro_core/dbg_class.h "unipro_core/dbg_class.h"
 *  \brief Template class for handling a paramter of type T
 */
template<typename T>
class dbg_class_param: public dbg_class_param_base
{
public:
    dbg_class_param(char *name,T &value,bool output=false);     //!< Constructor
    dbg_class_param(const char *name,T &value,bool output=false);     //!< Constructor
    dbg_class_param(char *name,T &value,int len,bool output=false);     //!< Constructor
    virtual ~dbg_class_param();                                 //!< Destructor

    virtual void Print(logmod::logger &os,bool enters=true);    //!< Print the parameter
    virtual void Print(std::ostream &os,bool enters=true);      //!< Print the parameter

    T &m_value;                                                 //!< The actual paramater
};

template<typename T>
dbg_class_param<T>::dbg_class_param(char *name,T &value,bool output)
    :dbg_class_param_base(name,output),m_value(value)
{}

template<typename T>
dbg_class_param<T>::dbg_class_param(const char *name,T &value,bool output)
    :dbg_class_param_base(name,output),m_value(value)
{}

template<typename T>
dbg_class_param<T>::dbg_class_param(char *name,T &value,int len,bool output)
    :dbg_class_param_base(name,len,output),m_value(value)
{}
    
template<typename T>
dbg_class_param<T>::~dbg_class_param()
{}

template<typename T>
void dbg_class_param<T>::Print(logmod::logger &os,bool enters)
{
    if (enters)
    {
        if (!IsOutput())
            os << m_name << " = " << m_value; // << std::endl;
        else
            os << m_name << " = " << m_value; // << std::endl;        
    }
    else
    {
        if (!IsOutput())
            os << m_name << " = " << m_value; // << std::endl;
        else
            os << m_name << " = " << m_value; // << std::endl;
    }
}

template<typename T>
void dbg_class_param<T>::Print(std::ostream &os,bool enters)
{    
    if (enters)
    {        
        if (!IsOutput())
            os << m_name << " = " << m_value; // << std::endl;
        else
            os << m_name << " = " << m_value; // << std::endl;        
    }
    else
    {        
        if (!IsOutput())
            os << m_name << " = " << m_value; // << std::endl;
        else
            os << m_name << " = " << m_value; // << std::endl;        
    }
}

template<typename T>
class dbg_class_param<std::vector<T> >: public dbg_class_param_base
{
public:
    dbg_class_param(char *name,const std::vector<T> &value,bool output=false);     //!< Constructor
    dbg_class_param(const char *name,const std::vector<T> &value,bool output=false);     //!< Constructor
    dbg_class_param(char *name,const std::vector<T> &value,int len,bool output=false);     //!< Constructor
    virtual ~dbg_class_param();                                 //!< Destructor

    void dbg_class_param::Print(std::ostream &os,bool enters);

    const std::vector<T> &m_value;                                                 //!< The actual paramater
};

template<typename T>
dbg_class_param<std::vector<T> >::dbg_class_param(char *name,const std::vector<T> &value,bool output)
    :dbg_class_param_base(name,output),m_value(value)
{}

template<typename T>
dbg_class_param<std::vector<T> >::dbg_class_param(const char *name,const std::vector<T> &value,bool output)
    :dbg_class_param_base(name,output),m_value(value)
{}

template<typename T>
dbg_class_param<std::vector<T> >::dbg_class_param(char *name,const std::vector<T> &value,int len,bool output)
    :dbg_class_param_base(name,len,output),m_value(value)
{}
    
template<typename T>
dbg_class_param<std::vector<T> >::~dbg_class_param()
{}

template<typename T>
void dbg_class_param<std::vector<T> >::Print(std::ostream &os,bool enters)
{
    uint32_t idx;

    os << m_name << " = " << std::endl;

    for (idx=0;idx<m_value.size();++idx)
    {
        os << std::setw(3) << std::dec << idx << " " << m_value[idx] << std::endl;
    }
}

}

#endif
