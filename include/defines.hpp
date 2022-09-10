#pragma once
#include <cstdint>
#include <climits>

/**
 * Checking for SIMD support 
 * 
 *  Reference : https://docs.microsoft.com/en-us/cpp/preprocessor/predefined-macros?redirectedfrom=MSDN&view=msvc-170 
 */
#if _M_IX86_FP == 1 || _M_IX86_FP == 2

#define HAKU_USE_SIMD

#endif

constexpr const f64 fpu_delta = FLT_MIN;