#ifndef __BSTCAR_H__
#define __BSTCAR_H__
/************BST-V51智能小车头文件*************/
#include <reg52.h>	   //包含52系统头文件

// 定义智能小车驱动模块输入IO口
sbit IN1=P1^2; // 高电平1 后退（反转）
sbit IN2=P1^3; // 高电平1 前进（正转）

sbit IN3=P1^6; // 高电平1 前进（正转）	
sbit IN4=P1^7; // 高电平1 后退（反转）

sbit EN1=P1^4; // 高电平使能 
sbit EN2=P1^5; // 高电平使能 

// 红外传感器声明
sbit infrared_right = P3^2;   
sbit infrared_left  = P3^3;

// 超声波模块
sbit Trig = P2^1;	   //超声波模块Trig	控制端
sbit Echo = P2^0;	   //超声波模块Echo	接收端


// 定义按键
sbit K4=P3^7;

// 蜂鸣器驱动口定义
sbit FM=P2^3; 

// 蓝牙接受数据形式 $模式-方向-速度#
#define   telecontrol  '1'//遥控模式
#define   infrared     '2'//红外模式
#define   wave         '3'//超声波模式

#define 	forward_car '1'//按键前
#define 	back_car    '2'//按键后
#define 	left_car    '3'//按键左
#define 	right_car   '4'//按键右
#define 	stop_car    '0'//按键停

#define   follow				'4'//跟随
#define		v_f						'3'//速度快
#define		v_m						'2'//速度慢
#define   v_s						'1'//速度慢

void delay(unsigned int xms);
void Delay10us(unsigned char i);
#endif