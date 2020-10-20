/*	Author: pasen001
 *  Partner(s) Name: Peter John Asence
 *	Lab Section:
 *	Assignment: Lab #3  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0x00;
	DDRB = 0x00; PORTB = 0x00; // A And B are the inputs for this exercise
	DDRC = 0xFF; PORTC = 0x00; // C is the output for this excercise
	unsigned char tempVal = 0x00;
	unsigned char tempVal2 = 0x00;
	unsigned char totalBits = 0x00; // 
    /* Insert your solution below */
    while (1) {
	tempVal = PINA;
	tempVal2 = PINB;
	totalBits = ((tempVal & 0x80) >> 7)+
			((tempVal & 0x40) >> 6)+
			((tempVal & 0x20) >> 5)+
			((tempVal & 0x10) >> 4)+
			((tempVal & 0x08) >> 3)+
			((tempVal & 0x04) >> 2)+
			((tempVal & 0x02) >> 1)+
			(tempVal & 0x01)+
			((tempVal2 & 0x80) >> 7)+
			((tempVal2 & 0x40) >> 6)+
			((tempVal2 & 0x20) >> 5)+
                        ((tempVal2 & 0x10) >> 4)+
                        ((tempVal2 & 0x08) >> 3)+
                        ((tempVal2 & 0x04) >> 2)+
                        ((tempVal2 & 0x02) >> 1)+
                        (tempVal2 & 0x01);

	PORTC = totalBits;
    }
    return 1;
}
