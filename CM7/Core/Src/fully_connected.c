/*
 * fully_connected.c
 *
 *  Created on: 15 de out de 2020
 *      Author: ronny
 */

#include "fully_connected.h"

extern q15_t layer_1_out_Buf[22];
extern q15_t layer_2_out_Buf[22];
extern q15_t layer_3_out_Buf[18];
extern q15_t layer_4_out_Buf[14];
extern q15_t layer_5_out_Buf[6];
extern q15_t output_data[6];
extern q15_t aq15_layer_1_weights[22*22];
extern q15_t aq15_layer_1_biases[22];
extern q15_t aq15_layer_2_weights[22*22];
extern q15_t aq15_layer_2_biases[22];
extern q15_t aq15_layer_3_weights[22*18];
extern q15_t aq15_layer_3_biases[18];
extern q15_t aq15_layer_4_weights[18*14];
extern q15_t aq15_layer_4_biases[14];
extern q15_t aq15_layer_5_weights[14*6];
extern q15_t aq15_layer_5_biases[6];

void fully_connected_run(q15_t input_data[], float32_t *prediction)
{
	q15_t max_Value = 0;
	uint32_t max_Index = 0;
    // Input layer
    arm_fully_connected_q15(
        input_data,
        aq15_layer_1_weights,
        LAYER_1_IN_DIM,
        LAYER_1_OU_DIM,
        LAYER_1_IN_SHIFT,
        LAYER_1_OU_SHIFT,
        aq15_layer_1_biases,
        layer_1_out_Buf,
        NULL);
    arm_nn_activations_direct_q15(
    		layer_1_out_Buf,
			LAYER_1_OU_DIM,
			0,
			ARM_SIGMOID);
    /*
    arm_relu_q15(
        aq15_out_Buf,
        LAYER_1_OU_DIM);
    */

    // First hidden layer
    arm_fully_connected_q15(
    	layer_1_out_Buf,
        aq15_layer_2_weights,
        LAYER_2_IN_DIM,
        LAYER_2_OU_DIM,
        LAYER_2_IN_SHIFT,
        LAYER_2_OU_SHIFT,
		aq15_layer_2_biases,
        layer_2_out_Buf,
        NULL);
    arm_nn_activations_direct_q15(
    		layer_2_out_Buf,
			LAYER_2_OU_DIM,
			0,
			ARM_SIGMOID);
    /*
    arm_relu_q15(
        aq15_out_Buf,
        LAYER_1_OU_DIM);
    */

    // Second hidden layer
    arm_fully_connected_q15(
    	layer_2_out_Buf,
        aq15_layer_3_weights,
        LAYER_3_IN_DIM,
        LAYER_3_OU_DIM,
        LAYER_3_IN_SHIFT,
        LAYER_3_OU_SHIFT,
		aq15_layer_3_biases,
        layer_3_out_Buf,
        NULL);
    arm_nn_activations_direct_q15(
    		layer_3_out_Buf,
			LAYER_3_OU_DIM,
			0,
			ARM_SIGMOID);
    /*
    arm_relu_q15(
        aq15_out_Buf,
        LAYER_1_OU_DIM);
    */

    // Third hidden layer
    arm_fully_connected_q15(
    	layer_3_out_Buf,
        aq15_layer_4_weights,
        LAYER_4_IN_DIM,
        LAYER_4_OU_DIM,
        LAYER_4_IN_SHIFT,
        LAYER_4_OU_SHIFT,
		aq15_layer_4_biases,
        layer_4_out_Buf,
        NULL);
    arm_nn_activations_direct_q15(
    		layer_4_out_Buf,
			LAYER_4_OU_DIM,
			0,
			ARM_SIGMOID);
    /*
    arm_relu_q15(
        aq15_out_Buf,
        LAYER_1_OU_DIM);
    */
    // Output layer
	arm_fully_connected_q15(
		layer_4_out_Buf,
		aq15_layer_5_weights,
		LAYER_5_IN_DIM,
		LAYER_5_OU_DIM,
		LAYER_5_IN_SHIFT,
		LAYER_5_OU_SHIFT,
		aq15_layer_5_biases,
		layer_5_out_Buf,
		NULL);
    arm_softmax_q15(
    	layer_5_out_Buf,
        LAYER_5_OU_DIM,
        output_data);
    arm_max_q15(output_data, LAYER_5_OU_DIM, &max_Value, &max_Index);
    *prediction = (float32_t) max_Index;
}
