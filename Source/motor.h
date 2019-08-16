#ifndef __MOTOR_H__
#define __MOTOR_H__

#include "bst_car.h"	 //����bst_car.h����С��ͷ�ļ�


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