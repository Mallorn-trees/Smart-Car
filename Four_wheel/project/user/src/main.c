/*********************************************************************************************************************
* COPYRIGHT NOTICE
* Copyright (c) 2019,��ɿƼ�
* All rights reserved.
*
* �����������ݰ�Ȩ������ɿƼ����У�δ��������������ҵ��;��
* ��ӭ��λʹ�ò������������޸�����ʱ���뱣����ɿƼ��İ�Ȩ������
*
* @file             main
* @company          �ɶ���ɿƼ����޹�˾
 * @author          ��ɿƼ�(QQ790875685)
* @version          �鿴doc��version�ļ� �汾˵��
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
    interrupt_global_disable();             // �ر����ж�
    clock_init(SYSTEM_CLOCK_144M);          // ��ر���������ϵͳʱ�ӡ�
    debug_init();                           // ��ر��������������ڳ�ʼ��MPU ʱ�� ���Դ���
    oled_init();
    mt9v03x_init_dvp ();
    servo_init();

    // �˴���д�û�����(���磺�����ʼ�������)
    interrupt_global_enable();              // ���ж������
    while(1)
    {
        if(mt9v03x_finish_flag_dvp)
          {
              mt9v03x_finish_flag_dvp = 0;
              compress_image();//ͼ���ֵ����zf_device_camera.c��
              zhongxian();
              display_oled();

          }
        PID();

//        display_oled();


    }
}







