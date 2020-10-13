/*
 * functions.c
 *
 *  Created on: Jul 20, 2020
 *      Author: ronny
 */

#include <functions.h>
#include <main.h>
#include "math.h"

//**********************************************************************************************//
// Preprocessing - Instantaneous values (6 features)
// To use with instantaneous values
void inst_absolute(float32_t in[], float32_t out[]){
	arm_abs_f32(&in[0], &out[0], frameSize);
}

// To use with complex input values
void complex_inst_absolute(float32_t in[], float32_t out[]){
	arm_cmplx_mag_f32(&in[0], &out[0], frameSize);
}

void inst_phase(float32_t in[], float32_t out[]){
	int j = 0;
	for(int i = 0; i < 2*frameSize; i = i + 2){
		out[j] = atan2f(in[i+1], in[i]);
		j++;
	}
}

void unwrap(float32_t in[], float32_t out[]){
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
	float32_t phase[2048] = {0};
	float32_t unwrapped_phase[2048] = {0};
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
	complex_inst_absolute(in, &absolute[0]);
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

void std_dev(float32_t in[], float32_t *out) {
	arm_std_f32(&in[0], frameSize, out);
}
//**********************************************************************************************//
// Feature number 6
void mean_of_signal_magnitude(float32_t in[], float32_t *out) {
	arm_mean_f32(&in[0], frameSize, out);
}

// Feature number 7
void squared_mean_of_signal_magnitude(float32_t in[], float32_t *out) {
	float32_t mean_of_signal_magnitude;
	arm_mean_f32(&in[0], frameSize, &mean_of_signal_magnitude);
	*out = mean_of_signal_magnitude * mean_of_signal_magnitude;
}

// Feature number 8
void normalized_sqrt_of_sum_of_amp(float32_t in[], float32_t *out) {
	float32_t sum = 0.0f;
	for(int i = 0; i < frameSize; i++){
		sum += in[i];
	}
	*out = sqrtf(sum)/frameSize;
}

// Feature number 9
void ratio_iq(float32_t in[], float32_t *out) {
	// ft_output = np.sum(np.power(np.imag(signal_input), 2)) / np.sum(np.power(np.real(signal_input), 2))
	float32_t sum_of_real_squared = 0.0f;
	float32_t sum_of_imag_squared = 0.0f;
	for(int i = 0; i < 2*frameSize; i+=2){
		sum_of_real_squared += in[i]*in[i];
		sum_of_imag_squared += in[i+1]*in[i+1];
	}
	*out = sum_of_imag_squared / sum_of_real_squared;
}

// Feature number 10
void gmax(float32_t in[], float32_t *out){
	uint32_t fftSize = 2048;
	uint32_t ifftFlag = 0;
	uint32_t doBitReverse = 1;
	uint32_t maxValueIndex; //Unused
	float32_t maxValue;
	float32_t *result_mag;
	float32_t result_fft[4096] = {0};

	result_mag = (float32_t *) malloc(fftSize * sizeof(float32_t));

	// Copy array to calculate
	for(int i = 0; i < frameSize*2; i++){
		result_fft[i] = in[i];
	}

	arm_cfft_f32(&arm_cfft_sR_f32_len2048, &result_fft[0], ifftFlag, doBitReverse);
	arm_cmplx_mag_f32(result_fft, result_mag, fftSize);
	arm_max_f32(result_mag, fftSize, &maxValue, &maxValueIndex);
	*out = maxValue*maxValue/fftSize;
	free(result_mag);
}

// Features number 11 and 12
void kurtosis_of_abs_amplitude(float32_t in[], float32_t *out, uint32_t blockSize){
	float32_t mean_array[blockSize];
	float32_t x_1[blockSize];
	float32_t x_2[blockSize];
	float32_t temp_1[blockSize];
	float32_t temp_2[blockSize];
	float32_t result[blockSize];
	float32_t mean, m4, m2;
	// Calculate mean
	arm_mean_f32(&in[0], blockSize, &mean);
	// Transform scalar into vector
	arm_fill_f32(mean, &mean_array[0], blockSize);
	// Calculate (x - mean)
	arm_sub_f32(&in[0], &mean_array[0], &x_1[0], blockSize);
	// Make a copy of (x - mean)
	arm_copy_f32(&x_1[0], &x_2[0], blockSize);
	// Calculate (x - mean) ^ 4
	arm_mult_f32(&x_1[0], &x_2[0], &temp_1[0], blockSize); // temp1 = (x - u)^2
	arm_mult_f32(&temp_1[0], &x_2[0], &temp_2[0], blockSize); // temp2 = (x - u)^3
	arm_mult_f32(&temp_2[0], &x_2[0], &result[0], blockSize); // result = (x - u)^4
	// Calculate mean of (x - mean) ^ 4
	arm_mean_f32(&result[0], blockSize, &m4);
	// Calculate mean of (x - mean) ^ 2
	arm_mean_f32(&temp_1[0], blockSize, &m2);
	*out = m4 / (m2*m2) - 3;
}

void kurtosis_of_abs_freq(float32_t in[], float32_t *out, uint32_t blockSize){
	float32_t mean_array[blockSize];
	float32_t x_1[blockSize];
	float32_t x_2[blockSize];
	float32_t temp_1[blockSize];
	float32_t temp_2[blockSize];
	float32_t result[blockSize];
	float32_t mean, m4, m2;
	// Calculate mean
	arm_mean_f32(&in[0], blockSize, &mean);
	// Transform scalar into vector
	arm_fill_f32(mean, &mean_array[0], blockSize);
	// Calculate (x - mean)
	arm_sub_f32(&in[0], &mean_array[0], &x_1[0], blockSize);
	// Make a copy of (x - mean)
	arm_copy_f32(&x_1[0], &x_2[0], blockSize);
	// Calculate (x - mean) ^ 4
	arm_mult_f32(&x_1[0], &x_2[0], &temp_1[0], blockSize); // temp1 = (x - u)^2
	arm_mult_f32(&temp_1[0], &x_2[0], &temp_2[0], blockSize); // temp2 = (x - u)^3
	arm_mult_f32(&temp_2[0], &x_2[0], &result[0], blockSize); // result = (x - u)^4
	// Calculate mean of (x - mean) ^ 4
	arm_mean_f32(&result[0], blockSize, &m4);
	// Calculate mean of (x - mean) ^ 2
	arm_mean_f32(&temp_1[0], blockSize, &m2);
	*out = m4 / (m2*m2) - 3;
}

// Central moment definition
// Mpq = E[x^(p-q).x*^q]
void complex_moment(float32_t in[], float32_t *out, uint8_t p, uint8_t q){
	//m20 = np.mean(np.power(signal_input, 2 - 0) * np.power(np.conj(signal_input), 0))
	float32_t in_cp[frameSize*2];
	float32_t in_sq[frameSize*2];
	float32_t in_mag[frameSize];
	arm_copy_f32(&in[0], &in_cp[0], frameSize*2);
	arm_cmplx_mult_cmplx_f32(&in[0], &in_cp[0], &in_sq[0], frameSize);
	arm_cmplx_mag_f32(&in_sq[0], &in_mag[0], frameSize);
	arm_mean_f32(&in_mag[0], frameSize, out);
	/*
	float32_t x, x_conj, *temp, mean;
	temp = (float32_t *) malloc(frameSize * sizeof(float32_t));
	for(int i = 0; i < frameSize*2; i+=2){
		x = powf(in[i] + in[i+1], p - q);
		x_conj = powf(in[i] - in[i+1], q);
		temp[i] = x * x_conj;
	}
	arm_mean_f32(&temp[0], frameSize, &mean);
	*out = mean;
	free(temp);
	*/
}

// Features no 13, 14, 15, 16, 17, 18, 19, 20 and 21
void cumulant_20(float32_t in[], float32_t *out){

};
void cumulant_21(float32_t in[], float32_t *out){

};
void cumulant_40(float32_t in[], float32_t *out){

};
void cumulant_41(float32_t in[], float32_t *out){

};
void cumulant_42(float32_t in[], float32_t *out){

};
void cumulant_60(float32_t in[], float32_t *out){

};
void cumulant_61(float32_t in[], float32_t *out){

};
void cumulant_62(float32_t in[], float32_t *out){

};
void cumulant_63(float32_t in[], float32_t *out){

};


// Neural networks

void quantize_weights(){

}
/*
min_wt = weight.min()
max_wt = weight.max()
#find number of integer bits to represent this range
int_bits = int(np.ceil(np.log2(max(abs(min_wt),abs(max_wt)))))
frac_bits = 7-int_bits #remaining bits are fractional bits (1-bit for sign)
#floating point weights are scaled and rounded to [-128,127], which are used in
#the fixed-point operations on the actual hardware (i.e., microcontroller)
quant_weight = np.round(weight*(2**frac_bits))
#To quantify the impact of quantized weights, scale them back to
# original range to run inference using quantized weights
weight = quant_weight/(2**frac_bits)
*/
