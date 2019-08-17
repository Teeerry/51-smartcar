/**************************************************************************************
ʵ����Ŀ������С��
���ߣ�Terry
���ڣ�2019-08-18
��ϵ��ʽ��terryluohello@qq.com
***************************************************************************************/	

#include "follow.h"				// ����ͷ�ļ�

//��ຯ�������ؾ�����ֵ
float distance_measure_2()		 		
{
	unsigned int time = 0; 	     // ʱ�����
	
	time=TH2*256+TL2;				     // ����ʱ��
	TH2=0;
	TL2=0;
	
	return (time*1.7)/10+10;     // �������MM	
} 

void Following(unsigned char *mode, unsigned char* direction)
{	  		
	float distances[] = {0.0, 0.0, 0.0, 0.0, 0.0};
	float sum_distances = 0;         // ������ξ���ĺ�
	float cur_ave_distances = 0;     // ��ǰ��ξ����ƽ��ֵ
	float pre_ave_distances = 0;     // ǰһ����ξ����ƽ��ֵ
	unsigned char i = 0;
	
	Timer2_Init();	 
	Trig=0;
	*direction = 1;
	
	for(i = 0; i < 5; i++)
	{
			Echo=1;
			start_measure();	//����ģ��   
			if(Echo==1)
			{
				TR2=1;			    // ��������
				while(Echo);		// ��EchoΪ1�������ȴ�
				TR2=0;				  // �رռ���
				distances[i] = distance_measure_2();			  //�������
				sum_distances += distances[i];
			}		
	 }
	
	cur_ave_distances = sum_distances / 5.0;
	while(*mode == follow)
	{		
			Echo=1;
			start_measure();	//����ģ��   
			if(Echo==1)
			{
				TR2=1;			    // ��������
				while(Echo);		// ��EchoΪ1�������ȴ�
				TR2=0;				  // �رռ���
				
				if (i >= 5)
					i %= 5;
				sum_distances -= distances[i];
				distances[i] = distance_measure_2();			  //�������
				sum_distances += distances[i];
				i += 1;
				
				pre_ave_distances = cur_ave_distances;
				cur_ave_distances = sum_distances / 5.0;
				
				KeepDistance(cur_ave_distances, direction);
			}	
			
	}
}

void KeepDistance(float cur_ave_distances, unsigned char* direction)
{
				if (cur_ave_distances > 130)    // ǰ������
				{
					if(infrared_top_left == 0 && infrared_top_right == 1)      // �����⵽�ұ����ϰ���
						*direction = 3;    // С��ǰ��ת
		      else if(infrared_top_left == 1 && infrared_top_right == 0) // �����⵽������ϰ���																							 // �������
			      *direction = 4;    // С��ǰ��ת
		      else if(infrared_top_left == 1 && infrared_top_right == 1) // �����⵽���Ҿ����ϰ���
			      *direction = 1;    // С��ǰ��
				}
				else if(cur_ave_distances < 70) // ���˻���
				{
					if(infrared_top_left == 0 && infrared_top_right == 1)      // �����⵽�ұ����ϰ���
						*direction = 6;    // С������ת
		      else if(infrared_top_left == 1 && infrared_top_right == 0) // �����⵽������ϰ���																							 // �������
			      *direction = 5;    // С������ת
		      else 
			      *direction = 2;    // С������
				}
				else   // ͣ��
				{
					if(infrared_top_left == 0 && infrared_top_right == 1)      // �����⵽�ұ����ϰ���
						*direction = 3;    // С��ǰ��ת
		      else if(infrared_top_left == 1 && infrared_top_right == 0) // �����⵽������ϰ���																							 // �������
			      *direction = 4;    // С��ǰ��ת
		      else 
			      *direction = 0;    // С��ͣ��
				}	
}