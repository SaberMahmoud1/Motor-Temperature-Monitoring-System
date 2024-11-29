################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCU1.c \
../adc.c \
../dc_motor.c \
../gpio.c \
../internal_eeprom.c \
../lm35_sensor.c \
../timer1_compare_normal.c \
../timer_pwm.c \
../uart.c \
../watch_dog.c 

OBJS += \
./MCU1.o \
./adc.o \
./dc_motor.o \
./gpio.o \
./internal_eeprom.o \
./lm35_sensor.o \
./timer1_compare_normal.o \
./timer_pwm.o \
./uart.o \
./watch_dog.o 

C_DEPS += \
./MCU1.d \
./adc.d \
./dc_motor.d \
./gpio.d \
./internal_eeprom.d \
./lm35_sensor.d \
./timer1_compare_normal.d \
./timer_pwm.d \
./uart.d \
./watch_dog.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


