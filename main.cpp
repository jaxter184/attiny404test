/*
 * GccApplication2.cpp
 *
 * Created: 2018-10-20 1:37:34 AM
 * Author : jaxter184
 */ 

#include <avr/io.h>


int main(void)
{
	int pin = 0;
	volatile uint8_t *port_pin_ctrl = ((uint8_t *)&PORTB + 0x10 + pin);
	*port_pin_ctrl &= ~PORT_PULLUPEN_bm;
	*port_pin_ctrl = (*port_pin_ctrl & ~PORT_ISC_gm) | PORT_ISC_INTDISABLE_gc;
	*port_pin_ctrl &= ~PORT_INVEN_bm;

	VPORTB.DIR |= (1 << pin);

	VPORTB.OUT |= (1 << pin);

    while (1) 
    {
	    //PORTB_set_pin_level(0, true);
	    //PORTB_set_pin_level(0, false);
    }
}
