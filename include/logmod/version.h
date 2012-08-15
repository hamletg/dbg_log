/*!
 * \file logmod/version.h
 * \brief Version info for logmod
 *
 * \cond
 *__legal_b__
 *
 *__legal_e__
 * \endcond
 *
 */

#ifndef __LOGMOD_VERSION_H__
#define __LOGMOD_VERSION_H__

// Bump-up with each new version
#define LOGMOD_MAJOR_VERSION    0
#define LOGMOD_MINOR_VERSION    0
#define LOGMOD_RELEASE_NUMBER   1
#define LOGMOD_VERSION_STRING   _T("logmod 0.0.1")

// Must be updated manually as well each time the version above changes
#define LOGMOD_VERSION_NUM_DOT_STRING   "0.0.1"
#define LOGMOD_VERSION_NUM_STRING       "0001"

// nothing should be updated below this line when updating the version

#define LOGMOD_VERSION_NUMBER (LOGMOD_MAJOR_VERSION * 1000) + (LOGMOD_MINOR_VERSION * 100) + LOGMOD_RELEASE_NUMBER
#define LOGMOD_BETA_NUMBER      1
#define LOGMOD_VERSION_FLOAT LOGMOD_MAJOR_VERSION + (LOGMOD_MINOR_VERSION/10.0) + (LOGMOD_RELEASE_NUMBER/100.0) + (LOGMOD_BETA_NUMBER/10000.0)

// check if the current version is at least major.minor.release
#define LOGMOD_CHECK_VERSION(major,minor,release) \
    (LOGMOD_MAJOR_VERSION > (major) || \
    (LOGMOD_MAJOR_VERSION == (major) && LOGMOD_MINOR_VERSION > (minor)) || \
    (LOGMOD_MAJOR_VERSION == (major) && LOGMOD_MINOR_VERSION == (minor) && LOGMOD_RELEASE_NUMBER >= (release)))

#endif

