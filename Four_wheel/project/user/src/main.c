/*********************************************************************************************************************
* COPYRIGHT NOTICE
* Copyright (c) 2019,逐飞科技
* All rights reserved.
*
* 以下所有内容版权均属逐飞科技所有，未经允许不得用于商业用途，
* 欢迎各位使用并传播本程序，修改内容时必须保留逐飞科技的版权声明。
*
* @file             main
* @company          成都逐飞科技有限公司
 * @author          逐飞科技(QQ790875685)
* @version          查看doc内version文件 版本说明
* @Software         MounRiver Studio V1.51
* @Target core      CH32V307VCT6
* @Taobao           https://seekfree.taobao.com/
* @date             2021-11-25
********************************************************************************************************************/

#include "zf_common_headfile.h"
#include "servo.h"
#include "picture_process.h"

int servo_pwm=790;

int main(void)
{
    interrupt_global_disable();             // 关闭总中断
    clock_init(SYSTEM_CLOCK_144M);          // 务必保留，设置系统时钟。
    debug_init();                           // 务必保留，本函数用于初始化MPU 时钟 调试串口
    oled_init();
    mt9v03x_init_dvp ();
    servo_init();

    // 此处编写用户代码(例如：外设初始化代码等)
    interrupt_global_enable();              // 总中断最后开启
    while(1)
    {
        if(mt9v03x_finish_flag_dvp)
          {
              mt9v03x_finish_flag_dvp = 0;
              compress_image();//图像二值化在zf_device_camera.c中
              zhongxian();
              display_oled();

          }
        PID();

//        display_oled();


    }
}







