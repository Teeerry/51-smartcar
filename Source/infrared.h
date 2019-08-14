#ifndef _INFRARED_H_
#define _INFRARED_H_

#include<reg52.h>

// 红外传感器声明
sbit infrared_right = P3^2;   
sbit infrared_left  = P3^3;

// 红外循迹函数
unsigned char InfraredTracking(void);

#endif