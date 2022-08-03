################################################################################
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/MounriverProject/ss/camera1/project/code/picture_process.c \
D:/MounriverProject/ss/camera1/project/code/process_auxiliary.c \
D:/MounriverProject/ss/camera1/project/code/servo.c 

OBJS += \
./code/picture_process.o \
./code/process_auxiliary.o \
./code/servo.o 

C_DEPS += \
./code/picture_process.d \
./code/process_auxiliary.d \
./code/servo.d 


# Each subdirectory must supply rules for building sources it contributes
code/picture_process.o: D:/MounriverProject/ss/camera1/project/code/picture_process.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"D:\MounriverProject\ss\camera1\Libraries\doc" -I"D:\MounriverProject\ss\camera1\libraries\sdk\Core" -I"D:\MounriverProject\ss\camera1\libraries\sdk\Ld" -I"D:\MounriverProject\ss\camera1\libraries\sdk\Peripheral" -I"D:\MounriverProject\ss\camera1\libraries\sdk\Startup" -I"D:\MounriverProject\ss\camera1\project\user\inc" -I"D:\MounriverProject\ss\camera1\libraries\zf_common" -I"D:\MounriverProject\ss\camera1\libraries\zf_device" -I"D:\MounriverProject\ss\camera1\project\code" -I"D:\MounriverProject\ss\camera1\libraries\zf_driver" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/process_auxiliary.o: D:/MounriverProject/ss/camera1/project/code/process_auxiliary.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"D:\MounriverProject\ss\camera1\Libraries\doc" -I"D:\MounriverProject\ss\camera1\libraries\sdk\Core" -I"D:\MounriverProject\ss\camera1\libraries\sdk\Ld" -I"D:\MounriverProject\ss\camera1\libraries\sdk\Peripheral" -I"D:\MounriverProject\ss\camera1\libraries\sdk\Startup" -I"D:\MounriverProject\ss\camera1\project\user\inc" -I"D:\MounriverProject\ss\camera1\libraries\zf_common" -I"D:\MounriverProject\ss\camera1\libraries\zf_device" -I"D:\MounriverProject\ss\camera1\project\code" -I"D:\MounriverProject\ss\camera1\libraries\zf_driver" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/servo.o: D:/MounriverProject/ss/camera1/project/code/servo.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"D:\MounriverProject\ss\camera1\Libraries\doc" -I"D:\MounriverProject\ss\camera1\libraries\sdk\Core" -I"D:\MounriverProject\ss\camera1\libraries\sdk\Ld" -I"D:\MounriverProject\ss\camera1\libraries\sdk\Peripheral" -I"D:\MounriverProject\ss\camera1\libraries\sdk\Startup" -I"D:\MounriverProject\ss\camera1\project\user\inc" -I"D:\MounriverProject\ss\camera1\libraries\zf_common" -I"D:\MounriverProject\ss\camera1\libraries\zf_device" -I"D:\MounriverProject\ss\camera1\project\code" -I"D:\MounriverProject\ss\camera1\libraries\zf_driver" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

