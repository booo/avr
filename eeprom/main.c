#include <avr/io.h>
#include <avr/sleep.h>
#include <util/delay.h>
#include <avr/eeprom.h>

//EEPROM nicht lokal definieren

uint8_t speicher EEMEM;

int main(void) {

    DDRD = 0xFF;  //Port D konfigurieren
    PORTD = 0x00; //Alle LEDs am Anfang aus


    uint8_t zaehler;
    //read eeprom value at EEMEM into zaehler
    zaehler = eeprom_read_byte(&speicher);


    while(1) {
        PORTD = zaehler;
        _delay_ms(1000);
        zaehler = zaehler + 1;

        //write value zaehler into eeprom
        eeprom_write_byte(&speicher, zaehler);
	}

    return 0;
}
