/* 
a)
 * 1) 0b00000000 00
 * 2) 0b00100001 01
 * 3) 0b01001101 00
 * 4) 0b01111000 01
 * 5) 0b10110100 01
b)         
*/

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
    ADMUX = 0b01000000;
    ADCSRA |= (1<<ADSC);
    while (1) {
        // any code here;
    }
}