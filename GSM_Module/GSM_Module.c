#include<avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>
int main()
{	
	gsm_init();
	notify();
	}
/***********************************************************/

/********************* UART FUNCTIONS **********************/

void UART_Init( unsigned int baud );
void UART_Transmit_char( unsigned char data );
unsigned char UART_Receive( void );
void UART_Transmit_string( char *string );

void UART_Init( unsigned int baud )
{
   /* Set baud rate */
   UBRRH = (unsigned char)(baud>>8);
   UBRRL = (unsigned char)baud;
   /* Enable receiver and transmitter */
   UCSRB = (1<<RXEN)|(1<<TXEN);
   /* Set frame format: 8data, 1stop bit */
   UCSRC = (1<<URSEL)|(0<<USBS)|(3<<UCSZ0);
}

void UART_Transmit_char( unsigned char data )
{
   /* Wait for empty transmit buffer */
   while ( !( UCSRA & (1<<UDRE)) )
   ;
   /* Put data into buffer, sends the data */
   UDR = data;
}

unsigned char UART_Receive( void )
{
   /* Wait for data to be received */
   while ( !(UCSRA & (1<<RXC)) )
   ;
   /* Get and return received data from buffer */
   return UDR;
}
void UART_Transmit_string( char string[] )
{
   int i=0;
   while ( string[i] > 0)
   UART_Transmit_char(string[i++]);
}

/*************************************************************/
void SendMsg(const char *msg)
{
while(*msg!='\0')
{
UART_Transmit_char(*msg);
msg++;
}
}


void Waiting(int j) // simple delay function
{
uint8_t i;
for(i=0;i<j;i++)
_delay_ms(200);
}
void notify()
{
DDRB=0XFF;
WriteString("AT+CMGF=1");
Waiting(1);
CMD("AT+CMGS=");
UART_Transmit_char(34);  // "
CMD("+918097921218"); // Replace the 'x's with a valid Phone number
UART_Transmit_char(34);
UART_Transmit_char('\0');
UART_Transmit_char(13); // <CR> OR \r
Waiting(1);
PORTB=0XF0;
CMD("Test Message");
UART_Transmit_char(26);  // CTRL+Z
Waiting(15);
}


void WriteString(const char *msg)
{
	while(*msg!='\0')
	{
	UART_Transmit_char(*msg);
	msg++;
	}
	UART_Transmit_char(13);
}
void CMD(const char *msg)
{
	while(*msg!='\0')
	{
	UART_Transmit_char(*msg);
	msg++;
	}
}
void gsm_init()
{	
	DDRB=0X0F;	
	UART_Init(71);
	_delay_ms(500);
	UART_Transmit_char("AT\r");
	_delay_ms(1000);
	PORTB= 0X03;
}
