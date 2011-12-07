#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>



int main(void) {

    DDRC = 0x02;
    PORTC = 0xFF;
    PCIR |= 0x02;

    sei();

    PCMSK1 = PCMSK1 | 0x01;
    set_sleep_mode(SLEEP_MODE_PWR_SAVE);

    while(1) {
        sleep_mode();
    }
    return 0;
}

void ISR() {
    PORTC ^= (1 << PC1);
}
