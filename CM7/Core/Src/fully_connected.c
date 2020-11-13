/*
 * fully_connected.c
 *
 *  Created on: 15 de out de 2020
 *      Author: ronny
 */

#include "fully_connected.h"

extern q15_t layer_1_out_Buf[L1_OUT_DIM];
extern q15_t layer_2_out_Buf[L2_OUT_DIM];
extern q15_t layer_3_out_Buf[L3_OUT_DIM];
extern q15_t layer_4_out_Buf[L4_OUT_DIM];
extern q15_t layer_5_out_Buf[L5_OUT_DIM];
extern q15_t output_data[L5_OUT_DIM];
extern q15_t aq15_layer_1_weights[L1_IN_DIM*L1_OUT_DIM];
extern q15_t aq15_layer_1_biases[L1_OUT_DIM];
extern q15_t aq15_layer_2_weights[L2_IN_DIM*L2_OUT_DIM];
extern q15_t aq15_layer_2_biases[L2_OUT_DIM];
extern q15_t aq15_layer_3_weights[L3_IN_DIM*L3_OUT_DIM];
extern q15_t aq15_layer_3_biases[L3_OUT_DIM];
extern q15_t aq15_layer_4_weights[L4_IN_DIM*L4_OUT_DIM];
extern q15_t aq15_layer_4_biases[L4_OUT_DIM];
extern q15_t aq15_layer_5_weights[L5_IN_DIM*L5_OUT_DIM];
extern q15_t aq15_layer_5_biases[L5_OUT_DIM];

void fully_connected_run(q15_t *input_data, float32_t *prediction)
{
	q15_t max_Value = 0, data[L1_IN_DIM] = {0};
	uint32_t max_Index = 0;
	arm_copy_q15(&input_data[0], &data[0], L1_IN_DIM);
    // Input layer
    arm_fully_connected_q15(
        data,
        aq15_layer_1_weights,
        L1_IN_DIM,
        L1_WM_NUM_OF_ROWS,
        L1_BIAS_SHIFT,
        L1_OUT_SHIFT,
        aq15_layer_1_biases,
        layer_1_out_Buf,
        NULL);
    arm_relu_q15(
    	layer_1_out_Buf,
        L1_OUT_DIM);

    // First hidden layer
    arm_fully_connected_q15(
    	layer_1_out_Buf,
        aq15_layer_2_weights,
        L2_IN_DIM,
        L2_WM_NUM_OF_ROWS,
        L2_BIAS_SHIFT,
        L2_OUT_SHIFT,
		aq15_layer_2_biases,
        layer_2_out_Buf,
        NULL);
    arm_relu_q15(
    	layer_2_out_Buf,
		L2_OUT_DIM);

    // Second hidden layer
    arm_fully_connected_q15(
    	layer_2_out_Buf,
        aq15_layer_3_weights,
        L3_IN_DIM,
        L3_WM_NUM_OF_ROWS,
        L3_BIAS_SHIFT,
        L3_OUT_SHIFT,
		aq15_layer_3_biases,
        layer_3_out_Buf,
        NULL);
    arm_relu_q15(
    	layer_3_out_Buf,
		L3_OUT_DIM);

    // Third hidden layer
    arm_fully_connected_q15(
    	layer_3_out_Buf,
        aq15_layer_4_weights,
        L4_IN_DIM,
        L4_WM_NUM_OF_ROWS,
        L4_BIAS_SHIFT,
        L4_OUT_SHIFT,
		aq15_layer_4_biases,
        layer_4_out_Buf,
        NULL);
    arm_relu_q15(
    	layer_4_out_Buf,
		L4_OUT_DIM);

    // Output layer
	arm_fully_connected_q15(
		layer_4_out_Buf,
		aq15_layer_5_weights,
		L5_IN_DIM,
		L5_WM_NUM_OF_ROWS,
		L5_BIAS_SHIFT,
		L5_OUT_SHIFT,
		aq15_layer_5_biases,
		layer_5_out_Buf,
		NULL);
    arm_softmax_q15(
    	layer_5_out_Buf,
		L5_OUT_DIM,
        output_data);
    arm_max_q15(output_data, L5_OUT_DIM, &max_Value, &max_Index);
    *prediction = (float32_t) max_Index;
}
