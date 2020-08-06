################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/ronny/STM32CubeIDE/mestrado/main_project/Drivers/CMSIS/Source/PoolingFunctions/arm_pool_q7_HWC.c 

OBJS += \
./Drivers/CMSIS/Source/PoolingFunctions/arm_pool_q7_HWC.o 

C_DEPS += \
./Drivers/CMSIS/Source/PoolingFunctions/arm_pool_q7_HWC.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/CMSIS/Source/PoolingFunctions/arm_pool_q7_HWC.o: C:/Users/ronny/STM32CubeIDE/mestrado/main_project/Drivers/CMSIS/Source/PoolingFunctions/arm_pool_q7_HWC.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DUSE_HAL_DRIVER -DCORE_CM7 -DSTM32H745xx -c -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Core/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/STM32H7xx_HAL_Driver/Inc -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/CMSIS/Source/PoolingFunctions/arm_pool_q7_HWC.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

