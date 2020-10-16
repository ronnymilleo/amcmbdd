################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/DSP-Src/ComplexMathFunctions/arm_cmplx_conj_f32.c \
../Core/DSP-Src/ComplexMathFunctions/arm_cmplx_conj_q15.c \
../Core/DSP-Src/ComplexMathFunctions/arm_cmplx_conj_q31.c \
../Core/DSP-Src/ComplexMathFunctions/arm_cmplx_dot_prod_f32.c \
../Core/DSP-Src/ComplexMathFunctions/arm_cmplx_dot_prod_q15.c \
../Core/DSP-Src/ComplexMathFunctions/arm_cmplx_dot_prod_q31.c \
../Core/DSP-Src/ComplexMathFunctions/arm_cmplx_mag_f32.c \
../Core/DSP-Src/ComplexMathFunctions/arm_cmplx_mag_q15.c \
../Core/DSP-Src/ComplexMathFunctions/arm_cmplx_mag_q31.c \
../Core/DSP-Src/ComplexMathFunctions/arm_cmplx_mag_squared_f32.c \
../Core/DSP-Src/ComplexMathFunctions/arm_cmplx_mag_squared_q15.c \
../Core/DSP-Src/ComplexMathFunctions/arm_cmplx_mag_squared_q31.c \
../Core/DSP-Src/ComplexMathFunctions/arm_cmplx_mult_cmplx_f32.c \
../Core/DSP-Src/ComplexMathFunctions/arm_cmplx_mult_cmplx_q15.c \
../Core/DSP-Src/ComplexMathFunctions/arm_cmplx_mult_cmplx_q31.c \
../Core/DSP-Src/ComplexMathFunctions/arm_cmplx_mult_real_f32.c \
../Core/DSP-Src/ComplexMathFunctions/arm_cmplx_mult_real_q15.c \
../Core/DSP-Src/ComplexMathFunctions/arm_cmplx_mult_real_q31.c 

OBJS += \
./Core/DSP-Src/ComplexMathFunctions/arm_cmplx_conj_f32.o \
./Core/DSP-Src/ComplexMathFunctions/arm_cmplx_conj_q15.o \
./Core/DSP-Src/ComplexMathFunctions/arm_cmplx_conj_q31.o \
./Core/DSP-Src/ComplexMathFunctions/arm_cmplx_dot_prod_f32.o \
./Core/DSP-Src/ComplexMathFunctions/arm_cmplx_dot_prod_q15.o \
./Core/DSP-Src/ComplexMathFunctions/arm_cmplx_dot_prod_q31.o \
./Core/DSP-Src/ComplexMathFunctions/arm_cmplx_mag_f32.o \
./Core/DSP-Src/ComplexMathFunctions/arm_cmplx_mag_q15.o \
./Core/DSP-Src/ComplexMathFunctions/arm_cmplx_mag_q31.o \
./Core/DSP-Src/ComplexMathFunctions/arm_cmplx_mag_squared_f32.o \
./Core/DSP-Src/ComplexMathFunctions/arm_cmplx_mag_squared_q15.o \
./Core/DSP-Src/ComplexMathFunctions/arm_cmplx_mag_squared_q31.o \
./Core/DSP-Src/ComplexMathFunctions/arm_cmplx_mult_cmplx_f32.o \
./Core/DSP-Src/ComplexMathFunctions/arm_cmplx_mult_cmplx_q15.o \
./Core/DSP-Src/ComplexMathFunctions/arm_cmplx_mult_cmplx_q31.o \
./Core/DSP-Src/ComplexMathFunctions/arm_cmplx_mult_real_f32.o \
./Core/DSP-Src/ComplexMathFunctions/arm_cmplx_mult_real_q15.o \
./Core/DSP-Src/ComplexMathFunctions/arm_cmplx_mult_real_q31.o 

