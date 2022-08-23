################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/LCD_PrintingName/Printing_Program.c 

OBJS += \
./APP/LCD_PrintingName/Printing_Program.o 

C_DEPS += \
./APP/LCD_PrintingName/Printing_Program.d 


# Each subdirectory must supply rules for building sources it contributes
APP/LCD_PrintingName/%.o: ../APP/LCD_PrintingName/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


