#include "APP.h"
#include <math.h>
#include <stdlib.h>
void SystemInit(){}
//#include "driverlib/sysctl.h"

int main(){
	char displacement_display[20];
	char lat_display[20];
	char lon_display[20];
char k;
char lat[20] = {0};
char log[20] = {0};	
double latitude_2=30.0639317	;
double logitude_2=31.2804318;
double displacement;
double latDM;
double lonDMM;
double latDD;
double lonDD;
//this function is called to set the clock of the tiva to 16MHZ
//SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC | SYSCTL_OSC_INT | SYSCTL_MAIN_OSC_DIS);
UART0_Init(  9600 );	
UART5_Init(  9600 ); 
UART7_Init(  9600 ); 
LED_init();
//printstring("distance to Target: \n");

while(1){ 

readGPS(lat,log);
latDM =ConvertToDouble(lat);
lonDMM =ConvertToDouble(log);
latDD = convertDMtoDD(latDM);
lonDD = convertDMMtoDD(lonDMM);
displacement = calculateDistance(latDD, lonDD, latitude_2, logitude_2);   
	

	

if(displacement>=20)
{
		LED_ON('r');
	LED_OFF('g');
	LED_OFF('b');
}
else if(displacement<20 && displacement>10)
{
		LED_OFF('r');
	LED_OFF('g');
		LED_ON('b');
}
else
{	
	LED_OFF('r');
	LED_OFF('b');
		LED_ON('g');	
	break;
}	
UART0_StringTX("displacement is: \n");
sprintf(displacement_display, "%f", displacement);
UART0_StringTX("\r \n ");
UART0_StringTX(displacement_display);
UART0_StringTX("\n ");
	
	UART0_StringTX("Latitude is: \n");
sprintf(lat_display, "%f", latDD);
UART0_StringTX("\r \n ");
UART0_StringTX(lat_display);
UART0_StringTX("\n ");
	
	UART0_StringTX("Longitude is: \n");
sprintf(lon_display, "%f", lonDD);
UART0_StringTX("\r \n ");
UART0_StringTX(lon_display);
UART0_StringTX("\n ");

delay_s();
delay_s();
delay_s();
delay_s();
delay_s();


    }	
UART0_StringTX("Destination reached");
		
}
