################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../TIMER_DRIVER/timer0_pwm.c \
../TIMER_DRIVER/timer_1.c 

OBJS += \
./TIMER_DRIVER/timer0_pwm.o \
./TIMER_DRIVER/timer_1.o 

C_DEPS += \
./TIMER_DRIVER/timer0_pwm.d \
./TIMER_DRIVER/timer_1.d 


# Each subdirectory must supply rules for building sources it contributes
TIMER_DRIVER/%.o: ../TIMER_DRIVER/%.c TIMER_DRIVER/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


