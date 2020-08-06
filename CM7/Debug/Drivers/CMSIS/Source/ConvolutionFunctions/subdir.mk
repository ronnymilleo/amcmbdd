################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/ronny/STM32CubeIDE/mestrado/main_project/Drivers/CMSIS/Source/ConvolutionFunctions/arm_convolve_1x1_HWC_q7_fast_nonsquare.c \
C:/Users/ronny/STM32CubeIDE/mestrado/main_project/Drivers/CMSIS/Source/ConvolutionFunctions/arm_convolve_HWC_q15_basic.c \
C:/Users/ronny/STM32CubeIDE/mestrado/main_project/Drivers/CMSIS/Source/ConvolutionFunctions/arm_convolve_HWC_q15_fast.c \
C:/Users/ronny/STM32CubeIDE/mestrado/main_project/Drivers/CMSIS/Source/ConvolutionFunctions/arm_convolve_HWC_q15_fast_nonsquare.c \
C:/Users/ronny/STM32CubeIDE/mestrado/main_project/Drivers/CMSIS/Source/ConvolutionFunctions/arm_convolve_HWC_q7_RGB.c \
C:/Users/ronny/STM32CubeIDE/mestrado/main_project/Drivers/CMSIS/Source/ConvolutionFunctions/arm_convolve_HWC_q7_basic.c \
C:/Users/ronny/STM32CubeIDE/mestrado/main_project/Drivers/CMSIS/Source/ConvolutionFunctions/arm_convolve_HWC_q7_basic_nonsquare.c \
C:/Users/ronny/STM32CubeIDE/mestrado/main_project/Drivers/CMSIS/Source/ConvolutionFunctions/arm_convolve_HWC_q7_fast.c \
C:/Users/ronny/STM32CubeIDE/mestrado/main_project/Drivers/CMSIS/Source/ConvolutionFunctions/arm_convolve_HWC_q7_fast_nonsquare.c \
C:/Users/ronny/STM32CubeIDE/mestrado/main_project/Drivers/CMSIS/Source/ConvolutionFunctions/arm_depthwise_separable_conv_HWC_q7.c \
C:/Users/ronny/STM32CubeIDE/mestrado/main_project/Drivers/CMSIS/Source/ConvolutionFunctions/arm_depthwise_separable_conv_HWC_q7_nonsquare.c \
C:/Users/ronny/STM32CubeIDE/mestrado/main_project/Drivers/CMSIS/Source/ConvolutionFunctions/arm_nn_mat_mult_kernel_q7_q15.c \
C:/Users/ronny/STM32CubeIDE/mestrado/main_project/Drivers/CMSIS/Source/ConvolutionFunctions/arm_nn_mat_mult_kernel_q7_q15_reordered.c 

OBJS += \
./Drivers/CMSIS/Source/ConvolutionFunctions/arm_convolve_1x1_HWC_q7_fast_nonsquare.o \
./Drivers/CMSIS/Source/ConvolutionFunctions/arm_convolve_HWC_q15_basic.o \
./Drivers/CMSIS/Source/ConvolutionFunctions/arm_convolve_HWC_q15_fast.o \
./Drivers/CMSIS/Source/ConvolutionFunctions/arm_convolve_HWC_q15_fast_nonsquare.o \
./Drivers/CMSIS/Source/ConvolutionFunctions/arm_convolve_HWC_q7_RGB.o \
./Drivers/CMSIS/Source/ConvolutionFunctions/arm_convolve_HWC_q7_basic.o \
./Drivers/CMSIS/Source/ConvolutionFunctions/arm_convolve_HWC_q7_basic_nonsquare.o \
./Drivers/CMSIS/Source/ConvolutionFunctions/arm_convolve_HWC_q7_fast.o \
./Drivers/CMSIS/Source/ConvolutionFunctions/arm_convolve_HWC_q7_fast_nonsquare.o \
./Drivers/CMSIS/Source/ConvolutionFunctions/arm_depthwise_separable_conv_HWC_q7.o \
./Drivers/CMSIS/Source/ConvolutionFunctions/arm_depthwise_separable_conv_HWC_q7_nonsquare.o \
./Drivers/CMSIS/Source/ConvolutionFunctions/arm_nn_mat_mult_kernel_q7_q15.o \
./Drivers/CMSIS/Source/ConvolutionFunctions/arm_nn_mat_mult_kernel_q7_q15_reordered.o 

