#ifndef __US_015_H__
#define __US_015_H__

#include "bst_car.h"	 //包含bst_car.h智能小车头文件

void start_measure();
void Timer2_Init();
unsigned char distance_measure();
void Ultrasonic(unsigned char* mode, unsigned char* direction);	  //超声波测距

#endif
