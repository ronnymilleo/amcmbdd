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
void moment20(float32_t in[], float32_t *out){
	float32_t in_cp[frameSize*2];
	float32_t m20[frameSize*2]; // in^2
	float32_t m20_real = 0, m20_imag = 0, m20_real_mean = 0, m20_imag_mean = 0;
	arm_copy_f32(&in[0], &in_cp[0], frameSize*2);
	arm_cmplx_mult_cmplx_f32(&in[0], &in_cp[0], &m20[0], frameSize);
	for(int i = 0; i < frameSize*2; i+=2){
		m20_real += m20[i];
		m20_imag += m20[i+1];
	}
	m20_real_mean = m20_real / frameSize;
	m20_imag_mean = m20_imag / frameSize;
	*out = sqrtf(m20_real_mean*m20_real_mean + m20_imag_mean*m20_imag_mean);
}

void moment21(float32_t in[], float32_t *out){
	float32_t in_conj[frameSize*2];
	float32_t m21[frameSize*2];
	float32_t in_mag[frameSize];
	arm_cmplx_conj_f32(&in[0], &in_conj[0], frameSize);
	arm_cmplx_mult_cmplx_f32(&in[0], &in_conj[0], &m21[0], frameSize);
	arm_cmplx_mag_f32(&m21[0], &in_mag[0], frameSize);
	arm_mean_f32(&in_mag[0], frameSize, out);
	// Calculating the mean after the absolute value here works because there
	// is no imaginary part in the number M21, different from M20
}

void moment22(float32_t in[], float32_t *out){
	float32_t in_conj[frameSize*2];
	float32_t in_conj_cp[frameSize*2];
	float32_t m22[frameSize*2]; // in^2
	float32_t m22_real = 0, m22_imag = 0, m22_real_mean = 0, m22_imag_mean = 0;
	arm_cmplx_conj_f32(&in[0], &in_conj[0], frameSize);
	arm_copy_f32(&in_conj[0], &in_conj_cp[0], frameSize*2);
	arm_cmplx_mult_cmplx_f32(&in_conj[0], &in_conj_cp[0], &m22[0], frameSize);
	for(int i = 0; i < frameSize*2; i+=2){
		m22_real += m22[i];
		m22_imag += m22[i+1];
	}
	m22_real_mean = m22_real / frameSize;
	m22_imag_mean = m22_imag / frameSize;
	*out = sqrtf(m22_real_mean*m22_real_mean + m22_imag_mean*m22_imag_mean);
}

void moment40(float32_t in[], float32_t *out){
	float32_t in_cp[frameSize*2];
	float32_t m20[frameSize*2]; // in^2
	float32_t m30[frameSize]; // in^3
	float32_t m40[frameSize]; // in^4
	float32_t m40_real = 0.0f, m40_imag = 0.0f;
	float32_t m40_real_mean = 0.0f, m40_imag_mean = 0.0f;
	arm_copy_f32(&in[0], &in_cp[0], frameSize*2);
	arm_cmplx_mult_cmplx_f32(&in[0], &in_cp[0], &m20[0], frameSize);
	arm_cmplx_mult_cmplx_f32(&m20[0], &in_cp[0], &m30[0], frameSize);
	arm_cmplx_mult_cmplx_f32(&m30[0], &in_cp[0], &m40[0], frameSize);
	for(int i = 0; i < frameSize*2; i+=2){
		m40_real += m40[i];
		m40_imag += m40[i+1];
	}
	m40_real_mean = m40_real / frameSize;
	m40_imag_mean = m40_imag / frameSize;
	*out = sqrtf(m40_real_mean*m40_real_mean + m40_imag_mean*m40_imag_mean);
}

void moment41(float32_t in[], float32_t *out){
	float32_t in_cp[frameSize*2];
	float32_t in_conj[frameSize*2];
	float32_t m20[frameSize*2]; // in^2
	float32_t m30[frameSize]; // in^3
	float32_t m41[frameSize]; // in^4
	float32_t m41_real = 0.0f, m41_imag = 0.0f;
	float32_t m41_real_mean = 0.0f, m41_imag_mean = 0.0f;
	arm_copy_f32(&in[0], &in_cp[0], frameSize*2);
	arm_cmplx_conj_f32(&in[0], &in_conj[0], frameSize);
	arm_cmplx_mult_cmplx_f32(&in[0], &in_cp[0], &m20[0], frameSize);
	arm_cmplx_mult_cmplx_f32(&m20[0], &in_cp[0], &m30[0], frameSize);
	arm_cmplx_mult_cmplx_f32(&m30[0], &in_conj[0], &m41[0], frameSize);
	for(int i = 0; i < frameSize*2; i+=2){
		m41_real += m41[i];
		m41_imag += m41[i+1];
	}
	m41_real_mean = m41_real / frameSize;
	m41_imag_mean = m41_imag / frameSize;
	*out = sqrtf(m41_real_mean*m41_real_mean + m41_imag_mean*m41_imag_mean);
}

