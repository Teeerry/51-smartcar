/**************************************************************************************
实验项目：红外模块
作者：Terry Billy
日期：2019-08-18
联系方式：terryluohello@qq.com 2228238121@qq.com
***************************************************************************************/	

#include "infrared.h"

// 红外循迹主程序
void InfraredTracking(unsigned char *mode, unsigned char* direction)
{
	*direction = 1;
	//有信号为0  没有信号为1
	while(*mode == infrared)
	{
		if(infrared_bottom_left == 0 && infrared_bottom_right == 0)
			*direction = 0;      // 小车停止
		else if(infrared_bottom_left == 1 && infrared_bottom_right == 0)	  //左边检测到黑线
		{
			*direction = 3;		// 小车左转
		}			   
		else if(infrared_bottom_right == 1 && infrared_bottom_left == 0)		//右边检测到黑线
		{	  
			*direction = 4;		// 小车右转
		}
		else
			*direction = 1;	  // 小车前进
	}
}