/*	Author: pasen001
 *  Partner(s) Name: Peter John Asence
 *	Lab Section: 022
 *	Assignment: Lab #3  Exercise #2
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
	DDRA = 0x00; PORTA = 0x00; // A is input
	DDRC = 0xFF; PORTC = 0x00; // C is output
	unsigned char tempVal = 0x00;  
    /* Insert your solution below */
    while (1) {
	tempVal = PINA & 0x0F;
	if (tempVal == 0x00) {
		PORTC = 0x40; // level 0 and lowfuel
	}
	else if(tempVal == 0x01 || tempVal ==0x02 ){
		 PORTC = 0x60; // level 1-2 and lowfuel
	}
	else if(tempVal == 0x03 || tempVal == 0x04){
		 PORTC = 0x70; // level 3-4 and lowfuel
	}
	else if(tempVal == 0x05 || tempVal == 0x06) {
		PORTC = 0x38; // level 5-6
	} 
	else if(tempVal >= 0x07 && tempVal <= 0x09){
		 PORTC = 0x3C; // level 7-9
	} 
	else if(tempVal >= 0x0A && tempVal <= 0x0C){
		 PORTC = 0x3E; // level 10-12
	}
	else if(tempVal >= 0x0D && tempVal <= 0x0F){
		 PORTC = 0x3F; // level 13-15
	}

    }
    return 1;
}
