/*****************************************************************//**
 * \file   vector.h
 * \brief  haku math vector operations
 * 
 * \author June
 * \date   October 2022
 *********************************************************************/
#pragma once

#include "config.h"
#include "hm_types.h"

/**
 * routine to load a vector4 with ints.
 * 
 * \param vec pointer to the vector to load value into
 * \param x  x value of the vector
 * \param y y value of the vector
 * \param z z value of the vector
 * \param w w value of the vector
 */
void HM_CALL load_vector4_float(vector4* vec, hmf32 x,hmf32 y, hmf32 z,hmf32 w);

/**
 * routine to make a vector zero.
 * 
 * \param vec pointer to a vector
 */
void HM_CALL load_vector4_zero(vector4* vec);

/**
 * routine to make a vector a unit vector.
 * 
 * \param vec pointer to vector to make it unique
 */
void HM_CALL load_unit_vector4(vector4* vec);

/**
 * routine to do vector additions.
 * 
 * \param out_vec pointer to a vector to store the resultant vector
 * \param vec_a pointer to a vector to add
 * \param vec_b pointer to a vector to add
 */
void HM_CALL vector4_add(vector4* out_vec, vector4* vec_a, vector4* vec_b);

/**
 * routine to do vector substractions.
 *
 * \param out_vec pointer to a vector to store the resultant vector
 * \param vec_a pointer to a vector to substract
 * \param vec_b pointer to a vector to substract
 */
void HM_CALL vector4_sub(vector4* out_vec, vector4* vec_a, vector4* vec_b);

/**
 * routine to get the magnitude of a vector.
 * 
 * \param vec pointer to a vector that needs to have it's magnitude 
 * \return magnitude of the vector
 */
hmf64 HM_CALL vector4_magnitude(vector4* vec);

/**
 * routine to do dot product with two vectors.
 * 
 * \param vec_a first vector to do operation on
 * \param vec_b second vector  to do operation on
 * \return returns the dot product
 */
hms64 HM_CALL vector_dot(vector4* vec_a,vector4* vec_b);

#include "impl\vector.inl"

