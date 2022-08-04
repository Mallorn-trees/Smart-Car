################################################################################
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/86157/Desktop/Smart-Car-Four_wheel/Four_wheel/libraries/sdk/Startup/system_ch32v30x.c 

S_UPPER_SRCS += \
C:/Users/86157/Desktop/Smart-Car-Four_wheel/Four_wheel/libraries/sdk/Startup/startup_ch32v30x.S 

OBJS += \
./sdk/Startup/startup_ch32v30x.o \
./sdk/Startup/system_ch32v30x.o 

S_UPPER_DEPS += \
./sdk/Startup/startup_ch32v30x.d 

C_DEPS += \
./sdk/Startup/system_ch32v30x.d 


# Each subdirectory must supply rules for building sources it contributes
sdk/Startup/startup_ch32v30x.o: C:/Users/86157/Desktop/Smart-Car-Four_wheel/Four_wheel/libraries/sdk/Startup/startup_ch32v30x.S
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -x assembler -I"C:\Users\86157\Desktop\Smart-Car-Four_wheel\Four_wheel\libraries\sdk\Startup" -I"C:\Users\86157\Desktop\Smart-Car-Four_wheel\Four_wheel\libraries\zf_driver" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
sdk/Startup/system_ch32v30x.o: C:/Users/86157/Desktop/Smart-Car-Four_wheel/Four_wheel/libraries/sdk/Startup/system_ch32v30x.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"C:\Users\86157\Desktop\Smart-Car-Four_wheel\Four_wheel\Libraries\doc" -I"C:\Users\86157\Desktop\Smart-Car-Four_wheel\Four_wheel\libraries\sdk\Core" -I"C:\Users\86157\Desktop\Smart-Car-Four_wheel\Four_wheel\libraries\sdk\Ld" -I"C:\Users\86157\Desktop\Smart-Car-Four_wheel\Four_wheel\libraries\sdk\Peripheral" -I"C:\Users\86157\Desktop\Smart-Car-Four_wheel\Four_wheel\libraries\sdk\Startup" -I"C:\Users\86157\Desktop\Smart-Car-Four_wheel\Four_wheel\project\user\inc" -I"C:\Users\86157\Desktop\Smart-Car-Four_wheel\Four_wheel\libraries\zf_common" -I"C:\Users\86157\Desktop\Smart-Car-Four_wheel\Four_wheel\libraries\zf_device" -I"C:\Users\86157\Desktop\Smart-Car-Four_wheel\Four_wheel\project\code" -I"C:\Users\86157\Desktop\Smart-Car-Four_wheel\Four_wheel\libraries\zf_driver" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

