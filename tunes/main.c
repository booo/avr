#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <avr/sleep.h>


//Konstanten
#define TAKT 1000000
#define PRESCALER 64
#define ACHTEL 100

#define TUNE_C 264
#define TUNE_D 297
#define TUNE_E 330
#define TUNE_F 352
#define TUNE_G 396
#define TUNE_A 440

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

    ton(TUNE_C);
    _delay_ms(ACHTEL);
    ton(0);
    _delay_ms(ACHTEL);
    ton(TUNE_D);
    _delay_ms(ACHTEL);
    ton(0);
    _delay_ms(ACHTEL);
    ton(TUNE_E);
    _delay_ms(ACHTEL);
    ton(0);
    _delay_ms(ACHTEL);
    ton(TUNE_F);
    _delay_ms(ACHTEL);
    ton(0);
    _delay_ms(ACHTEL);
    ton(TUNE_G);
    _delay_ms(2*ACHTEL);
    ton(0);
    _delay_ms(ACHTEL);
    ton(TUNE_G);
    _delay_ms(2*ACHTEL);
    ton(0);
    _delay_ms(ACHTEL);
    ton(TUNE_A);
    _delay_ms(ACHTEL);
    ton(0);
    _delay_ms(ACHTEL);
    ton(TUNE_A);
    _delay_ms(ACHTEL);
    ton(0);
    _delay_ms(ACHTEL);
    ton(TUNE_A);
    _delay_ms(ACHTEL);
    ton(0);
    _delay_ms(ACHTEL);
    ton(TUNE_A);
    _delay_ms(ACHTEL);
    ton(0);
    _delay_ms(ACHTEL);
    ton(TUNE_G);
    _delay_ms(4*ACHTEL);
    ton(0);
    _delay_ms(ACHTEL);
    ton(TUNE_A);
    _delay_ms(ACHTEL);
    ton(0);
    _delay_ms(ACHTEL);
    ton(TUNE_A);
    _delay_ms(ACHTEL);
    ton(0);
    _delay_ms(ACHTEL);
    ton(TUNE_A);
    _delay_ms(ACHTEL);
    ton(0);
    _delay_ms(ACHTEL);
    ton(TUNE_A);
    _delay_ms(ACHTEL);
    ton(0);
    _delay_ms(ACHTEL);
    ton(TUNE_G);
    _delay_ms(4*ACHTEL);
    ton(0);
    _delay_ms(ACHTEL);
    ton(TUNE_F);
    _delay_ms(ACHTEL);
    ton(0);
    _delay_ms(ACHTEL);
    ton(TUNE_F);
    _delay_ms(ACHTEL);
    ton(0);
    _delay_ms(ACHTEL);
    ton(TUNE_F);
    _delay_ms(ACHTEL);
    ton(0);
    _delay_ms(ACHTEL);
    ton(TUNE_F);
    _delay_ms(ACHTEL);
    ton(0);
    _delay_ms(ACHTEL);
    ton(TUNE_E);
    _delay_ms(2*ACHTEL);
    ton(0);
    _delay_ms(ACHTEL);
    ton(TUNE_E);
    _delay_ms(2*ACHTEL);
    ton(0);
    _delay_ms(ACHTEL);
    ton(TUNE_D);
    _delay_ms(ACHTEL);
    ton(0);
    _delay_ms(ACHTEL);
    ton(TUNE_D);
    _delay_ms(ACHTEL);
    ton(0);
    _delay_ms(ACHTEL);
    ton(TUNE_D);
    _delay_ms(ACHTEL);
    ton(0);
    _delay_ms(ACHTEL);
    ton(TUNE_G);
    _delay_ms(ACHTEL);
    ton(0);
    _delay_ms(ACHTEL);
    ton(TUNE_C);
    _delay_ms(4*ACHTEL);
    ton(0);
    _delay_ms(ACHTEL);
    return 0;
}
