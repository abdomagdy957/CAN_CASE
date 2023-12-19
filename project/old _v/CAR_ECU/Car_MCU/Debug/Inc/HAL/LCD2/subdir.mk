################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Inc/HAL/LCD2/LCD_Imp.c 

OBJS += \
./Inc/HAL/LCD2/LCD_Imp.o 

C_DEPS += \
./Inc/HAL/LCD2/LCD_Imp.d 


# Each subdirectory must supply rules for building sources it contributes
Inc/HAL/LCD2/%.o: ../Inc/HAL/LCD2/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


