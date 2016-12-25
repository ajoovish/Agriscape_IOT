#include <avr/io.h>
#include <util/delay.h>
#include "usart.h"


int main(void)
{
	DDRA=0X00;
	DDRB=0XFF;


	while(1)
	{
				
	if((PINA&0b00000100)==0)// Moisture Level High
	{
		PORTB=0X00;
		_delay_ms(500);
	}
	else if((PINA&0b00000100)==1)// Moisture Level Low
	{		
		PORTB= 0X0F;
		_delay_ms(500);
	}
	 }
 }
