/**************************************************************************************
实验项目：跟随小车
作者：Terry
日期：2019-08-18
联系方式：terryluohello@qq.com
***************************************************************************************/	

#include "follow.h"				// 跟随头文件

//测距函数，返回距离数值
float distance_measure_2()		 		
{
	unsigned int time = 0; 	     // 时间变量
	
	time=TH2*256+TL2;				     // 计算时间
	TH2=0;
	TL2=0;
	
	return (time*1.7)/10+10;     // 算出来是MM	
} 

void Following(unsigned char *mode, unsigned char* direction)
{	  		
	float distances[] = {0.0, 0.0, 0.0, 0.0, 0.0};
	float sum_distances = 0;         // 保存五次距离的和
	float cur_ave_distances = 0;     // 当前五次距离的平均值
	float pre_ave_distances = 0;     // 前一次五次距离的平均值
	unsigned char i = 0;
	
	Timer2_Init();	 
	Trig=0;
	*direction = 1;
	
	for(i = 0; i < 5; i++)
	{
			Echo=1;
			start_measure();	//启动模块   
			if(Echo==1)
			{
				TR2=1;			    // 开启计数
				while(Echo);		// 当Echo为1计数并等待
				TR2=0;				  // 关闭计数
				distances[i] = distance_measure_2();			  //计算距离
				sum_distances += distances[i];
			}		
	 }
	
	cur_ave_distances = sum_distances / 5.0;
	while(*mode == follow)
	{		
			Echo=1;
			start_measure();	//启动模块   
			if(Echo==1)
			{
				TR2=1;			    // 开启计数
				while(Echo);		// 当Echo为1计数并等待
				TR2=0;				  // 关闭计数
				
				if (i >= 5)
					i %= 5;
				sum_distances -= distances[i];
				distances[i] = distance_measure_2();			  //计算距离
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
				if (cur_ave_distances > 130)    // 前进调整
				{
					if(infrared_top_left == 0 && infrared_top_right == 1)      // 红外检测到右边无障碍物
						*direction = 3;    // 小车前左转
		      else if(infrared_top_left == 1 && infrared_top_right == 0) // 红外检测到左边无障碍物																							 // 其他情况
			      *direction = 4;    // 小车前右转
		      else if(infrared_top_left == 1 && infrared_top_right == 1) // 红外检测到左、右均无障碍物
			      *direction = 1;    // 小车前进
				}
				else if(cur_ave_distances < 70) // 后退缓冲
				{
					if(infrared_top_left == 0 && infrared_top_right == 1)      // 红外检测到右边无障碍物
						*direction = 6;    // 小车后右转
		      else if(infrared_top_left == 1 && infrared_top_right == 0) // 红外检测到左边无障碍物																							 // 其他情况
			      *direction = 5;    // 小车后左转
		      else 
			      *direction = 2;    // 小车后退
				}
				else   // 停下
				{
					if(infrared_top_left == 0 && infrared_top_right == 1)      // 红外检测到右边无障碍物
						*direction = 3;    // 小车前右转
		      else if(infrared_top_left == 1 && infrared_top_right == 0) // 红外检测到左边无障碍物																							 // 其他情况
			      *direction = 4;    // 小车前左转
		      else 
			      *direction = 0;    // 小车停下
				}	
}