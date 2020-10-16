################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/DSP-Src/SupportFunctions/arm_copy_f32.c \
../Core/DSP-Src/SupportFunctions/arm_copy_q15.c \
../Core/DSP-Src/SupportFunctions/arm_copy_q31.c \
../Core/DSP-Src/SupportFunctions/arm_copy_q7.c \
../Core/DSP-Src/SupportFunctions/arm_fill_f32.c \
../Core/DSP-Src/SupportFunctions/arm_fill_q15.c \
../Core/DSP-Src/SupportFunctions/arm_fill_q31.c \
../Core/DSP-Src/SupportFunctions/arm_fill_q7.c \
../Core/DSP-Src/SupportFunctions/arm_float_to_q15.c \
../Core/DSP-Src/SupportFunctions/arm_float_to_q31.c \
../Core/DSP-Src/SupportFunctions/arm_float_to_q7.c \
../Core/DSP-Src/SupportFunctions/arm_q15_to_float.c \
../Core/DSP-Src/SupportFunctions/arm_q15_to_q31.c \
../Core/DSP-Src/SupportFunctions/arm_q15_to_q7.c \
../Core/DSP-Src/SupportFunctions/arm_q31_to_float.c \
../Core/DSP-Src/SupportFunctions/arm_q31_to_q15.c \
../Core/DSP-Src/SupportFunctions/arm_q31_to_q7.c \
../Core/DSP-Src/SupportFunctions/arm_q7_to_float.c \
../Core/DSP-Src/SupportFunctions/arm_q7_to_q15.c \
../Core/DSP-Src/SupportFunctions/arm_q7_to_q31.c 

OBJS += \
./Core/DSP-Src/SupportFunctions/arm_copy_f32.o \
./Core/DSP-Src/SupportFunctions/arm_copy_q15.o \
./Core/DSP-Src/SupportFunctions/arm_copy_q31.o \
./Core/DSP-Src/SupportFunctions/arm_copy_q7.o \
./Core/DSP-Src/SupportFunctions/arm_fill_f32.o \
./Core/DSP-Src/SupportFunctions/arm_fill_q15.o \
./Core/DSP-Src/SupportFunctions/arm_fill_q31.o \
./Core/DSP-Src/SupportFunctions/arm_fill_q7.o \
./Core/DSP-Src/SupportFunctions/arm_float_to_q15.o \
./Core/DSP-Src/SupportFunctions/arm_float_to_q31.o \
./Core/DSP-Src/SupportFunctions/arm_float_to_q7.o \
./Core/DSP-Src/SupportFunctions/arm_q15_to_float.o \
./Core/DSP-Src/SupportFunctions/arm_q15_to_q31.o \
./Core/DSP-Src/SupportFunctions/arm_q15_to_q7.o \
./Core/DSP-Src/SupportFunctions/arm_q31_to_float.o \
./Core/DSP-Src/SupportFunctions/arm_q31_to_q15.o \
./Core/DSP-Src/SupportFunctions/arm_q31_to_q7.o \
./Core/DSP-Src/SupportFunctions/arm_q7_to_float.o \
./Core/DSP-Src/SupportFunctions/arm_q7_to_q15.o \
./Core/DSP-Src/SupportFunctions/arm_q7_to_q31.o 

C_DEPS += \
./Core/DSP-Src/SupportFunctions/arm_copy_f32.d \
./Core/DSP-Src/SupportFunctions/arm_copy_q15.d \
./Core/DSP-Src/SupportFunctions/arm_copy_q31.d \
./Core/DSP-Src/SupportFunctions/arm_copy_q7.d \
./Core/DSP-Src/SupportFunctions/arm_fill_f32.d \
./Core/DSP-Src/SupportFunctions/arm_fill_q15.d \
./Core/DSP-Src/SupportFunctions/arm_fill_q31.d \
./Core/DSP-Src/SupportFunctions/arm_fill_q7.d \
./Core/DSP-Src/SupportFunctions/arm_float_to_q15.d \
./Core/DSP-Src/SupportFunctions/arm_float_to_q31.d \
./Core/DSP-Src/SupportFunctions/arm_float_to_q7.d \
./Core/DSP-Src/SupportFunctions/arm_q15_to_float.d \
./Core/DSP-Src/SupportFunctions/arm_q15_to_q31.d \
./Core/DSP-Src/SupportFunctions/arm_q15_to_q7.d \
./Core/DSP-Src/SupportFunctions/arm_q31_to_float.d \
./Core/DSP-Src/SupportFunctions/arm_q31_to_q15.d \
./Core/DSP-Src/SupportFunctions/arm_q31_to_q7.d \
./Core/DSP-Src/SupportFunctions/arm_q7_to_float.d \
./Core/DSP-Src/SupportFunctions/arm_q7_to_q15.d \
./Core/DSP-Src/SupportFunctions/arm_q7_to_q31.d 


