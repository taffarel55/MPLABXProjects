#include <avr/io.h>

int main2() {
    DDRB |= (1<<4);     //set PB4 to out
    PORTB &= ~(1<<4);   //set PB4 to 0
    while(1) {
        TCNT0=0x74;                     //set Timer0 to 116 = 256 - 140
        TCCR0A = 0x00;                  //set normal counting 
        TCCR0B = 0x02;                  //set prescale by 8
        while((TIFR0&0x01)==0){}  //wait the counter
        TCCR0B = 0x00;                  //stop timer0
        TIFR0 = (1<<0);                 //reset the flag
        PORTB ^= (1<<4);                //invert PB4
    }
}