/*	Author: Abdullah Chaudhry
 *  Partner(s) Name: 
 *	Lab Section: 21
 *	Assignment: Lab #2  Exercise #1
 *	Exercise Description: Basic program which sets B's 8 pins to 0000 1111
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
	DDRB = 0xFF; PORTB = 0x00; //Configure's Port B's 8 pins as outputs
				   //Initializes PORTB(output) to 0x00;	

	/* Insert your solution below */
	unsigned char tmpB = 0x00;
	unsigned char tmpA = 0x00;
	while (1) {
		//Read Input
		tmpA = PINA & 0x01;
		//Perform Computation
		//If PA0 is 1 set PB1PB0 to 01, else to 10
		if(tmpA == 0x01){
			tmpB = (tmpB & 0xFC) | 0x01; //BBBBBB01
		}else{
			tmpB = (tmpB & 0xFC) | 0x02; //BBBBBB10
		}
		//Output
		PORTB = tmpB;
	}
    
	return 0;
}
