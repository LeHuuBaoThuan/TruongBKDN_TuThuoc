################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
<<<<<<< HEAD
C:/Users/BaoThuan/OneDrive\ -\ The\ University\ of\ Technology/Desktop/PROJECT/GIT_HUB/BKDN_TuThuoc/Driver_stm32/KeyPad.c \
C:/Users/BaoThuan/OneDrive\ -\ The\ University\ of\ Technology/Desktop/PROJECT/GIT_HUB/BKDN_TuThuoc/Driver_stm32/lcd_user.c 
=======
C:/Users/BaoThuan/OneDrive\ -\ The\ University\ of\ Technology/Desktop/PROJECT/GIT_HUB/BKDN_TuThuoc/Driver_stm32/KeyPad.c 
>>>>>>> parent of 10d839d (.)

OBJS += \
./Driver_stm32/KeyPad.o \
./Driver_stm32/lcd_user.o 

C_DEPS += \
./Driver_stm32/KeyPad.d \
./Driver_stm32/lcd_user.d 


# Each subdirectory must supply rules for building sources it contributes
Driver_stm32/KeyPad.o: C:/Users/BaoThuan/OneDrive\ -\ The\ University\ of\ Technology/Desktop/PROJECT/GIT_HUB/BKDN_TuThuoc/Driver_stm32/KeyPad.c Driver_stm32/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/BaoThuan/OneDrive - The University of Technology/Desktop/PROJECT/GIT_HUB/BKDN_TuThuoc/Driver_stm32/0_include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
<<<<<<< HEAD
Driver_stm32/lcd_user.o: C:/Users/BaoThuan/OneDrive\ -\ The\ University\ of\ Technology/Desktop/PROJECT/GIT_HUB/BKDN_TuThuoc/Driver_stm32/lcd_user.c Driver_stm32/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/BaoThuan/OneDrive - The University of Technology/Desktop/PROJECT/GIT_HUB/BKDN_TuThuoc/Driver_stm32/0_include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
=======
>>>>>>> parent of 10d839d (.)

clean: clean-Driver_stm32

clean-Driver_stm32:
	-$(RM) ./Driver_stm32/KeyPad.cyclo ./Driver_stm32/KeyPad.d ./Driver_stm32/KeyPad.o ./Driver_stm32/KeyPad.su ./Driver_stm32/lcd_user.cyclo ./Driver_stm32/lcd_user.d ./Driver_stm32/lcd_user.o ./Driver_stm32/lcd_user.su

.PHONY: clean-Driver_stm32
