#ifndef __MOTOR_H__
#define __MOTOR_H__

#include<reg52.h>

// ��������С������ģ������IO��
sbit IN1=P1^2; // �ߵ�ƽ1 ���ˣ���ת��
sbit IN2=P1^3; // �ߵ�ƽ1 ǰ������ת��

sbit IN3=P1^6; // �ߵ�ƽ1 ǰ������ת��	
sbit IN4=P1^7; // �ߵ�ƽ1 ���ˣ���ת��

sbit EN1=P1^4; // �ߵ�ƽʹ�� 
sbit EN2=P1^5; // �ߵ�ƽʹ�� 

// ���ת������
void forward(void);
void back(void);
void stop(void);
void turn_right(void);
void turn_left(void);
void spin_right(void);
void spin_left(void);

void MovingControl(bit pwm_on,unsigned char pwm_val, unsigned char pwm_n, unsigned char direction);

#endif