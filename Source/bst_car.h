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


// ���尴��
sbit K4=P3^7;

// �����������ڶ���
sbit FM=P2^3; 

// ��������������ʽ $ģʽ-����-�ٶ�#
#define   telecontrol  '1'//ң��ģʽ
#define   infrared     '2'//����ģʽ
#define   wave         '3'//������ģʽ

#define 	forward_car '1'//����ǰ
#define 	back_car    '2'//������
#define 	left_car    '3'//������
#define 	right_car   '4'//������
#define 	stop_car    '0'//����ͣ

#define   follow				'4'//����
#define		v_f						'3'//�ٶȿ�
#define		v_m						'2'//�ٶ���
#define   v_s						'1'//�ٶ���

void delay(unsigned int xms);
void Delay10us(unsigned char i);
#endif