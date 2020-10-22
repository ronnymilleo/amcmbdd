################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/NN-Src/NNSupportFunctions/arm_nn_mult_q15.c \
../Core/NN-Src/NNSupportFunctions/arm_nn_mult_q7.c \
../Core/NN-Src/NNSupportFunctions/arm_nntables.c \
../Core/NN-Src/NNSupportFunctions/arm_q7_to_q15_no_shift.c \
../Core/NN-Src/NNSupportFunctions/arm_q7_to_q15_reordered_no_shift.c 

OBJS += \
./Core/NN-Src/NNSupportFunctions/arm_nn_mult_q15.o \
./Core/NN-Src/NNSupportFunctions/arm_nn_mult_q7.o \
./Core/NN-Src/NNSupportFunctions/arm_nntables.o \
./Core/NN-Src/NNSupportFunctions/arm_q7_to_q15_no_shift.o \
./Core/NN-Src/NNSupportFunctions/arm_q7_to_q15_reordered_no_shift.o 

C_DEPS += \
./Core/NN-Src/NNSupportFunctions/arm_nn_mult_q15.d \
./Core/NN-Src/NNSupportFunctions/arm_nn_mult_q7.d \
./Core/NN-Src/NNSupportFunctions/arm_nntables.d \
./Core/NN-Src/NNSupportFunctions/arm_q7_to_q15_no_shift.d \
./Core/NN-Src/NNSupportFunctions/arm_q7_to_q15_reordered_no_shift.d 


# Each subdirectory must supply rules for building sources it contributes
Core/NN-Src/NNSupportFunctions/arm_nn_mult_q15.o: ../Core/NN-Src/NNSupportFunctions/arm_nn_mult_q15.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -D__FPU_PRESENT -DSTM32H745xx -DUSE_HAL_DRIVER -DCORE_CM7 -DARM_MATH_CM7 -DARM_MATH_MVEI -c -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/NN/Include" -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/DSP/Include" -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../Core/Inc -O3 -ffunction-sections -fdata-sections -fno-strict-aliasing -Wall -fstack-usage -MMD -MP -MF"Core/NN-Src/NNSupportFunctions/arm_nn_mult_q15.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/NN-Src/NNSupportFunctions/arm_nn_mult_q7.o: ../Core/NN-Src/NNSupportFunctions/arm_nn_mult_q7.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -D__FPU_PRESENT -DSTM32H745xx -DUSE_HAL_DRIVER -DCORE_CM7 -DARM_MATH_CM7 -DARM_MATH_MVEI -c -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/NN/Include" -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/DSP/Include" -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../Core/Inc -O3 -ffunction-sections -fdata-sections -fno-strict-aliasing -Wall -fstack-usage -MMD -MP -MF"Core/NN-Src/NNSupportFunctions/arm_nn_mult_q7.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/NN-Src/NNSupportFunctions/arm_nntables.o: ../Core/NN-Src/NNSupportFunctions/arm_nntables.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -D__FPU_PRESENT -DSTM32H745xx -DUSE_HAL_DRIVER -DCORE_CM7 -DARM_MATH_CM7 -DARM_MATH_MVEI -c -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/NN/Include" -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/DSP/Include" -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../Core/Inc -O3 -ffunction-sections -fdata-sections -fno-strict-aliasing -Wall -fstack-usage -MMD -MP -MF"Core/NN-Src/NNSupportFunctions/arm_nntables.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/NN-Src/NNSupportFunctions/arm_q7_to_q15_no_shift.o: ../Core/NN-Src/NNSupportFunctions/arm_q7_to_q15_no_shift.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -D__FPU_PRESENT -DSTM32H745xx -DUSE_HAL_DRIVER -DCORE_CM7 -DARM_MATH_CM7 -DARM_MATH_MVEI -c -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/NN/Include" -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/DSP/Include" -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../Core/Inc -O3 -ffunction-sections -fdata-sections -fno-strict-aliasing -Wall -fstack-usage -MMD -MP -MF"Core/NN-Src/NNSupportFunctions/arm_q7_to_q15_no_shift.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/NN-Src/NNSupportFunctions/arm_q7_to_q15_reordered_no_shift.o: ../Core/NN-Src/NNSupportFunctions/arm_q7_to_q15_reordered_no_shift.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -D__FPU_PRESENT -DSTM32H745xx -DUSE_HAL_DRIVER -DCORE_CM7 -DARM_MATH_CM7 -DARM_MATH_MVEI -c -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/NN/Include" -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/DSP/Include" -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../Core/Inc -O3 -ffunction-sections -fdata-sections -fno-strict-aliasing -Wall -fstack-usage -MMD -MP -MF"Core/NN-Src/NNSupportFunctions/arm_q7_to_q15_reordered_no_shift.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

