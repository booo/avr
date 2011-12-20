#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <avr/sleep.h>


int main(void) {

    DDRC = 0x03;		// PortC 1 and 2 as Output
    DDRD = 0x00;

	PORTC = 0x01;    	// LED at PortC1 on
    PORTD = 0xFF;


	EICRA = 0x02;
	EIMSK = 0x01;

	sei();          	// enable global interrupts


    set_sleep_mode(SLEEP_MODE_IDLE);

    while(1) {
        sleep_mode();
    }

    return 0;
}

//interrupt service routinge with interrupt vector
ISR(INT0_vect) {
    PORTC ^= 0x03;		// exclusive or for toggling the leds
	_delay_ms(1000);
}
