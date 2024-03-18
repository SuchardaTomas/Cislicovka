/*
 * Timer.c
 *
 * Created: 11.03.2024 14:03:44
 * Author : tomas.sucharda
 * co to dela: timer
 */ 

#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

uint8_t tis = 0;
uint8_t des = 0;
uint8_t sec = 0;

#define num0 0b01111110
#define num1 0b01001000
#define num2 0b00111101
#define num3 0b01101101
#define num4 0b01001011
#define num5 0b01100111
#define num6 0b01110111
#define num7 0b01001100
#define num8 0b01111111
#define num9 0b01101111


void cislo(uint8_t znak) {
	switch (znak){
		case 0: PORTB = num0; break;
		case 1: PORTB = num1; break;
		case 2: PORTB = num2; break;
		case 3: PORTB = num3; break;
		case 4: PORTB = num4; break;
		case 5: PORTB = num5; break;
		case 6: PORTB = num6; break;
		case 7: PORTB = num7; break;
		case 8: PORTB = num8; break;
		case 9: PORTB = num9; break;
	}
}

int main(void) {

	DDRB=0xFF;
	DDRC|= (1<<PORTC2)|(1<<PORTC3);
	TCCR2|=(1<<WGM21)|(1<<CS21);
	OCR2=125-1;
	TIMSK|=(1<<OCIE2);
	sei();
	
	DDRC=0b01111111;
	while(1)
	{
		for (int i = 0; i < 60; i++)
		{
			DDRC=0b00001000;
			cislo(sec/10);
			_delay_ms(10);
			DDRC=0b00000100;
			cislo(sec%10);
			_delay_ms(10);
		}
	}
}

ISR(TIMER2_COMP_vect) {
	tis++;
	if(tis==100) {
		des++;
		tis=0;
	}
	if(des==10) {
		sec++;
		des=0;
	}
	if (sec==60) {
		sec=0;
	}
}

