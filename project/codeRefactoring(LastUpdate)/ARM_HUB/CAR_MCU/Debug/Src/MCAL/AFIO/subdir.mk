################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/MCAL/AFIO/AFIO_program.c 

OBJS += \
./Src/MCAL/AFIO/AFIO_program.o 

C_DEPS += \
./Src/MCAL/AFIO/AFIO_program.d 


# Each subdirectory must supply rules for building sources it contributes
Src/MCAL/AFIO/%.o Src/MCAL/AFIO/%.su Src/MCAL/AFIO/%.cyclo: ../Src/MCAL/AFIO/%.c Src/MCAL/AFIO/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src-2f-MCAL-2f-AFIO

clean-Src-2f-MCAL-2f-AFIO:
	-$(RM) ./Src/MCAL/AFIO/AFIO_program.cyclo ./Src/MCAL/AFIO/AFIO_program.d ./Src/MCAL/AFIO/AFIO_program.o ./Src/MCAL/AFIO/AFIO_program.su

.PHONY: clean-Src-2f-MCAL-2f-AFIO

