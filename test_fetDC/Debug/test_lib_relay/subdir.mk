################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/BaoThuan/OneDrive\ -\ The\ University\ of\ Technology/Desktop/PROJECT/GIT_HUB/BKDN_TuThuoc/test_lib_relay/relay.c 

OBJS += \
./test_lib_relay/relay.o 

C_DEPS += \
./test_lib_relay/relay.d 


# Each subdirectory must supply rules for building sources it contributes
test_lib_relay/relay.o: C:/Users/BaoThuan/OneDrive\ -\ The\ University\ of\ Technology/Desktop/PROJECT/GIT_HUB/BKDN_TuThuoc/test_lib_relay/relay.c test_lib_relay/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/BaoThuan/OneDrive - The University of Technology/Desktop/PROJECT/GIT_HUB/BKDN_TuThuoc/test_lib_relay/0_include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-test_lib_relay

clean-test_lib_relay:
	-$(RM) ./test_lib_relay/relay.cyclo ./test_lib_relay/relay.d ./test_lib_relay/relay.o ./test_lib_relay/relay.su

.PHONY: clean-test_lib_relay

