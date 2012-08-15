/*!
 * \file logmod/blob_event.h
 * \brief Defines a blob event which can be logged
 *
 * \cond
 *__legal_b__
 *__legal_e__
 * \endcond
 */

#ifndef __LOGGER_BLOB_EVENT_H__
#define __LOGGER_BLOB_EVENT_H__

#include "logmod/logmod_defs.h"
#include "logmod/event.h"
#include "logmod/event_types.h"
#include "logmod/inttypes.h"

namespace logmod
{

/*! \class blob_event logmod/blob_event.h "logmod/blob_event.h"
 *  \brief A blob event, which can store a blob of data
 *
 */
class LOGMOD_API blob_event: public event
{
 public:
    blob_event();
    virtual ~blob_event();
 
    void Set(uint8_t *blob,uint32_t size);
    uint8_t *Get(uint32_t &size);
    void SetBlobType(uint32_t type);
    uint32_t GetBlobType();
 protected:
    uint8_t *m_blob;
    uint32_t m_blob_size;
    uint32_t m_blob_type;
};

}

#endif
