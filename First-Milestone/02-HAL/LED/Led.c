#include "../../01-MCAL/GPIO/GPIO.c"
#include "../../01-MCAL/GPIO/GPIO.h"
#include "../../03-Service/TM4C123.h"
#include "Led.h"


/******* OPTION 1 *******/
	void led_Output(double distance){
	if (distance>100)
	{
		GPIO_PORTF_DATA_R&=~0x0E;
		GPIO_PORTF_DATA_R|=0x8;
	}
}
	
	
	
/******* OPTION 2 *******/
void led_Output2(void){
	
	unsigned char SW1_in;
	unsigned char SW2_in;
	
	SW1_in = GPIO_getSwitchesValue(GPIO_SW1);
	SW2_in = GPIO_getSwitchesValue(GPIO_SW2);
	if ( ((SW1_in & 0x01)==0x00 || (SW2_in & 0x01)==0x00) ) //check if SW1 or SW2 is  pressed turn Green LED on
		{
		GPIO_PORTF_DATA_R&=~0x0E;
		GPIO_PORTF_DATA_R|=0x8;
	}
}

/******* OPTION 3 *******/
void led_Output3(double destLat,double destLon,double latitude,double longitude){
	
	if ( ((destLat-latitude)/destLat) <0.1 && ((destLon-longitude)/destLon) <0.1 )
	{
		GPIO_PORTF_DATA_R&=~0x0E;
		GPIO_PORTF_DATA_R|=0x8;
	}
	
}
/******* OPTION 1+2 *******/
void led_Output4(double distance){
	unsigned char SW1_in;
	unsigned char SW2_in;
	
	SW1_in = GPIO_getSwitchesValue(GPIO_SW1);
	SW2_in = GPIO_getSwitchesValue(GPIO_SW2);
	if ( ((SW1_in & 0x01)==0x00 || (SW2_in & 0x01)==0x00) && ( distance>100 ) ) 
		{
		GPIO_PORTF_DATA_R&=~0x0E;
		GPIO_PORTF_DATA_R|=0x8;
	}
	
}

/******* OPTION 1+2+3 *******/

void led_Output5(double distance,double destLat,double destLon,double latitude,double longitude){
	
	unsigned char SW1_in;
	unsigned char SW2_in;
	
	SW1_in = GPIO_getSwitchesValue(GPIO_SW1);
	SW2_in = GPIO_getSwitchesValue(GPIO_SW2);
	
	if ( ((SW1_in & 0x01)==0x00 || (SW2_in & 0x01)==0x00) &&  (distance>100) && ( ((destLat-latitude)/destLat) <=0.1 && ((destLon-longitude)/destLon) <=0.1  ))
		{
		GPIO_PORTF_DATA_R&=~0x0E;
		GPIO_PORTF_DATA_R|=0x8;
	}
	
}  
