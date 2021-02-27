void usart_init(void) {
    UBRR0L = 103;                       			// 9600 baud rate
    UCSR0C = (1<<UCSZ01)|(1<<UCSZ00)|(1<<UMSEL);   	// 8 bits
    UCSR0C&= ~(1<<UPM00) | ~(1<<UPM01); 			// without parity
    UCSR0C& = ~(1<<USBS0);              			// 1 stop bit
}
