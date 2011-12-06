#include <avr/io.h>

#include <stdint.h>

int main(void) {

    //DDRC = 0b00000110;
    DDRC = 0x06;
    PORTC = 0xF9;
    while(1) {
        //paste some shit here
        if (PINC & (1<<PINC0)) {
            PORTC = 0b11111101;
            //PORTC = (1<<PC5) | PORTC;
            //PORTC = (0<<PC4) & PORTC;
            //grün an - rot aus
        } else {
            //PORTC = (1<<PC) | PORTC;
            //rot an - grün aus
            PORTC = 0b11111011;
        }
        
    }
    return 0;
}
