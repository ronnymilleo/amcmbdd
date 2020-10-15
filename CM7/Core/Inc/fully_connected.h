/*
 * fully_connected.h
 *
 *  Created on: 15 de out de 2020
 *      Author: ronny
 */

#ifndef INC_FULLY_CONNECTED_H_
#define INC_FULLY_CONNECTED_H_

#define LAYER_1_IN_DIM 22
#define LAYER_1_OU_DIM 22
#define LAYER_2_IN_DIM 22
#define LAYER_2_OU_DIM 22
#define LAYER_3_IN_DIM 22
#define LAYER_3_OU_DIM 6
#define LAYER_1_IN_SHIFT 15
#define LAYER_1_OU_SHIFT 15
#define LAYER_2_IN_SHIFT 15
#define LAYER_2_OU_SHIFT 15
#define LAYER_3_IN_SHIFT 15
#define LAYER_3_OU_SHIFT 15

#include <stdint.h>

#include "arm_nnfunctions.h"

uint8_t fully_connected_run(q15_t * q15_input_data);

#endif /* INC_FULLY_CONNECTED_H_ */
