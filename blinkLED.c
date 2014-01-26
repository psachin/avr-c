/*
  blinkLED.c
*/

/* Externel clock(quartz) speed you are using: 16MHz*/
#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>

int main(void) {

  DDRB = 0x01;			/* in hex Or 0b00000001 in binary */
  PORTB = 0;			/* all pins OFF */
    
  while(1) {
    PORTB = 0x01;
    _delay_ms(1000);
    PORTB = 0;
    _delay_ms(1000);
  }
}


