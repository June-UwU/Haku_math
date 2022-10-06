/*****************************************************************//**
 * \file   vector.inl
 * \brief  vector operation implementations
 * 
 * \see https://piotte13.github.io/SIMD-Visualiser/#/
 * 
 * \author June
 * \date   October 2022
 *********************************************************************/
#pragma once

#include "../hm_func.h"
#include "../config.h"
#include "../hm_types.h"
#include "vector.h"

/**
 * routine to sum up a vector's elements.
 * 
 * \param vec pointer to the vector to sum of 
 * \return the sum of elements of the vec
 */
hmf32 vector4_horizontal_sum(vector4* vec)
{
#ifdef HM_SSE
	vector4 imed1 = *vec;
	vector4 imed2 = _mm_shuffle_ps(imed1, imed1, _MM_SHUFFLE(0, 1, 2, 3));
	imed1 = _mm_add_ps(imed1, imed2);
	imed2 = _mm_shuffle_ps(imed1, imed1, _MM_SHUFFLE(0, 1, 1, 1));
	imed1 = _mm_add_ps(imed1, imed2);
	hmf32 ret_val = 0;
	_mm_store_ps1(&ret_val, imed1);

	return ret_val;
#else
	return (vec->x + vec->y + vec->z + vec->w);
#endif //HM_SSE
}

void HM_CALL load_vector4_float(vector4* vec, hmf32 x, hmf32 y, hmf32 z, hmf32 w)
{
#ifdef HM_SSE
	* vec = _mm_set_ps(x, y, z, w);
#else
	vec->x = x;
	vec->y = y;
	vec->z = z;
	vec->w = w;
#endif
}

void HM_CALL load_vector4_zero(vector4* vec)
{
#ifdef HM_SSE
	* vec = _mm_setzero_ps();
#else
	for (hmu64 i = 0; i < 4; i++)
	{
		vec->ele[i] = 0.0f;
	}
#endif
}

void HM_CALL load_unit_vector4(vector4* vec)
{
#ifdef HM_SSE
	* vec = _mm_setr_ps(1.0f, 1.0f, 1.0f, 1.0f);
#else
	for (hmu64 i = 0; i < 4; i++)
	{
		vec->ele[i] = 1.0f;
	}
#endif
}


void HM_CALL vector4_add(vector4* out_vec, vector4* vec_a, vector4* vec_b)
{
#ifdef HM_SSE
	* out_vec = _mm_add_ps(*vec_a, *vec_b);
#else
	for (hmu64 i = 0; i < 4; i++)
	{
		out_vec->ele[i] = vec_a->ele[i] + vec_b->ele[i];
	}
#endif // HM_SSE
}

void HM_CALL vector4_sub(vector4* out_vec, vector4* vec_a, vector4* vec_b)
{
#ifdef HM_SSE
	* out_vec = _mm_sub_ps(*vec_a, *vec_b);
#else
	for (hmu64 i = 0; i < 4; i++)
	{
		out_vec->ele[i] = vec_a->ele[i] - vec_b->ele[i];
	}
#endif // HM_SSE
}

inline hmf64 HM_CALL vector4_magnitude(vector4* vec)
{
#ifdef  HM_SSE
	vector4 vec_squ = _mm_mul_ps(*vec, *vec); // squared
	hmf32 ret_val = vector4_horizontal_sum(&vec_squ);
	return hm_sqrtf(ret_val);
#else
	float sum = vec->x + vec->y + vec->z + vec->w;
	return hm_sqrtf(sum);
#endif //  HM_SSE
}

hms64 HM_CALL vector_dot(vector4* vec_a, vector4* vec_b)
{
#ifdef HM_SSE
	vector4 imed1 = _mm_mul_ps(*vec_a, *vec_b);
	return vector4_horizontal_sum(&imed1);
#else
	vector4 out_vec;
	for (hmu64 i = 0; i < 4; i++)
	{
		out_vec.ele[i] = vec_a->ele[i] + vec_b->ele[i];
	}
	hms64 ret_val = 0;
	for (hmu64 i = 0; i < 4; i++)
	{
		ret_val = ret_val + out_vec.ele[i];
	}
	return ret_val;
#endif // HM_SSE
}



