/*	Author: Abdullah Chaudhry
 *  Partner(s) Name: 
 *	Lab Section: 21
 *	Assignment: Lab #2  Exercise #4
 *	Exercise Description: Amusement Park Ride Weights - Ports A - C represent 8-bit weight sensors(in kg) for seats on a ride. If the total weight of the vehicle exceeds 140kg than PD0 should be set to 1. If the weight difference between seats A and C is greater than 80kg PD1 should be set to 1. 
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
	DDRB = 0x00; PORTB = 0xFF; //Configure's Port B's 8 pins as inputs
	DDRC = 0x00; PORTC = 0xFF; //Configure's Port C's 8 pins as inputs
	DDRD = 0xFF; PORTD = 0x00; //Configure's Port D's 8 pins as outputs
				   //Initializes PORTD(output) to 0x00;	

	/* Insert your solution below */
	unsigned char tmpA = 0x00; //To hold PINA
	unsigned char tmpB = 0x00; //To hold PINB
	unsigned char tmpC = 0x00; //To hold PINC
	unsigned char tmpD = 0x00; //To hold PORTD

	unsigned short totalWeight = 0; //Unsigned short to hold total weight
	signed short weightDifference = 0; //For weight difference between seats A and C
						//Short is needed because signed char range is 
						// -128 - 127
	while (1) {
		//Input 
		tmpA = PINA;
		tmpB = PINB;
		tmpC = PINC;

		totalWeight = tmpA + tmpB + tmpC;
		if(totalWeight > 140){
			tmpD = (tmpD | 0x01); //DDDD DDD1
		}else{
			tmpD = (tmpD & 0xFE); //DDDD DDD0
		}
		
		weightDifference = tmpA - tmpC;
		if(weightDifference > 80 || weightDifference < -80){ //Need to check <-80 if seat
									//C is heavier than seat A
			tmpD = (tmpD | 0x02); //DDDD DD1D
		}else{
			tmpD = (tmpD & 0xFD); //DDDD DD0D
		}
		
		//Weight Estimation
		totalWeight = totalWeight >> 2;
		totalWeight = totalWeight & 0xFC; //WWWW WW00
		tmpD = (tmpD | totalWeight); //WWWW WWDD

		//Output
		PORTD = tmpD;
	}
	
    
	return 0;
}
