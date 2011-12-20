#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <avr/sleep.h>


//Konstanten
#define TAKT 1000000
#define PRESCALER 64
#define ACHTEL 100

void ton(uint16_t freq) {

	if (freq == 0){
		TCCR0A = TCCR0A & 0b10111111;
	}

	else {
		TCCR0A = TCCR0A | 0b01000000;
		OCR0A = TAKT/(freq * 2 * PRESCALER) - 1;
	}

}

int main(void) {

    DDRD = 0x40;
    PORTD = 0xBF;

    TCCR0A = TCCR0A | 0b00000010;
    TCCR0A = TCCR0A & 0b00111110;

    TCCR0B = TCCR0B | 0b00000011;
    TCCR0B = TCCR0B & 0b11110011;

    ton(264);
    _delay_ms(100000);
    ton(0);

    return 0;
}
