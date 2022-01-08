#include<avr/io.h>

void usart_init(void) {
    UCSR0B = (1<<TXEN0);                    // transmit
    UBRR0L = 103;                           // 9600 baud rate
    UCSR0C = (1<<UCSZ01)|(1<<UCSZ00);       // 8 bits
    UCSR0C &= ~(1<<UMSEL01)|~(1<<UMSEL00);  // Assynchronous 
    UCSR0C &= ~(1<<USBS0);                  // 1 stop bit
    UCSR0C &= ~(1<<UPM00) | ~(1<<UPM01);    // without parity
}

void usart_send(unsigned char ch) {
    while(! (UCSR0A & (1<<UDRE0)) );    // wait UDR0 is empty
    UDR0 = ch;
}

int main(void) {
    usart_init();
    while(1) {
        usart_send('A');
    } 
}
