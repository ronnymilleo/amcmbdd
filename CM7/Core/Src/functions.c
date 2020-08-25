/*
 * functions.c
 *
 *  Created on: Jul 20, 2020
 *      Author: ronny
 */

#include "functions.h"

static float32_t pi = 3.141592654f;
extern uint16_t frameSize;
extern uint16_t doubleFrameSize;

// Preprocessing

void inst_absolute(float32_t in[], float32_t out[]){
	int j = 0;
	for(int i = 0; i < doubleFrameSize; i = i + 2){
		out[j] = sqrtf(in[i] * in[i] + in[i+1] * in[i+1]);
		j++;
	}
}

void inst_phase(float32_t in[], float32_t out[]){
	int j = 0;
	for(int i = 0; i < doubleFrameSize; i = i + 2){
		out[j] = atan2(in[i+1], in[i]);
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
	float32_t alpha = pi;
	for(int i = 0; i < (frameSize - 1); i++){
		out[i] = in[i] + 2*pi*k;
		if(abs(in[i+1] - in[i]) > abs(alpha)){
			if(in[i+1] < in[i]){
				k++;
			} else {
				k--;
			}
		}
	}
	out[frameSize-1] = in[frameSize-1] + 2*pi*k;
}

void inst_frequency(float32_t in[], float32_t out[]){
	float32_t *inst_phase, *unwrapped_phase;
	inst_phase = (float32_t *) malloc(frameSize * sizeof(float32_t));
	unwrapped_phase = (float32_t *) malloc(frameSize * sizeof(float32_t));
	int j = 0;
	for(int i = 0; i < doubleFrameSize; i = i + 2){
		inst_phase[j] = atan2(in[i], in[i+1]);
		j++;
	}
	unwrap(inst_phase, unwrapped_phase);
	for(int i = 0; i < frameSize - 1; i++){
		out[i] = (1/(2*pi))*(unwrapped_phase[i+1] - unwrapped_phase[i]);
	}
	out[frameSize - 1] = (1/(2*pi))*(0 - unwrapped_phase[frameSize - 1]);
	free(inst_phase);
	free(unwrapped_phase);
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
