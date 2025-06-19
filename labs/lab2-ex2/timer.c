#include <avr/io.h>
#include "timer.h"

/* Initialise timer.  */
void timer_init (void)
{
    TCCR1A = 0x00;// Normal mode
    TCCR1B = 0x05;// Prescaler = 1024
    TCCR1C = 0x00;// No forced compare

}


/* Wait for the specified length of time.  */
void timer_delay_ms (uint16_t milliseconds)
{
    int16_t counter = (milliseconds * 1000) / 128;
    TCNT1 = 0;
    while(TCNT1 < counter) {

    }

    /* TODO: Calculate the timer/counter value needed 
       for the given number of milliseconds. */

    /* TODO: Wait for the timer/couter to reach the 
       value calculated above.  */

}
