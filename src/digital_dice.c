#include "lazy.h"
#include "sc39_11gwa.h"


int main(){
	WDTCTL = WDTPW + WDTHOLD;         
	BCSCTL1 = CALBC1_1MHZ;
	DCOCTL = CALDCO_1MHZ;

	P2DIR |= BIT0 | BIT1 | BIT2 | BIT3 | BIT4 | BIT5;
	P2OUT = 0;

	P1DIR |= BIT7 | BIT6;

	uint8_t num = 0;
	while(1){
		write_num(num);
		num++;
		if (num > 9) num = 0;
		if (num % 2){
			set_DP();
		}
		else{
			clear_DP();
		}
		for (int i = 0 ; i < 1000; i++){
			__delay_cycles(1000);	
		}
	}
}
