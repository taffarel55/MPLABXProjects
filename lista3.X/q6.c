#include<avr/io.h>
#include <avr/interrupt.h>

int main6() {
    DDRB |= (1<<5);
    PORTB &= ~(1<<5);
    while (1) {
        TCCR0B = 0x01; // no prescaler
        TCNT0 = 0xF6; // left 10 to timer0 overflow
        TIMSK0 = (1<<TOIE0); // Overflow Interrupt enable
        sei();
        while(1){
            // any
        }
    }
}
ISR(TIMER0_OVF_vect) {
    TIRF0 = (1<<TOV0);
    TCNT0 = 0xF6;
    PORTB ^= (1<<5);
}
