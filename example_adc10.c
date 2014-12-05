#include "adc10.h"
#include "msp430g2553.h"

void main() {
	int signal;

	void initMSP430();
	IFG1=0; 													// clear interrupt flag1
	WDTCTL = WDTPW + WDTHOLD;									// disable WDT
	P1DIR |= BIT0;												// red led output

	signal = readADC(4);									// read analog pin 4

	if (signal > 0x200) {
		P1OUT |= BIT0;											// turn on red led
	} else {
		P1OUT &= ~BIT0;
	}
}
