################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/ronny/STM32CubeIDE/mestrado/main_project/Drivers/CMSIS/Source/CommonTables/arm_common_tables.c \
C:/Users/ronny/STM32CubeIDE/mestrado/main_project/Drivers/CMSIS/Source/CommonTables/arm_const_structs.c 

OBJS += \
./Drivers/CMSIS/Source/CommonTables/arm_common_tables.o \
./Drivers/CMSIS/Source/CommonTables/arm_const_structs.o 

C_DEPS += \
./Drivers/CMSIS/Source/CommonTables/arm_common_tables.d \
./Drivers/CMSIS/Source/CommonTables/arm_const_structs.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/CMSIS/Source/CommonTables/arm_common_tables.o: C:/Users/ronny/STM32CubeIDE/mestrado/main_project/Drivers/CMSIS/Source/CommonTables/arm_common_tables.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DUSE_HAL_DRIVER -DCORE_CM7 -DSTM32H745xx -c -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Core/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/STM32H7xx_HAL_Driver/Inc -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/CMSIS/Source/CommonTables/arm_common_tables.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/CMSIS/Source/CommonTables/arm_const_structs.o: C:/Users/ronny/STM32CubeIDE/mestrado/main_project/Drivers/CMSIS/Source/CommonTables/arm_const_structs.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DUSE_HAL_DRIVER -DCORE_CM7 -DSTM32H745xx -c -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Core/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/STM32H7xx_HAL_Driver/Inc -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/CMSIS/Source/CommonTables/arm_const_structs.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

