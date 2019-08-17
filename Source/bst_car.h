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
sbit infrared_bottom_right = P3^2;   
sbit infrared_bottom_left  = P3^3;

// ���Ϻ��ⶨ��  
sbit infrared_top_left  = P3^4;	   //����Ϻ��⴫����  
sbit infrared_top_right = P3^5;	   //�ұ��Ϻ��⴫���� 

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
#define   follow       '4'//����ģʽ

#define 	forward_car '1'//����ǰ
#define 	back_car    '2'//������
#define 	left_car    '3'//������
#define 	right_car   '4'//������
#define 	stop_car    '0'//����ͣ

#define   follow				'4'//����
#define		v_f						'3'//�ٶȿ�
#define		v_m						'2'//�ٶ���
#define   v_s						'1'//�ٶ���

void buzzer(void);               // ��������ʾ
void delay(unsigned int xms);
void Delay10us(unsigned char i);
#endif