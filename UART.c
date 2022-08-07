#define UBRRL					((volatile u8)0x29)		

#define UCSRC					((volatile u8)0x40)		

/*
 * baudrate: is an input argument that describes baudrate that the UART needs to make the communications.
 */
 void SWUART_init(uint32_t baudrate){

UBRRL = (uint8_t)(((8000000) / (16UL * 9600)) - 1);
UCSRC = 0b00101110;

 }

/*
 * data: is an input argument that describes a byte of data to be send over the SW UART.
 */
 void SWUART_send(uint8_t data)
 {
    while((UCSRA&0x20) == 0x00);
    UDR = data;
 }
 
 /*
 * data: is an output argument that describes a byte of data to be recieved by the SW UART.
 */
 void SWUART_recieve(uint8_t *data)
 {
  while((UCSRA&0x80) == 0x00);
  *data = UDR;
  SET_BIT(UCSRA,7);
 }

