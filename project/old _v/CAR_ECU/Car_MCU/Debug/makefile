################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Src/subdir.mk
-include Inc/MCAL/USART/subdir.mk
-include Inc/MCAL/TIMER2/subdir.mk
-include Inc/MCAL/TIMER1/subdir.mk
-include Inc/MCAL/TIMER0/subdir.mk
-include Inc/MCAL/SPI/subdir.mk
-include Inc/MCAL/Port/subdir.mk
-include Inc/MCAL/ICU/subdir.mk
-include Inc/MCAL/GIE/subdir.mk
-include Inc/MCAL/EXT_INT/subdir.mk
-include Inc/MCAL/DIO/subdir.mk
-include Inc/MCAL/ADC/subdir.mk
-include Inc/HAL/Servo/subdir.mk
-include Inc/HAL/Motor/subdir.mk
-include Inc/HAL/LED/subdir.mk
-include Inc/HAL/LCD2/subdir.mk
-include Inc/HAL/KeyPad/subdir.mk
-include Inc/APP/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
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
LSS += \
M_Car_MCU.lss \

FLASH_IMAGE += \
M_Car_MCU.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: M_Car_MCU.elf secondary-outputs

# Tool invocations
M_Car_MCU.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,M_Car_MCU.map -mmcu=atmega32 -o "M_Car_MCU.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

M_Car_MCU.lss: M_Car_MCU.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S M_Car_MCU.elf  >"M_Car_MCU.lss"
	@echo 'Finished building: $@'
	@echo ' '

M_Car_MCU.hex: M_Car_MCU.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex M_Car_MCU.elf  "M_Car_MCU.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: M_Car_MCU.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 M_Car_MCU.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) M_Car_MCU.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
