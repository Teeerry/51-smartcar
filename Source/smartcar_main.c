/**************************************************************************************
ʵ����Ŀ������С��������
���ߣ�Terry
���ڣ�2019-08-13
��ϵ��ʽ��terryluohello@qq.com
***************************************************************************************/
		 
#include "motor.h"
#include "infrared.h"
#include "US_015.h"
#include "bluetooth.h"

unsigned char pwm_val = 0; // PWM
unsigned char direction = 0; // С���ƶ�����Ĭ��ֹͣ


bit startBit = 0;  				//���ڽ��տ�ʼ��־λ
unsigned char newLineReceived = 0; 	//����һ֡Э����������
unsigned char inputString[50];  //��������Э��


void main()
{
	direction = 1; // ��ʼ�ƶ�����
	// ���ö�ʱ��
	TMOD |=0X01;
  TH0= 0XFC;  //1ms��ʱ
  TL0= 0X66;
  TR0= 1;
  ET0= 1;
	EA = 1;	    //�����ж�
	BluetoothInit();
	while(1)
	{			

		FM = 0;
	  delay(100);
	  FM = 1;
	  delay(1000);
		
    Ultrasonic(&direction);		// ����������
//		direction = InfraredTracking(); // ����ѭ��
//		MovingControl(0, pwm_val, 5, direction);    // PWM����
//		TeleControl(&direction, inputString, &newLineReceived);
	}	
}



/******************************************************************/
/* TIMER0�жϷ����Ӻ�������PWM�ź�*/
/******************************************************************/
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


/******************************************************************/
/* ������T2��ʱ���жϷ���*/
/******************************************************************/
void Timer2(void) interrupt 5
{
	TF2  = 0;
	Echo = 0;
}


//void timer2()  interrupt 5	 //��ʱ��2
//{
//	 TF2 = 0;
//   TH2 = 0;	  //1Ms��ʱ
//	 TL2 = 0;
//}
/******************************************************************/
/* �����жϳ���*/
/******************************************************************/
void UART_SER () interrupt 4
{
	unsigned char n; 	//������ʱ����
	static int num = 0;

	if(RI) 		//�ж��ǽ����жϲ���
	{
		RI = 0; 	//��־λ����
		n = SBUF; //���뻺������ֵ

	    if(n == '$')
	    {
	      startBit = 1;
		  num = 0;
	    }
	    if(startBit == 1)
	    {
	       inputString[num] = n;     
	    }  
	    if (n == '#') 
	    {
	       newLineReceived = 1; 
	       startBit = 0;
	    }
		num++;
		if(num >= 50)
		{
			num = 0;
			startBit = 0;
			newLineReceived	= 0;
		}
	}

}