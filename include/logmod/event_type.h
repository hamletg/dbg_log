/*!
 * \file logmod/event_type.h
 * \brief Define the type of event
 *
 * \cond
 *__legal_b__
 *__legal_e__
 * \endcond
 */

#ifndef __LOGGER_EVENT_TYPE_H__
#define __LOGGER_EVENT_TYPE_H__

#include "logmod/logmod_defs.h"
#include "logmod/inttypes.h"

#define DEFINE_LOGGER_EVENT_TYPE(ext,name) \
	extern ext logmod::event_type name;

#define DECLARE_LOGGER_EVENT_TYPE_INFO(cpp_namespace,cpp_include) \
    static const char *s_cpp_ns=cpp_namespace; \
    static const char *s_cpp_inc=cpp_include;

#define DECLARE_LOGGER_EVENT_TYPE_ID(ext,name,id) \
	ext logmod::event_type name(#name,id,s_cpp_ns,s_cpp_inc);

#define DECLARE_LOGGER_EVENT_TYPE(ext,name) \
	ext logmod::event_type name(#name,s_cpp_ns,s_cpp_inc);

namespace logmod
{

class LOGMOD_API event_type
{
 public:
    event_type(const char *name,const char *cpp_namespace,const char *include);
    event_type(const char *name,uint32_t id,const char *cpp_namespace,const char *include);    
    virtual ~event_type();

    uint32_t GetId();
    uint32_t GetIndex();
    event_type *GetNext();
    const char *GetName();
    const char *GetCppNameSpace();          //!< Return the C++ namespace where the event_type is defined
    const char *GetIncludeFile();           //!< Return the include file (without the extension) where the event_type is defined
    static event_type *GetFirst();
    static uint32_t GetCount();

    bool operator==( event_type &type) const;

 protected:
    uint32_t m_index;                       //!< Index of this event_type in the list of even_types
    uint32_t m_event_type_id;               //!< The actual value representing the event_type
    static uint32_t m_event_type_id_cur;    //!< The value of the next m_event_type_id if no value given
    static uint32_t m_count;                //!< Number of event_type
    static event_type *m_first;             //!< Pointer to the first event_tyte
    event_type *m_next;                     //!< Pointer to the next event_type
    const char *m_name;                     //!< Name of the event_type
    const char *m_cpp_namespace;            //!< The C++ namespace where the event_type is defined
    const char *m_cpp_include_file;         //!< The C++ include file (without extension) where the event_type is defined
};

}

#endif
