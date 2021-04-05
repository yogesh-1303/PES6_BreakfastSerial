#include "fifo_test.h"
#include "cbfifo.h"
#include "UART.h"
#include <assert.h>


//function testing the cbfifo
void cbfifo_test()
{

			char *str = "This is the testing of cbfifo!!";
			char deQ[256];
			size_t bytes;

			cbfifo_s *inst = (cbfifo_s *) malloc (sizeof(cbfifo_s));
			cbfifo_init(inst);
			//enqueing the bytes
		      bytes = cbfifo_enqueue(inst, "Hello", 5);
			  assert (bytes == 5);
			  assert (cbfifo_length(inst) == 5);

			  bytes = cbfifo_enqueue(inst, "its", 3);
			  assert(bytes == 3);
			  assert (inst->len == 8);

			  //dequeueing bytes and checking for length, bytes, and string dequeued
	       	  bytes = cbfifo_dequeue(inst, &deQ, 3);
	       	  assert(bytes == 3);
	       	  assert (inst->len == 5);
	       	  assert (deQ[0] == 'H');
	       	  assert (deQ[1] == 'e');
	       	  assert (deQ[2] == 'l');

	       	  //making the fifo empty
	       	  bytes = cbfifo_dequeue(inst, &deQ, 5);
	       	  assert(bytes == 5);
	          assert (inst->len == 0);

	          //enqueueing null string
	       	  bytes = cbfifo_enqueue(inst, NULL, 2);
	       	  assert(bytes == -1);

	       	  //checking if correct string is enqueued and of no. of bytes specified
	       	  bytes = cbfifo_enqueue(inst, str, 5);
	       	  assert(bytes == 5);
	       	  assert (inst->buffer[0] == 'T');
	       	  assert (inst->buffer[1] == 'h');
	       	  assert (inst->buffer[2] == 'i');
	          assert (inst->buffer[3] == 's');
	          assert (inst->buffer[4] == ' ');
}

