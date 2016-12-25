#include<avr/io.h>
#include<util/delay.h>
int main(void);

int main(void)
{
	DDRC = 0XFF;
	while(1)
	{
		PORTC=0X0F;
		_delay_ms(500);
	}
	}
