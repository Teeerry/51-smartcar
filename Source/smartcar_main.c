/**************************************************************************************
实验项目：智能小车主程序
作者：Terry
日期：2019-08-13
联系方式：terryluohello@qq.com
***************************************************************************************/
		 
#include "motor.h"
#include "infrared.h"
#include "US_015.h"
#include "bluetooth.h"

unsigned char pwm_val = 0; // PWM
unsigned char direction = 0; // 小车移动方向，默认停止


bit startBit = 0;  				//串口接收开始标志位
unsigned char newLineReceived = 0; 	//串口一帧协议包接收完成
unsigned char inputString[50];  //接收数据协议


void main()
{
	direction = 1; // 初始移动方向
	// 设置定时器
	TMOD |=0X01;
  TH0= 0XFC;  //1ms定时
  TL0= 0X66;
  TR0= 1;
  ET0= 1;
	EA = 1;	    //开总中断
	BluetoothInit();
	while(1)
	{			

		FM = 0;
	  delay(100);
	  FM = 1;
	  delay(1000);
		
    Ultrasonic(&direction);		// 超声波避障
//		direction = InfraredTracking(); // 红外循迹
//		MovingControl(0, pwm_val, 5, direction);    // PWM控制
//		TeleControl(&direction, inputString, &newLineReceived);
	}	
}



/******************************************************************/
/* TIMER0中断服务子函数产生PWM信号*/
/******************************************************************/
void Timer0() interrupt 1 using 2
{
   TH0=0XFC;	  //1Ms定时
	 TL0=0X66;
	 pwm_val++;
	 MovingControl(1, pwm_val, 5, direction);    // PWM控制
	 if(pwm_val >= 20)
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


//void timer2()  interrupt 5	 //定时器2
//{
//	 TF2 = 0;
//   TH2 = 0;	  //1Ms定时
//	 TL2 = 0;
//}
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

	    if(n == '$')
	    {
	      startBit = 1;
		  num = 0;
	    }
	    if(startBit == 1)
	    {
	       inputString[num] = n;     
	    }  
	    if (n == '#') 
	    {
	       newLineReceived = 1; 
	       startBit = 0;
	    }
		num++;
		if(num >= 50)
		{
			num = 0;
			startBit = 0;
			newLineReceived	= 0;
		}
	}

}