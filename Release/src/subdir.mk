################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/ImagineCore.cpp \
../src/MainMenu.cpp \
../src/Menu.cpp \
../src/Scene.cpp \
../src/SceneController.cpp \
../src/main.cpp 

OBJS += \
./src/ImagineCore.o \
./src/MainMenu.o \
./src/Menu.o \
./src/Scene.o \
./src/SceneController.o \
./src/main.o 

CPP_DEPS += \
./src/ImagineCore.d \
./src/MainMenu.d \
./src/Menu.d \
./src/Scene.d \
./src/SceneController.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++1y -O3 -Wall -c -fmessage-length=0 -fpermissive -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