C_DEPS += \
./Drivers/CMSIS/Source/ConvolutionFunctions/arm_convolve_1x1_HWC_q7_fast_nonsquare.d \
./Drivers/CMSIS/Source/ConvolutionFunctions/arm_convolve_HWC_q15_basic.d \
./Drivers/CMSIS/Source/ConvolutionFunctions/arm_convolve_HWC_q15_fast.d \
./Drivers/CMSIS/Source/ConvolutionFunctions/arm_convolve_HWC_q15_fast_nonsquare.d \
./Drivers/CMSIS/Source/ConvolutionFunctions/arm_convolve_HWC_q7_RGB.d \
./Drivers/CMSIS/Source/ConvolutionFunctions/arm_convolve_HWC_q7_basic.d \
./Drivers/CMSIS/Source/ConvolutionFunctions/arm_convolve_HWC_q7_basic_nonsquare.d \
./Drivers/CMSIS/Source/ConvolutionFunctions/arm_convolve_HWC_q7_fast.d \
./Drivers/CMSIS/Source/ConvolutionFunctions/arm_convolve_HWC_q7_fast_nonsquare.d \
./Drivers/CMSIS/Source/ConvolutionFunctions/arm_depthwise_separable_conv_HWC_q7.d \
./Drivers/CMSIS/Source/ConvolutionFunctions/arm_depthwise_separable_conv_HWC_q7_nonsquare.d \
./Drivers/CMSIS/Source/ConvolutionFunctions/arm_nn_mat_mult_kernel_q7_q15.d \
./Drivers/CMSIS/Source/ConvolutionFunctions/arm_nn_mat_mult_kernel_q7_q15_reordered.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/CMSIS/Source/ConvolutionFunctions/arm_convolve_1x1_HWC_q7_fast_nonsquare.o: C:/Users/ronny/STM32CubeIDE/mestrado/main_project/Drivers/CMSIS/Source/ConvolutionFunctions/arm_convolve_1x1_HWC_q7_fast_nonsquare.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -D__FPU_PRESENT -DARM_MATH_CM7 -DCORE_CM7 -DDEBUG -DSTM32H745xx -c -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Core/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/STM32H7xx_HAL_Driver/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/CMSIS/Source/ConvolutionFunctions/arm_convolve_1x1_HWC_q7_fast_nonsquare.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/CMSIS/Source/ConvolutionFunctions/arm_convolve_HWC_q15_basic.o: C:/Users/ronny/STM32CubeIDE/mestrado/main_project/Drivers/CMSIS/Source/ConvolutionFunctions/arm_convolve_HWC_q15_basic.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -D__FPU_PRESENT -DARM_MATH_CM7 -DCORE_CM7 -DDEBUG -DSTM32H745xx -c -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Core/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/STM32H7xx_HAL_Driver/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/CMSIS/Source/ConvolutionFunctions/arm_convolve_HWC_q15_basic.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/CMSIS/Source/ConvolutionFunctions/arm_convolve_HWC_q15_fast.o: C:/Users/ronny/STM32CubeIDE/mestrado/main_project/Drivers/CMSIS/Source/ConvolutionFunctions/arm_convolve_HWC_q15_fast.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -D__FPU_PRESENT -DARM_MATH_CM7 -DCORE_CM7 -DDEBUG -DSTM32H745xx -c -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Core/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/STM32H7xx_HAL_Driver/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/CMSIS/Source/ConvolutionFunctions/arm_convolve_HWC_q15_fast.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/CMSIS/Source/ConvolutionFunctions/arm_convolve_HWC_q15_fast_nonsquare.o: C:/Users/ronny/STM32CubeIDE/mestrado/main_project/Drivers/CMSIS/Source/ConvolutionFunctions/arm_convolve_HWC_q15_fast_nonsquare.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -D__FPU_PRESENT -DARM_MATH_CM7 -DCORE_CM7 -DDEBUG -DSTM32H745xx -c -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Core/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/STM32H7xx_HAL_Driver/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/CMSIS/Source/ConvolutionFunctions/arm_convolve_HWC_q15_fast_nonsquare.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/CMSIS/Source/ConvolutionFunctions/arm_convolve_HWC_q7_RGB.o: C:/Users/ronny/STM32CubeIDE/mestrado/main_project/Drivers/CMSIS/Source/ConvolutionFunctions/arm_convolve_HWC_q7_RGB.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -D__FPU_PRESENT -DARM_MATH_CM7 -DCORE_CM7 -DDEBUG -DSTM32H745xx -c -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Core/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/STM32H7xx_HAL_Driver/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/CMSIS/Source/ConvolutionFunctions/arm_convolve_HWC_q7_RGB.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/CMSIS/Source/ConvolutionFunctions/arm_convolve_HWC_q7_basic.o: C:/Users/ronny/STM32CubeIDE/mestrado/main_project/Drivers/CMSIS/Source/ConvolutionFunctions/arm_convolve_HWC_q7_basic.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -D__FPU_PRESENT -DARM_MATH_CM7 -DCORE_CM7 -DDEBUG -DSTM32H745xx -c -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Core/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/STM32H7xx_HAL_Driver/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/CMSIS/Source/ConvolutionFunctions/arm_convolve_HWC_q7_basic.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/CMSIS/Source/ConvolutionFunctions/arm_convolve_HWC_q7_basic_nonsquare.o: C:/Users/ronny/STM32CubeIDE/mestrado/main_project/Drivers/CMSIS/Source/ConvolutionFunctions/arm_convolve_HWC_q7_basic_nonsquare.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -D__FPU_PRESENT -DARM_MATH_CM7 -DCORE_CM7 -DDEBUG -DSTM32H745xx -c -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Core/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/STM32H7xx_HAL_Driver/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/CMSIS/Source/ConvolutionFunctions/arm_convolve_HWC_q7_basic_nonsquare.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/CMSIS/Source/ConvolutionFunctions/arm_convolve_HWC_q7_fast.o: C:/Users/ronny/STM32CubeIDE/mestrado/main_project/Drivers/CMSIS/Source/ConvolutionFunctions/arm_convolve_HWC_q7_fast.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -D__FPU_PRESENT -DARM_MATH_CM7 -DCORE_CM7 -DDEBUG -DSTM32H745xx -c -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Core/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/STM32H7xx_HAL_Driver/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/CMSIS/Source/ConvolutionFunctions/arm_convolve_HWC_q7_fast.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/CMSIS/Source/ConvolutionFunctions/arm_convolve_HWC_q7_fast_nonsquare.o: C:/Users/ronny/STM32CubeIDE/mestrado/main_project/Drivers/CMSIS/Source/ConvolutionFunctions/arm_convolve_HWC_q7_fast_nonsquare.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -D__FPU_PRESENT -DARM_MATH_CM7 -DCORE_CM7 -DDEBUG -DSTM32H745xx -c -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Core/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/STM32H7xx_HAL_Driver/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/CMSIS/Source/ConvolutionFunctions/arm_convolve_HWC_q7_fast_nonsquare.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/CMSIS/Source/ConvolutionFunctions/arm_depthwise_separable_conv_HWC_q7.o: C:/Users/ronny/STM32CubeIDE/mestrado/main_project/Drivers/CMSIS/Source/ConvolutionFunctions/arm_depthwise_separable_conv_HWC_q7.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -D__FPU_PRESENT -DARM_MATH_CM7 -DCORE_CM7 -DDEBUG -DSTM32H745xx -c -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Core/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/STM32H7xx_HAL_Driver/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/CMSIS/Source/ConvolutionFunctions/arm_depthwise_separable_conv_HWC_q7.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/CMSIS/Source/ConvolutionFunctions/arm_depthwise_separable_conv_HWC_q7_nonsquare.o: C:/Users/ronny/STM32CubeIDE/mestrado/main_project/Drivers/CMSIS/Source/ConvolutionFunctions/arm_depthwise_separable_conv_HWC_q7_nonsquare.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -D__FPU_PRESENT -DARM_MATH_CM7 -DCORE_CM7 -DDEBUG -DSTM32H745xx -c -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Core/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/STM32H7xx_HAL_Driver/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/CMSIS/Source/ConvolutionFunctions/arm_depthwise_separable_conv_HWC_q7_nonsquare.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/CMSIS/Source/ConvolutionFunctions/arm_nn_mat_mult_kernel_q7_q15.o: C:/Users/ronny/STM32CubeIDE/mestrado/main_project/Drivers/CMSIS/Source/ConvolutionFunctions/arm_nn_mat_mult_kernel_q7_q15.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -D__FPU_PRESENT -DARM_MATH_CM7 -DCORE_CM7 -DDEBUG -DSTM32H745xx -c -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Core/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/STM32H7xx_HAL_Driver/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/CMSIS/Source/ConvolutionFunctions/arm_nn_mat_mult_kernel_q7_q15.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/CMSIS/Source/ConvolutionFunctions/arm_nn_mat_mult_kernel_q7_q15_reordered.o: C:/Users/ronny/STM32CubeIDE/mestrado/main_project/Drivers/CMSIS/Source/ConvolutionFunctions/arm_nn_mat_mult_kernel_q7_q15_reordered.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -D__FPU_PRESENT -DARM_MATH_CM7 -DCORE_CM7 -DDEBUG -DSTM32H745xx -c -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Core/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/STM32H7xx_HAL_Driver/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/CMSIS/Source/ConvolutionFunctions/arm_nn_mat_mult_kernel_q7_q15_reordered.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

