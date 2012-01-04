#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <avr/sleep.h>


//Konstanten
#define TAKT 1000000
#define PRESCALER 32

#define SECHZEHNTEL 50
#define ACHTEL 2*SECHZEHNTEL
#define ACHTELPUNKT 3*SECHZEHNTEL
#define VIERTEL 2*ACHTEL
#define HALB 2*VIERTEL

#define C 262
#define D 294
#define EMOL 312
#define E 330
#define F 350
#define GMOL 370
#define G 392
#define GSHARP 416
#define A 440
#define BMOL 467
#define B 494
#define C2 524
#define C2SHARP 555
#define D2 588
#define D2SHARP 623
#define E2MOL 623
#define E2 660
#define F2 699
#define F2SHARP 740
#define G2 784

void ton(uint16_t freq, uint16_t duration) {
	if (freq == 0){
		TCCR0A = TCCR0A & 0b10111111;
	}
	else {
		TCCR0A = TCCR0A | 0b01000000;
		OCR0A = TAKT/(freq * 2 * PRESCALER) - 1;
	}
    _delay_ms(duration);
}

int main(void) {

    DDRD = 0x40;
    PORTD = 0xBF;

    TCCR0A = TCCR0A | 0b00000010;
    TCCR0A = TCCR0A & 0b00111110;

    TCCR0B = TCCR0B | 0b00000011;
    TCCR0B = TCCR0B & 0b11110011;

    EICRA = 0x02;
    EIMSK = 0x01;

    sei();

    set_sleep_mode(SLEEP_MODE_IDLE);

    while(1) {
        sleep_mode();

        ton(G,VIERTEL);
        ton(0, ACHTEL);
        ton(G, VIERTEL);
        ton(0, ACHTEL);
        ton(G, VIERTEL);
        ton(0, ACHTEL);
        ton(EMOL, ACHTELPUNKT);
        ton(0, ACHTEL);
        ton(BMOL, SECHZEHNTEL);
        ton(0, ACHTEL);
        //--------------------
        ton(G, VIERTEL);
        ton(0, ACHTEL);
        ton(EMOL, ACHTELPUNKT);
        ton(0, ACHTEL);
        ton(BMOL, SECHZEHNTEL);
        ton(0, ACHTEL);
        ton(G, HALB);
        ton(0, ACHTEL);
        //--------------------
        ton(D2, VIERTEL);
        ton(0, ACHTEL);
        ton(D2, VIERTEL);
        ton(0, ACHTEL);
        ton(D2, VIERTEL);
        ton(0, ACHTEL);
        ton(E2MOL, ACHTELPUNKT);
        ton(0, ACHTEL);
        ton(BMOL, SECHZEHNTEL);
        ton(0, ACHTEL);
        //--------------------
        ton(GMOL, VIERTEL);
        ton(0, ACHTEL);
        ton(EMOL, ACHTELPUNKT);
        ton(0, ACHTEL);
        ton(BMOL, SECHZEHNTEL);
        ton(0, ACHTEL);
        ton(G, HALB);
        ton(0, ACHTEL);
        //--------------------
        ton(G2, VIERTEL);
        ton(0, ACHTEL);
        ton(G, ACHTELPUNKT);
        ton(0, ACHTEL);
        ton(G, SECHZEHNTEL);
        ton(0, ACHTEL);
        ton(G2, VIERTEL);
        ton(0, ACHTEL);
        ton(F2SHARP, ACHTELPUNKT);
        ton(0, ACHTEL);
        ton(F2, SECHZEHNTEL);
        ton(0, ACHTEL);
        //--------------------
        ton(E2, SECHZEHNTEL);
        ton(0, ACHTEL);
        ton(D2SHARP, SECHZEHNTEL);
        ton(0, ACHTEL);
        ton(E2, ACHTEL);
        ton(0, ACHTEL);
        ton(0, ACHTEL); //achtel pause
        ton(0, ACHTEL);
        ton(GSHARP, ACHTEL);
        ton(0, ACHTEL);
        ton(C2SHARP, VIERTEL);
        ton(0, ACHTEL);
        ton(C2, ACHTELPUNKT);
        ton(0, ACHTEL);
        ton(B, SECHZEHNTEL);
        ton(0, ACHTEL);
        //--------------------
        ton(BMOL, SECHZEHNTEL);
        ton(0, ACHTEL);
        ton(A, SECHZEHNTEL);
        ton(0, ACHTEL);
        ton(BMOL, ACHTEL);
        ton(0, ACHTEL);
        ton(0, ACHTEL); //achtel pause
        ton(0, ACHTEL);
        ton(EMOL, ACHTEL);
        ton(0, ACHTEL);
        ton(GMOL, VIERTEL);
        ton(0, ACHTEL);
        ton(EMOL, ACHTELPUNKT);
        ton(0, ACHTEL);
        ton(GMOL, SECHZEHNTEL);
        ton(0, ACHTEL);
        //--------------------
        ton(BMOL, VIERTEL);
        ton(0, ACHTEL);
        ton(G, ACHTELPUNKT);
        ton(0, ACHTEL);
        ton(BMOL, SECHZEHNTEL);
        ton(0, ACHTEL);
        ton(D2, HALB);
        ton(0, ACHTEL);
        //--------------------
        ton(G2, VIERTEL);
        ton(0, ACHTEL);
        ton(G, ACHTELPUNKT);
        ton(0, ACHTEL);
        ton(G, SECHZEHNTEL);
        ton(0, ACHTEL);
        ton(G2, VIERTEL);
        ton(0, ACHTEL);
        ton(F2SHARP, ACHTELPUNKT);
        ton(0, ACHTEL);
        ton(F2, SECHZEHNTEL);
        ton(0, ACHTEL);
        //--------------------
        ton(E2, SECHZEHNTEL);
        ton(0, ACHTEL);
        ton(D2SHARP, SECHZEHNTEL);
        ton(0, ACHTEL);
        ton(E2, ACHTEL);
        ton(0, ACHTEL);
        ton(0, ACHTEL); //achtel pause
        ton(0, ACHTEL);
        ton(GSHARP, ACHTEL);
        ton(0, ACHTEL);
        ton(C2SHARP, VIERTEL);
        ton(0, ACHTEL);
        ton(C2, ACHTELPUNKT);
        ton(0, ACHTEL);
        ton(B, SECHZEHNTEL);
        ton(0, ACHTEL);
        //--------------------
        ton(BMOL, SECHZEHNTEL);
        ton(0, ACHTEL);
        ton(BMOL, SECHZEHNTEL);
        ton(0, ACHTEL);
        ton(A, SECHZEHNTEL);
        ton(0, ACHTEL);
        ton(BMOL, ACHTEL);
        ton(0, ACHTEL);
        ton(0, ACHTEL); //achtel pause
        ton(0, ACHTEL);
        ton(EMOL, ACHTEL);
        ton(0, ACHTEL);
        ton(GMOL, VIERTEL);
        ton(0, ACHTEL);
        ton(EMOL, ACHTELPUNKT);
        ton(0, ACHTEL);
        ton(BMOL, SECHZEHNTEL);
        ton(0, ACHTEL);
        //----------------------
        ton(G, VIERTEL);
        ton(0, ACHTEL);
        ton(EMOL, ACHTELPUNKT);
        ton(0, ACHTEL);
        ton(BMOL, SECHZEHNTEL);
        ton(0, ACHTEL);
        ton(G, HALB);
        ton(0, ACHTEL);


    }
    return 0;
}

ISR(INT0_vect) {
}
