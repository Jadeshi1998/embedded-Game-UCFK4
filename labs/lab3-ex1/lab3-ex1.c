#include "system.h"
#include "pacer.h"
#include "tinygl.h"
#include "../fonts/font5x7_1.h"


#define PACER_RATE 500
#define MESSAGE_RATE 10

int main (void)
{
    system_init();

    /* TODO: Initialise tinygl. */
    tinygl_init(PACER_RATE);
    tinygl_text_mode_set(TINYGL_TEXT_MODE_SCROLL);

    /* TODO: Set the message using tinygl_text().  */
    tinygl_font_set(&font5x7_1);
    tinygl_text_speed_set(MESSAGE_RATE);
    
    tinygl_text("GAME OVER");
    pacer_init (PACER_RATE);

    while(1)
    {
        pacer_wait();
        tinygl_update ();
        /* TODO: Call the tinygl update function. */
        
    }
    return 0;
}
