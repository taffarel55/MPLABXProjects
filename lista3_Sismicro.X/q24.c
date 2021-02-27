#include<avr/io.h>

int main() {
    DDRB = 0xFF;
    DDRC = 0x00;
    ADCSRA = 0b10000111;
    ADMUX = 0b11100001;
    while (1) {
        ADCSRA |= (1<<ADSC);
        while(! (ADCSRA && (1<<ADIF)));
        ADCSRA = (1<<ADIF);
        PORTB = ADCH;
    }
}