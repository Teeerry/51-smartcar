/**************************************************************************************
实验项目：蓝牙模块
作者：Terry
日期：2019-08-16
联系方式：terryluohello@qq.com
***************************************************************************************/	

#include "bluetooth.h"	 //包含bst_car.h智能小车头文件
#include <string.h>

//主函数
void TeleControl(unsigned char* mode, unsigned char* direction, unsigned char* inputString, unsigned char* newLineReceived)
{	
	while(*mode == telecontrol)	//无限循环
	{ 
		if (*newLineReceived)
			{
				P1=0Xfe;
			switch(*(inputString+2))
			{
				case forward_car:P1=P1<<1; *direction = 1;break;
				case back_car:   P1=P1<<2; *direction = 2;break;
				case left_car:   P1=P1<<3; *direction = 3;break;
				case right_car:  P1=P1<<4; *direction = 4;break;
				case stop_car:   P1=P1<<5; *direction = 0;break;
				default:         P1=P1<<6; *direction = 1;break;
			}

	     PutString(inputString); //返回协议数据包            
	     *newLineReceived = 0;  
		   memset(inputString, 0x00, sizeof(inputString));  
	 
	    }	 
	 }
}


// 蓝牙初始化
void BluetoothInit(void)
{
  SCON = 0x50; 	// SCON: 模式1, 8-bit UART, 使能接收
	TMOD |= 0x20;
	TH1 =0xfd; 		//波特率9600 初值
	TL1 =0xfd;
	TR1 = 1;
	EA = 1;	    	//开总中断
	ES = 1; 			//打开串口中断
}


//串口发送函数
void PutString(unsigned char *TXStr)  
{                
	ES=0;     
	while(*TXStr!=0) 
	{                      
	  SBUF=*TXStr;
	  while(TI==0);
	  TI=0;    
	  TXStr++;
	}
	ES=1; 
} 

