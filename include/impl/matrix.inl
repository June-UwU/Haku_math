/*****************************************************************//**
 * \file   matrix.inl
 * \brief  matrix header file inlines
 * 
 * \author June
 * \date   October 2022
 *********************************************************************/
#pragma once

#include "../config.h"
#include "../hm_types.h"


hmf32 m128_horizontal_sum(__m128* vec)
{
#ifdef HM_SSE
	__m128 imed1 = *vec;
	__m128 imed2 = _mm_shuffle_ps(imed1, imed1, _MM_SHUFFLE(0, 1, 2, 3));
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

void load_matrix4x4(matrix4x4* mat, hmf32* arr)
{
#ifdef HM_SSE
	mat->row[0] = _mm_set_ps(arr[0], arr[1], arr[2], arr[3]);
	mat->row[1] = _mm_set_ps(arr[4], arr[5], arr[6], arr[7]);
	mat->row[2] = _mm_set_ps(arr[8], arr[9], arr[10], arr[11]);
	mat->row[3] = _mm_set_ps(arr[12], arr[13], arr[14], arr[15]);
#else
	for (hmu32 i = 0; i < 4; i++)
	{
		mat->row[i].x = arr[(i * 4) + 0];
		mat->row[i].y = arr[(i * 4) + 1];
		mat->row[i].z = arr[(i * 4) + 2];
		mat->row[i].w = arr[(i * 4) + 3];
	}
#endif // HM_SSE
}

void matrix4x4_add(matrix4x4* out_mat, matrix4x4* mat_a, matrix4x4* mat_b)
{
#ifdef HM_SSE
	out_mat->row[0] = _mm_add_ps(mat_a->row[0], mat_b->row[0]);
	out_mat->row[1] = _mm_add_ps(mat_a->row[1], mat_b->row[1]);
	out_mat->row[2] = _mm_add_ps(mat_a->row[2], mat_b->row[2]);
	out_mat->row[3] = _mm_add_ps(mat_a->row[3], mat_b->row[3]);
#else
	for (hmu32 i = 0; i < 4; i++)
	{
		out_mat->row[i].x = mat_a->row[i].x + mat_b->row[i].x;
		out_mat->row[i].y = mat_a->row[i].y + mat_b->row[i].y;
		out_mat->row[i].z = mat_a->row[i].z + mat_b->row[i].z;
		out_mat->row[i].w = mat_a->row[i].w + mat_b->row[i].w;
	}
#endif // HM_SSE

}

void matrix4x4_sub(matrix4x4* out_mat, matrix4x4* mat_a, matrix4x4* mat_b)
{
#ifdef HM_SSE
	out_mat->row[0] = _mm_sub_ps(mat_a->row[0], mat_b->row[0]);
	out_mat->row[1] = _mm_sub_ps(mat_a->row[1], mat_b->row[1]);
	out_mat->row[2] = _mm_sub_ps(mat_a->row[2], mat_b->row[2]);
	out_mat->row[3] = _mm_sub_ps(mat_a->row[3], mat_b->row[3]);
#else
	for (hmu32 i = 0; i < 4; i++)
	{
		out_mat->row[i].x = mat_a->row[i].x - mat_b->row[i].x;
		out_mat->row[i].y = mat_a->row[i].y - mat_b->row[i].y;
		out_mat->row[i].z = mat_a->row[i].z - mat_b->row[i].z;
		out_mat->row[i].w = mat_a->row[i].w - mat_b->row[i].w;
	}
#endif // HM_SSE
}

void matrix4x4_mul(matrix4x4* out_mat, matrix4x4* mat_a, matrix4x4* mat_b)
{
	// TODO : make sure there is no other way to do this
#ifdef HM_SSE
	hmf32 arr[4 * 4];
	_mm_store_ps(&arr[0], mat_a->row[0]);
	_mm_store_ps(&arr[4], mat_a->row[1]);
	_mm_store_ps(&arr[8], mat_a->row[2]);
	_mm_store_ps(&arr[12], mat_a->row[3]);

	__m128 c[4];

	for (hmu32 i = 0; i < 4; i++)
	{
		c[i] = _mm_setr_ps(arr[i], arr[i + 4], arr[i + 8], arr[i + 12]);
	}

	__m128 imm_1x1 = _mm_mul_ps(mat_b->row[0], c[0]);
	__m128 imm_1x2 = _mm_mul_ps(mat_b->row[0], c[1]);
	__m128 imm_1x3 = _mm_mul_ps(mat_b->row[0], c[2]);
	__m128 imm_1x4 = _mm_mul_ps(mat_b->row[0], c[3]);

	__m128 imm_2x1 = _mm_mul_ps(mat_b->row[1], c[0]);
	__m128 imm_2x2 = _mm_mul_ps(mat_b->row[1], c[1]);
	__m128 imm_2x3 = _mm_mul_ps(mat_b->row[1], c[2]);
	__m128 imm_2x4 = _mm_mul_ps(mat_b->row[1], c[3]);

	__m128 imm_3x1 = _mm_mul_ps(mat_b->row[2], c[0]);
	__m128 imm_3x2 = _mm_mul_ps(mat_b->row[2], c[1]);
	__m128 imm_3x3 = _mm_mul_ps(mat_b->row[2], c[2]);
	__m128 imm_3x4 = _mm_mul_ps(mat_b->row[2], c[3]);

	__m128 imm_4x1 = _mm_mul_ps(mat_b->row[3], c[0]);
	__m128 imm_4x2 = _mm_mul_ps(mat_b->row[3], c[1]);
	__m128 imm_4x3 = _mm_mul_ps(mat_b->row[3], c[2]);
	__m128 imm_4x4 = _mm_mul_ps(mat_b->row[3], c[3]);

	hmf32 val_1x1 = m128_horizontal_sum(&imm_1x1);
	hmf32 val_1x2 = m128_horizontal_sum(&imm_1x2);
	hmf32 val_1x3 = m128_horizontal_sum(&imm_1x3);
	hmf32 val_1x4 = m128_horizontal_sum(&imm_1x4);

	hmf32 val_2x1 = m128_horizontal_sum(&imm_2x1);
	hmf32 val_2x2 = m128_horizontal_sum(&imm_2x2);
	hmf32 val_2x3 = m128_horizontal_sum(&imm_2x3);
	hmf32 val_2x4 = m128_horizontal_sum(&imm_2x4);

	hmf32 val_3x1 = m128_horizontal_sum(&imm_3x1);
	hmf32 val_3x2 = m128_horizontal_sum(&imm_3x2);
	hmf32 val_3x3 = m128_horizontal_sum(&imm_3x3);
	hmf32 val_3x4 = m128_horizontal_sum(&imm_3x4);

	hmf32 val_4x1 = m128_horizontal_sum(&imm_4x1);
	hmf32 val_4x2 = m128_horizontal_sum(&imm_4x2);
	hmf32 val_4x3 = m128_horizontal_sum(&imm_4x3);
	hmf32 val_4x4 = m128_horizontal_sum(&imm_4x4);

	out_mat->row[0] = _mm_set_ps(
		val_1x1,
		val_1x2,
		val_1x3,
		val_1x4
	);

	out_mat->row[1] = _mm_set_ps(
		val_2x1,
		val_2x2,
		val_2x3,
		val_2x4
	);

	out_mat->row[2] = _mm_set_ps(
		val_3x1,
		val_3x2,
		val_3x3,
		val_3x4
	);

	out_mat->row[3] = _mm_set_ps(
		val_4x1,
		val_4x2,
		val_4x3,
		val_4x4
	);

#else

	for (hmu32 i = 0; i < 4; i++)
	{
		out_mat->row[i].x = mat_a->row[i].x * mat_b->row[0].x + mat_a->row[i].y * mat_b->row[1].x
			+ mat_a->row[i].z * mat_b->row[2].x + mat_a->row[0].w * mat_b->row[3].x;

		out_mat->row[i].y = mat_a->row[i].x * mat_b->row[0].y + mat_a->row[i].y * mat_b->row[1].y
			+ mat_a->row[i].z * mat_b->row[2].y + mat_a->row[i].w * mat_b->row[3].y;

		out_mat->row[i].z = mat_a->row[i].x * mat_b->row[0].z + mat_a->row[i].y * mat_b->row[1].z
			+ mat_a->row[i].z * mat_b->row[2].z + mat_a->row[i].w * mat_b->row[3].z;

		out_mat->row[i].w = mat_a->row[i].x * mat_b->row[0].w + mat_a->row[i].y * mat_b->row[1].w
			+ mat_a->row[i].z * mat_b->row[2].w + mat_a->row[i].w * mat_b->row[3].w;
	}

#endif // HM_SSE
}
