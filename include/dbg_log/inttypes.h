#ifndef __DBG_LOG_INTTYPES_H__
#define __DBG_LOG_INTTYPES_H__

#ifdef _MSC_VER
#if _MSC_VER < 1600
#include <limits.h>

typedef __int8 int8_t;
typedef __int16 int16_t;
typedef __int32 int32_t;
typedef __int64 int64_t;

typedef unsigned __int8 uint8_t;
typedef unsigned __int16 uint16_t;
typedef unsigned __int32 uint32_t;
typedef unsigned __int64 uint64_t;
#else

#include <stdint.h>

#endif

#define UINT32_T_MAX ULONG_MAX
#else
#ifdef HAVE_STDINT_H
#include <stdint.h>
#endif
#ifdef HAVE_INTTYPES_H
#include <inttypes.h>
#endif
#include <limits.h>
#define UINT32_T_MAX ULONG_MAX
#endif //_MSC_VER

#endif 
