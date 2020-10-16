################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/NN-Src/ConvolutionFunctions/arm_convolve_1x1_HWC_q7_fast_nonsquare.c \
../Core/NN-Src/ConvolutionFunctions/arm_convolve_HWC_q15_basic.c \
../Core/NN-Src/ConvolutionFunctions/arm_convolve_HWC_q15_fast.c \
../Core/NN-Src/ConvolutionFunctions/arm_convolve_HWC_q15_fast_nonsquare.c \
../Core/NN-Src/ConvolutionFunctions/arm_convolve_HWC_q7_RGB.c \
../Core/NN-Src/ConvolutionFunctions/arm_convolve_HWC_q7_basic.c \
../Core/NN-Src/ConvolutionFunctions/arm_convolve_HWC_q7_basic_nonsquare.c \
../Core/NN-Src/ConvolutionFunctions/arm_convolve_HWC_q7_fast.c \
../Core/NN-Src/ConvolutionFunctions/arm_convolve_HWC_q7_fast_nonsquare.c \
../Core/NN-Src/ConvolutionFunctions/arm_depthwise_separable_conv_HWC_q7.c \
../Core/NN-Src/ConvolutionFunctions/arm_depthwise_separable_conv_HWC_q7_nonsquare.c \
../Core/NN-Src/ConvolutionFunctions/arm_nn_mat_mult_kernel_q7_q15.c \
../Core/NN-Src/ConvolutionFunctions/arm_nn_mat_mult_kernel_q7_q15_reordered.c 

OBJS += \
./Core/NN-Src/ConvolutionFunctions/arm_convolve_1x1_HWC_q7_fast_nonsquare.o \
./Core/NN-Src/ConvolutionFunctions/arm_convolve_HWC_q15_basic.o \
./Core/NN-Src/ConvolutionFunctions/arm_convolve_HWC_q15_fast.o \
./Core/NN-Src/ConvolutionFunctions/arm_convolve_HWC_q15_fast_nonsquare.o \
./Core/NN-Src/ConvolutionFunctions/arm_convolve_HWC_q7_RGB.o \
./Core/NN-Src/ConvolutionFunctions/arm_convolve_HWC_q7_basic.o \
./Core/NN-Src/ConvolutionFunctions/arm_convolve_HWC_q7_basic_nonsquare.o \
./Core/NN-Src/ConvolutionFunctions/arm_convolve_HWC_q7_fast.o \
./Core/NN-Src/ConvolutionFunctions/arm_convolve_HWC_q7_fast_nonsquare.o \
./Core/NN-Src/ConvolutionFunctions/arm_depthwise_separable_conv_HWC_q7.o \
./Core/NN-Src/ConvolutionFunctions/arm_depthwise_separable_conv_HWC_q7_nonsquare.o \
./Core/NN-Src/ConvolutionFunctions/arm_nn_mat_mult_kernel_q7_q15.o \
./Core/NN-Src/ConvolutionFunctions/arm_nn_mat_mult_kernel_q7_q15_reordered.o 

C_DEPS += \
./Core/NN-Src/ConvolutionFunctions/arm_convolve_1x1_HWC_q7_fast_nonsquare.d \
./Core/NN-Src/ConvolutionFunctions/arm_convolve_HWC_q15_basic.d \
./Core/NN-Src/ConvolutionFunctions/arm_convolve_HWC_q15_fast.d \
./Core/NN-Src/ConvolutionFunctions/arm_convolve_HWC_q15_fast_nonsquare.d \
./Core/NN-Src/ConvolutionFunctions/arm_convolve_HWC_q7_RGB.d \
./Core/NN-Src/ConvolutionFunctions/arm_convolve_HWC_q7_basic.d \
./Core/NN-Src/ConvolutionFunctions/arm_convolve_HWC_q7_basic_nonsquare.d \
./Core/NN-Src/ConvolutionFunctions/arm_convolve_HWC_q7_fast.d \
./Core/NN-Src/ConvolutionFunctions/arm_convolve_HWC_q7_fast_nonsquare.d \
./Core/NN-Src/ConvolutionFunctions/arm_depthwise_separable_conv_HWC_q7.d \
./Core/NN-Src/ConvolutionFunctions/arm_depthwise_separable_conv_HWC_q7_nonsquare.d \
./Core/NN-Src/ConvolutionFunctions/arm_nn_mat_mult_kernel_q7_q15.d \
./Core/NN-Src/ConvolutionFunctions/arm_nn_mat_mult_kernel_q7_q15_reordered.d 