void moment42(float32_t in[], float32_t *out){
	float32_t in_cp[frameSize*2];
	float32_t in_conj[frameSize*2];
	float32_t m20[frameSize*2]; // in^2
	float32_t m31[frameSize]; // in^3
	float32_t m42[frameSize]; // in^4
	float32_t m42_real = 0.0f, m42_imag = 0.0f;
	float32_t m42_real_mean = 0.0f, m42_imag_mean = 0.0f;
	arm_copy_f32(&in[0], &in_cp[0], frameSize*2);
	arm_cmplx_conj_f32(&in[0], &in_conj[0], frameSize);
	arm_cmplx_mult_cmplx_f32(&in[0], &in_cp[0], &m20[0], frameSize);
	arm_cmplx_mult_cmplx_f32(&m20[0], &in_conj[0], &m31[0], frameSize);
	arm_cmplx_mult_cmplx_f32(&m31[0], &in_conj[0], &m42[0], frameSize);
	for(int i = 0; i < frameSize*2; i+=2){
		m42_real += m42[i];
		m42_imag += m42[i+1];
	}
	m42_real_mean = m42_real / frameSize;
	m42_imag_mean = m42_imag / frameSize;
	*out = sqrtf(m42_real_mean*m42_real_mean + m42_imag_mean*m42_imag_mean);
}

void moment43(float32_t in[], float32_t *out){
	float32_t in_cp[frameSize*2];
	float32_t in_conj[frameSize*2];
	float32_t m21[frameSize*2]; // in^2
	float32_t m32[frameSize]; // in^3
	float32_t m43[frameSize]; // in^4
	float32_t m43_real = 0.0f, m43_imag = 0.0f;
	float32_t m43_real_mean = 0.0f, m43_imag_mean = 0.0f;
	arm_copy_f32(&in[0], &in_cp[0], frameSize*2);
	arm_cmplx_conj_f32(&in[0], &in_conj[0], frameSize);
	arm_cmplx_mult_cmplx_f32(&in[0], &in_conj[0], &m21[0], frameSize);
	arm_cmplx_mult_cmplx_f32(&m21[0], &in_conj[0], &m32[0], frameSize);
	arm_cmplx_mult_cmplx_f32(&m32[0], &in_conj[0], &m43[0], frameSize);
	for(int i = 0; i < frameSize*2; i+=2){
		m43_real += m43[i];
		m43_imag += m43[i+1];
	}
	m43_real_mean = m43_real / frameSize;
	m43_imag_mean = m43_imag / frameSize;
	*out = sqrtf(m43_real_mean*m43_real_mean + m43_imag_mean*m43_imag_mean);
}

void moment60(float32_t in[], float32_t *out){
	float32_t in_cp[frameSize*2];
	float32_t m20[frameSize*2]; // in^2
	float32_t m30[frameSize]; // in^3
	float32_t m40[frameSize]; // in^4
	float32_t m50[frameSize]; // in^5
	float32_t m60[frameSize]; // in^6
	float32_t m60_real = 0.0f, m60_imag = 0.0f;
	float32_t m60_real_mean = 0.0f, m60_imag_mean = 0.0f;
	arm_copy_f32(&in[0], &in_cp[0], frameSize*2);
	arm_cmplx_mult_cmplx_f32(&in[0], &in_cp[0], &m20[0], frameSize);
	arm_cmplx_mult_cmplx_f32(&m20[0], &in_cp[0], &m30[0], frameSize);
	arm_cmplx_mult_cmplx_f32(&m30[0], &in_cp[0], &m40[0], frameSize);
	arm_cmplx_mult_cmplx_f32(&m40[0], &in_cp[0], &m50[0], frameSize);
	arm_cmplx_mult_cmplx_f32(&m50[0], &in_cp[0], &m60[0], frameSize);
	for(int i = 0; i < frameSize*2; i+=2){
		m60_real += m60[i];
		m60_imag += m60[i+1];
	}
	m60_real_mean = m60_real / frameSize;
	m60_imag_mean = m60_imag / frameSize;
	*out = sqrtf(m60_real_mean*m60_real_mean + m60_imag_mean*m60_imag_mean);
}

