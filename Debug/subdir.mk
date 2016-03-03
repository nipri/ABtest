################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../AB2016.c \
../ArrowPatterns.c \
../client.c \
../displayPatterns.c \
../gpio.c \
../serial.c \
../spi.c 

OBJS += \
./AB2016.o \
./ArrowPatterns.o \
./client.o \
./displayPatterns.o \
./gpio.o \
./serial.o \
./spi.o 

C_DEPS += \
./AB2016.d \
./ArrowPatterns.d \
./client.d \
./displayPatterns.d \
./gpio.d \
./serial.d \
./spi.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	/usr/bin/arm-linux-gnueabi-gcc -I/usr/include -O0 -g3 -Wall -c -fmessage-length=0 -pthread -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


