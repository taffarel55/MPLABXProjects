#include<avr/io.h>
#include<avr/interrupt.h>

ISR(ADC_vect) {
    PORTD = ADCL;
    PORTB = ADCH;
    ADCSRA |= (1<<ADSC);
}

int main() {
    DDRB = 0xFF;
    DDRD = 0xFF;
    DDRC = 0;
    sei();
    ADCSRA = 0b10001111;
    ADMUX = 0b11000000;
    ADCSRA |= (1<<ADSC);
    while (1) {
        // any code here;
    }
}
