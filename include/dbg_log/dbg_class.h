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
#include "logmod/event_logger.h"

#include "logmod/logger.h"

#include <ostream>
#include <vector>
#include <sstream>

namespace dbg_log
{

class DBG_LOG_API dbg_class
{
public:
	dbg_class(const char *name,bool print_state);
	dbg_class(dbg_class *dbg);
	virtual ~dbg_class();

	void Message(const char *msg);                  //!< Send a message 

	void SetFunctionInfo(dbg_class_function_info *info);
	//static void SetStaticTextCtrl(wxTextCtrl *text);
	//static wxTextCtrl *GetStaticTextCtrl();

	virtual int GetDepth();             //!< Give the calling depth
    void IncDepth();                    //!< Increment by one the calling depth
    void DecDepth();                    //!< Decrement by one the calling depth
    static void ResetDepth();           //!< Set the depth to zero
	void AllParamAdded();                           //!< All parameters where added
	void AddParam(dbg_class_param_base *param);     //!< Add a parameter to be traced
	void SetReturn(dbg_class_param_base *ret);      //!< Set the return value to be traced
	void PrintBlankHeader(std::ostream &os);
	void PrintProcessId(std::ostream &os, int id);
	void PrintParamHeader(std::ostream &os);
	void PrintReturnHeader(std::ostream &os);
	void PrintCurTime(std::ostream &os);
	void PrintDepth(std::ostream &os);
	static uint64_t GetCurTime();
	static uint32_t GetCurThreaId();
	static void SetDefaultLogger(logmod::logger *logger);
	static logmod::logger *GetDefaultLogger();
	static void SetDefaultEventLogger(logmod::event_logger *log);  //!< Set the default event logger
protected:
	static int m_depth;                             //!< Overall calling depth
    int m_my_depth;                                 //!< Local calling depth
	//static wxTextCtrl *m_text;
	bool m_end;                                     //!< True if the last in the stack
    dbg_class *m_dbg_class;                         //!< Pointer to the first dbg_class on the stack
	dbg_class_function_info *m_fct_info;            //!< The class holding info about the function being called
	std::vector<dbg_class_param_base *> m_params;   //!< Vector of parameters
	dbg_class_param_base *m_return;                 //!< The return value
	std::ostringstream m_os_str;                    //!< Output string stream
	const char *m_name;
	bool m_print_state;                             //!< If true, the state of the module will be logged
	logmod::logger *m_logger;                       //!< The logger used to ouput traces
    static logmod::logger *m_dft_logger;            //!< The default logger
	static logmod::event_logger *m_dft_event_logger;//!< The default event logger;
	dbg_class_event m_event;                        //!< Event which can be logged
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

#define DBG_PARAM(number,name,type,var) \
	dbg_log::dbg_class_param<type> __up_dbg_class_param##number(name,var); \
	__up_dbg_class_member_call.AddParam(&__up_dbg_class_param##number);

#else

#define DBG_DEFINE_CLASS(type)

#define DBG_DECLARE_CLASS(type,name)

#define DBG_CALLMEMBER(name,print_state)
    

#define DBG_CALLMEMBER_END

#define DBG_CALLMEMBER_RET(name,state,type,var) \
	type var;
	

#define DBG_PARAM(number,name,type,var)

#endif

#endif
