/*	Author: Abdullah Chaudhry
 *  Partner(s) Name: 
 *	Lab Section: 21
 *	Assignment: Lab #2  Exercise #1
 *	Exercise Description: Garage Door Sensor - PA0 is a door sensor(1 is open), PA1 is a light sensor(1 is light sensed). PB0 is an LED that will illuminate(1) is the door is open at night(Door open && No light).
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
	unsigned char tmpA = 0x00; //To hold PINA
	unsigned char tmpB = 0x00; //To hold PORTB
	while (1) {
		//Input (PINA0 and PINA1)
		tmpA = PINA & 0x03; //000000AA
		if(tmpA == 0x01){ //xxxxxx01
			tmpB = (tmpB & 0xFE) | 0x01; //BBBBBBB1
		}else{
			tmpB = (tmpB & 0xFE); //BBBBBBB0
		}

		PORTB = tmpB;
	}
	
    
	return 0;
}
