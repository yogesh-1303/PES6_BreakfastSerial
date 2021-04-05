#ifndef UART_H
#define UART_H
#endif

#include <stdint.h>

//defining parameters for initialization of UART
#define OVERSAMPLE_RATE 16
#define BAUD_RATE 38400
#define DATA_SIZE 8
#define STOP_BITS 2
#define PARITY 0


void Init_UART0(uint32_t baud_rate);   //function to initialize the Uart for interrupt handling
