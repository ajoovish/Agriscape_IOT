 
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
 
#define BAUD 9600                                                       // define baud
#define BAUDRATE ((F_CPU)/(BAUD*16UL)-1)        // set baudrate value for UBRR
 
#ifndef F_CPU
#define F_CPU 16000000UL                                        // set the CPU clock
#endif
 
// function to initialize UART
void uart_init (void)
{
        UBRRH=(BAUDRATE>>8);
        UBRRL=BAUDRATE;                                                 //set baud rate
        UCSRB|=(1<<TXEN)|(1<<RXEN);                     //enable receiver and transmitter
        UCSRC|=(1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);// 8bit data format
}
 
// function to send data - NOT REQUIRED FOR THIS PROGRAM IMPLEMENTATION
void uart_transmit (unsigned char data)
{
        while (!( UCSRA & (1<<UDRE)));                  // wait while register is free
        UDR = data;                                                     // load data in the register
}
 
// function to receive data
unsigned char uart_recieve (void)
{
        while(!(UCSRA) & (1<<RXC));                     // wait while data is being received
        return UDR;                                                     // return 8-bit data
}
 
// main function: entry point of program
int main (void)
{
        unsigned char a;
        char buffer[10];
 
        uart_init();                                                    // initialize UART
        
        while(1)
        {
			uart_transmit('a1b0c2d3g40g5039c');
			uart_transmit(0x0d);
        }
       
        return 0;
}
