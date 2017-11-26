/* 
 * This program is free software. It comes without any warranty, to
 * the extent permitted by applicable law. You can redistribute it
 * and/or modify it under the terms of the Do What The Fuck You Want
 * To Public License, Version 2, as published by Sam Hocevar. See
 * http://www.wtfpl.net/ for more details. 
 */

#include "lazy.h"
#include "sc39_11gwa.h"

int main(){
	// Watchdog and oscillator setup
	WDTCTL = WDTPW + WDTHOLD;         
	BCSCTL1 = CALBC1_1MHZ;
	DCOCTL = CALDCO_1MHZ;

	// LED field setup
	P2DIR |= BIT0 | BIT1 | BIT2 | BIT3 | BIT4 | BIT5;
	P2OUT = 0;
	P1DIR |= BIT6;

	// Button setup
 	P1DIR &= ~BIT3;
   	P1OUT |= BIT3;
   	P1REN |= BIT3;

	// The number returned by dice rolls
	uint8_t num = 0;

	// Looping and incrementing num if the button is pressed
	while(1){
		// Button was pressed
		if ((P1IN & BIT3) == 0){ 
			num++;
			// Reset if num grows too large
			if (num > 6){
				num = 1;
			}
		}
		// Writing num
		write_num(num);
	}
}
