################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/DSP-Src/CommonTables/arm_common_tables.c \
../Core/DSP-Src/CommonTables/arm_const_structs.c 

OBJS += \
./Core/DSP-Src/CommonTables/arm_common_tables.o \
./Core/DSP-Src/CommonTables/arm_const_structs.o 

C_DEPS += \
./Core/DSP-Src/CommonTables/arm_common_tables.d \
./Core/DSP-Src/CommonTables/arm_const_structs.d 


# Each subdirectory must supply rules for building sources it contributes
Core/DSP-Src/CommonTables/arm_common_tables.o: ../Core/DSP-Src/CommonTables/arm_common_tables.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -D__FPU_PRESENT -DCORE_CM7 -DARM_MATH_CM7 -DARM_MATH_MVEI -DUSE_HAL_DRIVER -DSTM32H745xx -c -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/NN/Include" -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/DSP/Include" -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../Core/Inc -O3 -ffunction-sections -fdata-sections -fno-strict-aliasing -Wall -fstack-usage -MMD -MP -MF"Core/DSP-Src/CommonTables/arm_common_tables.d" -MT"$@"  -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/DSP-Src/CommonTables/arm_const_structs.o: ../Core/DSP-Src/CommonTables/arm_const_structs.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -D__FPU_PRESENT -DCORE_CM7 -DARM_MATH_CM7 -DARM_MATH_MVEI -DUSE_HAL_DRIVER -DSTM32H745xx -c -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/NN/Include" -I"C:/Users/ronny/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/DSP/Include" -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../Core/Inc -O3 -ffunction-sections -fdata-sections -fno-strict-aliasing -Wall -fstack-usage -MMD -MP -MF"Core/DSP-Src/CommonTables/arm_const_structs.d" -MT"$@"  -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

