#ifndef SWARM_DEVICE_UART_H_
#define SWARM_DEVICE_UART_H_

// Initializes UART peripherial
// module_id [in] : Defines the ID of the peripherial to be used
// baud [in]   : baud rate in decimal for example 9600 baud etc
// parity [in] : 0 for none, 1 for even, 2 for odd
// stop_bits [in] : Number of stop bits 
// sync[in] : 0 for Synchronous and 1 for Asynchronous.
void uart_init(uint8_t module_id, uint32_t baud, uint8_t parity, uint8_t stop_bits, uint8_t sync);

// send data to main microcontroller
bool uart_send(uint8_t module_id, char* data, uint16_t size);

// send data to main microcontroller
bool uart_recieve(uint8_t module_id, char* data, uint16_t* size);

#endif SWARM_DEVICE_UART_H_
