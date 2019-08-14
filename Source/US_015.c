/**************************************************************************************
ʵ����Ŀ��������ģ��
���ߣ�Terry
���ڣ�2019-08-14
��ϵ��ʽ��terryluohello@qq.com
***************************************************************************************/
#include"US_015.h"
#include <intrins.h>   //����nop��ϵͳ����

// 10us��ʱ���� ����������ģ��ʱʹ��
void Delay10us(unsigned char i)    	
{ 
   unsigned char j;
	do
	{ 
		j = 10; 
		do
		{ 
			_nop_(); 
		}while(--j); 
	}while(--i); 
}  

// ��ʱ��1��ʼ��
void Timer1_Init()
{
	TH1 = 0;
	TL1 = 0;
}
 
//��ຯ�������ؾ�����ֵ
unsigned char distance_measure()		 		
{
	unsigned char direction = 1; // С��Ĭ���ƶ�����
	unsigned int time = 0; 	     // ʱ�����
	float distance = 0; 		     // �ϰ���������
	
	time=TH1*256+TL1;				     // ����ʱ��
	TH1=0;
	TL1=0;
	
	distance =(time*1.7)/10+10;  // �������MM
	if(distance<300)		  	     // ����С��30cm
	{
		direction = 0;    // С��ֹͣ
	}
	else
		direction = 1;
	
	return direction;
} 

void start_measure()	// Trig����ߵ�ƽ�������
{
	Trig=1;    
	Delay10us(2);	
  Trig=0;
}

void Ultrasonic(unsigned char* direction)	    //������
{	  		
	Timer1_Init();	 
	Trig=0;
	while(1)
	{	
//		start_measure();	//����������
//    Echo = 0;
//		while(!Echo); 	//�ȴ�Echo�ز����ű�ߵ�ƽ//////////////////////////////////////////////////////////////
//    TR2=1;	FM = 0;                          		//�������е��˴�ʱ˵��Echo�ű���˸ߵ�ƽ����ʱ����T0��ʼ��ʱ
//    while(Echo);		//�ȴ�Echo�ز����Ÿߵ�ƽ����               
//    TR2=0;						//�������е��˴�ʱ˵��Echo�ű���˵͵�ƽ����ʱT0ֹͣ���
//		
//	  *direction = distance_measure();
		
		  Echo=1;
	    start_measure();	//����ģ��   
	    if(Echo==1)
			{
				 TR1=1;			    // ��������
				 while(Echo);		// ��EchoΪ1�������ȴ�
	       TR1=0;				  // �رռ���
				 *direction = distance_measure();			  //����
		   }		
	}
}