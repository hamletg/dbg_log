/*!
 * \file dbg_log/log_sqlite_defs.h
 * \brief Definitions needed for log_sqlite
 *
 * \cond
 *__legal_b__
 *
 *__legal_e__
 * \endcond
 *
 */

#ifndef __LOG_SQLITE_DEFS_H__
#define __LOG_SQLITE_DEFS_H__

#ifdef LOG_SQLITE_EXPORTS
#define LOG_SQLITE_API __declspec(dllexport)
#elif LOG_SQLITE_USE
#define LOG_SQLITE_API __declspec(dllimport)
#else
#define LOG_SQLITE_API
#endif

#endif

