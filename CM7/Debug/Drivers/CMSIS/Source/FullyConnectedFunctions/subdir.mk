################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/ronny/STM32CubeIDE/mestrado/main_project/Drivers/CMSIS/Source/FullyConnectedFunctions/arm_fully_connected_mat_q7_vec_q15.c \
C:/Users/ronny/STM32CubeIDE/mestrado/main_project/Drivers/CMSIS/Source/FullyConnectedFunctions/arm_fully_connected_mat_q7_vec_q15_opt.c \
C:/Users/ronny/STM32CubeIDE/mestrado/main_project/Drivers/CMSIS/Source/FullyConnectedFunctions/arm_fully_connected_q15.c \
C:/Users/ronny/STM32CubeIDE/mestrado/main_project/Drivers/CMSIS/Source/FullyConnectedFunctions/arm_fully_connected_q15_opt.c \
C:/Users/ronny/STM32CubeIDE/mestrado/main_project/Drivers/CMSIS/Source/FullyConnectedFunctions/arm_fully_connected_q7.c \
C:/Users/ronny/STM32CubeIDE/mestrado/main_project/Drivers/CMSIS/Source/FullyConnectedFunctions/arm_fully_connected_q7_opt.c 

OBJS += \
./Drivers/CMSIS/Source/FullyConnectedFunctions/arm_fully_connected_mat_q7_vec_q15.o \
./Drivers/CMSIS/Source/FullyConnectedFunctions/arm_fully_connected_mat_q7_vec_q15_opt.o \
./Drivers/CMSIS/Source/FullyConnectedFunctions/arm_fully_connected_q15.o \
./Drivers/CMSIS/Source/FullyConnectedFunctions/arm_fully_connected_q15_opt.o \
./Drivers/CMSIS/Source/FullyConnectedFunctions/arm_fully_connected_q7.o \
./Drivers/CMSIS/Source/FullyConnectedFunctions/arm_fully_connected_q7_opt.o 

C_DEPS += \
./Drivers/CMSIS/Source/FullyConnectedFunctions/arm_fully_connected_mat_q7_vec_q15.d \
./Drivers/CMSIS/Source/FullyConnectedFunctions/arm_fully_connected_mat_q7_vec_q15_opt.d \
./Drivers/CMSIS/Source/FullyConnectedFunctions/arm_fully_connected_q15.d \
./Drivers/CMSIS/Source/FullyConnectedFunctions/arm_fully_connected_q15_opt.d \
./Drivers/CMSIS/Source/FullyConnectedFunctions/arm_fully_connected_q7.d \
./Drivers/CMSIS/Source/FullyConnectedFunctions/arm_fully_connected_q7_opt.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/CMSIS/Source/FullyConnectedFunctions/arm_fully_connected_mat_q7_vec_q15.o: C:/Users/ronny/STM32CubeIDE/mestrado/main_project/Drivers/CMSIS/Source/FullyConnectedFunctions/arm_fully_connected_mat_q7_vec_q15.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -D__FPU_PRESENT -DARM_MATH_CM7 -DCORE_CM7 -DDEBUG -DSTM32H745xx -c -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Core/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/STM32H7xx_HAL_Driver/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/CMSIS/Source/FullyConnectedFunctions/arm_fully_connected_mat_q7_vec_q15.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/CMSIS/Source/FullyConnectedFunctions/arm_fully_connected_mat_q7_vec_q15_opt.o: C:/Users/ronny/STM32CubeIDE/mestrado/main_project/Drivers/CMSIS/Source/FullyConnectedFunctions/arm_fully_connected_mat_q7_vec_q15_opt.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -D__FPU_PRESENT -DARM_MATH_CM7 -DCORE_CM7 -DDEBUG -DSTM32H745xx -c -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Core/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/STM32H7xx_HAL_Driver/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/CMSIS/Source/FullyConnectedFunctions/arm_fully_connected_mat_q7_vec_q15_opt.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/CMSIS/Source/FullyConnectedFunctions/arm_fully_connected_q15.o: C:/Users/ronny/STM32CubeIDE/mestrado/main_project/Drivers/CMSIS/Source/FullyConnectedFunctions/arm_fully_connected_q15.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -D__FPU_PRESENT -DARM_MATH_CM7 -DCORE_CM7 -DDEBUG -DSTM32H745xx -c -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Core/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/STM32H7xx_HAL_Driver/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/CMSIS/Source/FullyConnectedFunctions/arm_fully_connected_q15.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/CMSIS/Source/FullyConnectedFunctions/arm_fully_connected_q15_opt.o: C:/Users/ronny/STM32CubeIDE/mestrado/main_project/Drivers/CMSIS/Source/FullyConnectedFunctions/arm_fully_connected_q15_opt.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -D__FPU_PRESENT -DARM_MATH_CM7 -DCORE_CM7 -DDEBUG -DSTM32H745xx -c -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Core/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/STM32H7xx_HAL_Driver/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/CMSIS/Source/FullyConnectedFunctions/arm_fully_connected_q15_opt.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/CMSIS/Source/FullyConnectedFunctions/arm_fully_connected_q7.o: C:/Users/ronny/STM32CubeIDE/mestrado/main_project/Drivers/CMSIS/Source/FullyConnectedFunctions/arm_fully_connected_q7.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -D__FPU_PRESENT -DARM_MATH_CM7 -DCORE_CM7 -DDEBUG -DSTM32H745xx -c -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Core/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/STM32H7xx_HAL_Driver/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/CMSIS/Source/FullyConnectedFunctions/arm_fully_connected_q7.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/CMSIS/Source/FullyConnectedFunctions/arm_fully_connected_q7_opt.o: C:/Users/ronny/STM32CubeIDE/mestrado/main_project/Drivers/CMSIS/Source/FullyConnectedFunctions/arm_fully_connected_q7_opt.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -D__FPU_PRESENT -DARM_MATH_CM7 -DCORE_CM7 -DDEBUG -DSTM32H745xx -c -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Core/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/STM32H7xx_HAL_Driver/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/CMSIS/Source/FullyConnectedFunctions/arm_fully_connected_q7_opt.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

