#include<avr/io.h>
#include<avr/interrupt.h>

ISR(ADC_vect) {
    while(! (UCSR0A & (1<<UDRE0)) );    // wait UDR0 is empty
    UDR0 = ADCH;
    ADCSRA |= (1<<ADSC);
}

void usart_init(void) {
    UCSR0B = (1<<TXEN0);                     // transmit
    UBRR0L = 0x33;                           // 9600 baud rate
    UCSR0C = (1<<UCSZ01)|(1<<UCSZ00);        // 8 bits
    UCSR0C &= ~(1<<UMSEL01)| ~(1<<UMSEL00);  // Assynchronous 
    UCSR0C &= ~(1<<USBS0);                   // 1 stop bit
    UCSR0C &= ~(1<<UPM00) | ~(1<<UPM01);     // without parity
}

int main() {
    usart_init();
    DDRC = 0;
    sei();
    ADCSRA = 0b10001111;
    ADMUX = 0b01100000;
    ADCSRA |= (1<<ADSC);
    while (1) {
        // any code here;
    }
}
