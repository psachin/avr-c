/*
  16bit-timer.c
  This is same as 8 bit except the registers
*/

/* Externel clock(quartz) speed: 16MHz */
#include <avr/io.h>
#include <avr/interrupt.h>

int main(void) {

  DDRB = 0x01;

  /* Timer/Counter control register B */
  TCCR1B = (1 << WGM12);	/* Set CTC(clear timer when confirmed) bit */
  OCR1A = 15625;
  TIMSK1 = (1 << OCIE1A);	      /* interrupt handler */

  sei();			      /* Set External Interrupt */
  TCCR1B = (1 << CS12) | (1 << CS10); /* Set prescaler to clk/1024 */
  while(1) {
  
  }
}

ISR(TIMER1_COMPA_vect)		/* timer 1, comparison A vector */
{
  //  extraTime++; // We don't need that extra variable as we are
  //  doing it for 1 second(see fig: 16bit.png)

  PORTB ^= (1 << PORT3);	/* pin 13 of arduino */
}

