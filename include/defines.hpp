/*****************************************************************//**
 * \file   defines.hpp
 * \brief  defines that are nessary or defined
 * 
 * \author June
 * \date   September 2022
 *********************************************************************/

#pragma once
#include <limits>
/**
 * Checking for SIMD support 
 * 
 *  Reference : https://docs.microsoft.com/en-us/cpp/preprocessor/predefined-macros?redirectedfrom=MSDN&view=msvc-170 
 */

/** constant to compare platform */
constexpr const double FLT_DELTA = FLT_MIN;

/** constant that is used for PI */
constexpr const double PI = 3.1415926535897931;


/** simd include handler */
#if __SSE4_1__

#define HAKU_USE_SIMD
#include <emmintrin.h>

#endif