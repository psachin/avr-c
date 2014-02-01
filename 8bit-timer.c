/*
  8bit-timer.c
*/

/* Externel clock(quartz) speed: 16MHz */
#include <avr/io.h>
#include <avr/interrupt.h>

int extraTime = 0;

int main(void) {

  DDRB = 0x01;

  /* Timer/Counter control register A */
  TCCR0A = (1 << WGM01);	/* Set CTC(clear timer when confirmed) bit */
  OCR0A = 156;
  TIMSK0 = (1 << OCIE0A);	      /* interrupt handler */

  sei();			      /* Set External Interrupt */
  TCCR0B = (1 << CS02) | (1 << CS00); /* Set prescaler to clk/1024 */
  while(1) {
  
  }
}

ISR(TIMER0_COMPA_vect)		/* timer 0, comparison A vector */
{
  extraTime++;

  if(extraTime > 100)
    {
      extraTime = 0;
      PORTB ^= (1 << PORT3);	/* pin 13 of arduino */
    }
}

