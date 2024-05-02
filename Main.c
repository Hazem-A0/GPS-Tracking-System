	#include "03-Service/bit_utilies.h"
	#include "01-MCAL/GPIO/GPIO.h"
	#include "02-HAL/LED/LED.h"
	#include "02-HAL/LED/LED.c"
  #include "TM4C123GH6PM.h"
	#include "01-MCAL/UART/UART.h"
	#include "01-MCAL/UART/UART.c"
	
	
	int main(){
		double distance=500.56;   //passed distance for testing
		UART_Init();
		GPIO_initPortf();

		while(1){
			led_Output(distance); // Green Led is turned on when passed distance >100 
      
      /* there are other functions implemented in Led.c for the other options for example  led_Output4(distance) turn the green Led when distance is greater
      than 100 and the button is pressed */
		}
	}
	
