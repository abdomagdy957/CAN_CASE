################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Inc/RTOS/Source/portable/MemMang/heap_4.c 

OBJS += \
./Inc/RTOS/Source/portable/MemMang/heap_4.o 

C_DEPS += \
./Inc/RTOS/Source/portable/MemMang/heap_4.d 


# Each subdirectory must supply rules for building sources it contributes
Inc/RTOS/Source/portable/MemMang/%.o Inc/RTOS/Source/portable/MemMang/%.su Inc/RTOS/Source/portable/MemMang/%.cyclo: ../Inc/RTOS/Source/portable/MemMang/%.c Inc/RTOS/Source/portable/MemMang/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Inc-2f-RTOS-2f-Source-2f-portable-2f-MemMang

clean-Inc-2f-RTOS-2f-Source-2f-portable-2f-MemMang:
	-$(RM) ./Inc/RTOS/Source/portable/MemMang/heap_4.cyclo ./Inc/RTOS/Source/portable/MemMang/heap_4.d ./Inc/RTOS/Source/portable/MemMang/heap_4.o ./Inc/RTOS/Source/portable/MemMang/heap_4.su

.PHONY: clean-Inc-2f-RTOS-2f-Source-2f-portable-2f-MemMang

