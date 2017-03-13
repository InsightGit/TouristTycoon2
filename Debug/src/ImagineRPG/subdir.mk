################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/ImagineRPG/MessageBox.cpp 

OBJS += \
./src/ImagineRPG/MessageBox.o 

CPP_DEPS += \
./src/ImagineRPG/MessageBox.d 


# Each subdirectory must supply rules for building sources it contributes
src/ImagineRPG/MessageBox.o: /home/newbobby/workspace/Project\ Zoing/src/ImagineRPG/MessageBox.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++1z -D_DEBUG -O0 -g3 -Wall -c -fmessage-length=0 -fpermissive -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


