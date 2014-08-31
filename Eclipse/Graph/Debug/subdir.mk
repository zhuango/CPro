################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../ShortPathUnweighted.cpp \
../ShortPathWeighted.cpp \
../graph.cpp 

OBJS += \
./ShortPathUnweighted.o \
./ShortPathWeighted.o \
./graph.o 

CPP_DEPS += \
./ShortPathUnweighted.d \
./ShortPathWeighted.d \
./graph.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


