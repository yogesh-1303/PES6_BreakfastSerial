
#include "cmd_proc.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "MKL25Z4.h"
#include "UART.h"

//function pointer to handle ommand functions
typedef void (*command_handler_t)(int, char *argv[]);

//command table structure
typedef struct {
	const char *name;
	command_handler_t handler;
	//const char *help_string;
} command_table_t;


//function handling the command author
//takes argc and *argv[] as arguments
//returns void
void handle_author(int argc, char *argv[])
{
	printf("\r\nYogesh Tripathi");
}


//function to handle dump command
void handle_dump(int argc, char *argv[]) {

	     return;

}

//lookup table for commands
static const command_table_t commands[] = {
		{"author", handle_author},
		{"dump", handle_dump}
};


static const int num_commands =  sizeof(commands) / sizeof(command_table_t);

//command processor function
//takes command as input string in argument
//dispatches the function pointer to call command
void process_command(char *input)
{
	char *p = input;
	char *end = (char *) malloc(sizeof(end));

	// find end of string
	 for(end = input; *end != '\0'; end++)
			;

	// Tokenize input in place
	char *argv[10];
	int argc = 0;
	memset(argv, 0, sizeof(argv));
	for (p = input; p < end;)
	{

		if((*p != '\0')&&(*p != ' '))            //when inside the token
		{
			argv[argc] = p;						//make the *argv[] vector pointer the token
			argc++;
			int i=0;
			while((*(p+i) != '\0')&&(*(p+i) != ' ')) //when in last character of the token
				i++;
			p = (p+i);
			*p ='\0';							//embed '\0' at the end of the token
			p++;
		}
		else									//when outside the token
			p++;
	}

		argv[argc] = NULL;
	if (argc == 0)   // no command
		return;

	//compare the command name with input and if matches call the handler
	for (int i=0; i < num_commands; i++) {
		if (strcasecmp(argv[0], commands[i].name) == 0) {
			commands[i].handler(argc, argv);
			break;
		}
		else							//if no name matches, display invalid command
		{
			if (i==num_commands-1)
			{
			printf("\r\nUnknown Command: %s", input);
			}
		}
	}
}

//Redlib function where output functions like like printf(), putchar(), etc are redirected
//arguments: handle for stdout or stderr, *buf is a string pointer to be printed, size is size of buff
//returns 0 in case of success and -1 in case of error
int __sys_write(int handle, char *buf, int size)
{

	if(handle == 0){
		return -1;						//in case of error
	}
	else
	{
	while(*buf != '\0')
	{
		// copy characters up to null terminator
			  					while (cbfifo_length(&tx_inst) == capacity)
			  						; // wait for space to open up
			  					cbfifo_enqueue(&tx_inst, buf, 1);  //enqueue to the tx buffer
			  					buf++;
	}
	if (!(UART0->C2 & UART0_C2_TIE_MASK)) {
	  					UART0->C2 |= UART0_C2_TIE(1);    //enable tx interrupt if not already enabled
	  				}
	return 0;
	}
}

//Redlib function where input functions like scanf(), sscanf(), etc are redirected
//no arguments in input
//returns character read
int __sys_readc(void)
{
	char c;
 while(cbfifo_length(&rx_inst)==0)
	  ;									//wait if fifo is empty
  cbfifo_dequeue(&rx_inst, &c, 1);		//dequeue from the rx buffer
  putchar(c);							//echo back the character to the terminal

	 return c;
}
