#include <avr/io.h>
#include "pacer.h"

static uint16_t pacer_period;

/* Initialise the pacer module.  */
void pacer_init (uint16_t pacer_frequency)
{
    TCCR1A = 0x00; // Normal mode
    TCCR1B = 0x05; // Prescaler 1024
    TCCR1C = 0x00; // No forced compare

    pacer_period = 7812 / pacer_frequency; // Calculate pacer period
    
}


/* Pace a while loop.  */
void pacer_wait (void)
{

    TCNT1 = 0;  // Reset the timer counter

    while (TCNT1 < pacer_period) {
        // Wait for the desired pacer period
    }

    TCNT1 = 0;  // Reset the counter again for the next iteration

}
