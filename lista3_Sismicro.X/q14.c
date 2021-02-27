#include<avr/io.h>

void usart_init(void) {
    UCSR0B = (1<<TXEN0);                    // transmit
    UCSR0B = (1<<TXCIE0);                   // enable interrupt
    UBRR0L = 103;                            // 19200 baud rate
    UCSR0C = (1<<UCSZ01)|(1<<UCSZ00);       // 8 bits
    UCSR0C &= ~(1<<UMSEL01)| ~(1<<UMSEL00);  // Assynchronous 
    UCSR0C &= ~(1<<USBS0);                  // 1 stop bit
    UCSR0C &= ~(1<<UPM00) | ~(1<<UPM01);    // without parity
}

int main(void) {
    usart_init();
    while(1) {
        // any code here
    } 
}

void ISR (USART_TX_vect) {
    UDR0 = 0x65;
}