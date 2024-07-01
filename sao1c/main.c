/*
 * sao1c.c
 *
 * Created: 30.06.2024 14:11:36
 * Author : luni
 */ 

#define F_CPU 8000000L
#include <avr/io.h>
//#include <avr/interrupt.h>
#include <util/delay.h>

// ISR(TIM0_OVF_vect){

// }

#include "writeRGB8.h"

const uint32_t text[5][4] = {
{0b01000010, 0b00100010, 0b00000000, 0b00001000},
{0b00000010, 0b00101111, 0b00000000, 0b00000000},
{0b01001110, 0b00100010, 0b10010010, 0b00001001},
{0b01010010, 0b00100010, 0b01010010, 0b00001010},
{0b01001100, 0b11001100, 0b01001100, 0b00001010},};

uint8_t frame[25];

const uint8_t map[5][8] = {
	{24,23,22,21,20,0,0,0},
	{15,16,17,18,19,0,0,0},
	{14,13,12,11,10,0,0,0},
	 {5, 6, 7, 8, 9,0,0,0},
	 {4, 3, 2, 1, 0,0,0,0}, };

int main(void)
{
	//8MHz
	CCP    = 0xD8;
	CLKMSR = 0x00;
	CCP    = 0xD8;
	CLKPSR = 0X00;
	//LEDs output
	DDRB  = (1 << DDB2);
	PUEB  = ~(1<<PUEB2);
	PORTB = (1<<PORTB2);
		
    /* Replace with your application code */
    static uint8_t i = 0;
	static uint8_t x,y,m,b,t;
	while (1) 
    {
		//background
		/*for(uint8_t y = 0; y < 5; y++)
			for(uint8_t x = 0; x < 5; x++)
				frame[map[x][y]] = (x << 3) + (y) + ((i & 3) << 6);
*/

		for(y = 0; y < 5; y++)
			for(uint8_t c = 0; c < 4; c++)
			{
				t = text[y][c];
				for(b = 0; b < 8; b++)
				{
					x = ((c * 8 + b) - i) & 31;
					if(x < 5)
					{
						m = map[y][x];
						if((t & 1) == 1)
							frame[m] = 0b00001000;
						else
							frame[m] = 0b00000000;
					}
					t >>= 1;
				}
			}
		i++;
		
		//writeGRB8(matrixB8);
		writeGRB8(frame);
		_delay_ms(100);
    }
}
