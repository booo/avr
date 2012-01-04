#define F_CPU 1000000
#define BAUD 2400

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <avr/sleep.h>
#include <util/setbaud.h>

int main(void) {

    PORTD = 0x04;

    DDRC = 0x01;        //PC1 output
	PORTC = 0xFF;    	// LED at PortC1 on

    UCSR0B |= (1<<TXEN0) | (1<<RXEN0) | (1<<RXCIE0);
    //use standard values for UCSR0C
    //set baud rate
    UBRR0L = UBRRL_VALUE;
    UBRR0H = UBRRH_VALUE;

    EICRA |= 0x02; //enable interupt at falling edge
    EIMSK |= 0x01;

	sei();         // enable global interrupts

    set_sleep_mode(SLEEP_MODE_IDLE);

    while(1) {
        sleep_mode();
    }

    return 0;
}

//interrupt service routine with interrupt vector
ISR(USART_RX_vect) {
    //read value
    uint8_t data = UDR0;
    if(data  == 'A') {
        PORTC ^= 0x01;		// exclusive or for toggling the leds
    };
}

ISR(INT0_vect) {
    //send some data
    while(!(UCSR0A & (1<<UDRE0))) {
    }
    UDR0 = 'A';
    _delay_ms(1000);
}
