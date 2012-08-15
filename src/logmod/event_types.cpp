/*!
 * \file logmod/event_types.h
 * \brief Declare some event_types
 *
 * \cond
 *__legal_b__
 *__legal_e__
 * \endcond
 */

#include "logmod/logmod_prec.h"

#include "logmod/event_types.h"

namespace logmod
{

namespace evt_typ
{

DECLARE_LOGGER_EVENT_TYPE_INFO("logger::evt_typ","logmod/event_types");

DECLARE_LOGGER_EVENT_TYPE(LOGMOD_API,EVT_NONE);
DECLARE_LOGGER_EVENT_TYPE(LOGMOD_API,EVT_DBG_CLASS);
DECLARE_LOGGER_EVENT_TYPE(LOGMOD_API,EVT_BLOB);
DECLARE_LOGGER_EVENT_TYPE(LOGMOD_API,EVT_LOGGER_EVENT);
DECLARE_LOGGER_EVENT_TYPE(LOGMOD_API,EVT_OPTION_EVENT);

}

}



