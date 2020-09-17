/*
 * functions.h
 *
 *  Created on: Jul 20, 2020
 *      Author: ronny
 */

#include "arm_math.h"
#include "arm_const_structs.h"
#include <stdlib.h>

void inst_absolute(float32_t in[], float32_t out[]);
void inst_phase(float32_t in[], float32_t out[]);
void unwrap(float32_t in[], float32_t out[]);
void inst_frequency(float32_t in[], float32_t out[]);
void inst_centralized_normalized_absolute(float32_t in[], float32_t out[]);

void mean(float32_t in[], float32_t *out);
void mean_of_squared(float32_t in[], float32_t *out);
void std_dev(float32_t in[], float32_t *out);

void variance(float32_t src[], float32_t *dst);
void gmax(float32_t src[], uint32_t *length, float32_t *maxValue, uint32_t *maxValueIndex);
void central_moment(float32_t src[], uint32_t *length, uint32_t *power, float32_t dst[]);
