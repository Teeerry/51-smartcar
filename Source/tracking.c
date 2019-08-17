/**************************************************************************************
实验项目：红外模块
作者：Terry
日期：2019-08-13
联系方式：terryluohello@qq.com
***************************************************************************************/	
#include "infrared.h"

// 红外循迹返回小车移动方向
void InfraredTracking(unsigned char *mode, unsigned char* direction)
{
	*direction = 1;
	//有信号为0  没有信号为1
	while(*mode == infrared)
	{
		if(infrared_left == 0 && infrared_right == 0)
			*direction = 0;      // 小车停止
		else if(infrared_left == 1 && infrared_right == 0)	  //左边检测到黑线
		{
			*direction = 3;		// 小车左转
		}			   
		else if(infrared_right == 1 && infrared_left == 0)		//右边检测到黑线
		{	  
			*direction = 4;		// 小车右转
		}
		else
			*direction = 1;	  // 小车前进
	}
}