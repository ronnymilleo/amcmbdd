/*
 * functions.c
 *
 *  Created on: Jul 20, 2020
 *      Author: ronny
 */

#include "functions.h"

// Preprocessing

void inst_absolute(float32_t src[], float32_t dst[], uint32_t *length){
	arm_abs_f32(&src[0], &dst[0], *length);
}

void inst_phase(float32_t src[], float32_t dst[], uint32_t *length){

}
void inst_unwrapped_phase(float32_t src[], float32_t dst[], uint32_t *length){

}
void inst_frequency(float32_t src[], float32_t dst[], uint32_t *length){

}
void inst_centralized_normalized_absolute(float32_t src[], float32_t dst[], uint32_t *length){

}

void mean(float32_t src[], float32_t *dst, uint32_t *length) {
	arm_mean_f32(&src[0], *length, dst);
}

void mean_of_squared(float32_t src[], float32_t *dst, uint32_t *length) {
	float32_t result;
	arm_power_f32(&src[0], *length, &result);
	*dst = result / (float32_t) *length;
}

void std_dev(float32_t src[], float32_t *dst, uint32_t *length) {
	arm_std_f32(&src[0], *length, dst);
}

void variance(float32_t src[], float32_t *dst, uint32_t *length) {
	arm_var_f32(&src[0], *length, dst);
}

void gmax(float32_t src[], uint32_t *length, float32_t *maxValue, uint32_t *maxValueIndex){
	uint32_t fftSize = 1024;
	uint32_t ifftFlag = 0;
	uint32_t doBitReverse = 1;
	float32_t *result_mag;
	float32_t result_fft[2048] = {0};

	result_mag = (float32_t *) malloc(fftSize/2 * sizeof(float32_t));

	for(int i = 0; i < 2048; i++){
		result_fft[i] = src[i];
	}

	arm_cfft_f32(&arm_cfft_sR_f32_len1024, &result_fft[0], ifftFlag, doBitReverse);
	arm_cmplx_mag_f32(result_fft, result_mag, fftSize/2);
	arm_max_f32(result_mag, fftSize/2, maxValue, maxValueIndex);
	free(result_mag);
}

void central_moment(float32_t src[], uint32_t *length, uint32_t *power, float32_t *dst){
	float32_t m = 0.0f;
	float32_t *sub, *mult;
	sub = (float32_t *) malloc((*length) * sizeof(float32_t));
	mult = (float32_t *) malloc((*length) * sizeof(float32_t));
	//float32_t parcial[2048] = {0};
	//float32_t mult[2048] = {0};
	arm_mean_f32(src, *length, &m);
	for(uint32_t i = 0; i < (*length); i = i + 4){
		sub[i+0] = (src[i+0] - m);
		sub[i+1] = (src[i+1] - m);
		sub[i+2] = (src[i+2] - m);
		sub[i+3] = (src[i+3] - m);
	}
	arm_mult_f32(sub, sub, mult, *length);
	arm_mean_f32(mult, *length, dst);
	free(sub);
	free(mult);
}
