#ifndef __US_015_H__
#define __US_015_H__

#include<reg52.h>

sbit Trig = P2^1;	   //³¬Éù²¨Ä£¿éTrig	¿ØÖÆ¶Ë
sbit Echo = P2^0;	   //³¬Éù²¨Ä£¿éEcho	½ÓÊÕ¶Ë

void Delay10us(unsigned char i);
void start_measure();
void Timer1_Init();
unsigned char distance_measure();
void Ultrasonic(unsigned char* direction);	  //³¬Éù²¨²â¾à

#endif
