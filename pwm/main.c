#include <avr/io.h>
#include <avr/sleep.h>
#include <avr/interrupt.h>

int main(void) {

    DDRD = 0xFF;  //Port D konfigurieren
    PORTD = 0x00; //Alle LEDs am Anfang aus

    TCCR0A |= 0b10000001;
	TCCR0A &= 0b10001101;

    TCCR0B |= 0b00000010;
	TCCR0B &= 0b00110010;

    OCR0A |= 0x0a;

	TIMSK0 |= 0b00000000;
	TIMSK0 &= 0b11111000;


	sei(); //Interrupts zulassen
	set_sleep_mode(SLEEP_MODE_IDLE);


    while(1) {
       sleep_mode();
    }

    return 0;
}

