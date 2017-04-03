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
src/ImagineRPG/%.o: ../src/ImagineRPG/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -std=c++14 -fpermissive -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


