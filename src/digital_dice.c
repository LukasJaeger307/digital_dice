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

	uint8_t num = 0;
	while(1){
		// Button was pressed
		if ((P1IN & BIT3) == 0){ 
			num++;
			if (num > 6){
				num = 1;
			}
		}
		write_num(num);
	}
}
