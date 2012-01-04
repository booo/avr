#include <avr/io.h>
#include <avr/sleep.h>
#include <util/delay.h>
#include <stdint.h>
#include <avr/interrupt.h>

#define TAKT 1000000
#define PRESCALER 64
#define ACHTEL 100

int main(void) {

    DDRD |= (1<<PD6);
    //DDRD = 0b01000000;
    //PORTD = 0b10111111;
    //PORTD = 0xFF;

    //TCNT0 = 0x00;
    //OCR0A = 255;

    //TCCR0A = TCCR0A | 0b10000011;
    //TCCR0A = TCCR0A & 0b10001111;

    //TCCR0B = TCCR0B | 0b00001010;
    //TCCR0B = TCCR0B & 0b11111010;

    TCCR0A |= (1<<COM0A1) | (1<<WGM00) | (1<<WGM01);
    TCCR0A &= ~(1<<COM0A0);
    TCCR0B |= (1<<CS01);
    TCCR0B &= ~((1<<FOC0A) | (1<<FOC0B) | (1<<CS00) | (1<<CS02));


    //use a 10kOhm resistor for voltage divider
    //ADC einstellen
    //select ADC0
    //no adjustment
    ADMUX = ADMUX & 0b00010000;

    //ADCSRA |= 0b11001111;
    ADCSRA |= 0b11011111;

    OCR0A=255;

    sei(); //set enable interrups: Interrups global zulassen

    //set_sleep_mode(SLEEP_MODE_ADC); //ADC Sleep Modus
    //enter ADC noise reduction
    //SMCR = SMCR | 0b00000011;
    //SMCR = SMCR & 0b11110011;
    set_sleep_mode(SLEEP_MODE_ADC);

    while(1) {
        sleep_mode();
        //PORTD ^= 0xFF;
        //_delay_ms(10000);
    }

    return 0;

}

//void ton(uint16_t freq) {
//
//    if (freq == 0){
//        TCCR0A = TCCR0A & 0b01111111;
//    }
//
//    else {
//        TCCR0A = TCCR0A | 0b10000000;
//        OCR0A = TAKT/(freq * 2 * PRESCALER) - 1;
//    }
//
//}


//Interrupt Service Routine für den ADC

ISR(ADC_vect) {
    //we read analog values from 1.82V to 4.82V
    //ADC VALUES should be in the range of
    //372 to 983
    //compute a linear function with this values
    //and the requested tune spectrum 100Hz to 5kHz
    //read 10 bits of ADC
    //read ADCL first
    uint16_t freq = ADCL;
    //read ADCH and shift it by 8 bits
    //use bitwise or to add this to freq
    //=> 10bit ADC sample
    freq = freq | (ADCH << 8);
    if(158 <= freq && freq <= 922) {
        //OCR0A = 3.18*freq+110.2;
        OCR0A--;
        //create a tune
        //ton((8.02*freq)-2883.31);
    } else {
        //no tune
        //ton(0);
    }
    //_delay_ms(100);
}
