/*
 * GccApplication1.c
 *
 * Created: 04.12.2023 13:31:53
 * Author : tomas.sucharda
 * Co to dela: čas
 */ 
#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>

#define num0 0b01111110;
#define num1 0b01001000;
#define num2 0b00111101;
#define num3 0b01101101;
#define num4 0b01001011;
#define num5 0b01100111;
#define num6 0b01110111;
#define num7 0b01001100;
#define num8 0b01111111;
#define num9 0b01101111;     


void cislo(uint8_t znak) {
	switch (znak){
		case 0: PORTA = num0; break;
		case 1: PORTA = num1; break;
		case 2: PORTA = num2; break;
		case 3: PORTA = num3; break;
		case 4: PORTA = num4; break;
		case 5: PORTA = num5; break;
		case 6: PORTA = num6; break;
		case 7: PORTA = num7; break;
		case 8: PORTA = num8; break;
		case 9: PORTA = num9; break;
	}
}


int main(void)
{
	DDRA=0b01111111;
	int sec = 0;
	int min = 0;
	while(1)
	{
		for (int i = 0; i < 60; i++)
		{
			DDRC=0b00000001;
			cislo(sec % 10);
			_delay_ms(4);
			DDRC=0b00000010;
			cislo(sec / 10);
			_delay_ms(4);
			DDRC=0b00000100;
			cislo(min % 10);
			_delay_ms(4);
			DDRC=0b00001000;
			cislo(min / 10);
			_delay_ms(4);
		}
		
		if (sec % 59 == 0 && sec != 0) { 
			sec = 0;min++; 
		}
		sec++;
	}
}
