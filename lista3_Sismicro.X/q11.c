#include<avr/io.h>

void usart_init(void) {
    UCSR0B = (1<<RXEN0);                    // receiver
    UBRR0L = 51;                            // 19200 baud rate
    UCSR0C = (1<<UCSZ01)|(1<<UCSZ00);       // 8 bits
    UCSR0C &= ~(1<<UMSEL01)|~(1<<UMSEL00);  // Assynchronous 
    UCSR0C &= ~(1<<USBS0);                  // 1 stop bit
    UCSR0C &= ~(1<<UPM00) | ~(1<<UPM01);    // without parity
}

void usart_receive(void) {
    while(! (UCSR0A & (1<<RXC0)) );    // wait UDR0 new data
    PORTB = UDR0;
}

int main(void) {
    DDRB=0xFF;
    usart_init();
    while(1) {
        usart_receive();
    } 
}