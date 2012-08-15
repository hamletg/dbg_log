/*!
 * \file dbg_log/log_ice_defs.h
 * \brief Definitions needed for log_ice
 *
 * \cond
 *__legal_b__
 *
 *__legal_e__
 * \endcond
 *
 */

#ifndef __LOG_ICE_DEFS_H__
#define __LOG_ICE_DEFS_H__

#ifdef LOG_ICE_EXPORTS
#define LOG_ICE_API __declspec(dllexport)
#elif LOG_ICE_USE
#define LOG_ICE_API __declspec(dllimport)
#else
#define LOG_ICE_API
#endif

#endif

