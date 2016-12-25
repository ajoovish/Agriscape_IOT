#include <avr/io.h>
#define F_CPU 16000000UL
#include<util/delay.h>
#include <inttypes.h>
#define Baud_Rate 1200UL

//This function is used to initialize the USART
//at a given UBRR value
void USARTInit(uint16_t ubrr_value)
{

   //Set Baud rate

   UBRRL = ubrr_value;
   UBRRH = (ubrr_value>>8);

   /*Set Frame Format


   >> Asynchronous mode
   >> No Parity
   >> 1 StopBit

   >> char size 8

   */

   UCSRC=(1<<URSEL)|(3<<UCSZ0);


   //Enable The receiver and transmitter

   UCSRB=(1<<RXEN)|(1<<TXEN);


}


//This function is used to read the available data
//from USART. This function will wait untill data is
//available.
char USARTReadChar()
{
   //Wait untill a data is available

   while(!(UCSRA & (1<<RXC)))
   {
      //Do nothing
   }

   //Now USART has got data from host
   //and is available is buffer

   return UDR;
}


//This fuction writes the given "data" to
//the USART which then transmit it via TX line
void USARTWriteChar(char data)
{

   //Wait untill the transmitter is ready

   while(!(UCSRA & (1<<UDRE)))
   {
    //Do nothing
   }

   //Now write the data to USART buffer

   UDR=data;
}

int main(void)
{
 
	  UCSRB|=1<<RXEN|1<<TXEN|1<<RXCIE;
  UCSRC|=1<<URSEL|1<<UCSZ0|1<<UCSZ1; 
  while(1)
  {
  _delay_ms(2000);
  USARTWriteChar("AT\r");
  _delay_ms(2000);
  USARTWriteChar("AT\r");
  _delay_ms(2000);
  USARTWriteChar("ATD+9757355696;\r");
  _delay_ms(20000);
  USARTWriteChar("ATH\r");
  }
   }
/*   void command(char*a)                   //function to send a string using pointers
{
  int i;
  for(i=0;a[i]!='\0';i++)
  {
    while(!(UCSRA&(1<<UDRE)));
    UDR=a[i];
    _delay_ms(100);
  }
}

*/

