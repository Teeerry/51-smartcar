/**************************************************************************************
程序项目：运动层控制函数
主要内容：根据传感器数据，获得的移动命令，控制电机移动
作者：Terry
日期：2019-08-13
联系方式：terryluohello@qq.com
***************************************************************************************/
#include "motor.h"


/*******************************************************************************
* 函 数 名       : MovingControl
* 函数功能		   : 主函数
* 输    入       : 方向(方向前进1，后退2，左转3，右转4,停止（其他))
									 PWM 开启标志
									 PWM 计数器
                   PWM 设定的N 占空比N/20 //速度调节变量 0-20。。。0最小，20最大
* 输    出    	 : 移动的结果1或0 1代表成功移动
*******************************************************************************/
void MovingControl(bit pwm_on,unsigned char pwm_val, unsigned char pwm_n, unsigned char direction)
{
	if (pwm_on == 0) // 全速模式
	{
		EN1=1;
	  EN2=1; // 电机使能
	}
	
	else             // PWM调速模式
	{
		if(pwm_val <= pwm_n)
		{
			EN1=1; 
			EN2=1;
		}
	  else 
		{
	    EN1=0;
			EN2=0;
		}		 
	}
	
	if(direction == 1)
		forward();
	else if (direction == 2)
		back();
	else if (direction == 3)
		spin_left();
	else if (direction == 4)
		spin_right();
	else
		stop();
}

