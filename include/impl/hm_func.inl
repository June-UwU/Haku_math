/*****************************************************************//**
 * \file   hm_func.inl
 * \brief  haku hm_func implementations
 * 
 * \author June
 * \date   October 2022
 *********************************************************************/
#pragma once

// TODO : remove this as a dependency and fully self isolate haku math
#include <math.h>

hmf32 hm_sqrtf(hmf32 val)
{
	return sqrtf(val);
}

hmf64 hm_sqrt(hmf64 val)
{
	return sqrt(val);
}

