#include <avr/io.h>
#include "system.h"

int main(void)
{
    // Set DDRD bit 7 to input (button) and DDRB bit 5 to output (LED)
    DDRD &= ~(1 << 7);   // Set PD7 (pin #7 on port D) as input
    DDRC |= (1 << 2);    // Set PC2 (pin #2 on port C) as output

    while (1)
    {
        // Check if the button is pressed 
        if (PIND & (1 << 7))
        {
            PORTC |= (1 << 2);  // Turn LED on when press
        }
        else
        {
            PORTC &= ~(1 << 2); // Turn LED off when not press
        }
    }

    return 0;
}