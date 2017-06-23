################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Lib/bios_gpio.c" \
"../Lib/bios_systick.c" \

C_SRCS += \
../Lib/bios_gpio.c \
../Lib/bios_systick.c \

OBJS += \
./Lib/bios_gpio.o \
./Lib/bios_systick.o \

OBJS_QUOTED += \
"./Lib/bios_gpio.o" \
"./Lib/bios_systick.o" \

C_DEPS += \
./Lib/bios_gpio.d \
./Lib/bios_systick.d \

C_DEPS_QUOTED += \
"./Lib/bios_gpio.d" \
"./Lib/bios_systick.d" \

OBJS_OS_FORMAT += \
./Lib/bios_gpio.o \
./Lib/bios_systick.o \


# Each subdirectory must supply rules for building sources it contributes
Lib/bios_gpio.o: ../Lib/bios_gpio.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C++ Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-g++" "$<" @"Lib/bios_gpio.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Lib/bios_gpio.o"
	@echo 'Finished building: $<'
	@echo ' '

Lib/bios_systick.o: ../Lib/bios_systick.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C++ Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-g++" "$<" @"Lib/bios_systick.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Lib/bios_systick.o"
	@echo 'Finished building: $<'
	@echo ' '


