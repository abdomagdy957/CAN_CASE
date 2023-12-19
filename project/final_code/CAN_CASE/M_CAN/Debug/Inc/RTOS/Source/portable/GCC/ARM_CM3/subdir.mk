################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Inc/RTOS/Source/portable/GCC/ARM_CM3/port.c 

OBJS += \
./Inc/RTOS/Source/portable/GCC/ARM_CM3/port.o 

C_DEPS += \
./Inc/RTOS/Source/portable/GCC/ARM_CM3/port.d 


# Each subdirectory must supply rules for building sources it contributes
Inc/RTOS/Source/portable/GCC/ARM_CM3/%.o Inc/RTOS/Source/portable/GCC/ARM_CM3/%.su Inc/RTOS/Source/portable/GCC/ARM_CM3/%.cyclo: ../Inc/RTOS/Source/portable/GCC/ARM_CM3/%.c Inc/RTOS/Source/portable/GCC/ARM_CM3/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Inc-2f-RTOS-2f-Source-2f-portable-2f-GCC-2f-ARM_CM3

clean-Inc-2f-RTOS-2f-Source-2f-portable-2f-GCC-2f-ARM_CM3:
	-$(RM) ./Inc/RTOS/Source/portable/GCC/ARM_CM3/port.cyclo ./Inc/RTOS/Source/portable/GCC/ARM_CM3/port.d ./Inc/RTOS/Source/portable/GCC/ARM_CM3/port.o ./Inc/RTOS/Source/portable/GCC/ARM_CM3/port.su

.PHONY: clean-Inc-2f-RTOS-2f-Source-2f-portable-2f-GCC-2f-ARM_CM3

