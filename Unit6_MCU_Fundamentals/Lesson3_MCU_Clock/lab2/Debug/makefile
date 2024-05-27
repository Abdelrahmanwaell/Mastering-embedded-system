################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
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
MCU_FUND_lab2.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
MCU_FUND_lab2.list \

OBJCOPY_BIN += \
MCU_FUND_lab2.bin \


# All Target
all: MCU_FUND_lab2.elf secondary-outputs

# Tool invocations
MCU_FUND_lab2.elf: $(OBJS) $(USER_OBJS) D:\learn\ in\ depth\unit6_MCU_Fund\Lesson3\MCU_FUND_lab2\STM32F103C8TX_FLASH.ld
	arm-none-eabi-gcc -o "MCU_FUND_lab2.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"D:\learn in depth\unit6_MCU_Fund\Lesson3\MCU_FUND_lab2\STM32F103C8TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="MCU_FUND_lab2.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

MCU_FUND_lab2.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "MCU_FUND_lab2.list"
	@echo 'Finished building: $@'
	@echo ' '

MCU_FUND_lab2.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "MCU_FUND_lab2.bin"
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
