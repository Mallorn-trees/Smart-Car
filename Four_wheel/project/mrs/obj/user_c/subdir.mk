################################################################################
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/MounriverProject/ss/camera1/project/user/src/isr.c \
D:/MounriverProject/ss/camera1/project/user/src/main.c 

OBJS += \
./user_c/isr.o \
./user_c/main.o 

C_DEPS += \
./user_c/isr.d \
./user_c/main.d 


# Each subdirectory must supply rules for building sources it contributes
user_c/isr.o: D:/MounriverProject/ss/camera1/project/user/src/isr.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"D:\MounriverProject\ss\camera1\Libraries\doc" -I"D:\MounriverProject\ss\camera1\libraries\sdk\Core" -I"D:\MounriverProject\ss\camera1\libraries\sdk\Ld" -I"D:\MounriverProject\ss\camera1\libraries\sdk\Peripheral" -I"D:\MounriverProject\ss\camera1\libraries\sdk\Startup" -I"D:\MounriverProject\ss\camera1\project\user\inc" -I"D:\MounriverProject\ss\camera1\libraries\zf_common" -I"D:\MounriverProject\ss\camera1\libraries\zf_device" -I"D:\MounriverProject\ss\camera1\project\code" -I"D:\MounriverProject\ss\camera1\libraries\zf_driver" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
user_c/main.o: D:/MounriverProject/ss/camera1/project/user/src/main.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"D:\MounriverProject\ss\camera1\Libraries\doc" -I"D:\MounriverProject\ss\camera1\libraries\sdk\Core" -I"D:\MounriverProject\ss\camera1\libraries\sdk\Ld" -I"D:\MounriverProject\ss\camera1\libraries\sdk\Peripheral" -I"D:\MounriverProject\ss\camera1\libraries\sdk\Startup" -I"D:\MounriverProject\ss\camera1\project\user\inc" -I"D:\MounriverProject\ss\camera1\libraries\zf_common" -I"D:\MounriverProject\ss\camera1\libraries\zf_device" -I"D:\MounriverProject\ss\camera1\project\code" -I"D:\MounriverProject\ss\camera1\libraries\zf_driver" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

