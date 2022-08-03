/*
 * servo.c
 *
 *  Created on: 2022年8月1日
 *      Author: 86157
 */

/*
 * servo.c
 *
 *  Created on: 2022年8月1日
 *      Author: 86157
 */


#include<servo.h>
#include"zf_common_headfile.h"

#define servo   TIM1_PWM_CH3_E13
#define zright B0  //正转
#define fright B1  //右轮
#define zleft A2
#define fleft A3  //左轮
#define middle 790

int erro_last=0;
int erro_next=0;
extern int servo_pwm;
extern uint8_t LCenter[70];

void servo_init()
{
    pwm_init(TIM3_PWM_CH3_B0, 12000, 0);
    pwm_init(TIM3_PWM_CH4_B1, 12000, 0);
    pwm_init(TIM2_PWM_CH3_A2, 12000, 0);
    pwm_init(TIM2_PWM_CH4_A3, 12000, 0);
    pwm_init( servo, 50, 0);

    pwm_set_duty(TIM3_PWM_CH3_B0, 2800);  //左轮前
    pwm_set_duty(TIM3_PWM_CH4_B1, 0);    //左轮后
    pwm_set_duty(TIM2_PWM_CH3_A2, 2800);     //右轮前
    pwm_set_duty(TIM2_PWM_CH4_A3, 0);  //右轮后
    pwm_set_duty(servo, servo_pwm);  //舵机右



}

void PID()
{
    float kp=1.8;//1.2/1.55
    int k=0;
    float kd=0.1;
    int pwm;
    for (int i = 4; i < 12; ++i)
    {
        k+=LCenter[i];
    }
    k/=8;
    erro_last=erro_next;
    erro_next=k-92;
    if(erro_next<-40||erro_next>40)
    {
        pwm=limit(kp*(k-92)-kd*(erro_next-erro_last),70);
    }
    else{  pwm=limit(kp*(k-92)/2.8-kd*(erro_next-erro_last)/2.9,70);}
    k=0;
    pwm_set_duty(servo, middle+pwm);
}
