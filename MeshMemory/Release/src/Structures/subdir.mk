################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Structures/DoublyLinkedList.cpp \
../src/Structures/SinglyLinkedList.cpp 

OBJS += \
./src/Structures/DoublyLinkedList.o \
./src/Structures/SinglyLinkedList.o 

CPP_DEPS += \
./src/Structures/DoublyLinkedList.d \
./src/Structures/SinglyLinkedList.d 


# Each subdirectory must supply rules for building sources it contributes
src/Structures/%.o: ../src/Structures/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