void moment61(float32_t in[], float32_t *out){
	float32_t in_cp[frameSize*2];
	float32_t in_conj[frameSize*2];
	float32_t m20[frameSize*2]; // in^2
	float32_t m30[frameSize]; // in^3
	float32_t m40[frameSize]; // in^4
	float32_t m50[frameSize]; // in^5
	float32_t m61[frameSize]; // in^6
	float32_t m61_real = 0.0f, m61_imag = 0.0f;
	float32_t m61_real_mean = 0.0f, m61_imag_mean = 0.0f;
	arm_copy_f32(&in[0], &in_cp[0], frameSize*2);
	arm_cmplx_conj_f32(&in[0], &in_conj[0], frameSize);
	arm_cmplx_mult_cmplx_f32(&in[0], &in_cp[0], &m20[0], frameSize);
	arm_cmplx_mult_cmplx_f32(&m20[0], &in_cp[0], &m30[0], frameSize);
	arm_cmplx_mult_cmplx_f32(&m30[0], &in_cp[0], &m40[0], frameSize);
	arm_cmplx_mult_cmplx_f32(&m40[0], &in_cp[0], &m50[0], frameSize);
	arm_cmplx_mult_cmplx_f32(&m50[0], &in_conj[0], &m61[0], frameSize);
	for(int i = 0; i < frameSize*2; i+=2){
		m61_real += m61[i];
		m61_imag += m61[i+1];
	}
	m61_real_mean = m61_real / frameSize;
	m61_imag_mean = m61_imag / frameSize;
	*out = sqrtf(m61_real_mean*m61_real_mean + m61_imag_mean*m61_imag_mean);
}

void moment62(float32_t in[], float32_t *out){
	float32_t in_cp[frameSize*2];
	float32_t in_conj[frameSize*2];
	float32_t m20[frameSize*2]; // in^2
	float32_t m30[frameSize]; // in^3
	float32_t m40[frameSize]; // in^4
	float32_t m51[frameSize]; // in^5
	float32_t m62[frameSize]; // in^6
	float32_t m62_real = 0.0f, m62_imag = 0.0f;
	float32_t m62_real_mean = 0.0f, m62_imag_mean = 0.0f;
	arm_copy_f32(&in[0], &in_cp[0], frameSize*2);
	arm_cmplx_conj_f32(&in[0], &in_conj[0], frameSize);
	arm_cmplx_mult_cmplx_f32(&in[0], &in_cp[0], &m20[0], frameSize);
	arm_cmplx_mult_cmplx_f32(&m20[0], &in_cp[0], &m30[0], frameSize);
	arm_cmplx_mult_cmplx_f32(&m30[0], &in_cp[0], &m40[0], frameSize);
	arm_cmplx_mult_cmplx_f32(&m40[0], &in_conj[0], &m51[0], frameSize);
	arm_cmplx_mult_cmplx_f32(&m51[0], &in_conj[0], &m62[0], frameSize);
	for(int i = 0; i < frameSize*2; i+=2){
		m62_real += m62[i];
		m62_imag += m62[i+1];
	}
	m62_real_mean = m62_real / frameSize;
	m62_imag_mean = m62_imag / frameSize;
	*out = sqrtf(m62_real_mean*m62_real_mean + m62_imag_mean*m62_imag_mean);
}

