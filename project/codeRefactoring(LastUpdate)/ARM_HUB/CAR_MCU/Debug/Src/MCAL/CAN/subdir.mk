################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/MCAL/CAN/CAN_program.c 

OBJS += \
./Src/MCAL/CAN/CAN_program.o 

C_DEPS += \
./Src/MCAL/CAN/CAN_program.d 


# Each subdirectory must supply rules for building sources it contributes
Src/MCAL/CAN/%.o Src/MCAL/CAN/%.su Src/MCAL/CAN/%.cyclo: ../Src/MCAL/CAN/%.c Src/MCAL/CAN/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src-2f-MCAL-2f-CAN

clean-Src-2f-MCAL-2f-CAN:
	-$(RM) ./Src/MCAL/CAN/CAN_program.cyclo ./Src/MCAL/CAN/CAN_program.d ./Src/MCAL/CAN/CAN_program.o ./Src/MCAL/CAN/CAN_program.su

.PHONY: clean-Src-2f-MCAL-2f-CAN