C_DEPS += \
./Core/DSP-Src/ComplexMathFunctions/arm_cmplx_conj_f32.d \
./Core/DSP-Src/ComplexMathFunctions/arm_cmplx_conj_q15.d \
./Core/DSP-Src/ComplexMathFunctions/arm_cmplx_conj_q31.d \
./Core/DSP-Src/ComplexMathFunctions/arm_cmplx_dot_prod_f32.d \
./Core/DSP-Src/ComplexMathFunctions/arm_cmplx_dot_prod_q15.d \
./Core/DSP-Src/ComplexMathFunctions/arm_cmplx_dot_prod_q31.d \
./Core/DSP-Src/ComplexMathFunctions/arm_cmplx_mag_f32.d \
./Core/DSP-Src/ComplexMathFunctions/arm_cmplx_mag_q15.d \
./Core/DSP-Src/ComplexMathFunctions/arm_cmplx_mag_q31.d \
./Core/DSP-Src/ComplexMathFunctions/arm_cmplx_mag_squared_f32.d \
./Core/DSP-Src/ComplexMathFunctions/arm_cmplx_mag_squared_q15.d \
./Core/DSP-Src/ComplexMathFunctions/arm_cmplx_mag_squared_q31.d \
./Core/DSP-Src/ComplexMathFunctions/arm_cmplx_mult_cmplx_f32.d \
./Core/DSP-Src/ComplexMathFunctions/arm_cmplx_mult_cmplx_q15.d \
./Core/DSP-Src/ComplexMathFunctions/arm_cmplx_mult_cmplx_q31.d \
./Core/DSP-Src/ComplexMathFunctions/arm_cmplx_mult_real_f32.d \
./Core/DSP-Src/ComplexMathFunctions/arm_cmplx_mult_real_q15.d \
./Core/DSP-Src/ComplexMathFunctions/arm_cmplx_mult_real_q31.d 


