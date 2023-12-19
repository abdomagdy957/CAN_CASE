################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Inc/RTOS/Source/croutine.c \
../Inc/RTOS/Source/event_groups.c \
../Inc/RTOS/Source/list.c \
../Inc/RTOS/Source/queue.c \
../Inc/RTOS/Source/stream_buffer.c \
../Inc/RTOS/Source/tasks.c \
../Inc/RTOS/Source/timers.c 

OBJS += \
./Inc/RTOS/Source/croutine.o \
./Inc/RTOS/Source/event_groups.o \
./Inc/RTOS/Source/list.o \
./Inc/RTOS/Source/queue.o \
./Inc/RTOS/Source/stream_buffer.o \
./Inc/RTOS/Source/tasks.o \
./Inc/RTOS/Source/timers.o 

C_DEPS += \
./Inc/RTOS/Source/croutine.d \
./Inc/RTOS/Source/event_groups.d \
./Inc/RTOS/Source/list.d \
./Inc/RTOS/Source/queue.d \
./Inc/RTOS/Source/stream_buffer.d \
./Inc/RTOS/Source/tasks.d \
./Inc/RTOS/Source/timers.d 


# Each subdirectory must supply rules for building sources it contributes
Inc/RTOS/Source/%.o Inc/RTOS/Source/%.su Inc/RTOS/Source/%.cyclo: ../Inc/RTOS/Source/%.c Inc/RTOS/Source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Inc-2f-RTOS-2f-Source

clean-Inc-2f-RTOS-2f-Source:
	-$(RM) ./Inc/RTOS/Source/croutine.cyclo ./Inc/RTOS/Source/croutine.d ./Inc/RTOS/Source/croutine.o ./Inc/RTOS/Source/croutine.su ./Inc/RTOS/Source/event_groups.cyclo ./Inc/RTOS/Source/event_groups.d ./Inc/RTOS/Source/event_groups.o ./Inc/RTOS/Source/event_groups.su ./Inc/RTOS/Source/list.cyclo ./Inc/RTOS/Source/list.d ./Inc/RTOS/Source/list.o ./Inc/RTOS/Source/list.su ./Inc/RTOS/Source/queue.cyclo ./Inc/RTOS/Source/queue.d ./Inc/RTOS/Source/queue.o ./Inc/RTOS/Source/queue.su ./Inc/RTOS/Source/stream_buffer.cyclo ./Inc/RTOS/Source/stream_buffer.d ./Inc/RTOS/Source/stream_buffer.o ./Inc/RTOS/Source/stream_buffer.su ./Inc/RTOS/Source/tasks.cyclo ./Inc/RTOS/Source/tasks.d ./Inc/RTOS/Source/tasks.o ./Inc/RTOS/Source/tasks.su ./Inc/RTOS/Source/timers.cyclo ./Inc/RTOS/Source/timers.d ./Inc/RTOS/Source/timers.o ./Inc/RTOS/Source/timers.su

.PHONY: clean-Inc-2f-RTOS-2f-Source

