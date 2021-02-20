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
#define L2_OUT_DIM 26
#define L2_WM_NUM_OF_ROWS 26
#define L3_IN_DIM 26
#define L3_OUT_DIM 29
#define L3_WM_NUM_OF_ROWS 29
#define L4_IN_DIM 29
#define L4_OUT_DIM 30
#define L4_WM_NUM_OF_ROWS 30
#define L5_IN_DIM 30
#define L5_OUT_DIM 6
#define L5_WM_NUM_OF_ROWS 6
// The bias shift is : (fi + fw) - fb
// The out shift is : (fi + fw) - fo
// fi = fractional bits for the input
// fo = fractional bits for the output
// fw = fractional bits for the weights
// fb = fractional bits for the biases
// Input is Q3.12
#define L1_FI 12
#define L1_FW 13
#define L1_FB 13
#define L1_FO 10

#define L2_FI 10
#define L2_FW 14
#define L2_FB 13
#define L2_FO 9

#define L3_FI 9
#define L3_FW 15
#define L3_FB 12
#define L3_FO 8

#define L4_FI 8
#define L4_FW 15
#define L4_FB 10
#define L4_FO 7

#define L5_FI 7
#define L5_FW 12
#define L5_FB 9
#define L5_FO 8

#define L1_BIAS_SHIFT L1_FI+L1_FW-L1_FB
#define L1_OUT_SHIFT L1_FI+L1_FW-L1_FO
#define L2_BIAS_SHIFT L2_FI+L2_FW-L2_FB
#define L2_OUT_SHIFT L2_FI+L2_FW-L2_FO
#define L3_BIAS_SHIFT L3_FI+L3_FW-L3_FB
#define L3_OUT_SHIFT L3_FI+L3_FW-L3_FO
#define L4_BIAS_SHIFT L4_FI+L4_FW-L4_FB
#define L4_OUT_SHIFT L4_FI+L4_FW-L4_FO
#define L5_BIAS_SHIFT L5_FI+L5_FW-L5_FB
#define L5_OUT_SHIFT L5_FI+L5_FW-L5_FO
#define BIASES L1_OUT_DIM + L2_OUT_DIM + L3_OUT_DIM + L4_OUT_DIM + L5_OUT_DIM
#define WEIGHTS L1_IN_DIM * L1_OUT_DIM + L2_IN_DIM * L2_OUT_DIM + L3_IN_DIM * L3_OUT_DIM + L4_IN_DIM * L4_OUT_DIM + L5_IN_DIM * L5_OUT_DIM

#include <stdint.h>

#include "arm_nnfunctions.h"

void fully_connected_run(q15_t input_data[], float32_t *prediction);

#endif /* INC_FULLY_CONNECTED_H_ */
