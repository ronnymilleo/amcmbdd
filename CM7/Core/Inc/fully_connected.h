/*
 * fully_connected.h
 *
 *  Created on: 15 de out de 2020
 *      Author: ronny
 */

#ifndef INC_FULLY_CONNECTED_H_
#define INC_FULLY_CONNECTED_H_

#define L1_IN_DIM 6
#define L1_OUT_DIM 6
#define L1_WM_NUM_OF_ROWS 6
#define L2_IN_DIM 6
#define L2_OUT_DIM 36
#define L2_WM_NUM_OF_ROWS 36
#define L3_IN_DIM 36
#define L3_OUT_DIM 24
#define L3_WM_NUM_OF_ROWS 24
#define L4_IN_DIM 24
#define L4_OUT_DIM 12
#define L4_WM_NUM_OF_ROWS 12
#define L5_IN_DIM 12
#define L5_OUT_DIM 6
#define L5_WM_NUM_OF_ROWS 6
// The bias shift is : (fi + fw) - fb
// The out shift is : (fi + fw) - fo
// fi = fractional bits for the input
// fo = fractional bits for the output
// fw = fractional bits for the weights
// fb = fractional bits for the biases
// Input is Q4.11
#define L1_BIAS_SHIFT 11+14-14
#define L1_OUT_SHIFT 11+14-13
#define L2_BIAS_SHIFT 13+14-15
#define L2_OUT_SHIFT 13+14-14
#define L3_BIAS_SHIFT 14+14-15
#define L3_OUT_SHIFT 14+14-13
#define L4_BIAS_SHIFT 13+14-14
#define L4_OUT_SHIFT 13+14-11
#define L5_BIAS_SHIFT 11+13-14
#define L5_OUT_SHIFT 11+13-14
#define BIASES L1_OUT_DIM + L2_OUT_DIM + L3_OUT_DIM + L4_OUT_DIM + L5_OUT_DIM
#define WEIGHTS L1_IN_DIM * L1_OUT_DIM + L2_IN_DIM * L2_OUT_DIM + L3_IN_DIM * L3_OUT_DIM + L4_IN_DIM * L4_OUT_DIM + L5_IN_DIM * L5_OUT_DIM

#include <stdint.h>

#include "arm_nnfunctions.h"

void fully_connected_run(q15_t input_data[], float32_t *prediction);

#endif /* INC_FULLY_CONNECTED_H_ */
