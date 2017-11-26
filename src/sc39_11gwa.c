/**\file */

/* 
 * This program is free software. It comes without any warranty, to
 * the extent permitted by applicable law. You can redistribute it
 * and/or modify it under the terms of the Do What The Fuck You Want
 * To Public License, Version 2, as published by Sam Hocevar. See
 * http://www.wtfpl.net/ for more details. 
 */

#include "sc39_11gwa.h"

/**
 * Sets the bit masks according to the given number. If the number is larger
 * than 9, all segments go dark and _ERR_ is returned.
 * @param num The number to write
 * @return _OK_ if num was not larger than 9 and _ERR_ otherwise
 */
RC write_num(uint8_t num){
	switch (num){
		case 0:
			P2OUT = BIT1 | BIT4 | BIT5 | BIT3 | BIT2;
			P1OUT |= BIT6;
			return OK;
		case 1:
			P2OUT = BIT5;
			P1OUT |= BIT6;
			return OK;
		case 2:
			P2OUT = BIT4 | BIT5 | BIT0 | BIT2 | BIT3;
			P1OUT &= ~BIT6;
			return OK;
		case 3:
			P2OUT = BIT4 | BIT5 | BIT0 | BIT3;
			P1OUT |= BIT6;
			return OK;	
		case 4:
			P2OUT = BIT1 | BIT0 | BIT5;
			P1OUT |= BIT6;
			return OK;
		case 5:
			P2OUT = BIT4 | BIT1 | BIT0 | BIT3;
			P1OUT |= BIT6;
			return OK;
		case 6:
			P2OUT = BIT4 | BIT1 | BIT0 | BIT2 | BIT3;
			P1OUT |= BIT6;	
			return OK;
		case 7:
			P2OUT = BIT5 | BIT4;
			P1OUT |= BIT6;
			return OK;
		case 8:
			P2OUT = BIT0 | BIT1 | BIT2 | BIT3 | BIT4 | BIT5;
			P1OUT |= BIT6;
			return OK;
		case 9:
			P2OUT = BIT0 | BIT1 | BIT3 | BIT4 | BIT5;
			P1OUT |= BIT6;
			return OK;			
		default:
			P2OUT = 0x00;
			P1OUT &= ~BIT6;
			return ERR;
	}
}

/**
 * Sets the bit mask for the decimal point.
 * @return _OK_. Nothing can go wrong with this implementation
 */
RC set_DP(){
	P1OUT |= BIT7;
	return OK;
}

/**
 * Clears the bit mask for the decimal point.
 * @return _OK_. Nothing can go wrong with this implementation
 */
RC clear_DP(){
	P1OUT &= ~BIT7;
	return OK;
}
