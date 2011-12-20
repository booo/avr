#include <avr/io.h>
#include <avr/sleep.h>
#include <stdint.h>
#include <avr/interrupt.h>

int main(void) {

    DDRD = 0xFF;  //Port D konfigurieren
    PORTD = 0x00; //Alle LEDs am Anfang aus

	//ADC einstellen
	ADMUX = ADMUX | 0b00100000;
	ADMUX = ADMUX & 0b00110000;
	ADCSRA |= 0b11001111;
	ADCSRA |= 0b11011111;

    sei(); //set enable interrups: Interrups global zulassen

	set_sleep_mode(SLEEP_MODE_ADC); //ADC Sleep Modus

    while(1) {
        sleep_mode();

    }

    return 0;
}

//Interrupt Service Routine für den ADC

ISR(ADC_vect) {

	PORTD = ADCH;

}
