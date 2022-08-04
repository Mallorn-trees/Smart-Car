################################################################################
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/86157/Desktop/Smart-Car-Four_wheel/Four_wheel/project/code/my_imagetransfer.c \
C:/Users/86157/Desktop/Smart-Car-Four_wheel/Four_wheel/project/code/my_sd_card.c \
C:/Users/86157/Desktop/Smart-Car-Four_wheel/Four_wheel/project/code/picture_process.c \
C:/Users/86157/Desktop/Smart-Car-Four_wheel/Four_wheel/project/code/process_auxiliary.c \
C:/Users/86157/Desktop/Smart-Car-Four_wheel/Four_wheel/project/code/servo.c 

OBJS += \
./code/my_imagetransfer.o \
./code/my_sd_card.o \
./code/picture_process.o \
./code/process_auxiliary.o \
./code/servo.o 

C_DEPS += \
./code/my_imagetransfer.d \
./code/my_sd_card.d \
./code/picture_process.d \
./code/process_auxiliary.d \
./code/servo.d 


# Each subdirectory must supply rules for building sources it contributes
code/my_imagetransfer.o: C:/Users/86157/Desktop/Smart-Car-Four_wheel/Four_wheel/project/code/my_imagetransfer.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"C:\Users\86157\Desktop\Smart-Car-Four_wheel\Four_wheel\Libraries\doc" -I"C:\Users\86157\Desktop\Smart-Car-Four_wheel\Four_wheel\libraries\sdk\Core" -I"C:\Users\86157\Desktop\Smart-Car-Four_wheel\Four_wheel\libraries\sdk\Ld" -I"C:\Users\86157\Desktop\Smart-Car-Four_wheel\Four_wheel\libraries\sdk\Peripheral" -I"C:\Users\86157\Desktop\Smart-Car-Four_wheel\Four_wheel\libraries\sdk\Startup" -I"C:\Users\86157\Desktop\Smart-Car-Four_wheel\Four_wheel\project\user\inc" -I"C:\Users\86157\Desktop\Smart-Car-Four_wheel\Four_wheel\libraries\zf_common" -I"C:\Users\86157\Desktop\Smart-Car-Four_wheel\Four_wheel\libraries\zf_device" -I"C:\Users\86157\Desktop\Smart-Car-Four_wheel\Four_wheel\project\code" -I"C:\Users\86157\Desktop\Smart-Car-Four_wheel\Four_wheel\libraries\zf_driver" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/my_sd_card.o: C:/Users/86157/Desktop/Smart-Car-Four_wheel/Four_wheel/project/code/my_sd_card.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"C:\Users\86157\Desktop\Smart-Car-Four_wheel\Four_wheel\Libraries\doc" -I"C:\Users\86157\Desktop\Smart-Car-Four_wheel\Four_wheel\libraries\sdk\Core" -I"C:\Users\86157\Desktop\Smart-Car-Four_wheel\Four_wheel\libraries\sdk\Ld" -I"C:\Users\86157\Desktop\Smart-Car-Four_wheel\Four_wheel\libraries\sdk\Peripheral" -I"C:\Users\86157\Desktop\Smart-Car-Four_wheel\Four_wheel\libraries\sdk\Startup" -I"C:\Users\86157\Desktop\Smart-Car-Four_wheel\Four_wheel\project\user\inc" -I"C:\Users\86157\Desktop\Smart-Car-Four_wheel\Four_wheel\libraries\zf_common" -I"C:\Users\86157\Desktop\Smart-Car-Four_wheel\Four_wheel\libraries\zf_device" -I"C:\Users\86157\Desktop\Smart-Car-Four_wheel\Four_wheel\project\code" -I"C:\Users\86157\Desktop\Smart-Car-Four_wheel\Four_wheel\libraries\zf_driver" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/picture_process.o: C:/Users/86157/Desktop/Smart-Car-Four_wheel/Four_wheel/project/code/picture_process.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"C:\Users\86157\Desktop\Smart-Car-Four_wheel\Four_wheel\Libraries\doc" -I"C:\Users\86157\Desktop\Smart-Car-Four_wheel\Four_wheel\libraries\sdk\Core" -I"C:\Users\86157\Desktop\Smart-Car-Four_wheel\Four_wheel\libraries\sdk\Ld" -I"C:\Users\86157\Desktop\Smart-Car-Four_wheel\Four_wheel\libraries\sdk\Peripheral" -I"C:\Users\86157\Desktop\Smart-Car-Four_wheel\Four_wheel\libraries\sdk\Startup" -I"C:\Users\86157\Desktop\Smart-Car-Four_wheel\Four_wheel\project\user\inc" -I"C:\Users\86157\Desktop\Smart-Car-Four_wheel\Four_wheel\libraries\zf_common" -I"C:\Users\86157\Desktop\Smart-Car-Four_wheel\Four_wheel\libraries\zf_device" -I"C:\Users\86157\Desktop\Smart-Car-Four_wheel\Four_wheel\project\code" -I"C:\Users\86157\Desktop\Smart-Car-Four_wheel\Four_wheel\libraries\zf_driver" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/process_auxiliary.o: C:/Users/86157/Desktop/Smart-Car-Four_wheel/Four_wheel/project/code/process_auxiliary.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"C:\Users\86157\Desktop\Smart-Car-Four_wheel\Four_wheel\Libraries\doc" -I"C:\Users\86157\Desktop\Smart-Car-Four_wheel\Four_wheel\libraries\sdk\Core" -I"C:\Users\86157\Desktop\Smart-Car-Four_wheel\Four_wheel\libraries\sdk\Ld" -I"C:\Users\86157\Desktop\Smart-Car-Four_wheel\Four_wheel\libraries\sdk\Peripheral" -I"C:\Users\86157\Desktop\Smart-Car-Four_wheel\Four_wheel\libraries\sdk\Startup" -I"C:\Users\86157\Desktop\Smart-Car-Four_wheel\Four_wheel\project\user\inc" -I"C:\Users\86157\Desktop\Smart-Car-Four_wheel\Four_wheel\libraries\zf_common" -I"C:\Users\86157\Desktop\Smart-Car-Four_wheel\Four_wheel\libraries\zf_device" -I"C:\Users\86157\Desktop\Smart-Car-Four_wheel\Four_wheel\project\code" -I"C:\Users\86157\Desktop\Smart-Car-Four_wheel\Four_wheel\libraries\zf_driver" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/servo.o: C:/Users/86157/Desktop/Smart-Car-Four_wheel/Four_wheel/project/code/servo.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"C:\Users\86157\Desktop\Smart-Car-Four_wheel\Four_wheel\Libraries\doc" -I"C:\Users\86157\Desktop\Smart-Car-Four_wheel\Four_wheel\libraries\sdk\Core" -I"C:\Users\86157\Desktop\Smart-Car-Four_wheel\Four_wheel\libraries\sdk\Ld" -I"C:\Users\86157\Desktop\Smart-Car-Four_wheel\Four_wheel\libraries\sdk\Peripheral" -I"C:\Users\86157\Desktop\Smart-Car-Four_wheel\Four_wheel\libraries\sdk\Startup" -I"C:\Users\86157\Desktop\Smart-Car-Four_wheel\Four_wheel\project\user\inc" -I"C:\Users\86157\Desktop\Smart-Car-Four_wheel\Four_wheel\libraries\zf_common" -I"C:\Users\86157\Desktop\Smart-Car-Four_wheel\Four_wheel\libraries\zf_device" -I"C:\Users\86157\Desktop\Smart-Car-Four_wheel\Four_wheel\project\code" -I"C:\Users\86157\Desktop\Smart-Car-Four_wheel\Four_wheel\libraries\zf_driver" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

