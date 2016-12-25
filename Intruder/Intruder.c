#include<avr/io.h>
#include<util/delay.h>
void ADC_init(void);
unsigned int ADC_read(unsigned char);
void intruder();
int main()
{
	DDRA=0X00;
	DDRB=0XFF;
	unsigned int a;
	ADC_init();
	while(1)
	{
		a = ADC_read(3);
	
		if((PINA&0b00000010)== 0)
		{
			PORTB = 0X08;
				}
		else
		{
			if(a<512)
			{
				PORTB=0X0F;
			}

			else 
			{
				PORTB= 0XF0;
			}
			_delay_ms(1000);
		}
	}

}
void ADC_init() // Initialization of ADC
{
ADMUX|=(1<<REFS1)|(1<<REFS0);; // AVcc with external capacitor at AREF
ADCSRA=(1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0); 
// Enable ADC and set Prescaler division factor as 128
}
 
unsigned int ADC_read(unsigned char ch)
{
ch= ch & 0b00000111; // channel must be b/w 0 to 7
ADMUX |= ch; // selecting channel
 
ADCSRA|=(1<<ADSC); // start conversion
while(!(ADCSRA & (1<<ADIF))); // waiting for ADIF, conversion complete
ADCSRA|=(1<<ADIF); // clearing of ADIF, it is done by writing 1 to it
 
return (ADC);
}
 
 
