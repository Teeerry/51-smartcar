/**************************************************************************************
实验项目：智能小车
作者：Terry
日期：2019-08-16
联系方式：terryluohello@qq.com
***************************************************************************************/	

#include "bst_car.h"	 //包含bst_car.h智能小车头文件
#include <intrins.h>   //包含nop等系统函数

//延时函数	
void delay(unsigned int xms)				
{
    unsigned int i,j;
	for(i=xms;i>0;i--)		      //i=xms即延时约xms毫秒
    for(j=112;j>0;j--);
}

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