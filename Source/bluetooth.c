/**************************************************************************************
ʵ����Ŀ������ģ��
���ߣ�Terry
���ڣ�2019-08-16
��ϵ��ʽ��terryluohello@qq.com
***************************************************************************************/	

#include "bluetooth.h"	 //����bst_car.h����С��ͷ�ļ�
#include <string.h>

//������
void TeleControl(unsigned char* mode, unsigned char* direction, unsigned char* inputString, unsigned char* newLineReceived)
{	
	while(*mode == telecontrol)	//����ѭ��
	{ 
		if (*newLineReceived)
			{
				P1=0Xfe;
			switch(*(inputString+2))
			{
				case forward_car:P1=P1<<1; *direction = 1;break;
				case back_car:   P1=P1<<2; *direction = 2;break;
				case left_car:   P1=P1<<3; *direction = 3;break;
				case right_car:  P1=P1<<4; *direction = 4;break;
				case stop_car:   P1=P1<<5; *direction = 0;break;
				default:         P1=P1<<6; *direction = 1;break;
			}

	     PutString(inputString); //����Э�����ݰ�            
	     *newLineReceived = 0;  
		   memset(inputString, 0x00, sizeof(inputString));  
	 
	    }	 
	 }
}


// ������ʼ��
void BluetoothInit(void)
{
  SCON = 0x50; 	// SCON: ģʽ1, 8-bit UART, ʹ�ܽ���
	TMOD |= 0x20;
	TH1 =0xfd; 		//������9600 ��ֵ
	TL1 =0xfd;
	TR1 = 1;
	EA = 1;	    	//�����ж�
	ES = 1; 			//�򿪴����ж�
}


//���ڷ��ͺ���
void PutString(unsigned char *TXStr)  
{                
	ES=0;     
	while(*TXStr!=0) 
	{                      
	  SBUF=*TXStr;
	  while(TI==0);
	  TI=0;    
	  TXStr++;
	}
	ES=1; 
} 

