################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/BaoThuan/OneDrive\ -\ The\ University\ of\ Technology/Desktop/PROJECT/GIT_HUB/BKDN_TuThuoc/1_Application_stm32/KeyPad.c \
C:/Users/BaoThuan/OneDrive\ -\ The\ University\ of\ Technology/Desktop/PROJECT/GIT_HUB/BKDN_TuThuoc/1_Application_stm32/fet_74hc595.c \
C:/Users/BaoThuan/OneDrive\ -\ The\ University\ of\ Technology/Desktop/PROJECT/GIT_HUB/BKDN_TuThuoc/1_Application_stm32/handler_keyIN.c \
C:/Users/BaoThuan/OneDrive\ -\ The\ University\ of\ Technology/Desktop/PROJECT/GIT_HUB/BKDN_TuThuoc/1_Application_stm32/lcd_user.c \
C:/Users/BaoThuan/OneDrive\ -\ The\ University\ of\ Technology/Desktop/PROJECT/GIT_HUB/BKDN_TuThuoc/1_Application_stm32/uart_user.c 

OBJS += \
./1_Application_stm32/KeyPad.o \
./1_Application_stm32/fet_74hc595.o \
./1_Application_stm32/handler_keyIN.o \
./1_Application_stm32/lcd_user.o \
./1_Application_stm32/uart_user.o 

C_DEPS += \
./1_Application_stm32/KeyPad.d \
./1_Application_stm32/fet_74hc595.d \
./1_Application_stm32/handler_keyIN.d \
./1_Application_stm32/lcd_user.d \
./1_Application_stm32/uart_user.d 


# Each subdirectory must supply rules for building sources it contributes
1_Application_stm32/KeyPad.o: C:/Users/BaoThuan/OneDrive\ -\ The\ University\ of\ Technology/Desktop/PROJECT/GIT_HUB/BKDN_TuThuoc/1_Application_stm32/KeyPad.c 1_Application_stm32/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/BaoThuan/OneDrive - The University of Technology/Desktop/PROJECT/GIT_HUB/BKDN_TuThuoc/1_Application_stm32/include" -I"C:/Users/BaoThuan/OneDrive - The University of Technology/Desktop/PROJECT/GIT_HUB/BKDN_TuThuoc/0_Driver_stm32/0_include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
1_Application_stm32/fet_74hc595.o: C:/Users/BaoThuan/OneDrive\ -\ The\ University\ of\ Technology/Desktop/PROJECT/GIT_HUB/BKDN_TuThuoc/1_Application_stm32/fet_74hc595.c 1_Application_stm32/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/BaoThuan/OneDrive - The University of Technology/Desktop/PROJECT/GIT_HUB/BKDN_TuThuoc/1_Application_stm32/include" -I"C:/Users/BaoThuan/OneDrive - The University of Technology/Desktop/PROJECT/GIT_HUB/BKDN_TuThuoc/0_Driver_stm32/0_include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
1_Application_stm32/handler_keyIN.o: C:/Users/BaoThuan/OneDrive\ -\ The\ University\ of\ Technology/Desktop/PROJECT/GIT_HUB/BKDN_TuThuoc/1_Application_stm32/handler_keyIN.c 1_Application_stm32/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/BaoThuan/OneDrive - The University of Technology/Desktop/PROJECT/GIT_HUB/BKDN_TuThuoc/1_Application_stm32/include" -I"C:/Users/BaoThuan/OneDrive - The University of Technology/Desktop/PROJECT/GIT_HUB/BKDN_TuThuoc/0_Driver_stm32/0_include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
1_Application_stm32/lcd_user.o: C:/Users/BaoThuan/OneDrive\ -\ The\ University\ of\ Technology/Desktop/PROJECT/GIT_HUB/BKDN_TuThuoc/1_Application_stm32/lcd_user.c 1_Application_stm32/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/BaoThuan/OneDrive - The University of Technology/Desktop/PROJECT/GIT_HUB/BKDN_TuThuoc/1_Application_stm32/include" -I"C:/Users/BaoThuan/OneDrive - The University of Technology/Desktop/PROJECT/GIT_HUB/BKDN_TuThuoc/0_Driver_stm32/0_include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
1_Application_stm32/uart_user.o: C:/Users/BaoThuan/OneDrive\ -\ The\ University\ of\ Technology/Desktop/PROJECT/GIT_HUB/BKDN_TuThuoc/1_Application_stm32/uart_user.c 1_Application_stm32/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/BaoThuan/OneDrive - The University of Technology/Desktop/PROJECT/GIT_HUB/BKDN_TuThuoc/1_Application_stm32/include" -I"C:/Users/BaoThuan/OneDrive - The University of Technology/Desktop/PROJECT/GIT_HUB/BKDN_TuThuoc/0_Driver_stm32/0_include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-1_Application_stm32

clean-1_Application_stm32:
	-$(RM) ./1_Application_stm32/KeyPad.cyclo ./1_Application_stm32/KeyPad.d ./1_Application_stm32/KeyPad.o ./1_Application_stm32/KeyPad.su ./1_Application_stm32/fet_74hc595.cyclo ./1_Application_stm32/fet_74hc595.d ./1_Application_stm32/fet_74hc595.o ./1_Application_stm32/fet_74hc595.su ./1_Application_stm32/handler_keyIN.cyclo ./1_Application_stm32/handler_keyIN.d ./1_Application_stm32/handler_keyIN.o ./1_Application_stm32/handler_keyIN.su ./1_Application_stm32/lcd_user.cyclo ./1_Application_stm32/lcd_user.d ./1_Application_stm32/lcd_user.o ./1_Application_stm32/lcd_user.su ./1_Application_stm32/uart_user.cyclo ./1_Application_stm32/uart_user.d ./1_Application_stm32/uart_user.o ./1_Application_stm32/uart_user.su

.PHONY: clean-1_Application_stm32

