#ifndef __BLUETOOTH_H__
#define __BLUETOOTH_H__

#include "bst_car.h"	 //����bst_car.h����С��ͷ�ļ�

// ����������ʽ $ģʽ-����-�ٶ�#
#define   telecontrol  '1'//ң��ģʽ
#define   infrared     '2'//����ģʽ
#define   wave         '3'//������ģʽ

#define 	forward_car '1'//����ǰ
#define 	back_car    '2'//������
#define 	left_car    '3'//������
#define 	right_car   '4'//������
#define 	stop_car    '0'//����ͣ

#define   follow				'4'//����
#define		v_f						'1'//�ٶȿ�
#define		v_m						'2'//�ٶ���
#define   v_s						'3'//�ٶ���

void BluetoothInit(void);
void PutString(unsigned char *TXStr);
void TeleControl(unsigned char* direction, unsigned char* inputString, unsigned char* newLineReceived);	
#endif