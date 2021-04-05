#ifndef CMD_PROC_H
#define CMD_PROC_H
#endif

#include "UART.h"
#include "cbfifo.h"

void handle_dump(int argc, char *argv[]);    //hexdump
void handle_author(int argc, char *argv[]);	//author command
void process_command(char *input);			//processor function
int __sys_write(int handle, char *buf, int size); //where output function are redirected
int __sys_readc(void); //where input functions are redirected


