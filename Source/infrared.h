#ifndef _INFRARED_H_
#define _INFRARED_H_

#include<reg52.h>

// ���⴫��������
sbit infrared_right = P3^2;   
sbit infrared_left  = P3^3;

// ����ѭ������
unsigned char InfraredTracking(void);

#endif