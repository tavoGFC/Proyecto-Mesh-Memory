################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/API/HelloWorld.cpp \
../src/API/MeshMemAPI.cpp \
../src/API/Token.cpp \
../src/API/xReference.cpp 

OBJS += \
./src/API/HelloWorld.o \
./src/API/MeshMemAPI.o \
./src/API/Token.o \
./src/API/xReference.o 

CPP_DEPS += \
./src/API/HelloWorld.d \
./src/API/MeshMemAPI.d \
./src/API/Token.d \
./src/API/xReference.d 


# Each subdirectory must supply rules for building sources it contributes
src/API/%.o: ../src/API/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


