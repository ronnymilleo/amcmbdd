################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/NN-Src/ActivationFunctions/arm_nn_activations_q15.c \
../Core/NN-Src/ActivationFunctions/arm_nn_activations_q7.c \
../Core/NN-Src/ActivationFunctions/arm_relu_q15.c \
../Core/NN-Src/ActivationFunctions/arm_relu_q7.c 

OBJS += \
./Core/NN-Src/ActivationFunctions/arm_nn_activations_q15.o \
./Core/NN-Src/ActivationFunctions/arm_nn_activations_q7.o \
./Core/NN-Src/ActivationFunctions/arm_relu_q15.o \
./Core/NN-Src/ActivationFunctions/arm_relu_q7.o 

C_DEPS += \
./Core/NN-Src/ActivationFunctions/arm_nn_activations_q15.d \
./Core/NN-Src/ActivationFunctions/arm_nn_activations_q7.d \
./Core/NN-Src/ActivationFunctions/arm_relu_q15.d \
./Core/NN-Src/ActivationFunctions/arm_relu_q7.d 


# Each subdirectory must supply rules for building sources it contributes
Core/NN-Src/ActivationFunctions/arm_nn_activations_q15.o: ../Core/NN-Src/ActivationFunctions/arm_nn_activations_q15.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -D__FPU_PRESENT -DSTM32H745xx -DUSE_HAL_DRIVER -DCORE_CM7 -DARM_MATH_CM7 -DARM_MATH_MVEI -c -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/NN/Include" -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/DSP/Include" -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../Core/Inc -O3 -ffunction-sections -fdata-sections -fno-strict-aliasing -Wall -fstack-usage -MMD -MP -MF"Core/NN-Src/ActivationFunctions/arm_nn_activations_q15.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/NN-Src/ActivationFunctions/arm_nn_activations_q7.o: ../Core/NN-Src/ActivationFunctions/arm_nn_activations_q7.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -D__FPU_PRESENT -DSTM32H745xx -DUSE_HAL_DRIVER -DCORE_CM7 -DARM_MATH_CM7 -DARM_MATH_MVEI -c -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/NN/Include" -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/DSP/Include" -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../Core/Inc -O3 -ffunction-sections -fdata-sections -fno-strict-aliasing -Wall -fstack-usage -MMD -MP -MF"Core/NN-Src/ActivationFunctions/arm_nn_activations_q7.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/NN-Src/ActivationFunctions/arm_relu_q15.o: ../Core/NN-Src/ActivationFunctions/arm_relu_q15.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -D__FPU_PRESENT -DSTM32H745xx -DUSE_HAL_DRIVER -DCORE_CM7 -DARM_MATH_CM7 -DARM_MATH_MVEI -c -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/NN/Include" -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/DSP/Include" -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../Core/Inc -O3 -ffunction-sections -fdata-sections -fno-strict-aliasing -Wall -fstack-usage -MMD -MP -MF"Core/NN-Src/ActivationFunctions/arm_relu_q15.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/NN-Src/ActivationFunctions/arm_relu_q7.o: ../Core/NN-Src/ActivationFunctions/arm_relu_q7.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -D__FPU_PRESENT -DSTM32H745xx -DUSE_HAL_DRIVER -DCORE_CM7 -DARM_MATH_CM7 -DARM_MATH_MVEI -c -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/NN/Include" -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/DSP/Include" -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../Core/Inc -O3 -ffunction-sections -fdata-sections -fno-strict-aliasing -Wall -fstack-usage -MMD -MP -MF"Core/NN-Src/ActivationFunctions/arm_relu_q7.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

