#include<avr/io.h>
#include<util/delay.h>
void main()
{	
	DDRA=0X00;
	DDRB = 0XFF;
	while(1)
	{
		if((PINA&0b00000010)==0)
		{	
			PORTB = 0X0F;
			}
			else
			{
			 PORTB = 0XF0;
			 }
			 }
			 }
