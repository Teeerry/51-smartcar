/**************************************************************************************
ʵ����Ŀ������С��������
���ߣ�Terry
���ڣ�2019-08-17
��ϵ��ʽ��terryluohello@qq.com
***************************************************************************************/
		 
#include "motor.h"				// ���ͷ�ļ�
#include "infrared.h"			// ����ͷ�ļ�
#include "US_015.h"				// ������ͷ�ļ�
#include "bluetooth.h"		// ����ͷ�ļ�

bit startBit = 0;  				          // ���ڽ��տ�ʼ��־λ
unsigned char newLineReceived = 0; 	// ����һ֡Э����������
unsigned char inputString[50];      // ��������Э��
unsigned char direction = 0;        // С���ƶ�����Ĭ��ֹͣ
unsigned char pwm_val = 0;          // PWM����
unsigned char mode = telecontrol;   // ��ǰ����ģʽ
unsigned char speed_left = 10, speed_right = 10; // ��������PWM


/******************************************************************/
/* ������*/
/******************************************************************/
void main()
{
	// ���ö�ʱ��
	TMOD |=0X01;
  TH0= 0XFC;  //1ms��ʱ
  TL0= 0X66;
  TR0= 1;
  ET0= 1;
	EA = 1;	    //�����ж�
	BluetoothInit();
	
	FM = 0;           // ��������ʾ
	delay(100);
	FM = 1;
	while(1)
	{					
		direction = 1;  // ��ʼ�ƶ�����		
//		mode = inputString[1];
		switch(mode)
			{
				case telecontrol: P1=P1<<1; TeleControl(&mode, &direction, inputString, &newLineReceived); break; // ����ң��
				case infrared:    P1=P1<<2; InfraredTracking(&mode, &direction); break; // ����ѭ��
				case wave:        P1=P1<<3; Ultrasonic(&mode, &direction); break;       // ����������
				default:          P1=P1<<6; TeleControl(&mode, &direction, inputString, &newLineReceived); break; // ����ң��
			}
			
	}	
}



/******************************************************************/
/* TIMER0�жϷ����Ӻ�������PWM�ź�*/
/******************************************************************/
void Timer0() interrupt 1 using 2
{
   TH0=0XFC;	  // 1Ms��ʱ
	 TL0=0X66;
	 pwm_val++;   // PWM������һ
	 MovingControl(1, pwm_val, speed_left, speed_right, direction); // PWM����
	 if(pwm_val >= 50) // ����PWM����ͨ��speed_left/50��speed_right/50 �ֱ���������ٶ� 
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

	  if(n == '$')  // ������ʼλ
			{
	      startBit = 1;
		    num = 0;
	    }
			
		if(startBit == 1)
	    {
	       inputString[num] = n;     
	    }
			
	  if (n == '#') // ���ݽ���λ
	    {
	       newLineReceived = 1; 
	       startBit = 0;
	    }
			
		num++;
//		if(num >= 50)
//		{
//			num = 0;
//			startBit = 0;
//			newLineReceived	= 0;
//		}
		
		switch(inputString[3])  // ���µ��ת��
			{
				case v_f:  speed_left = 25; speed_right = 22; break; // ����
				case v_m:  speed_left = 12; speed_right = 14; break; // ����
				case v_s:  speed_left = 8;  speed_right = 9;  break; // ����
				default:   speed_left = 12; speed_right = 14; break; // ����
			}
		mode = inputString[1];  // ��ʱ���¹���ģʽ
	}

}