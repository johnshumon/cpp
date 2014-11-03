################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../createplayer.cc \
../dipoly.cc \
../game.cc \
../player.cc \
../playerlist.cc \
../square.cc \
../squarelist.cc 

OBJS += \
./createplayer.o \
./dipoly.o \
./game.o \
./player.o \
./playerlist.o \
./square.o \
./squarelist.o 

CC_DEPS += \
./createplayer.d \
./dipoly.d \
./game.d \
./player.d \
./playerlist.d \
./square.d \
./squarelist.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


