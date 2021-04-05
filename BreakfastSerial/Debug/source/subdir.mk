################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/UART.c \
../source/cbfifo.c \
../source/cmd_proc.c \
../source/fifo_test.c \
../source/main.c \
../source/mtb.c \
../source/semihost_hardfault.c \
../source/sysclock.c 

OBJS += \
./source/UART.o \
./source/cbfifo.o \
./source/cmd_proc.o \
./source/fifo_test.o \
./source/main.o \
./source/mtb.o \
./source/semihost_hardfault.o \
./source/sysclock.o 

C_DEPS += \
./source/UART.d \
./source/cbfifo.d \
./source/cmd_proc.d \
./source/fifo_test.d \
./source/main.d \
./source/mtb.d \
./source/semihost_hardfault.d \
./source/sysclock.d 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DCPU_MKL25Z128VLK4 -DCPU_MKL25Z128VLK4_cm0plus -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=1 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -D__REDLIB__ -DSDK_DEBUGCONSOLE=0 -I"C:\CU_Files\MCUXpressoIDE_11.2.1_4149\workspace\BreakfastSerial\source" -I"C:\CU_Files\MCUXpressoIDE_11.2.1_4149\workspace\BreakfastSerial" -I"C:\CU_Files\MCUXpressoIDE_11.2.1_4149\workspace\BreakfastSerial\startup" -I"C:\CU_Files\MCUXpressoIDE_11.2.1_4149\workspace\BreakfastSerial\CMSIS" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


