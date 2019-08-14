/**************************************************************************************
ʵ����Ŀ������С��������
���ߣ�Terry
���ڣ�2019-08-13
��ϵ��ʽ��terryluohello@qq.com
***************************************************************************************/

#include <reg52.h>		 
#include "motor.h"
#include "infrared.h"
#include "US_015.h"

unsigned char pwm_val = 0; // PWM
unsigned char direction = 0; // С���ƶ�����Ĭ��ֹͣ

sbit FM=P2^3; //�����������ڶ���



void delay(unsigned int xms) //i=xms����ʱԼxms����				
{
	unsigned int i,j;
	for(i=xms;i>0;i--)		      
		for(j=112;j>0;j--);
}


void main()
{
	direction = 1; // ��ʼ�ƶ�����
	// ���ö�ʱ��
	TMOD=0X01;
  TH0= 0XFC;  //1ms��ʱ
  TL0= 0X66;
  TR0= 1;
  ET0= 1;
	EA = 1;	    //�����ж�
  
	while(1)
	{			

		FM = 0;
	  delay(100);
	  FM = 1;
	  delay(1000);
		
    Ultrasonic(&direction);		// ����������
//		direction = InfraredTracking(); // ����ѭ��
//		MovingControl(0, pwm_val, 5, direction);    // PWM����
	}	
}


// TIMER0�жϷ����Ӻ�������PWM�ź�
void Timer0() interrupt 1 using 2
{
   TH0=0XFC;	  //1Ms��ʱ
	 TL0=0X66;
	 pwm_val++;
	 MovingControl(1, pwm_val, 5, direction);    // PWM����
	 if(pwm_val >= 20)
	 {
		 pwm_val = 0;
	 }
}	

// �������жϷ���
void Timer1(void) interrupt 3
{
	TF1 = 0;
	Echo=0;
}