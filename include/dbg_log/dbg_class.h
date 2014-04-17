#ifndef __DBG_CLASS_H__
#define __DBG_CLASS_H__

#include "dbg_log/dbg_log_defs.h"
#include "dbg_log/inttypes.h"

#include "dbg_log/dbg_class_prof.h"
#include "dbg_log/dbg_class_prof_bug.h"
#include "dbg_log/dbg_class_function_info.h"
#include "dbg_log/dbg_class_class_info.h"
#include "dbg_log/dbg_class_param_base.h"
#include "dbg_log/dbg_class_param.h"
#include "dbg_log/dbg_class_event.h"
#include "dbg_log/dbg_class_thread.h"
#include "logmod/event_logger.h"

#include "logmod/logger.h"

#include <ostream>
#include <vector>
#include <sstream>
#include <map>

namespace dbg_log
{

class DBG_LOG_API dbg_class
{
public:
    dbg_class(const char *name,bool print_state);
    dbg_class(dbg_class *dbg);
    virtual ~dbg_class();

    void Message(const char *msg);                  //!< Send a message 
    void Message(const std::string &msg);                  //!< Send a message 
    void MessageF(const char *format,...);                  //!< Send a message

    void SetFunctionInfo(dbg_class_function_info *info);
    //static void SetStaticTextCtrl(wxTextCtrl *text);
    //static wxTextCtrl *GetStaticTextCtrl();

    virtual int GetDepth();             //!< Give the calling depth
    void IncDepth(dbg_class_thread *thread_info=NULL);	//!< Increment by one the calling depth
    void DecDepth(dbg_class_thread *thread_info=NULL);	//!< Decrement by one the calling depth
    static void ResetDepth();           //!< Set the depth to zero
    static int Depth(dbg_class_thread **thread_info=NULL);             //!< Give the calling depth
    void AllParamAdded();                           //!< All parameters where added
    void AddParam(dbg_class_param_base *param);     //!< Add a parameter to be traced
    void SetReturn(dbg_class_param_base *ret);      //!< Set the return value to be traced
    void PrintBlankHeader(std::ostream &os);
    void PrintRegId(std::ostream &os, int id);
    void PrintParamHeader(std::ostream &os);
    void PrintReturnHeader(std::ostream &os);
    void PrintCurTime(std::ostream &os);
    void PrintDepth(std::ostream &os);
    void PrintThreadName(std::ostream &os);
    void AddDepth(std::string &str,bool with_static_header);

    static void SetThreadName(const char *name);
    static void SetDifferentiateThread(bool value);
    static uint64_t GetCurTime();
    static uint32_t GetCurThreaId();
    static void SetDefaultLogger(logmod::logger *logger);
    static logmod::logger *GetDefaultLogger();
    static void SetDefaultEventLogger(logmod::event_logger *log);  //!< Set the default event logger

    static void SetThreadNameWidth(int size);
    static int GetThreadNameWidth();
    static void Enable(bool enable=true);
    static void Disable();

    inline std::ostringstream &GetTempOss(bool clear=false)
    {
        if (clear)
            m_os_temp.str("");
        return m_os_temp;
    }
protected:
    static bool m_enable;
    static int m_depth;                             //!< Overall calling depth
    static bool m_diff_thread;
    static int m_thread_name_width;
    static std::string m_depth_str;
    static std::string m_blank_hdr;
    static std::string m_param_hdr;
    static std::string m_blank_param_hdr;
    static std::string m_struct_param_hdr;
    static std::string m_return_hdr;
    int m_my_depth;                                 //!< Local calling depth
    //static wxTextCtrl *m_text;
    bool m_end;                                     //!< True if the last in the stack
    dbg_class *m_dbg_class;                         //!< Pointer to the first dbg_class on the stack
    dbg_class_function_info *m_fct_info;            //!< The class holding info about the function being called
    std::vector<dbg_class_param_base *> m_params;   //!< Vector of parameters
    dbg_class_param_base *m_return;                 //!< The return value
    std::ostringstream m_os_str;                    //!< Output string stream
    std::ostringstream m_os_temp;                    //!< Output string stream
    const char *m_name;
    bool m_print_state;                             //!< If true, the state of the module will be logged
    logmod::logger *m_logger;                       //!< The logger used to ouput traces
    static logmod::logger *m_dft_logger;            //!< The default logger
    static logmod::event_logger *m_dft_event_logger;//!< The default event logger;
    dbg_class_event m_event;                        //!< Event which can be logged
    static std::map<uint64_t,dbg_class_thread> m_named_threads;
    static int m_thread_count;
    dbg_class_thread *m_thread_info;
};

}

#ifdef DBG_LOG

#define DBG_DEFINE_CLASS(type) \
    static dbg_log::dbg_class_class_info m_dbg_class_class_info_##type; \
    virtual dbg_log::dbg_class_class_info *__get_dbg_class_class_info() \
    { \
        return &m_dbg_class_class_info_##type; \
    }

