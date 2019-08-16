#ifndef __BLUETOOTH_H__
#define __BLUETOOTH_H__

#include "bst_car.h"	 //包含bst_car.h智能小车头文件

// 接受数据形式 $模式-方向-速度#
#define   telecontrol  '1'//遥控模式
#define   infrared     '2'//红外模式
#define   wave         '3'//超声波模式

#define 	forward_car '1'//按键前
#define 	back_car    '2'//按键后
#define 	left_car    '3'//按键左
#define 	right_car   '4'//按键右
#define 	stop_car    '0'//按键停

#define   follow				'4'//跟随
#define		v_f						'1'//速度快
#define		v_m						'2'//速度慢
#define   v_s						'3'//速度慢

void BluetoothInit(void);
void PutString(unsigned char *TXStr);
void TeleControl(unsigned char* direction, unsigned char* inputString, unsigned char* newLineReceived);	
#endif