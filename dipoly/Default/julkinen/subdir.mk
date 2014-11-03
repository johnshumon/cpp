################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../julkinen/boarddrawer.cc \
../julkinen/chopper.cc \
../julkinen/die.cc \
../julkinen/initreader.cc \
../julkinen/utility.cc 

OBJS += \
./julkinen/boarddrawer.o \
./julkinen/chopper.o \
./julkinen/die.o \
./julkinen/initreader.o \
./julkinen/utility.o 

CC_DEPS += \
./julkinen/boarddrawer.d \
./julkinen/chopper.d \
./julkinen/die.d \
./julkinen/initreader.d \
./julkinen/utility.d 


# Each subdirectory must supply rules for building sources it contributes
julkinen/%.o: ../julkinen/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


