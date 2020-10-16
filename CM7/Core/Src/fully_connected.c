/*
 * fully_connected.c
 *
 *  Created on: 15 de out de 2020
 *      Author: ronny
 */

#include "fully_connected.h"

q15_t aq15_out_Buf[22] = {0};
q15_t aq15_layer_1_weights[22*22] = {0};
q15_t aq15_layer_1_bias[22] = {0};
q15_t aq15_layer_2_weights[22*22] = {0};
q15_t aq15_layer_2_bias[22] = {0};
q15_t aq15_layer_3_weights[22*22] = {0};
q15_t aq15_layer_3_bias[22] = {0};

void fully_connected_run(q15_t input_data[], uint32_t *prediction)
{
    int16_t i16_max_val = 0x7FFF, i = 0;

    arm_fully_connected_q15(
        input_data,
        aq15_layer_1_weights,
        LAYER_1_IN_DIM,
        LAYER_1_OU_DIM,
        LAYER_1_IN_SHIFT,
        LAYER_1_OU_SHIFT,
        aq15_layer_1_bias,
        aq15_out_Buf,
        NULL);

    arm_nn_activations_direct_q15(
    		aq15_out_Buf,
			LAYER_1_OU_DIM,
			1,
			ARM_SIGMOID);

    arm_relu_q15(
        aq15_out_Buf,
        LAYER_1_OU_DIM);
    memcpy(input_data, aq15_out_Buf, sizeof(aq15_out_Buf));
    arm_fully_connected_q15(
        input_data,
        aq15_layer_2_weights,
        LAYER_2_IN_DIM,
        LAYER_2_OU_DIM,
        LAYER_2_IN_SHIFT,
        LAYER_2_OU_SHIFT,
        aq15_layer_2_bias,
        aq15_out_Buf,
        NULL);
    arm_relu_q15(
        aq15_out_Buf,
        LAYER_2_OU_DIM);
    memcpy(input_data, aq15_out_Buf, sizeof(aq15_out_Buf));
    arm_fully_connected_q15(
        input_data,
        aq15_layer_3_weights,
        LAYER_3_IN_DIM,
        LAYER_3_OU_DIM,
        LAYER_3_IN_SHIFT,
        LAYER_3_OU_SHIFT,
        aq15_layer_3_bias,
        aq15_out_Buf,
        NULL);
    memcpy(input_data, aq15_out_Buf, sizeof(aq15_out_Buf));
    arm_softmax_q15(
        input_data,
        LAYER_3_OU_DIM,
        aq15_out_Buf);
    for(i = 0; i < LAYER_3_OU_DIM; i++) {
        if(i16_max_val < aq15_out_Buf[i]) {
            i16_max_val = aq15_out_Buf[i];
            *prediction = i;
        }
    }
}
