/**************************************************************************************
������Ŀ���˶�����ƺ���
��Ҫ���ݣ����ݴ��������ݣ���õ��ƶ�������Ƶ���ƶ�
���ߣ�Terry
���ڣ�2019-08-13
��ϵ��ʽ��terryluohello@qq.com
***************************************************************************************/
#include "motor.h"


/*******************************************************************************
* �� �� ��       : MovingControl
* ��������		   : �������������
* ��    ��       : pwm_on��PWM������־
									 pwm_val��PWM ������
                   pwm_n_left������ռ�ձ�
									 pwm_n_right����·ռ�ձ�
									 direction������(����ǰ��1������2����ת3����ת4,ֹͣ������))
* ��    ��    	 : ��
*******************************************************************************/
void MovingControl(bit pwm_on,unsigned char pwm_val, unsigned char pwm_n_left, unsigned char pwm_n_right, unsigned char direction)
{
	int pwm_left = pwm_n_left, pwm_right = pwm_n_right;
	// �������
	if(direction == 1)
	{
		forward();
	}
	else if (direction == 2)
	{
		back();
	}
	else if (direction == 3)   // ���ٶ�ת��
	{
		spin_left();
		pwm_left = 8;
		pwm_right = 9;
	}
	else if (direction == 4)   // ���ٶ�ת��
	{
		spin_right();
		pwm_left = 8;
		pwm_right = 9;
	}
	else
		stop();
	
	// PWM����
	if (pwm_on == 0) // ȫ��ģʽ
	{
		EN1=1;
	  EN2=1; // ���ʹ��
	}
	
	else             // PWM����ģʽ
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

