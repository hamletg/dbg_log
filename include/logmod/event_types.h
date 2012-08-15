/*!
 * \file logmod/event_types.h
 * \brief Define some event_types
 *
 * \cond
 *__legal_b__
 *__legal_e__
 * \endcond
 */

#ifndef __LOGGER_EVENT_TYPES_H__
#define __LOGGER_EVENT_TYPES_H__

#include "logmod/logmod_defs.h"

#include "logmod/event_type.h"

namespace logmod
{

namespace evt_typ
{

DEFINE_LOGGER_EVENT_TYPE(LOGMOD_API,EVT_NONE);
DEFINE_LOGGER_EVENT_TYPE(LOGMOD_API,EVT_DBG_CLASS);
DEFINE_LOGGER_EVENT_TYPE(LOGMOD_API,EVT_BLOB);
DEFINE_LOGGER_EVENT_TYPE(LOGMOD_API,EVT_LOGGER_EVENT);
DEFINE_LOGGER_EVENT_TYPE(LOGMOD_API,EVT_OPTION_EVENT);

}

}

#endif

