/*****************************************************************//**
 * \file   matrix.h
 * \brief  haku math matrix operations
 * 
 * \author June
 * \date   October 2022
 *********************************************************************/
#pragma once

#include "config.h"
#include "hm_types.h"

/**
 * create a matrix from an array of floats.
 * 
 * \param mat pointer to a matrix to load the element
 * \param arr pointer to an array of matrix elements
 */
void load_matrix4x4(matrix4x4* mat, hmf32* arr);

/**
 * adds and store the matrix element to a matrix4x4.
 * 
 * \param out_mat matrix to store the result
 * \param mat_a pointer to a matrix to add
 * \param mat_b pointer to a matrix to add
 */
void matrix4x4_add(matrix4x4* out_mat, matrix4x4* mat_a, matrix4x4* mat_b);

/**
 * substacts and store the matrix element to a matrix4x4.
 *
 * \param out_mat matrix to store the result
 * \param mat_a pointer to a matrix to substracts
 * \param mat_b pointer to a matrix to substracts
 */
void matrix4x4_sub(matrix4x4* out_mat, matrix4x4* mat_a, matrix4x4* mat_b);

/**
 * multiples and store the matrix element to a matrix4x4.
 *
 * \param out_mat matrix to store the result
 * \param mat_a pointer to a matrix to multiply
 * \param mat_b pointer to a matrix to multiply
 */
void matrix4x4_mul(matrix4x4* out_mat, matrix4x4* mat_a, matrix4x4* mat_b);


#include "impl/matrix.inl"