/**************************************************************************************
ʵ����Ŀ������ģ��
���ߣ�Terry Billy
���ڣ�2019-08-18
��ϵ��ʽ��terryluohello@qq.com 2228238121@qq.com
***************************************************************************************/	

#include "infrared.h"

// ����ѭ��������
void InfraredTracking(unsigned char *mode, unsigned char* direction)
{
	*direction = 1;
	//���ź�Ϊ0  û���ź�Ϊ1
	while(*mode == infrared)
	{
		if(infrared_bottom_left == 0 && infrared_bottom_right == 0)
			*direction = 0;      // С��ֹͣ
		else if(infrared_bottom_left == 1 && infrared_bottom_right == 0)	  //��߼�⵽����
		{
			*direction = 3;		// С����ת
		}			   
		else if(infrared_bottom_right == 1 && infrared_bottom_left == 0)		//�ұ߼�⵽����
		{	  
			*direction = 4;		// С����ת
		}
		else
			*direction = 1;	  // С��ǰ��
	}
}