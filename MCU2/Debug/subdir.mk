################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCU2.c \
../Timer1_Fast_PWM.c \
../adc.c \
../buzzer.c \
../dc_motor.c \
../gpio.c \
../leds.c \
../timer2_fast_PWM.c \
../timer_pwm.c \
../uart.c 

OBJS += \
./MCU2.o \
./Timer1_Fast_PWM.o \
./adc.o \
./buzzer.o \
./dc_motor.o \
./gpio.o \
./leds.o \
./timer2_fast_PWM.o \
./timer_pwm.o \
./uart.o 

C_DEPS += \
./MCU2.d \
./Timer1_Fast_PWM.d \
./adc.d \
./buzzer.d \
./dc_motor.d \
./gpio.d \
./leds.d \
./timer2_fast_PWM.d \
./timer_pwm.d \
./uart.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


