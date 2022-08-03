################################################################################
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/MounriverProject/ss/camera1/libraries/sdk/Startup/system_ch32v30x.c 

S_UPPER_SRCS += \
D:/MounriverProject/ss/camera1/libraries/sdk/Startup/startup_ch32v30x.S 

OBJS += \
./sdk/Startup/startup_ch32v30x.o \
./sdk/Startup/system_ch32v30x.o 

S_UPPER_DEPS += \
./sdk/Startup/startup_ch32v30x.d 

C_DEPS += \
./sdk/Startup/system_ch32v30x.d 


# Each subdirectory must supply rules for building sources it contributes
sdk/Startup/startup_ch32v30x.o: D:/MounriverProject/ss/camera1/libraries/sdk/Startup/startup_ch32v30x.S
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -x assembler -I"D:\MounriverProject\ss\camera1\libraries\sdk\Startup" -I"D:\MounriverProject\ss\camera1\libraries\zf_driver" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
sdk/Startup/system_ch32v30x.o: D:/MounriverProject/ss/camera1/libraries/sdk/Startup/system_ch32v30x.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"D:\MounriverProject\ss\camera1\Libraries\doc" -I"D:\MounriverProject\ss\camera1\libraries\sdk\Core" -I"D:\MounriverProject\ss\camera1\libraries\sdk\Ld" -I"D:\MounriverProject\ss\camera1\libraries\sdk\Peripheral" -I"D:\MounriverProject\ss\camera1\libraries\sdk\Startup" -I"D:\MounriverProject\ss\camera1\project\user\inc" -I"D:\MounriverProject\ss\camera1\libraries\zf_common" -I"D:\MounriverProject\ss\camera1\libraries\zf_device" -I"D:\MounriverProject\ss\camera1\project\code" -I"D:\MounriverProject\ss\camera1\libraries\zf_driver" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

