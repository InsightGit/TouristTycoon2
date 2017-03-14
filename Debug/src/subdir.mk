################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/ClickableSprite.cpp \
../src/ImagineCore.cpp \
../src/ImagineSaveGame.cpp \
../src/Main.cpp \
../src/MainMenu.cpp \
../src/Menu.cpp \
../src/Scene.cpp \
../src/SceneController.cpp \
../src/SceneMusicPlayer.cpp \
../src/l3DRM.cpp 

OBJS += \
./src/ClickableSprite.o \
./src/ImagineCore.o \
./src/ImagineSaveGame.o \
./src/Main.o \
./src/MainMenu.o \
./src/Menu.o \
./src/Scene.o \
./src/SceneController.o \
./src/SceneMusicPlayer.o \
./src/l3DRM.o 

CPP_DEPS += \
./src/ClickableSprite.d \
./src/ImagineCore.d \
./src/ImagineSaveGame.d \
./src/Main.d \
./src/MainMenu.d \
./src/Menu.d \
./src/Scene.d \
./src/SceneController.d \
./src/SceneMusicPlayer.d \
./src/l3DRM.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++14 -O0 -g3 -Wall -c -fmessage-length=0 -fpermissive -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


