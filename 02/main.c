#include <avr/io.h>

#include <stdint.h>
#include <util/delay.h>



int main(void) {

    //DDRC = 0b00000110;
    DDRC = 0x06;
    PORTC = 0xF9;
    PORTC = 0xFF;
    while(1) {
        _delay_ms(500);
        PORTC = 0xFB;
        _delay_ms(500);
        PORTC = 0xFD;

    }
    return 0;
}
