/**************************************************************************************
ʵ����Ŀ��������ģ��
���ߣ�Terry
���ڣ�2019-08-14
��ϵ��ʽ��terryluohello@qq.com
***************************************************************************************/
#include"US_015.h"

// ��ʱ��1��ʼ��
void Timer1_Init()
{
	TH2 = 0;
	TL2 = 0;
}
 
//��ຯ�������ؾ�����ֵ
unsigned char distance_measure()		 		
{
	unsigned char direction = 1; // С��Ĭ���ƶ�����
	unsigned int time = 0; 	     // ʱ�����
	float distance = 0; 		     // �ϰ���������
	
	time=TH2*256+TL2;				     // ����ʱ��
	TH2=0;
	TL2=0;
	
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
				 TR2=1;			    // ��������
				 while(Echo);		// ��EchoΪ1�������ȴ�
	       TR2=0;				  // �رռ���
				 *direction = distance_measure();			  //����
		   }		
	}
}