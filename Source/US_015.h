#ifndef __US_015_H__
#define __US_015_H__

#include<reg52.h>

sbit Trig = P2^1;	   //������ģ��Trig	���ƶ�
sbit Echo = P2^0;	   //������ģ��Echo	���ն�

void Delay10us(unsigned char i);
void start_measure();
void Timer1_Init();
unsigned char distance_measure();
void Ultrasonic(unsigned char* direction);	  //���������

#endif
