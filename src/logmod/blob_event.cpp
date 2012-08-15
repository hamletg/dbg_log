/*!
 * \file logmod/blob_event.cpp
 * \brief Declares a blob event which can be logged
 *
 * \cond
 *__legal_b__
 *__legal_e__
 * \endcond
 */

#include "logmod/logmod_prec.h"
#include "logmod/blob_event.h"

#include <stdlib.h>     //needed for the definition of NULL

namespace logmod
{

blob_event::blob_event():event(&logmod::evt_typ::EVT_BLOB)
{
    m_blob=NULL;
    m_blob_size=0;
    m_blob_type=0;
}

blob_event::~blob_event()
{
}
 
void blob_event::Set(uint8_t *blob,uint32_t size)
{
    m_blob=blob;
    m_blob_size=size;
}

uint8_t *blob_event::Get(uint32_t &size)
{
    size=m_blob_size;
    return m_blob;
}

void blob_event::SetBlobType(uint32_t type)
{
    m_blob_type=type;
}

uint32_t blob_event::GetBlobType()
{
    return m_blob_type;
}

}