# Each subdirectory must supply rules for building sources it contributes
Core/DSP-Src/ComplexMathFunctions/arm_cmplx_conj_f32.o: ../Core/DSP-Src/ComplexMathFunctions/arm_cmplx_conj_f32.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -D__FPU_PRESENT -DCORE_CM7 -DARM_MATH_CM7 -DARM_MATH_MVEI -DUSE_HAL_DRIVER -DSTM32H745xx -c -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/NN/Include" -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/DSP/Include" -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../Core/Inc -O3 -ffunction-sections -fdata-sections -fno-strict-aliasing -Wall -fstack-usage -MMD -MP -MF"Core/DSP-Src/ComplexMathFunctions/arm_cmplx_conj_f32.d" -MT"$@"  -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/DSP-Src/ComplexMathFunctions/arm_cmplx_conj_q15.o: ../Core/DSP-Src/ComplexMathFunctions/arm_cmplx_conj_q15.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -D__FPU_PRESENT -DCORE_CM7 -DARM_MATH_CM7 -DARM_MATH_MVEI -DUSE_HAL_DRIVER -DSTM32H745xx -c -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/NN/Include" -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/DSP/Include" -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../Core/Inc -O3 -ffunction-sections -fdata-sections -fno-strict-aliasing -Wall -fstack-usage -MMD -MP -MF"Core/DSP-Src/ComplexMathFunctions/arm_cmplx_conj_q15.d" -MT"$@"  -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/DSP-Src/ComplexMathFunctions/arm_cmplx_conj_q31.o: ../Core/DSP-Src/ComplexMathFunctions/arm_cmplx_conj_q31.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -D__FPU_PRESENT -DCORE_CM7 -DARM_MATH_CM7 -DARM_MATH_MVEI -DUSE_HAL_DRIVER -DSTM32H745xx -c -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/NN/Include" -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/DSP/Include" -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../Core/Inc -O3 -ffunction-sections -fdata-sections -fno-strict-aliasing -Wall -fstack-usage -MMD -MP -MF"Core/DSP-Src/ComplexMathFunctions/arm_cmplx_conj_q31.d" -MT"$@"  -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/DSP-Src/ComplexMathFunctions/arm_cmplx_dot_prod_f32.o: ../Core/DSP-Src/ComplexMathFunctions/arm_cmplx_dot_prod_f32.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -D__FPU_PRESENT -DCORE_CM7 -DARM_MATH_CM7 -DARM_MATH_MVEI -DUSE_HAL_DRIVER -DSTM32H745xx -c -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/NN/Include" -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/DSP/Include" -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../Core/Inc -O3 -ffunction-sections -fdata-sections -fno-strict-aliasing -Wall -fstack-usage -MMD -MP -MF"Core/DSP-Src/ComplexMathFunctions/arm_cmplx_dot_prod_f32.d" -MT"$@"  -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/DSP-Src/ComplexMathFunctions/arm_cmplx_dot_prod_q15.o: ../Core/DSP-Src/ComplexMathFunctions/arm_cmplx_dot_prod_q15.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -D__FPU_PRESENT -DCORE_CM7 -DARM_MATH_CM7 -DARM_MATH_MVEI -DUSE_HAL_DRIVER -DSTM32H745xx -c -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/NN/Include" -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/DSP/Include" -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../Core/Inc -O3 -ffunction-sections -fdata-sections -fno-strict-aliasing -Wall -fstack-usage -MMD -MP -MF"Core/DSP-Src/ComplexMathFunctions/arm_cmplx_dot_prod_q15.d" -MT"$@"  -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/DSP-Src/ComplexMathFunctions/arm_cmplx_dot_prod_q31.o: ../Core/DSP-Src/ComplexMathFunctions/arm_cmplx_dot_prod_q31.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -D__FPU_PRESENT -DCORE_CM7 -DARM_MATH_CM7 -DARM_MATH_MVEI -DUSE_HAL_DRIVER -DSTM32H745xx -c -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/NN/Include" -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/DSP/Include" -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../Core/Inc -O3 -ffunction-sections -fdata-sections -fno-strict-aliasing -Wall -fstack-usage -MMD -MP -MF"Core/DSP-Src/ComplexMathFunctions/arm_cmplx_dot_prod_q31.d" -MT"$@"  -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/DSP-Src/ComplexMathFunctions/arm_cmplx_mag_f32.o: ../Core/DSP-Src/ComplexMathFunctions/arm_cmplx_mag_f32.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -D__FPU_PRESENT -DCORE_CM7 -DARM_MATH_CM7 -DARM_MATH_MVEI -DUSE_HAL_DRIVER -DSTM32H745xx -c -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/NN/Include" -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/DSP/Include" -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../Core/Inc -O3 -ffunction-sections -fdata-sections -fno-strict-aliasing -Wall -fstack-usage -MMD -MP -MF"Core/DSP-Src/ComplexMathFunctions/arm_cmplx_mag_f32.d" -MT"$@"  -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/DSP-Src/ComplexMathFunctions/arm_cmplx_mag_q15.o: ../Core/DSP-Src/ComplexMathFunctions/arm_cmplx_mag_q15.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -D__FPU_PRESENT -DCORE_CM7 -DARM_MATH_CM7 -DARM_MATH_MVEI -DUSE_HAL_DRIVER -DSTM32H745xx -c -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/NN/Include" -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/DSP/Include" -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../Core/Inc -O3 -ffunction-sections -fdata-sections -fno-strict-aliasing -Wall -fstack-usage -MMD -MP -MF"Core/DSP-Src/ComplexMathFunctions/arm_cmplx_mag_q15.d" -MT"$@"  -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/DSP-Src/ComplexMathFunctions/arm_cmplx_mag_q31.o: ../Core/DSP-Src/ComplexMathFunctions/arm_cmplx_mag_q31.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -D__FPU_PRESENT -DCORE_CM7 -DARM_MATH_CM7 -DARM_MATH_MVEI -DUSE_HAL_DRIVER -DSTM32H745xx -c -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/NN/Include" -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/DSP/Include" -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../Core/Inc -O3 -ffunction-sections -fdata-sections -fno-strict-aliasing -Wall -fstack-usage -MMD -MP -MF"Core/DSP-Src/ComplexMathFunctions/arm_cmplx_mag_q31.d" -MT"$@"  -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/DSP-Src/ComplexMathFunctions/arm_cmplx_mag_squared_f32.o: ../Core/DSP-Src/ComplexMathFunctions/arm_cmplx_mag_squared_f32.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -D__FPU_PRESENT -DCORE_CM7 -DARM_MATH_CM7 -DARM_MATH_MVEI -DUSE_HAL_DRIVER -DSTM32H745xx -c -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/NN/Include" -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/DSP/Include" -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../Core/Inc -O3 -ffunction-sections -fdata-sections -fno-strict-aliasing -Wall -fstack-usage -MMD -MP -MF"Core/DSP-Src/ComplexMathFunctions/arm_cmplx_mag_squared_f32.d" -MT"$@"  -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/DSP-Src/ComplexMathFunctions/arm_cmplx_mag_squared_q15.o: ../Core/DSP-Src/ComplexMathFunctions/arm_cmplx_mag_squared_q15.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -D__FPU_PRESENT -DCORE_CM7 -DARM_MATH_CM7 -DARM_MATH_MVEI -DUSE_HAL_DRIVER -DSTM32H745xx -c -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/NN/Include" -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/DSP/Include" -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../Core/Inc -O3 -ffunction-sections -fdata-sections -fno-strict-aliasing -Wall -fstack-usage -MMD -MP -MF"Core/DSP-Src/ComplexMathFunctions/arm_cmplx_mag_squared_q15.d" -MT"$@"  -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/DSP-Src/ComplexMathFunctions/arm_cmplx_mag_squared_q31.o: ../Core/DSP-Src/ComplexMathFunctions/arm_cmplx_mag_squared_q31.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -D__FPU_PRESENT -DCORE_CM7 -DARM_MATH_CM7 -DARM_MATH_MVEI -DUSE_HAL_DRIVER -DSTM32H745xx -c -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/NN/Include" -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/DSP/Include" -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../Core/Inc -O3 -ffunction-sections -fdata-sections -fno-strict-aliasing -Wall -fstack-usage -MMD -MP -MF"Core/DSP-Src/ComplexMathFunctions/arm_cmplx_mag_squared_q31.d" -MT"$@"  -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/DSP-Src/ComplexMathFunctions/arm_cmplx_mult_cmplx_f32.o: ../Core/DSP-Src/ComplexMathFunctions/arm_cmplx_mult_cmplx_f32.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -D__FPU_PRESENT -DCORE_CM7 -DARM_MATH_CM7 -DARM_MATH_MVEI -DUSE_HAL_DRIVER -DSTM32H745xx -c -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/NN/Include" -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/DSP/Include" -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../Core/Inc -O3 -ffunction-sections -fdata-sections -fno-strict-aliasing -Wall -fstack-usage -MMD -MP -MF"Core/DSP-Src/ComplexMathFunctions/arm_cmplx_mult_cmplx_f32.d" -MT"$@"  -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/DSP-Src/ComplexMathFunctions/arm_cmplx_mult_cmplx_q15.o: ../Core/DSP-Src/ComplexMathFunctions/arm_cmplx_mult_cmplx_q15.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -D__FPU_PRESENT -DCORE_CM7 -DARM_MATH_CM7 -DARM_MATH_MVEI -DUSE_HAL_DRIVER -DSTM32H745xx -c -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/NN/Include" -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/DSP/Include" -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../Core/Inc -O3 -ffunction-sections -fdata-sections -fno-strict-aliasing -Wall -fstack-usage -MMD -MP -MF"Core/DSP-Src/ComplexMathFunctions/arm_cmplx_mult_cmplx_q15.d" -MT"$@"  -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/DSP-Src/ComplexMathFunctions/arm_cmplx_mult_cmplx_q31.o: ../Core/DSP-Src/ComplexMathFunctions/arm_cmplx_mult_cmplx_q31.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -D__FPU_PRESENT -DCORE_CM7 -DARM_MATH_CM7 -DARM_MATH_MVEI -DUSE_HAL_DRIVER -DSTM32H745xx -c -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/NN/Include" -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/DSP/Include" -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../Core/Inc -O3 -ffunction-sections -fdata-sections -fno-strict-aliasing -Wall -fstack-usage -MMD -MP -MF"Core/DSP-Src/ComplexMathFunctions/arm_cmplx_mult_cmplx_q31.d" -MT"$@"  -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/DSP-Src/ComplexMathFunctions/arm_cmplx_mult_real_f32.o: ../Core/DSP-Src/ComplexMathFunctions/arm_cmplx_mult_real_f32.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -D__FPU_PRESENT -DCORE_CM7 -DARM_MATH_CM7 -DARM_MATH_MVEI -DUSE_HAL_DRIVER -DSTM32H745xx -c -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/NN/Include" -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/DSP/Include" -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../Core/Inc -O3 -ffunction-sections -fdata-sections -fno-strict-aliasing -Wall -fstack-usage -MMD -MP -MF"Core/DSP-Src/ComplexMathFunctions/arm_cmplx_mult_real_f32.d" -MT"$@"  -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/DSP-Src/ComplexMathFunctions/arm_cmplx_mult_real_q15.o: ../Core/DSP-Src/ComplexMathFunctions/arm_cmplx_mult_real_q15.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -D__FPU_PRESENT -DCORE_CM7 -DARM_MATH_CM7 -DARM_MATH_MVEI -DUSE_HAL_DRIVER -DSTM32H745xx -c -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/NN/Include" -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/DSP/Include" -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../Core/Inc -O3 -ffunction-sections -fdata-sections -fno-strict-aliasing -Wall -fstack-usage -MMD -MP -MF"Core/DSP-Src/ComplexMathFunctions/arm_cmplx_mult_real_q15.d" -MT"$@"  -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/DSP-Src/ComplexMathFunctions/arm_cmplx_mult_real_q31.o: ../Core/DSP-Src/ComplexMathFunctions/arm_cmplx_mult_real_q31.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -D__FPU_PRESENT -DCORE_CM7 -DARM_MATH_CM7 -DARM_MATH_MVEI -DUSE_HAL_DRIVER -DSTM32H745xx -c -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/NN/Include" -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/DSP/Include" -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../Core/Inc -O3 -ffunction-sections -fdata-sections -fno-strict-aliasing -Wall -fstack-usage -MMD -MP -MF"Core/DSP-Src/ComplexMathFunctions/arm_cmplx_mult_real_q31.d" -MT"$@"  -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

