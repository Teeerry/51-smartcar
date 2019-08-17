/**************************************************************************************
实验项目：智能小车主程序
作者：Terry
日期：2019-08-17
联系方式：terryluohello@qq.com
***************************************************************************************/
		 
#include "motor.h"				// 电机头文件
#include "infrared.h"			// 红外头文件
#include "US_015.h"				// 超声波头文件
#include "bluetooth.h"		// 蓝牙头文件

bit startBit = 0;  				          // 串口接收开始标志位
unsigned char newLineReceived = 0; 	// 串口一帧协议包接收完成
unsigned char inputString[50];      // 接收数据协议
unsigned char direction = 0;        // 小车移动方向，默认停止
unsigned char pwm_val = 0;          // PWM计数
unsigned char mode = telecontrol;   // 当前工作模式
unsigned char speed_left = 10, speed_right = 10; // 调节左右PWM


/******************************************************************/
/* 主程序*/
/******************************************************************/
void main()
{
	// 设置定时器
	TMOD |=0X01;
  TH0= 0XFC;  //1ms定时
  TL0= 0X66;
  TR0= 1;
  ET0= 1;
	EA = 1;	    //开总中断
	BluetoothInit();
	
	FM = 0;           // 蜂鸣器提示
	delay(100);
	FM = 1;
	while(1)
	{					
		direction = 1;  // 初始移动方向		
//		mode = inputString[1];
		switch(mode)
			{
				case telecontrol: P1=P1<<1; TeleControl(&mode, &direction, inputString, &newLineReceived); break; // 蓝牙遥控
				case infrared:    P1=P1<<2; InfraredTracking(&mode, &direction); break; // 红外循迹
				case wave:        P1=P1<<3; Ultrasonic(&mode, &direction); break;       // 超声波避障
				default:          P1=P1<<6; TeleControl(&mode, &direction, inputString, &newLineReceived); break; // 蓝牙遥控
			}
			
	}	
}



/******************************************************************/
/* TIMER0中断服务子函数产生PWM信号*/
/******************************************************************/
void Timer0() interrupt 1 using 2
{
   TH0=0XFC;	  // 1Ms定时
	 TL0=0X66;
	 pwm_val++;   // PWM计数加一
	 MovingControl(1, pwm_val, speed_left, speed_right, direction); // PWM控制
	 if(pwm_val >= 50) // 更新PWM计数通过speed_left/50，speed_right/50 分别控制左右速度 
	 {
		 pwm_val = 0;
	 }
}	


/******************************************************************/
/* 超声波T2定时器中断服务*/
/******************************************************************/
void Timer2(void) interrupt 5
{
	TF2  = 0;
	Echo = 0;
}

/******************************************************************/
/* 串口中断程序*/
/******************************************************************/
void UART_SER () interrupt 4
{
	unsigned char n; 	//定义临时变量
	static int num = 0;

	if(RI) 		//判断是接收中断产生
	{
		RI = 0; 	//标志位清零
		n = SBUF; //读入缓冲区的值

	  if(n == '$')  // 数据起始位
			{
	      startBit = 1;
		    num = 0;
	    }
			
		if(startBit == 1)
	    {
	       inputString[num] = n;     
	    }
			
	  if (n == '#') // 数据结束位
	    {
	       newLineReceived = 1; 
	       startBit = 0;
	    }
			
		num++;
//		if(num >= 50)
//		{
//			num = 0;
//			startBit = 0;
//			newLineReceived	= 0;
//		}
		
		switch(inputString[3])  // 更新电机转速
			{
				case v_f:  speed_left = 25; speed_right = 22; break; // 快速
				case v_m:  speed_left = 12; speed_right = 14; break; // 中速
				case v_s:  speed_left = 8;  speed_right = 9;  break; // 慢速
				default:   speed_left = 12; speed_right = 14; break; // 中速
			}
		mode = inputString[1];  // 及时更新工作模式
	}

}