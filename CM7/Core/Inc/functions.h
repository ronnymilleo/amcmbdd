/*
 * functions.h
 *
 *  Created on: Jul 20, 2020
 *      Author: ronny
 */
#include <stdlib.h>
#include <stdint.h>

#include "arm_math.h"
#include "arm_common_tables.h"
#include "arm_const_structs.h"

extern const uint32_t frameSize;

// Instantaneous values + 6 features ( 0 -> 5)
void inst_absolute(float32_t in[], float32_t out[]);
void complex_inst_absolute(float32_t in[], float32_t out[]);
void inst_phase(float32_t in[], float32_t out[]);
void unwrap(float32_t in[], float32_t out[]);
void inst_frequency(float32_t in[], float32_t out[]);
void inst_centralized_normalized_absolute(float32_t in[], float32_t out[]);
void std_dev(float32_t in[], float32_t *out);

// Features no 6, 7, 8, 9 and 10
void mean_of_signal_magnitude(float32_t in[], float32_t *out);
void squared_mean_of_signal_magnitude(float32_t in[], float32_t *out);
void normalized_sqrt_of_sum_of_amp(float32_t in[], float32_t *out);
void ratio_iq(float32_t in[], float32_t *out);
void gmax(float32_t src[], float32_t *maxValue);

// Features no 11 and 12
void kurtosis(float32_t in[], float32_t *out, uint32_t blockSize);

// Features no 13, 14, 15, 16, 17, 18, 19, 20 and 21
void moment20(float32_t in[], float32_t out[]);
void moment21(float32_t in[], float32_t *out);
void moment40(float32_t in[], float32_t out[]);
void moment41(float32_t in[], float32_t out[]);
void moment42(float32_t in[], float32_t out[]);
void moment43(float32_t in[], float32_t out[]);
void moment60(float32_t in[], float32_t out[]);
void moment61(float32_t in[], float32_t out[]);
void moment62(float32_t in[], float32_t out[]);
void moment63(float32_t in[], float32_t out[]);
void cumulant_20(float32_t in[], float32_t *out);
void cumulant_21(float32_t in[], float32_t *out);
void cumulant_40(float32_t in[], float32_t *out);
void cumulant_41(float32_t in[], float32_t *out);
void cumulant_42(float32_t in[], float32_t *out);
void cumulant_60(float32_t in[], float32_t *out);
void cumulant_61(float32_t in[], float32_t *out);
void cumulant_62(float32_t in[], float32_t *out);
void cumulant_63(float32_t in[], float32_t *out);
