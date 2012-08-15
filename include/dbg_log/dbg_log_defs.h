/*!
 * \file dbg_log/dbg_log_defs.h
 * \brief Definitions needed for dbg_log
 *
 * \cond
 *__legal_b__
 *
 *__legal_e__
 * \endcond
 *
 */

#ifndef __DBG_LOG_DEFS_H__
#define __DBG_LOG_DEFS_H__

#ifdef DBG_LOG_EXPORTS
#define DBG_LOG_API __declspec(dllexport)
#elif DBG_LOG_USE
#define DBG_LOG_API __declspec(dllimport)
#else
#define DBG_LOG_API
#endif

#ifndef _MSC_VER
#include "logmod/unix/setup.h"
#endif

#include "logmod/inttypes.h"

#endif

