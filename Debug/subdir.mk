################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC.c \
../App.c \
../Buzzer.c \
../Flame.c \
../LCD.c \
../LDR.c \
../LED.c \
../LM35.c \
../Motor.c \
../PWM.c \
../gpio.c \
../interface.c 

OBJS += \
./ADC.o \
./App.o \
./Buzzer.o \
./Flame.o \
./LCD.o \
./LDR.o \
./LED.o \
./LM35.o \
./Motor.o \
./PWM.o \
./gpio.o \
./interface.o 

C_DEPS += \
./ADC.d \
./App.d \
./Buzzer.d \
./Flame.d \
./LCD.d \
./LDR.d \
./LED.d \
./LM35.d \
./Motor.d \
./PWM.d \
./gpio.d \
./interface.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


