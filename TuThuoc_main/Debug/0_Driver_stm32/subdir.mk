################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/BaoThuan/OneDrive\ -\ The\ University\ of\ Technology/Desktop/PROJECT/GIT_HUB/BKDN_TuThuoc/0_Driver_stm32/i2c-lcd.c 

OBJS += \
./0_Driver_stm32/i2c-lcd.o 

C_DEPS += \
./0_Driver_stm32/i2c-lcd.d 


# Each subdirectory must supply rules for building sources it contributes
0_Driver_stm32/i2c-lcd.o: C:/Users/BaoThuan/OneDrive\ -\ The\ University\ of\ Technology/Desktop/PROJECT/GIT_HUB/BKDN_TuThuoc/0_Driver_stm32/i2c-lcd.c 0_Driver_stm32/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/BaoThuan/OneDrive - The University of Technology/Desktop/PROJECT/GIT_HUB/BKDN_TuThuoc/1_Application_stm32/include" -I"C:/Users/BaoThuan/OneDrive - The University of Technology/Desktop/PROJECT/GIT_HUB/BKDN_TuThuoc/0_Driver_stm32/0_include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-0_Driver_stm32

clean-0_Driver_stm32:
	-$(RM) ./0_Driver_stm32/i2c-lcd.cyclo ./0_Driver_stm32/i2c-lcd.d ./0_Driver_stm32/i2c-lcd.o ./0_Driver_stm32/i2c-lcd.su

.PHONY: clean-0_Driver_stm32

