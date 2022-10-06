/*****************************************************************//**
 * \file   hm_types.h
 * \brief  haku math types, untyped is considered as integers and else its typed
 * 
 * \author June
 * \date   October 2022
 *********************************************************************/
#pragma once

#include "config.h"

#ifdef HM_SSE
/** sse2 vector implementations */

/** sse2 floating point vector defintion */
typedef __m128  vector4;

/** sse2 matrix implementations */
/** sse2 floating 4x4 matrix implementations */
typedef struct matrix4x4
{
	/** matrix is defined four integer vector4f */
	vector4 row[4];
}matrix4x4;

#else

/**
 * fpu declaration for a vector4. the individual elements can be addressed as either the x-y , u-v or a straight plane array.
 */
typedef struct vector4
{
	union
	{
		/** anonymous struct for holding the x-y and u-v addressing  */
		struct
		{
			union
			{
				hmf32 x;
				hmf32 u;
			};

			union
			{
				hmf32 y;
				hmf32 v;
			};

			union
			{
				hmf32 z;
				hmf32 w;
			};

			union
			{
				hmf32 d;
				hmf32 c;
			};
		};

		/** element holding */
		hmf32 ele[4];
	};

}vector4;


/** fpu matrix definitions */

typedef struct matrix4x4
{
	vector4f row[4];

}matrix4x4;

typedef struct matrix4x4d
{
	vector4f row[4];

}matrix4x4d;

#endif // HM_SSE

