/**************************************************************************************
实验项目：智能小车主程序
作者：Terry
日期：2019-08-13
联系方式：terryluohello@qq.com
***************************************************************************************/

#include <reg52.h>		 
#include "motor.h"
#include "infrared.h"
#include "US_015.h"

unsigned char pwm_val = 0; // PWM
unsigned char direction = 0; // 小车移动方向，默认停止

sbit FM=P2^3; //蜂鸣器驱动口定义



void delay(unsigned int xms) //i=xms即延时约xms毫秒				
{
	unsigned int i,j;
	for(i=xms;i>0;i--)		      
		for(j=112;j>0;j--);
}


void main()
{
	direction = 1; // 初始移动方向
	// 设置定时器
	TMOD=0X01;
  TH0= 0XFC;  //1ms定时
  TL0= 0X66;
  TR0= 1;
  ET0= 1;
	EA = 1;	    //开总中断
  
	while(1)
	{			

		FM = 0;
	  delay(100);
	  FM = 1;
	  delay(1000);
		
    Ultrasonic(&direction);		// 超声波避障
//		direction = InfraredTracking(); // 红外循迹
//		MovingControl(0, pwm_val, 5, direction);    // PWM控制
	}	
}


// TIMER0中断服务子函数产生PWM信号
void Timer0() interrupt 1 using 2
{
   TH0=0XFC;	  //1Ms定时
	 TL0=0X66;
	 pwm_val++;
	 MovingControl(1, pwm_val, 5, direction);    // PWM控制
	 if(pwm_val >= 20)
	 {
		 pwm_val = 0;
	 }
}	

// 超声波中断服务
void Timer1(void) interrupt 3
{
	TF1 = 0;
	Echo=0;
}