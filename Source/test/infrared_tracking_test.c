/**************************************************************************************
ʵ����Ŀ�����ת������
���ߣ�Terry
���ڣ�2019-08-13
��ϵ��ʽ��terryluohello@qq.com
***************************************************************************************/

#include <reg52.h>		 
#include "motor.h"
#include "infrared.h"


void delay(unsigned int xms)				
{
	unsigned int i,j;
	for(i=xms;i>0;i--)		      //i=xms����ʱԼxms����
		for(j=112;j>0;j--);
}

void main()
{
	FM = 0;
	while(1)
	{			
		InfraredTracking();	
	}		
}
