#ifndef __US_015_H__
#define __US_015_H__

#include "bst_car.h"	 //����bst_car.h����С��ͷ�ļ�

void start_measure();
void Timer2_Init();
unsigned char distance_measure();
void Ultrasonic(unsigned char* mode, unsigned char* direction);	  //���������

#endif
