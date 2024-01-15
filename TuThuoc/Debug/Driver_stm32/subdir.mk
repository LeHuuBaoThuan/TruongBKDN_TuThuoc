################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
E:/STM32/tuthuoc/Driver_stm32/KeyPad.c 

OBJS += \
./Driver_stm32/KeyPad.o 

C_DEPS += \
./Driver_stm32/KeyPad.d 


# Each subdirectory must supply rules for building sources it contributes
Driver_stm32/KeyPad.o: E:/STM32/tuthuoc/Driver_stm32/KeyPad.c Driver_stm32/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/BaoThuan/OneDrive - The University of Technology/Desktop/PROJECT/GIT_HUB/BKDN_TuThuoc/Driver_stm32/0_include" -I"E:/STM32/tuthuoc/Driver_stm32/0_include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Driver_stm32

clean-Driver_stm32:
	-$(RM) ./Driver_stm32/KeyPad.cyclo ./Driver_stm32/KeyPad.d ./Driver_stm32/KeyPad.o ./Driver_stm32/KeyPad.su

.PHONY: clean-Driver_stm32

