################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Inc/MCAL/TIMER2/TIMER2_Program.c 

OBJS += \
./Inc/MCAL/TIMER2/TIMER2_Program.o 

C_DEPS += \
./Inc/MCAL/TIMER2/TIMER2_Program.d 


# Each subdirectory must supply rules for building sources it contributes
Inc/MCAL/TIMER2/%.o: ../Inc/MCAL/TIMER2/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


