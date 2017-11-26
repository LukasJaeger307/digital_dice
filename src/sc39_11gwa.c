#include "sc39_11gwa.h"

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

RC set_DP(){
	P1OUT |= BIT7;
	return OK;
}

RC clear_DP(){
	P1OUT &= ~BIT7;
	return OK;
}
