/**************************************************************************************
ʵ����Ŀ������С��
���ߣ�Terry Billy
���ڣ�2019-08-18
��ϵ��ʽ��terryluohello@qq.com 2228238121@qq.com
***************************************************************************************/	


#include "bst_car.h"	 //����bst_car.h����С��ͷ�ļ�
#include <intrins.h>   //����nop��ϵͳ����

// ��������ʾ
void buzzer(void)
{
	FM = 0;           
	delay(100);
	FM = 1;
}
// ��ʱ����	
void delay(unsigned int xms)				
{
  unsigned int i,j;
	for(i=xms;i>0;i--)		      //i=xms����ʱԼxms����
    for(j=112;j>0;j--);
}

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