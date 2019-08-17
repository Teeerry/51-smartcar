/**************************************************************************************
ʵ����Ŀ��������ģ��
���ߣ�Terry Billy
���ڣ�2019-08-18
��ϵ��ʽ��terryluohello@qq.com 2228238121@qq.com
***************************************************************************************/	

#include"US_015.h"

// ��ʱ��2��ʼ��
void Timer2_Init()
{
	TH2 = 0;
	TL2 = 0;
}
 
//��ຯ���������˶�����
unsigned char distance_measure()		 		
{
	unsigned char direction = 1; // С��Ĭ���ƶ�����
	unsigned int time = 0; 	     // ʱ�����
	float distance = 0; 		     // �ϰ���������
	
	time=TH2*256+TL2;				     // ����ʱ��
	TH2=0;
	TL2=0;
	
	distance =(time*1.7)/10+10;  // �������MM
	if(distance < 200)		  	   // ����С��30cm
	{
		if(infrared_top_left == 0 && infrared_top_right == 1) // �����⵽�ұ����ϰ���
			direction = 4;    // С����ת
		else if(infrared_top_left == 1 && infrared_top_right == 0)	// �����⵽������ϰ���																							 // �������
			direction = 3;    // С����ת
		else 
			direction = 6;    // С��������ת
	}
	else												 // �������
	{
		if(infrared_top_left == 0 && infrared_top_right == 1) // �����⵽�ұ����ϰ���
			direction = 4;    // С����ת
		else if(infrared_top_left == 1 && infrared_top_right == 0)	// �����⵽������ϰ���																							 // �������
			direction = 3;    // С����ת
		else
			direction = 1;    // С��ǰ��
	}
	return direction;
} 

void start_measure()	// Trig����ߵ�ƽ�������
{
	Trig=1;    
	Delay10us(2);	
  Trig=0;
}

// ����������������
void Ultrasonic(unsigned char *mode, unsigned char* direction)	    //������
{	  		
	Timer2_Init();	 
	Trig=0;
	*direction = 1;
	while(*mode == wave)
	{		
		  Echo=1;
	    start_measure();	//����ģ��   
	    if(Echo==1)
			{
				 TR2=1;			    // ��������
				 while(Echo);		// ��EchoΪ1�������ȴ�
	       TR2=0;				  // �رռ���
				 *direction = distance_measure();			  //����
		     delay(300);    // ��ʱ300ms���ת��
				 
				*direction = 1;// �ָ�ֱ��
			}		
	}
}