# Each subdirectory must supply rules for building sources it contributes
Core/NN-Src/ConvolutionFunctions/arm_convolve_1x1_HWC_q7_fast_nonsquare.o: ../Core/NN-Src/ConvolutionFunctions/arm_convolve_1x1_HWC_q7_fast_nonsquare.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -D__FPU_PRESENT -DCORE_CM7 -DARM_MATH_CM7 -DARM_MATH_MVEI -DUSE_HAL_DRIVER -DSTM32H745xx -c -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/NN/Include" -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/DSP/Include" -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../Core/Inc -O3 -ffunction-sections -fdata-sections -fno-strict-aliasing -Wall -fstack-usage -MMD -MP -MF"Core/NN-Src/ConvolutionFunctions/arm_convolve_1x1_HWC_q7_fast_nonsquare.d" -MT"$@"  -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/NN-Src/ConvolutionFunctions/arm_convolve_HWC_q15_basic.o: ../Core/NN-Src/ConvolutionFunctions/arm_convolve_HWC_q15_basic.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -D__FPU_PRESENT -DCORE_CM7 -DARM_MATH_CM7 -DARM_MATH_MVEI -DUSE_HAL_DRIVER -DSTM32H745xx -c -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/NN/Include" -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/DSP/Include" -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../Core/Inc -O3 -ffunction-sections -fdata-sections -fno-strict-aliasing -Wall -fstack-usage -MMD -MP -MF"Core/NN-Src/ConvolutionFunctions/arm_convolve_HWC_q15_basic.d" -MT"$@"  -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/NN-Src/ConvolutionFunctions/arm_convolve_HWC_q15_fast.o: ../Core/NN-Src/ConvolutionFunctions/arm_convolve_HWC_q15_fast.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -D__FPU_PRESENT -DCORE_CM7 -DARM_MATH_CM7 -DARM_MATH_MVEI -DUSE_HAL_DRIVER -DSTM32H745xx -c -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/NN/Include" -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/DSP/Include" -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../Core/Inc -O3 -ffunction-sections -fdata-sections -fno-strict-aliasing -Wall -fstack-usage -MMD -MP -MF"Core/NN-Src/ConvolutionFunctions/arm_convolve_HWC_q15_fast.d" -MT"$@"  -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/NN-Src/ConvolutionFunctions/arm_convolve_HWC_q15_fast_nonsquare.o: ../Core/NN-Src/ConvolutionFunctions/arm_convolve_HWC_q15_fast_nonsquare.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -D__FPU_PRESENT -DCORE_CM7 -DARM_MATH_CM7 -DARM_MATH_MVEI -DUSE_HAL_DRIVER -DSTM32H745xx -c -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/NN/Include" -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/DSP/Include" -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../Core/Inc -O3 -ffunction-sections -fdata-sections -fno-strict-aliasing -Wall -fstack-usage -MMD -MP -MF"Core/NN-Src/ConvolutionFunctions/arm_convolve_HWC_q15_fast_nonsquare.d" -MT"$@"  -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/NN-Src/ConvolutionFunctions/arm_convolve_HWC_q7_RGB.o: ../Core/NN-Src/ConvolutionFunctions/arm_convolve_HWC_q7_RGB.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -D__FPU_PRESENT -DCORE_CM7 -DARM_MATH_CM7 -DARM_MATH_MVEI -DUSE_HAL_DRIVER -DSTM32H745xx -c -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/NN/Include" -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/DSP/Include" -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../Core/Inc -O3 -ffunction-sections -fdata-sections -fno-strict-aliasing -Wall -fstack-usage -MMD -MP -MF"Core/NN-Src/ConvolutionFunctions/arm_convolve_HWC_q7_RGB.d" -MT"$@"  -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/NN-Src/ConvolutionFunctions/arm_convolve_HWC_q7_basic.o: ../Core/NN-Src/ConvolutionFunctions/arm_convolve_HWC_q7_basic.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -D__FPU_PRESENT -DCORE_CM7 -DARM_MATH_CM7 -DARM_MATH_MVEI -DUSE_HAL_DRIVER -DSTM32H745xx -c -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/NN/Include" -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/DSP/Include" -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../Core/Inc -O3 -ffunction-sections -fdata-sections -fno-strict-aliasing -Wall -fstack-usage -MMD -MP -MF"Core/NN-Src/ConvolutionFunctions/arm_convolve_HWC_q7_basic.d" -MT"$@"  -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/NN-Src/ConvolutionFunctions/arm_convolve_HWC_q7_basic_nonsquare.o: ../Core/NN-Src/ConvolutionFunctions/arm_convolve_HWC_q7_basic_nonsquare.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -D__FPU_PRESENT -DCORE_CM7 -DARM_MATH_CM7 -DARM_MATH_MVEI -DUSE_HAL_DRIVER -DSTM32H745xx -c -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/NN/Include" -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/DSP/Include" -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../Core/Inc -O3 -ffunction-sections -fdata-sections -fno-strict-aliasing -Wall -fstack-usage -MMD -MP -MF"Core/NN-Src/ConvolutionFunctions/arm_convolve_HWC_q7_basic_nonsquare.d" -MT"$@"  -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/NN-Src/ConvolutionFunctions/arm_convolve_HWC_q7_fast.o: ../Core/NN-Src/ConvolutionFunctions/arm_convolve_HWC_q7_fast.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -D__FPU_PRESENT -DCORE_CM7 -DARM_MATH_CM7 -DARM_MATH_MVEI -DUSE_HAL_DRIVER -DSTM32H745xx -c -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/NN/Include" -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/DSP/Include" -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../Core/Inc -O3 -ffunction-sections -fdata-sections -fno-strict-aliasing -Wall -fstack-usage -MMD -MP -MF"Core/NN-Src/ConvolutionFunctions/arm_convolve_HWC_q7_fast.d" -MT"$@"  -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/NN-Src/ConvolutionFunctions/arm_convolve_HWC_q7_fast_nonsquare.o: ../Core/NN-Src/ConvolutionFunctions/arm_convolve_HWC_q7_fast_nonsquare.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -D__FPU_PRESENT -DCORE_CM7 -DARM_MATH_CM7 -DARM_MATH_MVEI -DUSE_HAL_DRIVER -DSTM32H745xx -c -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/NN/Include" -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/DSP/Include" -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../Core/Inc -O3 -ffunction-sections -fdata-sections -fno-strict-aliasing -Wall -fstack-usage -MMD -MP -MF"Core/NN-Src/ConvolutionFunctions/arm_convolve_HWC_q7_fast_nonsquare.d" -MT"$@"  -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/NN-Src/ConvolutionFunctions/arm_depthwise_separable_conv_HWC_q7.o: ../Core/NN-Src/ConvolutionFunctions/arm_depthwise_separable_conv_HWC_q7.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -D__FPU_PRESENT -DCORE_CM7 -DARM_MATH_CM7 -DARM_MATH_MVEI -DUSE_HAL_DRIVER -DSTM32H745xx -c -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/NN/Include" -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/DSP/Include" -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../Core/Inc -O3 -ffunction-sections -fdata-sections -fno-strict-aliasing -Wall -fstack-usage -MMD -MP -MF"Core/NN-Src/ConvolutionFunctions/arm_depthwise_separable_conv_HWC_q7.d" -MT"$@"  -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/NN-Src/ConvolutionFunctions/arm_depthwise_separable_conv_HWC_q7_nonsquare.o: ../Core/NN-Src/ConvolutionFunctions/arm_depthwise_separable_conv_HWC_q7_nonsquare.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -D__FPU_PRESENT -DCORE_CM7 -DARM_MATH_CM7 -DARM_MATH_MVEI -DUSE_HAL_DRIVER -DSTM32H745xx -c -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/NN/Include" -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/DSP/Include" -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../Core/Inc -O3 -ffunction-sections -fdata-sections -fno-strict-aliasing -Wall -fstack-usage -MMD -MP -MF"Core/NN-Src/ConvolutionFunctions/arm_depthwise_separable_conv_HWC_q7_nonsquare.d" -MT"$@"  -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/NN-Src/ConvolutionFunctions/arm_nn_mat_mult_kernel_q7_q15.o: ../Core/NN-Src/ConvolutionFunctions/arm_nn_mat_mult_kernel_q7_q15.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -D__FPU_PRESENT -DCORE_CM7 -DARM_MATH_CM7 -DARM_MATH_MVEI -DUSE_HAL_DRIVER -DSTM32H745xx -c -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/NN/Include" -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/DSP/Include" -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../Core/Inc -O3 -ffunction-sections -fdata-sections -fno-strict-aliasing -Wall -fstack-usage -MMD -MP -MF"Core/NN-Src/ConvolutionFunctions/arm_nn_mat_mult_kernel_q7_q15.d" -MT"$@"  -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/NN-Src/ConvolutionFunctions/arm_nn_mat_mult_kernel_q7_q15_reordered.o: ../Core/NN-Src/ConvolutionFunctions/arm_nn_mat_mult_kernel_q7_q15_reordered.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -D__FPU_PRESENT -DCORE_CM7 -DARM_MATH_CM7 -DARM_MATH_MVEI -DUSE_HAL_DRIVER -DSTM32H745xx -c -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/NN/Include" -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/DSP/Include" -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../Core/Inc -O3 -ffunction-sections -fdata-sections -fno-strict-aliasing -Wall -fstack-usage -MMD -MP -MF"Core/NN-Src/ConvolutionFunctions/arm_nn_mat_mult_kernel_q7_q15_reordered.d" -MT"$@"  -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

