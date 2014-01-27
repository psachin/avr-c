/*
  switchLED.c
*/

/* Externel clock(quartz) speed you are using: 16MHz*/
#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>

int main(void) {

  /* PINB0 is set as o/p */
  DDRB = 0x01;			/* in hex Or 0b00000001 in binary */

  /*
    PINB1 or 00000010 is where out push button is connected. It is
    set to HIGH.
   */
  PORTB = 0x02;			/* in hex or 00000010. PINB1 is HIGH */
    
  while(1) {
    /* if button is pressed */
    if(!(PINB & 0x02)) {	/* masking 00000010 with AND */
      PORTB |= 0x01;		/* masking 00000001 with OR */
    }
    else {
      PORTB &= 0xFE;		/* masking 11111110 with AND */
    }
  }
}


