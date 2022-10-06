/*****************************************************************//**
 * \file   config.h
 * \brief  haku_math configurations
 * 
 * \author June
 * \date   October 2022
 *********************************************************************/
#pragma once

#include <stdint.h>
#include <float.h>

 /** Haku math bit constrained typedef for internal use, naming convention hm<signed(s)/unsigned(u)><bit length> */

 /** 32 bit floating point */
#define hmf32 float

/** 64 bit floating point */
#define hmf64 double

/** 8 bit signed type */
#define hms8 int8_t

/** 16 bit signed type */
#define hms16 int16_t

/** 32  bit signed type */
#define hms32 int32_t

/** 64  bit signed type */
#define hms64 int64_t

/** 8 bit unsigned type */
#define hmu8 uint8_t

/** 16 bit unsigned type */
#define hmu16 uint16_t

/** 32 bit unsigned type */
#define hmu32 uint32_t

/** 64 bit unsigned type */
#define hmu64 uint64_t


/** simd include handler */
#if (defined(_M_AMD64) || defined(_M_X64) || (_M_IX86_FP == 2)) 
/** haku sse2 specfic define */
#define HM_SSE
#include <smmintrin.h> 

#else

#warning "No SSE2 support or defined, switching to typical fpu math"

#endif

/** dynamically change the calling convention of the project based on the settings */
#ifdef  HM_SSE

#define HM_CALL __vectorcall

#else

#define HM_CALL __fastcall

#endif //  HAKU_

