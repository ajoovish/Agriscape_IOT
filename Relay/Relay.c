#include<avr/io.h>
#include<util/delay.h>
int main()
{
	DDRC=0XFF;
	DDRB=0XFF;
	while(1)
	{
		PORTC= 0XFF;
		PORTB= 0X01;
		_delay_ms(10000);
		
		PORTC= 0X00;
		PORTB= 0X00;
		_delay_ms(10000);	
	}
}
