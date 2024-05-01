#include "..\..\03-Service\TM4C123.h" 
#include <string.h>
#include <stdint.h>



void UART_Init(void){
	SYSCTL_RCGCUART_R |= 0x0001; // activate clock of uart
	while((SYSCTL_RCGCUART_R & 0x01 )==0); // wait
	SYSCTL_RCGCGPIO_R|=0x0001;
	while((SYSCTL_PRGPIO_R & 0x01 )==0); //make sure that clock of port A is enabled 
	UART0_CTL_R &= ~ 0x0001;   //disable for configuration
	UART0_IBRD_R =  0x68;
	UART0_FBRD_R =  0xB;  // baud rate = 9600
	UART0_LCRH_R =  0x70; // 8 bit word length and enable fifo
	UART0_CTL_R =  0x0301;  //enable rxe , txe and uart
	GPIO_PORTA_LOCK_R= GPIO_LOCK_KEY;
	GPIO_PORTA_CR_R |=0x03; // allow changes to pins 0,1 for port A
	GPIO_PORTA_AFSEL_R |= 0x03;  //alternating function on 
	GPIO_PORTA_PCTL_R = (GPIO_PORTA_PCTL_R&0xFFFFFF00)+0x00000011;  // pin0(RX),1(TX)
	GPIO_PORTA_DIR_R |= 0x02; // enable pin0 input,1 output 
	GPIO_PORTA_DEN_R |= 0x03;  // enable pin0,1 to be digital
	GPIO_PORTA_AMSEL_R &=~ 0x03;  // disable anlog 
}

void UART_output_char (char data)
{
	while((UART0_FR_R & 0x20)!=0);
	UART0_DR_R = data;
}	

// read UART data
char UART_GetChar(void)
{
	while((UART0_FR_R&0x10)!=0);
	return (char)UART0_DR_R&0xFF;
	
}

void UART_OutString( const char *pt)
{
	while(*pt)
	{
		UART_output_char(*pt);
	pt++;
	}
}
// CHECK IF THERE IS CHAR RECIEVED 
char UART_IsCharAvail () { 
return((UART0_FR_R&0x10)==0x10); 
}



