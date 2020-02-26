#include<avr/io.h>
#include<avr/interrupt.h>

ISR(ADC_vect) {
    PORTB = ADCH;
    ADCSRA |= (1<<ADSC);
}

int main() {
    DDRB = 0xFF;
    DDRC = 0;
    sei();
    ADCSRA = 0b10001111;
    ADMUX = 0b11100001;
    ADCSRA |= (1<<ADSC);
    while (1) {
        // any code here;
    }
}