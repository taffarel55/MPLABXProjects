#include <avr/io.h>

int main5() {
    DDRB|=(1<<0);
    PORTB&=~(1<<0);
    while(1) {
        TCNT0 = 0xC2;
        TCCR0A = 0x00;
        TCCR0B = 0x02;
        while(TIFR0 & (1<<TOV0) == 0);
        TCCRB = 0x00;
        TIFR0 = (1<<TOV0);
        POTB^=(1<<0);    
    }
}