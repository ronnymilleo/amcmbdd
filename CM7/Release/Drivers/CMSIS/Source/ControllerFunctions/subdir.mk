################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/ronny/STM32CubeIDE/mestrado/main_project/Drivers/CMSIS/Source/ControllerFunctions/arm_pid_init_f32.c \
C:/Users/ronny/STM32CubeIDE/mestrado/main_project/Drivers/CMSIS/Source/ControllerFunctions/arm_pid_init_q15.c \
C:/Users/ronny/STM32CubeIDE/mestrado/main_project/Drivers/CMSIS/Source/ControllerFunctions/arm_pid_init_q31.c \
C:/Users/ronny/STM32CubeIDE/mestrado/main_project/Drivers/CMSIS/Source/ControllerFunctions/arm_pid_reset_f32.c \
C:/Users/ronny/STM32CubeIDE/mestrado/main_project/Drivers/CMSIS/Source/ControllerFunctions/arm_pid_reset_q15.c \
C:/Users/ronny/STM32CubeIDE/mestrado/main_project/Drivers/CMSIS/Source/ControllerFunctions/arm_pid_reset_q31.c \
C:/Users/ronny/STM32CubeIDE/mestrado/main_project/Drivers/CMSIS/Source/ControllerFunctions/arm_sin_cos_f32.c \
C:/Users/ronny/STM32CubeIDE/mestrado/main_project/Drivers/CMSIS/Source/ControllerFunctions/arm_sin_cos_q31.c 

OBJS += \
./Drivers/CMSIS/Source/ControllerFunctions/arm_pid_init_f32.o \
./Drivers/CMSIS/Source/ControllerFunctions/arm_pid_init_q15.o \
./Drivers/CMSIS/Source/ControllerFunctions/arm_pid_init_q31.o \
./Drivers/CMSIS/Source/ControllerFunctions/arm_pid_reset_f32.o \
./Drivers/CMSIS/Source/ControllerFunctions/arm_pid_reset_q15.o \
./Drivers/CMSIS/Source/ControllerFunctions/arm_pid_reset_q31.o \
./Drivers/CMSIS/Source/ControllerFunctions/arm_sin_cos_f32.o \
./Drivers/CMSIS/Source/ControllerFunctions/arm_sin_cos_q31.o 

C_DEPS += \
./Drivers/CMSIS/Source/ControllerFunctions/arm_pid_init_f32.d \
./Drivers/CMSIS/Source/ControllerFunctions/arm_pid_init_q15.d \
./Drivers/CMSIS/Source/ControllerFunctions/arm_pid_init_q31.d \
./Drivers/CMSIS/Source/ControllerFunctions/arm_pid_reset_f32.d \
./Drivers/CMSIS/Source/ControllerFunctions/arm_pid_reset_q15.d \
./Drivers/CMSIS/Source/ControllerFunctions/arm_pid_reset_q31.d \
./Drivers/CMSIS/Source/ControllerFunctions/arm_sin_cos_f32.d \
./Drivers/CMSIS/Source/ControllerFunctions/arm_sin_cos_q31.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/CMSIS/Source/ControllerFunctions/arm_pid_init_f32.o: C:/Users/ronny/STM32CubeIDE/mestrado/main_project/Drivers/CMSIS/Source/ControllerFunctions/arm_pid_init_f32.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DUSE_HAL_DRIVER -DCORE_CM7 -DSTM32H745xx -c -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Core/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/STM32H7xx_HAL_Driver/Inc -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/CMSIS/Source/ControllerFunctions/arm_pid_init_f32.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/CMSIS/Source/ControllerFunctions/arm_pid_init_q15.o: C:/Users/ronny/STM32CubeIDE/mestrado/main_project/Drivers/CMSIS/Source/ControllerFunctions/arm_pid_init_q15.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DUSE_HAL_DRIVER -DCORE_CM7 -DSTM32H745xx -c -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Core/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/STM32H7xx_HAL_Driver/Inc -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/CMSIS/Source/ControllerFunctions/arm_pid_init_q15.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/CMSIS/Source/ControllerFunctions/arm_pid_init_q31.o: C:/Users/ronny/STM32CubeIDE/mestrado/main_project/Drivers/CMSIS/Source/ControllerFunctions/arm_pid_init_q31.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DUSE_HAL_DRIVER -DCORE_CM7 -DSTM32H745xx -c -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Core/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/STM32H7xx_HAL_Driver/Inc -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/CMSIS/Source/ControllerFunctions/arm_pid_init_q31.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/CMSIS/Source/ControllerFunctions/arm_pid_reset_f32.o: C:/Users/ronny/STM32CubeIDE/mestrado/main_project/Drivers/CMSIS/Source/ControllerFunctions/arm_pid_reset_f32.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DUSE_HAL_DRIVER -DCORE_CM7 -DSTM32H745xx -c -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Core/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/STM32H7xx_HAL_Driver/Inc -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/CMSIS/Source/ControllerFunctions/arm_pid_reset_f32.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/CMSIS/Source/ControllerFunctions/arm_pid_reset_q15.o: C:/Users/ronny/STM32CubeIDE/mestrado/main_project/Drivers/CMSIS/Source/ControllerFunctions/arm_pid_reset_q15.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DUSE_HAL_DRIVER -DCORE_CM7 -DSTM32H745xx -c -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Core/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/STM32H7xx_HAL_Driver/Inc -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/CMSIS/Source/ControllerFunctions/arm_pid_reset_q15.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/CMSIS/Source/ControllerFunctions/arm_pid_reset_q31.o: C:/Users/ronny/STM32CubeIDE/mestrado/main_project/Drivers/CMSIS/Source/ControllerFunctions/arm_pid_reset_q31.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DUSE_HAL_DRIVER -DCORE_CM7 -DSTM32H745xx -c -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Core/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/STM32H7xx_HAL_Driver/Inc -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/CMSIS/Source/ControllerFunctions/arm_pid_reset_q31.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/CMSIS/Source/ControllerFunctions/arm_sin_cos_f32.o: C:/Users/ronny/STM32CubeIDE/mestrado/main_project/Drivers/CMSIS/Source/ControllerFunctions/arm_sin_cos_f32.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DUSE_HAL_DRIVER -DCORE_CM7 -DSTM32H745xx -c -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Core/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/STM32H7xx_HAL_Driver/Inc -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/CMSIS/Source/ControllerFunctions/arm_sin_cos_f32.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/CMSIS/Source/ControllerFunctions/arm_sin_cos_q31.o: C:/Users/ronny/STM32CubeIDE/mestrado/main_project/Drivers/CMSIS/Source/ControllerFunctions/arm_sin_cos_q31.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DUSE_HAL_DRIVER -DCORE_CM7 -DSTM32H745xx -c -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Core/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/STM32H7xx_HAL_Driver/Inc -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/CMSIS/Source/ControllerFunctions/arm_sin_cos_q31.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

