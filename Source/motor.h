#ifndef __MOTOR_H__
#define __MOTOR_H__

#include<reg52.h>

// 定义智能小车驱动模块输入IO口
sbit IN1=P1^2; // 高电平1 后退（反转）
sbit IN2=P1^3; // 高电平1 前进（正转）

sbit IN3=P1^6; // 高电平1 前进（正转）	
sbit IN4=P1^7; // 高电平1 后退（反转）

sbit EN1=P1^4; // 高电平使能 
sbit EN2=P1^5; // 高电平使能 

// 电机转动函数
void forward(void);
void back(void);
void stop(void);
void turn_right(void);
void turn_left(void);
void spin_right(void);
void spin_left(void);

void MovingControl(bit pwm_on,unsigned char pwm_val, unsigned char pwm_n, unsigned char direction);

#endif