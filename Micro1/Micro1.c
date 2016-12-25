#include <avr/io.h>
#include <util/delay.h>
#include "usart.h"


int main()
{
	unsigned int wl;
	//unsigned int x;
	DDRA=0X00;
	DDRB=0XFF;


	while(1)
	{
				
	if((PINA&0b00000100)==1)// Moisture Level High
	{
		PORTB=0X00;
		_delay_ms(500);
	}
	else if((PINA&0b00000100)==0)// Moisture Level Low
	{		
		PORTB= 0XFF;
		_delay_ms(500);
	}
	 }
 }

/*
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
 
 
 

*/
