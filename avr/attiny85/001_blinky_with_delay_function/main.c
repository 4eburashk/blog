/**
 * Copyright (c) 2018, Łukasz Marcin Podkalicki <lpodkalicki@gmail.com>
 * ATtiny85/001
 * Simple blinky with delay function.
 */

#include <avr/io.h>
#include <util/delay.h>

#define	LED_PIN	PB2

int
main(void)
{

	/* setup */
	DDRB |= _BV(LED_PIN); // set LED pin as OUTPUT

	/* loop */
	while (1) {
		PORTB ^= _BV(LED_PIN); // toggle LED pin
		_delay_ms(500);
	}
}
