/*
 * GccApplication3.c
 *
 * Created: 26.02.2024 13:40:11
 * Author : tomas.sucharda
 * co to dela: smajlík :)
 */ 

#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRA=0b11111111;
	DDRC=0b11111111;
	
	while (1)
	{
		PORTA=0b00000010;
		PORTC=0b11011011;
		
		PORTA=0b00000100;
		PORTC=0b11011011;
		
		PORTA=0b00001000;
		PORTC=0b11011011;
		
		PORTA=0b00100000;
		PORTC=0b10111101;
		
		PORTA=0b01000000;
		PORTC=0b11000011;
	}
}