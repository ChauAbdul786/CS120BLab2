/*	Author: Abdullah Chaudhry
 *  Partner(s) Name: 
 *	Lab Section: 21
 *	Assignment: Lab #2  Exercise #2
 *	Exercise Description: Parking Lot Detector - PA3 - PA0 are parking spots(1 for occupied, 0 for vacant). Port C should reflect the number of open spots available in the lot.
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
	DDRA = 0x00; PORTA = 0xFF; //Configure's Port A's 8 pins as inputs
	DDRC = 0xFF; PORTC = 0x00; //Configure's Port C's 8 pins as outputs
				   //Initializes PORTC(output) to 0x00;	

	/* Insert your solution below */
	unsigned char tmpA = 0x00; //To hold PINA
	unsigned char tmpC = 0x00; //To hold PORTC
	while (1) {
		//Input (PINA3 - PINA0)
		tmpA = PINA & 0x0F; //0000AAAA
		
		unsigned char cnt =	((tmpA & 0x08) >> 3) + ((tmpA & 0x04) >> 2) +
					((tmpA & 0x02) >> 1) + ((tmpA & 0x01));

		tmpC = 4 - cnt; 

		//Output
		PORTC = tmpC;
	}
	
    
	return 0;
}
