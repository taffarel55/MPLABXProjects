#include <avr/io.h>

int main1() {
    DDRB = 0xFF;
    PORTB = 0x00;
    while (1) {
        TCNT0 = 0xF2;
        TCCR0A = 0x00;
        TCCR0B = 0x01;
        while((TIFR0 & ~(1<<0)));
        TCCR0B = 0x00;
        TIFR0 = (1<<TOV0);
        PORTB ^= 0xFF;
    }
}