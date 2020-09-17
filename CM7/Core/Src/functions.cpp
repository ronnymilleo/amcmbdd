/*
 * functions.c
 *
 *  Created on: Jul 20, 2020
 *      Author: ronny
 */

#include <functions.hpp>
#include <main.hpp>
#include "math.h"

// Preprocessing

void inst_absolute(float32_t in[], float32_t out[]){
	int j = 0;
	for(int i = 0; i < 2*frameSize; i = i + 2){
		out[j] = sqrtf(in[i] * in[i] + in[i+1] * in[i+1]);
		j++;
	}
}

void inst_phase(float32_t in[], float32_t out[]){
	int j = 0;
	for(int i = 0; i < 2*frameSize; i = i + 2){
		out[j] = atan2f(in[i+1], in[i]);
		j++;
	}
}

void unwrap(float32_t in[], float32_t out[]){
	/* MATLAB
	k=0; % initialize k to 0
	i=1; % initialize the counter to 1
	alpha=pi; % set alpha to the desired Tolerance. In this case, pi

	for i = 1:(size(u)-1)
	    yout(i,:)=u(i)+(2*pi*k); % add 2*pi*k to ui
	    if((abs(u(i+1)-u(i)))>(abs(alpha)))  %if diff is greater than alpha, increment or decrement k

	        if u(i+1)<u(i)   % if the phase jump is negative, increment k
	            k=k+1;
	        else             % if the phase jump is positive, decrement k
	            k=k-1;
	        end
	    end
	end
	yout((i+1),:)=u(i+1)+(2*pi*k); % add 2*pi*k to the last element of the input
	*/
	uint16_t k = 0;
	float32_t alpha = M_PI;
	float32_t diff = 0.0f;
	for(int i = 0; i < (frameSize - 1); i++){
		out[i] = in[i] + 2*M_PI*k;
		diff = fabsf(in[i+1] - in[i]);
		if(diff > alpha){
			if(in[i+1] < in[i]){
				k++;
			} else {
				k--;
			}
		}
	}
	out[frameSize-1] = in[frameSize-1] + 2*M_PI*k;
}

void inst_frequency(float32_t in[], float32_t out[]){
	float32_t phase[1024] = {0};
	float32_t unwrapped_phase[1024] = {0};
	float32_t C = 1 / M_TWOPI;
	inst_phase(&in[0], &phase[0]);
	unwrap(&phase[0], &unwrapped_phase[0]);
	for(int i = 0; i < (frameSize-1); i++){
		out[i] = C*(unwrapped_phase[i + 1] - unwrapped_phase[i]);
	}
	out[frameSize - 1] = 0;
}

void inst_centralized_normalized_absolute(float32_t in[], float32_t out[]){
	float32_t mean = 0, max = 0;
	uint32_t max_index = 0;
	float32_t *absolute, *normalized;
	absolute = (float32_t *) malloc(frameSize * sizeof(float32_t));
	normalized = (float32_t *) malloc(frameSize * sizeof(float32_t));
	inst_absolute(in, &absolute[0]);
	arm_max_f32(absolute, frameSize, &max, &max_index);
	for(int a = 0; a < frameSize; a++){
		normalized[a] = absolute[a] / max;
	}
	arm_mean_f32(&normalized[0], frameSize, &mean);
	for(int i = 0; i < frameSize; i++){
		out[i] = normalized[i] / mean - 1;
	}
	free(absolute);
	free(normalized);
}

void mean(float32_t in[], float32_t *out) {
	arm_mean_f32(&in[0], frameSize, out);
}

void mean_of_squared(float32_t in[], float32_t *out) {
	float32_t result;
	arm_power_f32(&in[0], frameSize, &result);
	*out = result / (float32_t) frameSize;
}

void std_dev(float32_t in[], float32_t *out) {
	arm_std_f32(&in[0], frameSize, out);
}

void variance(float32_t in[], float32_t *out) {
	arm_var_f32(&in[0], frameSize, out);
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
