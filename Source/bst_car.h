#ifndef __BSTCAR_H__
#define __BSTCAR_H__
/************BST-V51����С��ͷ�ļ�*************/
#include <reg52.h>	   //����52ϵͳͷ�ļ�

// ��������С������ģ������IO��
sbit IN1=P1^2; // �ߵ�ƽ1 ���ˣ���ת��
sbit IN2=P1^3; // �ߵ�ƽ1 ǰ������ת��

sbit IN3=P1^6; // �ߵ�ƽ1 ǰ������ת��	
sbit IN4=P1^7; // �ߵ�ƽ1 ���ˣ���ת��

sbit EN1=P1^4; // �ߵ�ƽʹ�� 
sbit EN2=P1^5; // �ߵ�ƽʹ�� 

// ���⴫��������
sbit infrared_right = P3^2;   
sbit infrared_left  = P3^3;

// ������ģ��
sbit Trig = P2^1;	   //������ģ��Trig	���ƶ�
sbit Echo = P2^0;	   //������ģ��Echo	���ն�


//���尴��
sbit K4=P3^7;

//�����������ڶ���
sbit FM=P2^3; 

void delay(unsigned int xms);
void Delay10us(unsigned char i);
#endif