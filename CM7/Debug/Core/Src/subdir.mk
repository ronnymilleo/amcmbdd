################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/fully_connected.c \
../Core/Src/functions.c \
../Core/Src/gpio.c \
../Core/Src/main.c \
../Core/Src/stm32h7xx_hal_msp.c \
../Core/Src/stm32h7xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/tim.c \
../Core/Src/usart.c 

OBJS += \
./Core/Src/fully_connected.o \
./Core/Src/functions.o \
./Core/Src/gpio.o \
./Core/Src/main.o \
./Core/Src/stm32h7xx_hal_msp.o \
./Core/Src/stm32h7xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/tim.o \
./Core/Src/usart.o 

C_DEPS += \
./Core/Src/fully_connected.d \
./Core/Src/functions.d \
./Core/Src/gpio.d \
./Core/Src/main.d \
./Core/Src/stm32h7xx_hal_msp.d \
./Core/Src/stm32h7xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/tim.d \
./Core/Src/usart.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/fully_connected.o: ../Core/Src/fully_connected.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -D__FPU_PRESENT -DSTM32H745xx -DUSE_HAL_DRIVER -DCORE_CM7 -DARM_MATH_CM7 -DARM_MATH_MVEI -DDEBUG -c -I"D:/Programming/C/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/NN/Include" -I"D:/Programming/C/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/DSP/Include" -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../Core/Inc -O0 -ffunction-sections -fdata-sections -fno-strict-aliasing -Wall -fstack-usage -MMD -MP -MF"Core/Src/fully_connected.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/functions.o: ../Core/Src/functions.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -D__FPU_PRESENT -DSTM32H745xx -DUSE_HAL_DRIVER -DCORE_CM7 -DARM_MATH_CM7 -DARM_MATH_MVEI -DDEBUG -c -I"D:/Programming/C/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/NN/Include" -I"D:/Programming/C/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/DSP/Include" -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../Core/Inc -O0 -ffunction-sections -fdata-sections -fno-strict-aliasing -Wall -fstack-usage -MMD -MP -MF"Core/Src/functions.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/gpio.o: ../Core/Src/gpio.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -D__FPU_PRESENT -DSTM32H745xx -DUSE_HAL_DRIVER -DCORE_CM7 -DARM_MATH_CM7 -DARM_MATH_MVEI -DDEBUG -c -I"D:/Programming/C/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/NN/Include" -I"D:/Programming/C/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/DSP/Include" -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../Core/Inc -O0 -ffunction-sections -fdata-sections -fno-strict-aliasing -Wall -fstack-usage -MMD -MP -MF"Core/Src/gpio.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/main.o: ../Core/Src/main.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -D__FPU_PRESENT -DSTM32H745xx -DUSE_HAL_DRIVER -DCORE_CM7 -DARM_MATH_CM7 -DARM_MATH_MVEI -DDEBUG -c -I"D:/Programming/C/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/NN/Include" -I"D:/Programming/C/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/DSP/Include" -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../Core/Inc -O0 -ffunction-sections -fdata-sections -fno-strict-aliasing -Wall -fstack-usage -MMD -MP -MF"Core/Src/main.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/stm32h7xx_hal_msp.o: ../Core/Src/stm32h7xx_hal_msp.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -D__FPU_PRESENT -DSTM32H745xx -DUSE_HAL_DRIVER -DCORE_CM7 -DARM_MATH_CM7 -DARM_MATH_MVEI -DDEBUG -c -I"D:/Programming/C/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/NN/Include" -I"D:/Programming/C/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/DSP/Include" -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../Core/Inc -O0 -ffunction-sections -fdata-sections -fno-strict-aliasing -Wall -fstack-usage -MMD -MP -MF"Core/Src/stm32h7xx_hal_msp.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/stm32h7xx_it.o: ../Core/Src/stm32h7xx_it.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -D__FPU_PRESENT -DSTM32H745xx -DUSE_HAL_DRIVER -DCORE_CM7 -DARM_MATH_CM7 -DARM_MATH_MVEI -DDEBUG -c -I"D:/Programming/C/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/NN/Include" -I"D:/Programming/C/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/DSP/Include" -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../Core/Inc -O0 -ffunction-sections -fdata-sections -fno-strict-aliasing -Wall -fstack-usage -MMD -MP -MF"Core/Src/stm32h7xx_it.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/syscalls.o: ../Core/Src/syscalls.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -D__FPU_PRESENT -DSTM32H745xx -DUSE_HAL_DRIVER -DCORE_CM7 -DARM_MATH_CM7 -DARM_MATH_MVEI -DDEBUG -c -I"D:/Programming/C/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/NN/Include" -I"D:/Programming/C/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/DSP/Include" -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../Core/Inc -O0 -ffunction-sections -fdata-sections -fno-strict-aliasing -Wall -fstack-usage -MMD -MP -MF"Core/Src/syscalls.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/sysmem.o: ../Core/Src/sysmem.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -D__FPU_PRESENT -DSTM32H745xx -DUSE_HAL_DRIVER -DCORE_CM7 -DARM_MATH_CM7 -DARM_MATH_MVEI -DDEBUG -c -I"D:/Programming/C/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/NN/Include" -I"D:/Programming/C/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/DSP/Include" -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../Core/Inc -O0 -ffunction-sections -fdata-sections -fno-strict-aliasing -Wall -fstack-usage -MMD -MP -MF"Core/Src/sysmem.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/tim.o: ../Core/Src/tim.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -D__FPU_PRESENT -DSTM32H745xx -DUSE_HAL_DRIVER -DCORE_CM7 -DARM_MATH_CM7 -DARM_MATH_MVEI -DDEBUG -c -I"D:/Programming/C/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/NN/Include" -I"D:/Programming/C/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/DSP/Include" -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../Core/Inc -O0 -ffunction-sections -fdata-sections -fno-strict-aliasing -Wall -fstack-usage -MMD -MP -MF"Core/Src/tim.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/usart.o: ../Core/Src/usart.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -D__FPU_PRESENT -DSTM32H745xx -DUSE_HAL_DRIVER -DCORE_CM7 -DARM_MATH_CM7 -DARM_MATH_MVEI -DDEBUG -c -I"D:/Programming/C/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/NN/Include" -I"D:/Programming/C/STM32Cube/Repository/STM32Cube_FW_H7_V1.8.0/Drivers/CMSIS/DSP/Include" -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../Core/Inc -O0 -ffunction-sections -fdata-sections -fno-strict-aliasing -Wall -fstack-usage -MMD -MP -MF"Core/Src/usart.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

