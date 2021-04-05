/*
 * main.c - application entry point
 * 
 * Author Yogesh Tripathi
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include "MKL25Z4.h"
#include "sysclock.h"
#include "UART.h"
#include "cbfifo.h"
#include "cmd_proc.h"
#include "fifo_test.h"


//main function
int main(void)
{
	sysclock_init();

  Init_UART0(BAUD_RATE);			//setting the Uart
  cbfifo_test();					//cb_fifo test function
  char str[256];

  printf("\r\nWelcome to BreakfastSerial!");

  // enter infinite loop
  while (1) {

	  printf("\r\n? ");
	  scanf("%s", str);

	  process_command(str);			//command processor

  }
  return 0;
}
