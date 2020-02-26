#include<avr/io.h>

void usart_init(void) {
    UCSR0B = (1<<RXEN0);                    // receiver
    UCSR0B = (1<<RXCIE0);                   // enable interrupt
    UBRR0L = 51;                            // 19200 baud rate
    UCSR0C = (1<<UCSZ01)|(1<<UCSZ00);       // 8 bits
    UCSR0C &= ~(1<<UMSEL01)| ~(1<<UMSEL00);  // Assynchronous 
    UCSR0C &= ~(1<<USBS0);                  // 1 stop bit
    UCSR0C &= ~(1<<UPM00) | ~(1<<UPM01);    // without parity
}

int main(void) {
    usart_init();
    PORTB=0xFF;
    while(1) {
        // any code here
    } 
}

void ISR (USART_RX_vect) {
    PORTB = UDR0;
}
