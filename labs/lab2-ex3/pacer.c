#include <avr/io.h>
#include "pacer.h"

static uint16_t pacer_period_ticks;  /* Number of ticks of the timer for the given pacer frequency */

/* Initialise the pacer module.  */
void pacer_init (uint16_t pacer_frequency)
{
    //timer init
    TCCR1A = 0x00;
    TCCR1B = 0x05;
    TCCR1C = 0x00;
    //counter init
    
    pacer_period_ticks = (7812 / pacer_frequency); 
    /* TODO: initialise timer/counter peripheral the
       same way as in lab2/lab2-ex2/timer.c but also calculate 
       the timer/counter value from the pacer frequency */
}


/* Pace a while loop.  */
void pacer_wait (void)
{    
    TCNT1 = 0;
    while(TCNT1 < pacer_period_ticks) {

    }
    TCNT1 = 0;
    /* TODO: Implement the same way as the timer_delay () function 
       lab2-except reset TCNT1 after the while loop. */

}
