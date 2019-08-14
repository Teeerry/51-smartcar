/**************************************************************************************
ÊµÑéÏîÄ¿£º³¬Éù²¨Ä£¿é
×÷Õß£ºTerry
ÈÕÆÚ£º2019-08-14
ÁªÏµ·½Ê½£ºterryluohello@qq.com
***************************************************************************************/
#include"US_015.h"
#include <intrins.h>   //°üº¬nopµÈÏµÍ³º¯Êı

// 10usÑÓÊ±º¯Êı Æô¶¯³¬Éù²¨Ä£¿éÊ±Ê¹ÓÃ
void Delay10us(unsigned char i)    	
{ 
   unsigned char j;
	do
	{ 
		j = 10; 
		do
		{ 
			_nop_(); 
		}while(--j); 
	}while(--i); 
}  

// ¶¨Ê±Æ÷1³õÊ¼»¯
void Timer1_Init()
{
	TH1 = 0;
	TL1 = 0;
}
 
//²â¾àº¯Êı£¬·µ»Ø¾àÀëÊıÖµ
unsigned char distance_measure()		 		
{
	unsigned char direction = 1; // Ğ¡³µÄ¬ÈÏÒÆ¶¯·½Ïò
	unsigned int time = 0; 	     // Ê±¼ä±äÁ¿
	float distance = 0; 		     // ÕÏ°­Îï¾àÀë±äÁ¿
	
	time=TH1*256+TL1;				     // ¼ÆËãÊ±¼ä
	TH1=0;
	TL1=0;
	
	distance =(time*1.7)/10+10;  // Ëã³öÀ´ÊÇMM
	if(distance<300)		  	     // ¾àÀëĞ¡ÓÚ30cm
	{
		direction = 0;    // Ğ¡³µÍ£Ö¹
	}
	else
		direction = 1;
	
	return direction;
} 

void start_measure()	// TrigÊä³ö¸ßµçÆ½´¥·¢²â¾à
{
	Trig=1;    
	Delay10us(2);	
  Trig=0;
}

void Ultrasonic(unsigned char* direction)	    //³¬Éù²¨
{	  		
	Timer1_Init();	 
	Trig=0;
	while(1)
	{	
//		start_measure();	//Æô¶¯³¬Éù²¨
//    Echo = 0;
//		while(!Echo); 	//µÈ´ıEcho»Ø²¨Òı½Å±ä¸ßµçÆ½//////////////////////////////////////////////////////////////
//    TR2=1;	FM = 0;                          		//³ÌĞòÔËĞĞµ½´Ë´¦Ê±ËµÃ÷Echo½Å±ä³ÉÁË¸ßµçÆ½£¬´ËÊ±Æô¶¯T0¿ªÊ¼¼ÆÊ±
//    while(Echo);		//µÈ´ıEcho»Ø²¨Òı½Å¸ßµçÆ½½áÊø               
//    TR2=0;						//³ÌĞòÔËĞĞµ½´Ë´¦Ê±ËµÃ÷Echo½Å±ä³ÉÁËµÍµçÆ½£¬´ËÊ±T0Í£Ö¹¼ÆÊ
//		
//	  *direction = distance_measure();
		
		  Echo=1;
	    start_measure();	//Æô¶¯Ä£¿é   
	    if(Echo==1)
			{
				 TR1=1;			    // ¿ªÆô¼ÆÊı
				 while(Echo);		// µ±EchoÎª1¼ÆÊı²¢µÈ´ı
	       TR1=0;				  // ¹Ø±Õ¼ÆÊı
				 *direction = distance_measure();			  //¼ÆËã
		   }		
	}
}