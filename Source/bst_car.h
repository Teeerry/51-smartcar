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


//定义按键
sbit K4=P3^7;

//蜂鸣器驱动口定义
sbit FM=P2^3; 

void delay(unsigned int xms);
void Delay10us(unsigned char i);
#endif