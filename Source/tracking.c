/**************************************************************************************
ʵ����Ŀ������ģ��
���ߣ�Terry
���ڣ�2019-08-13
��ϵ��ʽ��terryluohello@qq.com
***************************************************************************************/	
#include "infrared.h"

// ����ѭ������С���ƶ�����
void InfraredTracking(unsigned char *mode, unsigned char* direction)
{
	*direction = 1;
	//���ź�Ϊ0  û���ź�Ϊ1
	while(*mode == infrared)
	{
		if(infrared_left == 0 && infrared_right == 0)
			*direction = 0;      // С��ֹͣ
		else if(infrared_left == 1 && infrared_right == 0)	  //��߼�⵽����
		{
			*direction = 3;		// С����ת
		}			   
		else if(infrared_right == 1 && infrared_left == 0)		//�ұ߼�⵽����
		{	  
			*direction = 4;		// С����ת
		}
		else
			*direction = 1;	  // С��ǰ��
	}
}