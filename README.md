ADC10_Library
=============

Library that allows for direct analog-to-digital conversion (Lab 7)

C2C Jasper Arneberg  
T5 ECE 382  
Capt Trimble  

##Description
This library allows the user to read a signal off a specified analog pin and convert it to a hexadecimal number using ADC10 on the MSP430. The method is titled readADC(pin), and it returns a value of the int type.

##Example
The library's functionality is demonstrated in the example_adc.c file. This file reads in an analog singal with the readADC(pin) command. Based on this value, it then turns on or off the red and green LEDs connected to P1.0 and P1.6, respectively.
```
#include "adc10.h"
#include "msp430g2553.h"

void main() {
	int signal2;
	int signal4;

	void initMSP430();
	IFG1=0; 														// clear interrupt flag1
	WDTCTL = WDTPW + WDTHOLD;				// disable WDT
	P1DIR |= BIT0 | BIT6;							// set leds to output

	while(1) {

		signal2 = readADC(2);						// read analog pin 2
		signal4 = readADC(4);						// read analog pin 4

		if (signal2 > 0x200) {
			P1OUT |= BIT0;						// turn on red led
			P1OUT &= ~BIT6;
		} else if (signal4 > 0x200) {
			P1OUT &= ~BIT0;
			P1OUT |= BIT6;						// turn on green led
		} else {
			P1OUT &= ~BIT0;						// turn off both leds
			P1OUT &= ~BIT6;
		}
	}
}
````

##Documentation
I used http://www.cs.swarthmore.edu/~newhall/unixhelp/howto_C_libraries.html as a reminder how to create C libraries.
