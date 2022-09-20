/*****************************************************************//**
 * \file   types.hpp
 * \brief  haku-mathematical types
 * 
 * \author June
 * \date   September 2022
 *********************************************************************/

#pragma once

#ifdef HAKU_USE_SIMD

 /** simd struct vector2d that used the intrincis cms */
typedef struct vector2d
{
	__m128 data;
}vector2d;

/** simd struct vector3d that used the intrincis cms */
typedef struct  vector3d
{
	__m128 data;
}vector3d;

/** simd struct vector4d that used the intrincis cms */
typedef struct vector4d
{
	__m128 data;
}vector4d;

/** simd struct matrix2x2 that used the intrincis cms */
typedef struct mat2x2
{
	__m128 data[2];
}mat2x2;

/** simd struct matrix3x3 that used the intrincis cms */
typedef struct mat3x3
{
	__m128 data[3];
}mat3x3;

/** simd struct matrix4x4 that used the intrincis cms */
typedef struct mat4x4
{
	__m128 data[4];
}mat4x4;

#else

/** simd struct vector2d that is fell back on */
typedef struct vector2d
{
	union
	{
		float x;
		float u;
	};

	union
	{
		float y;
		float v;
	};

}vector2d;

/** simd struct vector3d that is fell back on */
typedef struct vector3d
{
	union
	{
		float x;
		float u;
	};

	union
	{
		float y;
		float v;
	};

	union
	{
		float z;
		float w;
	};

}vector3d;

/** simd struct vector2d that is felt back on */
typedef struct vector4d
{

	union
	{
		float x;
		float u;
	};

	union
	{
		float y;
		float v;
	};

	union
	{
		float z;
		float w;
	};

	union
	{
		float d;
		float t;
	};

}vector4d;

/** 2x2 matrix for haku mathematics */
typedef struct mat2x2
{
	vector2d data[2];
}mat2x2;

/** 3x3 matrix for haku mathematics */
typedef struct mat3x3
{
	vector3d data[3];
}mat3x3;

/** 4x4 matrix for haku mathematics */
typedef struct mat4x4
{
	vector4d data[4];
}mat4x4;

#endif