#include "system.h"
#include "pio.h"
#include "pacer.h"


/** Define PIO pins driving LED matrix rows.  */
static const pio_t rows[] =
{
    LEDMAT_ROW1_PIO, LEDMAT_ROW2_PIO, LEDMAT_ROW3_PIO, 
    LEDMAT_ROW4_PIO, LEDMAT_ROW5_PIO, LEDMAT_ROW6_PIO,
    LEDMAT_ROW7_PIO
};


/** Define PIO pins driving LED matrix columns.  */
static const pio_t cols[] =
{
    LEDMAT_COL1_PIO, LEDMAT_COL2_PIO, LEDMAT_COL3_PIO,
    LEDMAT_COL4_PIO, LEDMAT_COL5_PIO
};


static const uint8_t bitmap[] =
{
    0x30, 0x46, 0x40, 0x46, 0x30
};


/**display the each column*/
static void display_column (uint8_t row_pattern, uint8_t current_column)
{
    /**This is the provious colum*/
    static uint8_t col_pre = 0;
    pio_output_high(cols[col_pre]);

    for (uint8_t row = 0; row < LEDMAT_ROWS_NUM; row++) {
        if ((row_pattern >> row) & 1) {
            // Set the current row pin to low
            pio_output_low(rows[row]);
        } else {
            pio_output_high(rows[row]);
        }
    }
    pio_output_low(cols[current_column]);
    col_pre = current_column;

}


/** init ledmat to all high*/
void ledmat_init (void)
{
    uint8_t row;
    uint8_t col;

    for (row = 0; row < LEDMAT_ROWS_NUM; row++) {
        pio_config_set (rows[row], PIO_OUTPUT_HIGH);
    }

    for (col = 0; col < LEDMAT_COLS_NUM; col++) {
        pio_config_set (cols[col], PIO_OUTPUT_HIGH);
    }
}

int main (void)
{
    uint8_t current_column = 0;
  
    system_init ();
    ledmat_init();
    pacer_init (500);
    
    /* TODO: Initialise LED matrix pins.  */
    

    while (1) {
        pacer_wait ();
        
        display_column (bitmap[current_column], current_column);
    
        current_column++;
    
        if (current_column > (LEDMAT_COLS_NUM - 1)) {
            current_column = 0;
        }           
    }
}
