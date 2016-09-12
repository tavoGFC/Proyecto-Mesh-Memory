################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Client-Server/Client.cpp \
../src/Client-Server/Server.cpp 

OBJS += \
./src/Client-Server/Client.o \
./src/Client-Server/Server.o 

CPP_DEPS += \
./src/Client-Server/Client.d \
./src/Client-Server/Server.d 


# Each subdirectory must supply rules for building sources it contributes
src/Client-Server/%.o: ../src/Client-Server/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


