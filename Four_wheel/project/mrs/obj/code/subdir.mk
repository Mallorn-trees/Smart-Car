################################################################################
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/MounriverProject/Smart-Car/Four_wheel/project/code/picture_process.c \
D:/MounriverProject/Smart-Car/Four_wheel/project/code/process_auxiliary.c \
D:/MounriverProject/Smart-Car/Four_wheel/project/code/servo.c 

OBJS += \
./code/picture_process.o \
./code/process_auxiliary.o \
./code/servo.o 

C_DEPS += \
./code/picture_process.d \
./code/process_auxiliary.d \
./code/servo.d 


# Each subdirectory must supply rules for building sources it contributes
code/picture_process.o: D:/MounriverProject/Smart-Car/Four_wheel/project/code/picture_process.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"D:\MounriverProject\Smart-Car\Four_wheel\Libraries\doc" -I"D:\MounriverProject\Smart-Car\Four_wheel\libraries\sdk\Core" -I"D:\MounriverProject\Smart-Car\Four_wheel\libraries\sdk\Ld" -I"D:\MounriverProject\Smart-Car\Four_wheel\libraries\sdk\Peripheral" -I"D:\MounriverProject\Smart-Car\Four_wheel\libraries\sdk\Startup" -I"D:\MounriverProject\Smart-Car\Four_wheel\project\user\inc" -I"D:\MounriverProject\Smart-Car\Four_wheel\libraries\zf_common" -I"D:\MounriverProject\Smart-Car\Four_wheel\libraries\zf_device" -I"D:\MounriverProject\Smart-Car\Four_wheel\project\code" -I"D:\MounriverProject\Smart-Car\Four_wheel\libraries\zf_driver" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/process_auxiliary.o: D:/MounriverProject/Smart-Car/Four_wheel/project/code/process_auxiliary.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"D:\MounriverProject\Smart-Car\Four_wheel\Libraries\doc" -I"D:\MounriverProject\Smart-Car\Four_wheel\libraries\sdk\Core" -I"D:\MounriverProject\Smart-Car\Four_wheel\libraries\sdk\Ld" -I"D:\MounriverProject\Smart-Car\Four_wheel\libraries\sdk\Peripheral" -I"D:\MounriverProject\Smart-Car\Four_wheel\libraries\sdk\Startup" -I"D:\MounriverProject\Smart-Car\Four_wheel\project\user\inc" -I"D:\MounriverProject\Smart-Car\Four_wheel\libraries\zf_common" -I"D:\MounriverProject\Smart-Car\Four_wheel\libraries\zf_device" -I"D:\MounriverProject\Smart-Car\Four_wheel\project\code" -I"D:\MounriverProject\Smart-Car\Four_wheel\libraries\zf_driver" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/servo.o: D:/MounriverProject/Smart-Car/Four_wheel/project/code/servo.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"D:\MounriverProject\Smart-Car\Four_wheel\Libraries\doc" -I"D:\MounriverProject\Smart-Car\Four_wheel\libraries\sdk\Core" -I"D:\MounriverProject\Smart-Car\Four_wheel\libraries\sdk\Ld" -I"D:\MounriverProject\Smart-Car\Four_wheel\libraries\sdk\Peripheral" -I"D:\MounriverProject\Smart-Car\Four_wheel\libraries\sdk\Startup" -I"D:\MounriverProject\Smart-Car\Four_wheel\project\user\inc" -I"D:\MounriverProject\Smart-Car\Four_wheel\libraries\zf_common" -I"D:\MounriverProject\Smart-Car\Four_wheel\libraries\zf_device" -I"D:\MounriverProject\Smart-Car\Four_wheel\project\code" -I"D:\MounriverProject\Smart-Car\Four_wheel\libraries\zf_driver" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

