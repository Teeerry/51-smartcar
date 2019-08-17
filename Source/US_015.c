/**************************************************************************************
实验项目：超声波模块
作者：Terry
日期：2019-08-14
联系方式：terryluohello@qq.com
***************************************************************************************/
#include"US_015.h"

// 定时器2初始化
void Timer2_Init()
{
	TH2 = 0;
	TL2 = 0;
}
 
//测距函数，返回距离数值
unsigned char distance_measure()		 		
{
	unsigned char direction = 1; // 小车默认移动方向
	unsigned int time = 0; 	     // 时间变量
	float distance = 0; 		     // 障碍物距离变量
	
	time=TH2*256+TL2;				     // 计算时间
	TH2=0;
	TL2=0;
	
	distance =(time*1.7)/10+10;  // 算出来是MM
	if(distance<300)		  	     // 距离小于30cm
	{
		direction = 3;    // 小车停止
	}
	else
		direction = 1;
	
	return direction;
} 

void start_measure()	// Trig输出高电平触发测距
{
	Trig=1;    
	Delay10us(2);	
  Trig=0;
}

void Ultrasonic(unsigned char *mode, unsigned char* direction)	    //超声波
{	  		
	Timer2_Init();	 
	Trig=0;
	while(*mode == wave)
	{		
		  Echo=1;
	    start_measure();	//启动模块   
	    if(Echo==1)
			{
				 TR2=1;			    // 开启计数
				 while(Echo);		// 当Echo为1计数并等待
	       TR2=0;				  // 关闭计数
				 *direction = distance_measure();			  //计算
		     delay(500);    // 延时500ms完成转弯
				 *direction = 1;// 恢复直行
			}		
	}
}