# Each subdirectory must supply rules for building sources it contributes
Core/DSP-Src/SupportFunctions/arm_copy_f32.o: ../Core/DSP-Src/SupportFunctions/arm_copy_f32.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -D__FPU_PRESENT -DCORE_CM7 -DARM_MATH_CM7 -DARM_MATH_MVEI -DUSE_HAL_DRIVER -DSTM32H745xx -c -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/NN/Include" -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/DSP/Include" -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../Core/Inc -O3 -ffunction-sections -fdata-sections -fno-strict-aliasing -Wall -fstack-usage -MMD -MP -MF"Core/DSP-Src/SupportFunctions/arm_copy_f32.d" -MT"$@"  -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/DSP-Src/SupportFunctions/arm_copy_q15.o: ../Core/DSP-Src/SupportFunctions/arm_copy_q15.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -D__FPU_PRESENT -DCORE_CM7 -DARM_MATH_CM7 -DARM_MATH_MVEI -DUSE_HAL_DRIVER -DSTM32H745xx -c -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/NN/Include" -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/DSP/Include" -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../Core/Inc -O3 -ffunction-sections -fdata-sections -fno-strict-aliasing -Wall -fstack-usage -MMD -MP -MF"Core/DSP-Src/SupportFunctions/arm_copy_q15.d" -MT"$@"  -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/DSP-Src/SupportFunctions/arm_copy_q31.o: ../Core/DSP-Src/SupportFunctions/arm_copy_q31.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -D__FPU_PRESENT -DCORE_CM7 -DARM_MATH_CM7 -DARM_MATH_MVEI -DUSE_HAL_DRIVER -DSTM32H745xx -c -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/NN/Include" -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/DSP/Include" -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../Core/Inc -O3 -ffunction-sections -fdata-sections -fno-strict-aliasing -Wall -fstack-usage -MMD -MP -MF"Core/DSP-Src/SupportFunctions/arm_copy_q31.d" -MT"$@"  -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/DSP-Src/SupportFunctions/arm_copy_q7.o: ../Core/DSP-Src/SupportFunctions/arm_copy_q7.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -D__FPU_PRESENT -DCORE_CM7 -DARM_MATH_CM7 -DARM_MATH_MVEI -DUSE_HAL_DRIVER -DSTM32H745xx -c -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/NN/Include" -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/DSP/Include" -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../Core/Inc -O3 -ffunction-sections -fdata-sections -fno-strict-aliasing -Wall -fstack-usage -MMD -MP -MF"Core/DSP-Src/SupportFunctions/arm_copy_q7.d" -MT"$@"  -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/DSP-Src/SupportFunctions/arm_fill_f32.o: ../Core/DSP-Src/SupportFunctions/arm_fill_f32.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -D__FPU_PRESENT -DCORE_CM7 -DARM_MATH_CM7 -DARM_MATH_MVEI -DUSE_HAL_DRIVER -DSTM32H745xx -c -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/NN/Include" -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/DSP/Include" -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../Core/Inc -O3 -ffunction-sections -fdata-sections -fno-strict-aliasing -Wall -fstack-usage -MMD -MP -MF"Core/DSP-Src/SupportFunctions/arm_fill_f32.d" -MT"$@"  -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/DSP-Src/SupportFunctions/arm_fill_q15.o: ../Core/DSP-Src/SupportFunctions/arm_fill_q15.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -D__FPU_PRESENT -DCORE_CM7 -DARM_MATH_CM7 -DARM_MATH_MVEI -DUSE_HAL_DRIVER -DSTM32H745xx -c -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/NN/Include" -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/DSP/Include" -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../Core/Inc -O3 -ffunction-sections -fdata-sections -fno-strict-aliasing -Wall -fstack-usage -MMD -MP -MF"Core/DSP-Src/SupportFunctions/arm_fill_q15.d" -MT"$@"  -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/DSP-Src/SupportFunctions/arm_fill_q31.o: ../Core/DSP-Src/SupportFunctions/arm_fill_q31.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -D__FPU_PRESENT -DCORE_CM7 -DARM_MATH_CM7 -DARM_MATH_MVEI -DUSE_HAL_DRIVER -DSTM32H745xx -c -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/NN/Include" -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/DSP/Include" -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../Core/Inc -O3 -ffunction-sections -fdata-sections -fno-strict-aliasing -Wall -fstack-usage -MMD -MP -MF"Core/DSP-Src/SupportFunctions/arm_fill_q31.d" -MT"$@"  -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/DSP-Src/SupportFunctions/arm_fill_q7.o: ../Core/DSP-Src/SupportFunctions/arm_fill_q7.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -D__FPU_PRESENT -DCORE_CM7 -DARM_MATH_CM7 -DARM_MATH_MVEI -DUSE_HAL_DRIVER -DSTM32H745xx -c -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/NN/Include" -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/DSP/Include" -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../Core/Inc -O3 -ffunction-sections -fdata-sections -fno-strict-aliasing -Wall -fstack-usage -MMD -MP -MF"Core/DSP-Src/SupportFunctions/arm_fill_q7.d" -MT"$@"  -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/DSP-Src/SupportFunctions/arm_float_to_q15.o: ../Core/DSP-Src/SupportFunctions/arm_float_to_q15.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -D__FPU_PRESENT -DCORE_CM7 -DARM_MATH_CM7 -DARM_MATH_MVEI -DUSE_HAL_DRIVER -DSTM32H745xx -c -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/NN/Include" -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/DSP/Include" -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../Core/Inc -O3 -ffunction-sections -fdata-sections -fno-strict-aliasing -Wall -fstack-usage -MMD -MP -MF"Core/DSP-Src/SupportFunctions/arm_float_to_q15.d" -MT"$@"  -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/DSP-Src/SupportFunctions/arm_float_to_q31.o: ../Core/DSP-Src/SupportFunctions/arm_float_to_q31.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -D__FPU_PRESENT -DCORE_CM7 -DARM_MATH_CM7 -DARM_MATH_MVEI -DUSE_HAL_DRIVER -DSTM32H745xx -c -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/NN/Include" -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/DSP/Include" -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../Core/Inc -O3 -ffunction-sections -fdata-sections -fno-strict-aliasing -Wall -fstack-usage -MMD -MP -MF"Core/DSP-Src/SupportFunctions/arm_float_to_q31.d" -MT"$@"  -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/DSP-Src/SupportFunctions/arm_float_to_q7.o: ../Core/DSP-Src/SupportFunctions/arm_float_to_q7.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -D__FPU_PRESENT -DCORE_CM7 -DARM_MATH_CM7 -DARM_MATH_MVEI -DUSE_HAL_DRIVER -DSTM32H745xx -c -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/NN/Include" -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/DSP/Include" -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../Core/Inc -O3 -ffunction-sections -fdata-sections -fno-strict-aliasing -Wall -fstack-usage -MMD -MP -MF"Core/DSP-Src/SupportFunctions/arm_float_to_q7.d" -MT"$@"  -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/DSP-Src/SupportFunctions/arm_q15_to_float.o: ../Core/DSP-Src/SupportFunctions/arm_q15_to_float.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -D__FPU_PRESENT -DCORE_CM7 -DARM_MATH_CM7 -DARM_MATH_MVEI -DUSE_HAL_DRIVER -DSTM32H745xx -c -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/NN/Include" -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/DSP/Include" -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../Core/Inc -O3 -ffunction-sections -fdata-sections -fno-strict-aliasing -Wall -fstack-usage -MMD -MP -MF"Core/DSP-Src/SupportFunctions/arm_q15_to_float.d" -MT"$@"  -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/DSP-Src/SupportFunctions/arm_q15_to_q31.o: ../Core/DSP-Src/SupportFunctions/arm_q15_to_q31.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -D__FPU_PRESENT -DCORE_CM7 -DARM_MATH_CM7 -DARM_MATH_MVEI -DUSE_HAL_DRIVER -DSTM32H745xx -c -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/NN/Include" -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/DSP/Include" -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../Core/Inc -O3 -ffunction-sections -fdata-sections -fno-strict-aliasing -Wall -fstack-usage -MMD -MP -MF"Core/DSP-Src/SupportFunctions/arm_q15_to_q31.d" -MT"$@"  -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/DSP-Src/SupportFunctions/arm_q15_to_q7.o: ../Core/DSP-Src/SupportFunctions/arm_q15_to_q7.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -D__FPU_PRESENT -DCORE_CM7 -DARM_MATH_CM7 -DARM_MATH_MVEI -DUSE_HAL_DRIVER -DSTM32H745xx -c -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/NN/Include" -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/DSP/Include" -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../Core/Inc -O3 -ffunction-sections -fdata-sections -fno-strict-aliasing -Wall -fstack-usage -MMD -MP -MF"Core/DSP-Src/SupportFunctions/arm_q15_to_q7.d" -MT"$@"  -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/DSP-Src/SupportFunctions/arm_q31_to_float.o: ../Core/DSP-Src/SupportFunctions/arm_q31_to_float.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -D__FPU_PRESENT -DCORE_CM7 -DARM_MATH_CM7 -DARM_MATH_MVEI -DUSE_HAL_DRIVER -DSTM32H745xx -c -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/NN/Include" -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/DSP/Include" -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../Core/Inc -O3 -ffunction-sections -fdata-sections -fno-strict-aliasing -Wall -fstack-usage -MMD -MP -MF"Core/DSP-Src/SupportFunctions/arm_q31_to_float.d" -MT"$@"  -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/DSP-Src/SupportFunctions/arm_q31_to_q15.o: ../Core/DSP-Src/SupportFunctions/arm_q31_to_q15.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -D__FPU_PRESENT -DCORE_CM7 -DARM_MATH_CM7 -DARM_MATH_MVEI -DUSE_HAL_DRIVER -DSTM32H745xx -c -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/NN/Include" -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/DSP/Include" -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../Core/Inc -O3 -ffunction-sections -fdata-sections -fno-strict-aliasing -Wall -fstack-usage -MMD -MP -MF"Core/DSP-Src/SupportFunctions/arm_q31_to_q15.d" -MT"$@"  -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/DSP-Src/SupportFunctions/arm_q31_to_q7.o: ../Core/DSP-Src/SupportFunctions/arm_q31_to_q7.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -D__FPU_PRESENT -DCORE_CM7 -DARM_MATH_CM7 -DARM_MATH_MVEI -DUSE_HAL_DRIVER -DSTM32H745xx -c -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/NN/Include" -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/DSP/Include" -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../Core/Inc -O3 -ffunction-sections -fdata-sections -fno-strict-aliasing -Wall -fstack-usage -MMD -MP -MF"Core/DSP-Src/SupportFunctions/arm_q31_to_q7.d" -MT"$@"  -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/DSP-Src/SupportFunctions/arm_q7_to_float.o: ../Core/DSP-Src/SupportFunctions/arm_q7_to_float.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -D__FPU_PRESENT -DCORE_CM7 -DARM_MATH_CM7 -DARM_MATH_MVEI -DUSE_HAL_DRIVER -DSTM32H745xx -c -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/NN/Include" -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/DSP/Include" -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../Core/Inc -O3 -ffunction-sections -fdata-sections -fno-strict-aliasing -Wall -fstack-usage -MMD -MP -MF"Core/DSP-Src/SupportFunctions/arm_q7_to_float.d" -MT"$@"  -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/DSP-Src/SupportFunctions/arm_q7_to_q15.o: ../Core/DSP-Src/SupportFunctions/arm_q7_to_q15.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -D__FPU_PRESENT -DCORE_CM7 -DARM_MATH_CM7 -DARM_MATH_MVEI -DUSE_HAL_DRIVER -DSTM32H745xx -c -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/NN/Include" -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/DSP/Include" -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../Core/Inc -O3 -ffunction-sections -fdata-sections -fno-strict-aliasing -Wall -fstack-usage -MMD -MP -MF"Core/DSP-Src/SupportFunctions/arm_q7_to_q15.d" -MT"$@"  -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/DSP-Src/SupportFunctions/arm_q7_to_q31.o: ../Core/DSP-Src/SupportFunctions/arm_q7_to_q31.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -D__FPU_PRESENT -DCORE_CM7 -DARM_MATH_CM7 -DARM_MATH_MVEI -DUSE_HAL_DRIVER -DSTM32H745xx -c -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/NN/Include" -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/DSP/Include" -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../Core/Inc -O3 -ffunction-sections -fdata-sections -fno-strict-aliasing -Wall -fstack-usage -MMD -MP -MF"Core/DSP-Src/SupportFunctions/arm_q7_to_q31.d" -MT"$@"  -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

