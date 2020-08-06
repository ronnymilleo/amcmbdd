################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32H7xx_HAL_Driver/Src/subdir.mk
-include Drivers/CMSIS/Source/TransformFunctions/subdir.mk
-include Drivers/CMSIS/Source/SupportFunctions/subdir.mk
-include Drivers/CMSIS/Source/StatisticsFunctions/subdir.mk
-include Drivers/CMSIS/Source/SoftmaxFunctions/subdir.mk
-include Drivers/CMSIS/Source/PoolingFunctions/subdir.mk
-include Drivers/CMSIS/Source/NNSupportFunctions/subdir.mk
-include Drivers/CMSIS/Source/MatrixFunctions/subdir.mk
-include Drivers/CMSIS/Source/FullyConnectedFunctions/subdir.mk
-include Drivers/CMSIS/Source/FilteringFunctions/subdir.mk
-include Drivers/CMSIS/Source/FastMathFunctions/subdir.mk
-include Drivers/CMSIS/Source/ConvolutionFunctions/subdir.mk
-include Drivers/CMSIS/Source/ControllerFunctions/subdir.mk
-include Drivers/CMSIS/Source/ComplexMathFunctions/subdir.mk
-include Drivers/CMSIS/Source/CommonTables/subdir.mk
-include Drivers/CMSIS/Source/BasicMathFunctions/subdir.mk
-include Drivers/CMSIS/Source/ActivationFunctions/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include Common/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
main_project_CM7.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
main_project_CM7.list \

OBJCOPY_BIN += \
main_project_CM7.bin \


# All Target
all: main_project_CM7.elf secondary-outputs

# Tool invocations
main_project_CM7.elf: $(OBJS) $(USER_OBJS) C:\Users\ronny\STM32CubeIDE\mestrado\main_project\CM7\STM32H745ZITX_FLASH.ld
	arm-none-eabi-gcc -o "main_project_CM7.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m7 -T"C:\Users\ronny\STM32CubeIDE\mestrado\main_project\CM7\STM32H745ZITX_FLASH.ld" --specs=nosys.specs -Wl,-Map="main_project_CM7.map" -Wl,--gc-sections -static -L"C:\Users\ronny\STM32CubeIDE\mestrado\main_project\Drivers\CMSIS\Lib" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -u _printf_float -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

main_project_CM7.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "main_project_CM7.list"
	@echo 'Finished building: $@'
	@echo ' '

main_project_CM7.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "main_project_CM7.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
