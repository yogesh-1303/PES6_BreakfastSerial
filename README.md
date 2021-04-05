# PES6_BreakfastSerial
The Environment:
The program is created in MCUXpresso with FRDM KL25Z MCU board.

The program contains following files:

1.	UART.c and UART.h :
UART.c file contains the uart initialization function which sets the parameters of uart accordingly as specified in the assignment. It also calls initialization functions for rx and tx fifo instances. The setup is interrupt based.
 
UART.h files declares the prototypes of the function used in UART.c as well as defines some UART parameters.

2.	cbfifo.c and cbfifo.h
cbfifo.c file contains functions to enqueue a string, dequeue a string, return length, and return capacity. The enqueue and dequeue functions use masking to protect the critical section of the code.

cbfifo.h defines the circular buffer structure and conatians prototypes of all the functions used in cbfifo.c. It also creates instances for receiving and transmitting data from and to the fifo.

3.	fifo_test.c and fifo_test.h
fifo_test.c tests the circular buffer by enqueueing and dequeuing different sets of bytes as and checking for length, string, and bytes. It checks the errors conditions as well

fifo_test.h contains the prototype of the function testing the cbfifo in cbfifo.c

4.	cmd_proc.c and cmd_proc.h
the cmd_proc.c file contains the function which does the lexical analysis by tokenizing a string and dispatches the argc and *argv[] to the command as specified in the input of the function. It also contains the function definitions for each command and a function pointer to call the command specified by the user. Also a table of command name and handler is created for comparison of the command input by the user and the command already stored. This file is the gist of the program and prints appropriate response when user enters a command. Further, this file contains the redlib input function __sys_readc() and redlib output function __sys_write() where input standard input and output functions are redirected when called.

cmd_proc.h contains prototypes of the command functions and the command processor function. It also contains the prototypes of redlib sys functions.

5.	sysclock.c and sysclock.h
sysclock.c contains the function that initializes the system clock for the MCU to operate. This file was already provided and no changes have been made to the file.

Sysclock.h contains prototype of the function that initializes the sysclock and defines the macro for clock frequency.


6.	main.c
this file contains the main function which calls the command processor. 
