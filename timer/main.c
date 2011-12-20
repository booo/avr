#include <avr/io.h>
#include <avr/sleep.h>
#include <avr/interrupt.h>

int main(void) {

    DDRD = 0xFF;  //Port D konfigurieren

    PORTD = 0x00; //Alle LEDs am Anfang aus

    TCCR0A |= 0b00000010;
    TCCR0A &= 0b00001110;

    TCCR0B |= 0b00000101;
    TCCR0B &= 0b00110101;

    OCR0A |= 0xc8;

    TIMSK0 |= 0b00000010;
    TIMSK0 &= 0b11111010;


    sei(); //Interrupts zulassen

    set_sleep_mode(SLEEP_MODE_IDLE);


    while(1) {

        sleep_mode();

    }

    return 0;

}

//Interrupt Service Routine
ISR(TIMER0_COMPA_vect) {

    PORTD = PORTD + 0x01;

}


