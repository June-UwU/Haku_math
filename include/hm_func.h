/*****************************************************************//**
 * \file   hm_func.h
 * \brief  haku math functions
 * 
 * \author June
 * \date   October 2022
 *********************************************************************/
#pragma once

#include "config.h"
#include "hm_types.h"

/**
 * routine to get the square root of a 32 bit floating point value.
 * 
 * \param val value to find the root
 * \return root of val
 */
hmf32 hm_sqrtf(hmf32 val);

/**
 * routine to get the square root of a 64 bit floating point value.
 *
 * \param val value to find the root
 * \return root of val
 */
hmf64 hm_sqrt(hmf64 val);




#include "impl/hm_func.inl"