#define DBG_DECLARE_CLASS(type,name) \
    dbg_log::dbg_class_class_info type::m_dbg_class_class_info_##type(name);

#define DBG_CALLMEMBER(name,print_state) \
    static dbg_log::dbg_class_prof __up_dbg_class_member_call_prof(name); \
    static dbg_log::dbg_class_function_info __up_dbg_member_call_info(name); \
    dbg_log::dbg_class __up_dbg_class_member_call(name,print_state); \
    __up_dbg_class_member_call.SetFunctionInfo(&__up_dbg_member_call_info); \
    __up_dbg_class_member_call_prof.IncCall(); \
    __up_dbg_class_member_call_prof.Start(); \
    dbg_log::dbg_class_prof_bug __up_dbg_class_member_call_prof_bug(&__up_dbg_class_member_call_prof)

#define DBG_CALLMEMBER_END \
    __up_dbg_class_member_call.AllParamAdded(); \
    dbg_log::dbg_class __up_dbg_class_member_call_end(&__up_dbg_class_member_call);
//! Macro to trace of function with a return value
/* \param name the name of the member function
 * \param state true if the PrintState should be called, false if not
 * \param type the type of the return value
 * \param var the variable which will store the return value
 *
 */
#define DBG_CALLMEMBER_RET(name,state,type,var) \
    static dbg_log::dbg_class_prof __up_dbg_class_member_call_prof(name); \
    static dbg_log::dbg_class_function_info __up_dbg_member_call_info(name); \
    type var; \
    dbg_log::dbg_class_param<type> __up_dbg_class_param_ret(#var,var); \
    dbg_log::dbg_class __up_dbg_class_member_call(name,state); \
    __up_dbg_class_member_call.SetFunctionInfo(&__up_dbg_member_call_info); \
    __up_dbg_class_member_call.SetReturn(&__up_dbg_class_param_ret); \
    __up_dbg_class_member_call_prof.IncCall(); \
    __up_dbg_class_member_call_prof.Start(); \
    dbg_log::dbg_class_prof_bug __up_dbg_class_member_call_prof_bug(&__up_dbg_class_member_call_prof);

#define DBG_CALLMEMBER_RETREF(name,state,type,var_name,var) \
    static dbg_log::dbg_class_prof __up_dbg_class_member_call_prof(name); \
    static dbg_log::dbg_class_function_info __up_dbg_member_call_info(name); \
    type &var_name=var; \
    dbg_log::dbg_class_param<type &> __up_dbg_class_param_ret(#var_name,var_name); \
    dbg_log::dbg_class __up_dbg_class_member_call(name,state); \
    __up_dbg_class_member_call.SetFunctionInfo(&__up_dbg_member_call_info); \
    __up_dbg_class_member_call.SetReturn(&__up_dbg_class_param_ret); \
    __up_dbg_class_member_call_prof.IncCall(); \
    __up_dbg_class_member_call_prof.Start(); \
    dbg_log::dbg_class_prof_bug __up_dbg_class_member_call_prof_bug(&__up_dbg_class_member_call_prof);

#define DBG_PARAM(number,name,type,var) \
    dbg_log::dbg_class_param<type> __up_dbg_class_param##number(name,var); \
    __up_dbg_class_member_call.AddParam(&__up_dbg_class_param##number);

#define DBG_NPARAM(name,type,var) \
    dbg_log::dbg_class_param<type> __up_dbg_class_param##__COUNTER__(name,var); \
    __up_dbg_class_member_call.AddParam(&__up_dbg_class_param##__COUNTER__);

#define DBG_PARAM_OUT(number,name,type,var) \
    dbg_log::dbg_class_param<type> __up_dbg_class_param##number(name,var,true); \
    __up_dbg_class_member_call.AddParam(&__up_dbg_class_param##number);

#define DBG_MSG(msg) __up_dbg_class_member_call.Message(msg);
#define DBG_MSGF(format,...) __up_dbg_class_member_call.MessageF(format,__VA_ARGS__);

#define DBG_MSG_OS(msg) \
    __up_dbg_class_member_call.GetTempOss(true) << msg; \
    __up_dbg_class_member_call.Message(__up_dbg_class_member_call.GetTempOss().str());

#define DBG_SET_THREAD_NAME(name) \
    dbg_log::dbg_class::SetThreadName(name)

#else

#define DBG_DEFINE_CLASS(type)

#define DBG_DECLARE_CLASS(type,name)

#define DBG_CALLMEMBER(name,print_state)
    

#define DBG_CALLMEMBER_END

#define DBG_CALLMEMBER_RET(name,state,type,var) \
    type var;
    
#define DBG_CALLMEMBER_RETREF(name,state,type,var_name,var)

#define DBG_PARAM(number,name,type,var)

#define DBG_NPARAM(name,type,var)

#define DBG_PARAM_OUT(number,name,type,var)

#define DBG_MSG(msg)
#define DBG_MSGF(format,...)

#define DBG_MSG_OS(msg)

#define DBG_SET_THREAD_NAME(name)

#endif

#endif
