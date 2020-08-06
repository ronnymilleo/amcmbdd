################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/ronny/STM32CubeIDE/mestrado/main_project/Drivers/CMSIS/Source/ActivationFunctions/arm_nn_activations_q15.c \
C:/Users/ronny/STM32CubeIDE/mestrado/main_project/Drivers/CMSIS/Source/ActivationFunctions/arm_nn_activations_q7.c \
C:/Users/ronny/STM32CubeIDE/mestrado/main_project/Drivers/CMSIS/Source/ActivationFunctions/arm_relu_q15.c \
C:/Users/ronny/STM32CubeIDE/mestrado/main_project/Drivers/CMSIS/Source/ActivationFunctions/arm_relu_q7.c 

OBJS += \
./Drivers/CMSIS/Source/ActivationFunctions/arm_nn_activations_q15.o \
./Drivers/CMSIS/Source/ActivationFunctions/arm_nn_activations_q7.o \
./Drivers/CMSIS/Source/ActivationFunctions/arm_relu_q15.o \
./Drivers/CMSIS/Source/ActivationFunctions/arm_relu_q7.o 

C_DEPS += \
./Drivers/CMSIS/Source/ActivationFunctions/arm_nn_activations_q15.d \
./Drivers/CMSIS/Source/ActivationFunctions/arm_nn_activations_q7.d \
./Drivers/CMSIS/Source/ActivationFunctions/arm_relu_q15.d \
./Drivers/CMSIS/Source/ActivationFunctions/arm_relu_q7.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/CMSIS/Source/ActivationFunctions/arm_nn_activations_q15.o: C:/Users/ronny/STM32CubeIDE/mestrado/main_project/Drivers/CMSIS/Source/ActivationFunctions/arm_nn_activations_q15.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -D__FPU_PRESENT -DARM_MATH_CM7 -DCORE_CM7 -DDEBUG -DSTM32H745xx -c -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Core/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/STM32H7xx_HAL_Driver/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/CMSIS/Source/ActivationFunctions/arm_nn_activations_q15.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/CMSIS/Source/ActivationFunctions/arm_nn_activations_q7.o: C:/Users/ronny/STM32CubeIDE/mestrado/main_project/Drivers/CMSIS/Source/ActivationFunctions/arm_nn_activations_q7.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -D__FPU_PRESENT -DARM_MATH_CM7 -DCORE_CM7 -DDEBUG -DSTM32H745xx -c -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Core/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/STM32H7xx_HAL_Driver/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/CMSIS/Source/ActivationFunctions/arm_nn_activations_q7.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/CMSIS/Source/ActivationFunctions/arm_relu_q15.o: C:/Users/ronny/STM32CubeIDE/mestrado/main_project/Drivers/CMSIS/Source/ActivationFunctions/arm_relu_q15.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -D__FPU_PRESENT -DARM_MATH_CM7 -DCORE_CM7 -DDEBUG -DSTM32H745xx -c -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Core/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/STM32H7xx_HAL_Driver/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/CMSIS/Source/ActivationFunctions/arm_relu_q15.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/CMSIS/Source/ActivationFunctions/arm_relu_q7.o: C:/Users/ronny/STM32CubeIDE/mestrado/main_project/Drivers/CMSIS/Source/ActivationFunctions/arm_relu_q7.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -D__FPU_PRESENT -DARM_MATH_CM7 -DCORE_CM7 -DDEBUG -DSTM32H745xx -c -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Core/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/STM32H7xx_HAL_Driver/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/CMSIS/Source/ActivationFunctions/arm_relu_q7.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