void moment63(float32_t in[], float32_t *out){
	float32_t in_cp[frameSize*2];
	float32_t in_conj[frameSize*2];
	float32_t m20[frameSize*2]; // in^2
	float32_t m30[frameSize]; // in^3
	float32_t m41[frameSize]; // in^4
	float32_t m52[frameSize]; // in^5
	float32_t m63[frameSize]; // in^6
	float32_t m63_real = 0.0f, m63_imag = 0.0f;
	float32_t m63_real_mean = 0.0f, m63_imag_mean = 0.0f;
	arm_copy_f32(&in[0], &in_cp[0], frameSize*2);
	arm_cmplx_conj_f32(&in[0], &in_conj[0], frameSize);
	arm_cmplx_mult_cmplx_f32(&in[0], &in_cp[0], &m20[0], frameSize);
	arm_cmplx_mult_cmplx_f32(&m20[0], &in_cp[0], &m30[0], frameSize);
	arm_cmplx_mult_cmplx_f32(&m30[0], &in_conj[0], &m41[0], frameSize);
	arm_cmplx_mult_cmplx_f32(&m41[0], &in_conj[0], &m52[0], frameSize);
	arm_cmplx_mult_cmplx_f32(&m52[0], &in_conj[0], &m63[0], frameSize);
	for(int i = 0; i < frameSize*2; i+=2){
		m63_real += m63[i];
		m63_imag += m63[i+1];
	}
	m63_real_mean = m63_real / frameSize;
	m63_imag_mean = m63_imag / frameSize;
	*out = sqrtf(m63_real_mean*m63_real_mean + m63_imag_mean*m63_imag_mean);
}

// Features no 13, 14, 15, 16, 17, 18, 19, 20 and 21
void cumulant_20(float32_t in[], float32_t *out){
	moment20(&in[0], out);
};
void cumulant_21(float32_t in[], float32_t *out){
	moment21(&in[0], out);
};

void cumulant_40(float32_t in[], float32_t *out){
	float32_t m40, m20;
	moment20(&in[0], &m20);
	moment40(&in[0], &m40);
	*out = fabsf(m40 - 3*m20*m20);
};
void cumulant_41(float32_t in[], float32_t *out){
	float32_t m41, m20, m21;
	moment41(&in[0], &m41);
	moment20(&in[0], &m20);
	moment21(&in[0], &m21);
	*out = fabsf(m41 - 3*m20*m21);
};
void cumulant_42(float32_t in[], float32_t *out){
	float32_t m42, m20, m21, temp;
	moment42(&in[0], &m42);
	moment20(&in[0], &m20);
	moment21(&in[0], &m21);
	temp = fabsf(m20);
	*out = fabsf(m42 - temp*temp - 2*m21*m21);
};
void cumulant_60(float32_t in[], float32_t *out){
	float32_t m60, m40, m20;
	moment20(&in[0], &m20);
	moment40(&in[0], &m40);
	moment60(&in[0], &m60);
	*out = fabsf(m60 - 15*m20*m40 + 30*m20*m20*m20);
};
void cumulant_61(float32_t in[], float32_t *out){
	//M61 - 5 M21 M40 - 10 M20 M41 + 30 M20 M20 M21
	float32_t m61, m21, m40, m20, m41;
	moment20(&in[0], &m20);
	moment21(&in[0], &m21);
	moment40(&in[0], &m40);
	moment41(&in[0], &m41);
	moment61(&in[0], &m61);
	*out = fabsf(m61 - 5*m21*m40 - 10*m20*m41 + 30*m20*m20*m21);
};
void cumulant_62(float32_t in[], float32_t *out){
	// M62 - 6 M20 M42 - 8 M21 M41 - M22 M40 + 6 M20 M20 M22 + 24 M21 M21 M22
	float32_t m62, m20, m42, m21, m41, m22, m40;
	moment20(&in[0], &m20);
	moment21(&in[0], &m21);
	moment22(&in[0], &m22);
	moment40(&in[0], &m40);
	moment41(&in[0], &m41);
	moment42(&in[0], &m42);
	moment62(&in[0], &m62);
	*out = fabsf(m62 - 6*m20*m42 - 8*m21*m41 - m22*m40 + 6*m20*m20*m22 + 24*m21*m21*m22);
};
void cumulant_63(float32_t in[], float32_t *out){
	// M63 - 9 M21 M42 + 12 M21 M21 M21 - 3 M20 M43 - 3 M22 M41 + 18 M20 M21 M22
	float32_t m63, m21, m42, m20, m43, m22, m41;
	moment20(&in[0], &m20);
	moment21(&in[0], &m21);
	moment22(&in[0], &m22);
	moment41(&in[0], &m41);
	moment42(&in[0], &m42);
	moment43(&in[0], &m43);
	moment63(&in[0], &m63);
	*out = fabsf(m63 - 9*m21*m42 + 12*m21*m21*m21 - 3*m20*m43 - 3*m22*m41 + 18*m20*m21*m22);
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
