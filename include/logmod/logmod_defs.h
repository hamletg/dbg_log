/*!
 * \file dbg_log/logger_defs.h
 * \brief Definitions needed for logger
 *
 * \cond
 *__legal_b__
 *
 *__legal_e__
 * \endcond
 *
 */

#ifndef __LOGMOD_DEFS_H__
#define __LOGMOD_DEFS_H__

#ifdef LOGMOD_EXPORTS
#define LOGMOD_API __declspec(dllexport)
#elif LOGMOD_USE
#define LOGMOD_API __declspec(dllimport)
#else
#define LOGMOD_API
#endif

#ifndef _MSC_VER
#include "logmod/unix/setup.h"
#endif

#include "logmod/inttypes.h"

#endif

