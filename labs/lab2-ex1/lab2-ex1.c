#include <avr/io.h>
#include "system.h"
#include "led.h"

int main (void)
{
    system_init ();
    led_init ();
    
    /* Initialise timer/counter1 in normal mode with a prescaler of 1024. */
    TCCR1A = 0x00;
    TCCR1B = 0x05;
    TCCR1C = 0x00;

    uint16_t count = 7813;  // Count for 5 ms delay

    while (1)
    {
        /* Turn LED on.  */
        led_set (LED1, 1);
        TCNT1 = 0;

        /* Wait for 5 milliseconds.  */
        while (TCNT1 < count)
        {
            // Wait until TCNT1 reaches the desired count
        }

        /* Turn LED off.  */
        led_set (LED1, 0);

        TCNT1 = 0;

        /* Wait for 5 milliseconds.  */
        while (TCNT1 < count)
        {
            // Wait until TCNT1 reaches the desired count
        }
    }
}
