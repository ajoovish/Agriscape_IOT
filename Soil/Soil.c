#include<avr/io.h>
#include<util/delay.h>
int main(void)
{

	DDRA=0x00;
	DDRB=0xFF;
	while(1)
	{
		
		if((PINA&0b00000001)==1)
		{	
			PORTB = 0X01;
		
		}
		else
		{	
		PORTB= 0X10;
		}
	}
}
