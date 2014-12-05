#include "adc10.h"
#include "msp430g2553.h"

void main() {
	int signal2;
	int signal4;

	void initMSP430();
	IFG1=0; 													// clear interrupt flag1
	WDTCTL = WDTPW + WDTHOLD;									// disable WDT
	P1DIR |= BIT0 | BIT6;										// set leds to output

	while(1) {

		signal2 = readADC(2);									// read analog pin 2
		signal4 = readADC(4);									// read analog pin 4

		if (signal2 > 0x200) {
			P1OUT |= BIT0;										// turn on red led
			P1OUT &= ~BIT6;
		} else if (signal4 > 0x200) {
			P1OUT &= ~BIT0;
			P1OUT |= BIT6;										// turn on green led
		} else {
			P1OUT &= ~BIT0;										// turn off both leds
			P1OUT &= ~BIT6;
		}
	}
}
