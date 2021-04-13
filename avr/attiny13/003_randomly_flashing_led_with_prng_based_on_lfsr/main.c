/**
 * Copyright (c) 2016, Łukasz Marcin Podkalicki <lpodkalicki@gmail.com>
 * ATtiny13/003
 * Randomly flashing LED with PRNG based on LFSR.
 */

#include <avr/io.h>
#include <util/delay.h>

#define LFSR_SEED 	(100)
#define	DELAY		(500)

static uint16_t
prng_lfsr16(void) {
        static uint16_t cnt16 = LFSR_SEED;
        return (cnt16 = (cnt16 >> 1) ^ (-(cnt16 & 1) & 0xB400));
}

int main(void) {
	/* setup */
	DDRB = 0b00000100; // set LED pin as OUTPUT
	PORTB = 0x00; // set all pins to LOW
	/* loop */
	while (1) {
		if (prng_lfsr16() & 1) {
		        PORTB |= (1<<2); // LED on
		} else {
		        PORTB &= ~(1<<2); // LED off
		}
    _delay_ms(DELAY);
	}
}
