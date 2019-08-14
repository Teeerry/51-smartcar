/**************************************************************************************
实验项目：超声波模块
作者：Terry
日期：2019-08-14
联系方式：terryluohello@qq.com
***************************************************************************************/
#include"US_015.h"
#include <intrins.h>   //包含nop等系统函数

// 10us延时函数 启动超声波模块时使用
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

// 定时器1初始化
void Timer1_Init()
{
	TH1 = 0;
	TL1 = 0;
}
 
//测距函数，返回距离数值
unsigned char distance_measure()		 		
{
	unsigned char direction = 1; // 小车默认移动方向
	unsigned int time = 0; 	     // 时间变量
	float distance = 0; 		     // 障碍物距离变量
	
	time=TH1*256+TL1;				     // 计算时间
	TH1=0;
	TL1=0;
	
	distance =(time*1.7)/10+10;  // 算出来是MM
	if(distance<300)		  	     // 距离小于30cm
	{
		direction = 0;    // 小车停止
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

void Ultrasonic(unsigned char* direction)	    //超声波
{	  		
	Timer1_Init();	 
	Trig=0;
	while(1)
	{	
//		start_measure();	//启动超声波
//    Echo = 0;
//		while(!Echo); 	//等待Echo回波引脚变高电平//////////////////////////////////////////////////////////////
//    TR2=1;	FM = 0;                          		//程序运行到此处时说明Echo脚变成了高电平，此时启动T0开始计时
//    while(Echo);		//等待Echo回波引脚高电平结束               
//    TR2=0;						//程序运行到此处时说明Echo脚变成了低电平，此时T0停止计�
//		
//	  *direction = distance_measure();
		
		  Echo=1;
	    start_measure();	//启动模块   
	    if(Echo==1)
			{
				 TR1=1;			    // 开启计数
				 while(Echo);		// 当Echo为1计数并等待
	       TR1=0;				  // 关闭计数
				 *direction = distance_measure();			  //计算
		   }		
	}
}