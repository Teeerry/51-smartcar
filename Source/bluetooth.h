#ifndef __BLUETOOTH_H__
#define __BLUETOOTH_H__

#include "bst_car.h"	 //����bst_car.h����С��ͷ�ļ�

void BluetoothInit(void);
void PutString(unsigned char *TXStr);
void TeleControl(unsigned char* mode, unsigned char* direction, unsigned char* inputString, unsigned char* newLineReceived);	
#endif