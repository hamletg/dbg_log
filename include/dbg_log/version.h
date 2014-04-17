/*!
 * \file dbg_log/version.h
 * \brief Version info for dbg_log
 *
 * \cond
 *__legal_b__
 *
 *__legal_e__
 * \endcond
 *
 */

#ifndef __DBG_LOG_VERSION_H__
#define __DBG_LOG_VERSION_H__

// Bump-up with each new version
#define DBG_LOG_MAJOR_VERSION    0
#define DBG_LOG_MINOR_VERSION    0
#define DBG_LOG_RELEASE_NUMBER   2
#define DBG_LOG_VERSION_STRING   _T("dbg_log 0.0.2")

// Must be updated manually as well each time the version above changes
#define DBG_LOG_VERSION_NUM_DOT_STRING   "0.0.2"
#define DBG_LOG_VERSION_NUM_STRING       "0002"

// nothing should be updated below this line when updating the version

#define DBG_LOG_VERSION_NUMBER (DBG_LOG_MAJOR_VERSION * 1000) + (DBG_LOG_MINOR_VERSION * 100) + DBG_LOG_RELEASE_NUMBER
#define DBG_LOG_BETA_NUMBER      1
#define DBG_LOG_VERSION_FLOAT DBG_LOG_MAJOR_VERSION + (DBG_LOG_MINOR_VERSION/10.0) + (DBG_LOG_RELEASE_NUMBER/100.0) + (DBG_LOG_BETA_NUMBER/10000.0)

// check if the current version is at least major.minor.release
#define DBG_LOG_CHECK_VERSION(major,minor,release) \
    (DBG_LOG_MAJOR_VERSION > (major) || \
    (DBG_LOG_MAJOR_VERSION == (major) && DBG_LOG_MINOR_VERSION > (minor)) || \
    (DBG_LOG_MAJOR_VERSION == (major) && DBG_LOG_MINOR_VERSION == (minor) && DBG_LOG_RELEASE_NUMBER >= (release)))

#endif

