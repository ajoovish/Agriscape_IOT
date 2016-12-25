#include<avr/io.h>
#include<util/delay.h>
void main()
{
	DDRB=0XFF;
	DDRA= 0X00;
	while(1)
	{
		if((PINA & 0b11111111)==1)
		{
			PORTB= 0X0F;
		
			}
			else
			{
			PORTB = 0XF0;
			}
				_delay_ms(5000);
		
		}
}

