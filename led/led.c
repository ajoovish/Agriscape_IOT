#include<avr/io.h>
#include<util/delay.h>
int main()
{	
	DDRB=0XFF;
while(1)
{
	PORTB = 0b00000001;
	_delay_ms(100);
	PORTB= 0b00000010;
	_delay_ms(100);
}
}
