/**************************************************************************************
ʵ����Ŀ�����ת������
���ߣ�Terry
���ڣ�2019-08-13
��ϵ��ʽ��terryluohello@qq.com
***************************************************************************************/

#include "reg52.h"			 
#include "motor.h"			 


void delay(unsigned int xms)				
{
	unsigned int i,j;
	for(i=xms;i>0;i--)		      //i=xms����ʱԼxms����
		for(j=112;j>0;j--);
}

void main()
{
	while(1)
	{			
		forward();
		delay(1000);
		back();
		delay(1000);
		stop();
		delay(1000);
		turn_right();
		delay(1000);
		turn_left();
		delay(1000);
		spin_right();
		delay(1000);
		spin_left();
		delay(4000);		
	}		
}
