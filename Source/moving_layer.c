/**************************************************************************************
程序项目：运动层控制函数
主要内容：根据传感器数据，获得的移动命令，控制电机移动
作者：Terry Billy
日期：2019-08-18
联系方式：terryluohello@qq.com 2228238121@qq.com
***************************************************************************************/	

#include "motor.h"


/*******************************************************************************
* 函 数 名       : MovingControl
* 函数功能		   : 电机控制主函数
* 输    入       : pwm_on：PWM开启标志
									 pwm_val：PWM 计数器
                   pwm_n_left：左轮占空比
									 pwm_n_right：右路占空比
									 direction：方向(方向前进1，后退2，左转3，右转4,停止（其他))
* 输    出    	 : 无
*******************************************************************************/
void MovingControl(bit pwm_on,unsigned char pwm_val, unsigned char pwm_n_left, unsigned char pwm_n_right, unsigned char direction)
{
	unsigned char pwm_left = pwm_n_left, pwm_right = pwm_n_right;
	// 方向控制
	if(direction == 1)
	{
		forward();
	}
	else if (direction == 2)
	{
		back();
	}
	else if (direction == 3)   // 低速度前左转弯
	{
		spin_left();
		pwm_left = 13;
		pwm_right = 13;
	}
	else if (direction == 4)   // 低速度前右转弯
	{
		spin_right();
		pwm_left = 13;
		pwm_right = 13;
	}
	else if (direction == 5)   // 低速度后左转弯
	{
		spin_back_left();
		pwm_left = 12;
		pwm_right = 14;
	}
	else if (direction == 6)   // 低速度后右转弯
	{
		spin_back_right();
		pwm_left = 14;
		pwm_right = 12;
	}
	else
		stop();
	
	// PWM控制
	if (pwm_on == 0) // 全速模式
	{
		EN1=1;
	  EN2=1; // 电机使能
	}
	
	else             // PWM调速模式
	{
		if(pwm_val < pwm_left)   // motor left
		{
			EN1=1;
		}
	  else 
		{
	    EN1=0;
		}	
		
		if(pwm_val < pwm_right)  // motor right
		{
			EN2=1;
		}
	  else 
		{
			EN2=0;
		}		 
	}
	
}

