#include "system.h"
#include "pio.h"

/* Include the pacer module from the previous lab.
   You must have completed this before starting this lab2-exercise.  */
#include "pacer.h"

static const pio_t ledmat_rows[] =
{
    LEDMAT_ROW1_PIO, LEDMAT_ROW2_PIO, LEDMAT_ROW3_PIO, 
    LEDMAT_ROW4_PIO, LEDMAT_ROW5_PIO, LEDMAT_ROW6_PIO,
    LEDMAT_ROW7_PIO
};

static const pio_t ledmat_cols[] =
{
    LEDMAT_COL1_PIO, LEDMAT_COL2_PIO, LEDMAT_COL3_PIO,
    LEDMAT_COL4_PIO, LEDMAT_COL5_PIO
};
void ledmat_init (void)
{
    uint8_t row;
    uint8_t col;

    for (row = 0; row < LEDMAT_ROWS_NUM; row++)
    {
        pio_config_set (ledmat_rows[row], PIO_OUTPUT_HIGH);
    }

    for (col = 0; col < LEDMAT_COLS_NUM; col++)
    {
        pio_config_set (ledmat_cols[col], PIO_OUTPUT_HIGH);
    }
}

int main (void)
{
    system_init ();
    ledmat_init();
    /* Set up pacer with a frequency of 100 Hz.  
        This gives 50Hz alternating between the 2 states.*/
    pacer_init (100);
    uint8_t toggle = 0;

    while (1)
    {
        /* Pace the loop.  */
        pacer_wait ();
        if (toggle == 0) {
            ledmat_init();
            // Configuration 1
            // Set first and last row pins to low
            pio_output_low(ledmat_rows[0]);
            pio_output_low(ledmat_rows[6]);
            pio_output_low(ledmat_cols[0]);
        } else {
            // Configuration 2
            ledmat_init();
            pio_output_low(ledmat_rows[0]);
            pio_output_low(ledmat_cols[4]);
        }

        toggle = !toggle;

    }
}
