/*!
 * \file dbg_log/version.h
 * \brief Version info for log_sqlite
 *
 * \cond
 *__legal_b__
 *
 *__legal_e__
 * \endcond
 *
 */

#ifndef __LOG_SQLITE_VERSION_H__
#define __LOG_SQLITE_VERSION_H__

// Bump-up with each new version
#define LOG_SQLITE_MAJOR_VERSION    0
#define LOG_SQLITE_MINOR_VERSION    0
#define LOG_SQLITE_RELEASE_NUMBER   1
#define LOG_SQLITE_VERSION_STRING   _T("log_sqlite 0.0.1")

// Must be updated manually as well each time the version above changes
#define LOG_SQLITE_VERSION_NUM_DOT_STRING   "0.0.1"
#define LOG_SQLITE_VERSION_NUM_STRING       "0001"

// nothing should be updated below this line when updating the version

#define LOG_SQLITE_VERSION_NUMBER (LOG_SQLITE_MAJOR_VERSION * 1000) + (LOG_SQLITE_MINOR_VERSION * 100) + LOG_SQLITE_RELEASE_NUMBER
#define LOG_SQLITE_BETA_NUMBER      1
#define LOG_SQLITE_VERSION_FLOAT LOG_SQLITE_MAJOR_VERSION + (LOG_SQLITE_MINOR_VERSION/10.0) + (LOG_SQLITE_RELEASE_NUMBER/100.0) + (LOG_SQLITE_BETA_NUMBER/10000.0)

// check if the current version is at least major.minor.release
#define LOG_SQLITE_CHECK_VERSION(major,minor,release) \
    (LOG_SQLITE_MAJOR_VERSION > (major) || \
    (LOG_SQLITE_MAJOR_VERSION == (major) && LOG_SQLITE_MINOR_VERSION > (minor)) || \
    (LOG_SQLITE_MAJOR_VERSION == (major) && LOG_SQLITE_MINOR_VERSION == (minor) && LOG_SQLITE_RELEASE_NUMBER >= (release)))

#endif

