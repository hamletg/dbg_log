#ifndef __DBG_CLASS_PARAM_BASE_H__
#define __DBG_CLASS_PARAM_BASE_H__

#include "dbg_log/dbg_log_defs.h"
#include "dbg_log/inttypes.h"

#include <ostream>

namespace dbg_log
{

class DBG_LOG_API dbg_class;

/*! \class dbg_class_param_base unipro_core/dbg_class.h "unipro_core/dbg_class.h"
 *  \brief Base class of all paramaters used by the debug classes
 */
class DBG_LOG_API dbg_class_param_base
{
public:
    dbg_class_param_base(char *name,bool output=false); //!< Constructor
    dbg_class_param_base(const char *name,bool output=false); //!< Constructor
    dbg_class_param_base(char *name,int len,bool output=false); //!< Constructor
    virtual ~dbg_class_param_base();                    //!< Destructor

    //virtual void Print(logmod::logger &os,bool enters=true)=0;
    virtual void Print(std::ostream &os,bool enters=true)=0;
    bool IsOutput();                        //!< Returns true if the parameter is used to return a value
    void SetOuput(bool value=true);         //!< Set the flag saying if the parameter is used to return a value
    void SetDbgClass(dbg_class *dbgclass);  //!< Set the debug class
    dbg_class *GetDbgClass();               //!< Get the debug class
    void StrConvert(std::string &v, const std::wstring &value);
    void StrConvert(std::string &v, std::wstring &value);
protected:
    const char *m_name;		///< Name the parameter
    bool m_output_param;	///< True is the parameter is used to output a value
    bool m_is_array;        //!< True if the parameter should be handled as an array
    int m_array_len;        //!< If m_is_array is true, gives the len of the array
    dbg_class *m_dbg_class; //!< Pointer to the dbg_class 
};

}

#endif
