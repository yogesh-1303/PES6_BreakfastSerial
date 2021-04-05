#include <stdio.h>
#include <MKL25Z4.h>
#include "cbfifo.h"
#include "UART.h"


//initializes the fifo instances
//take instance pointer as argument
void cbfifo_init(cbfifo_s *data)
{
	  data->write = 0;
	  data->read = 0;
	  data->is_full = false;
	  data->is_empty = false;
	  data->len = 0;
}

//following function enqueues an element to the circular buffer
// takes the fifo instance, pointer to data and number of bytes to enqueue as arguments
//returns actual number of bytes enqueued
size_t cbfifo_enqueue(cbfifo_s *data, void *str, size_t nbytes)
{
  char *buff = (char *) str;
  uint32_t masking_state;
  uint8_t i=0;

  	  if(nbytes < 0)				//error if bytes entered are negative
  		  {return -1;}

  	  else
  	  {
  		  if(buff == NULL)			//error if null string is entered
  			  {return -1;}

  		  else
  		  {
  			  if(data->is_full)		//Buffer Full
  			  {
  				  data->write = 0;
  				  return 0;
  			  }
  			  else
  			  {
  				  if(nbytes >= ((capacity) - (data->len)))   //if nbytes > remaining size of buf
  				  { nbytes = (capacity) - (data->len);
  				  	data->is_full = true;
  				  }

  				  for(i=0;i<nbytes;i++)			//writing to the buffer
  				  {
  					  data->buffer[data->write] = buff[i];
  					  data->write = (data->write + 1) & (capacity-1);
  					// protect q->Size++ operation from preemption
  								// save current masking state
  								masking_state = __get_PRIMASK();
  								// disable interrupts
  								__disable_irq();
  								// update variable
  					  data->len++;
  					// restore  interrupt masking state
  					     			__set_PRIMASK(masking_state);
  				  }
   	  return nbytes;
  			  }
  		  }

  	  }

}


//following function dequeues an element to the circular buffer
//takes the fifo instance, storage pointer and number of bytes to dequeue as arguments
//returns actual number of bytes enqueued

size_t cbfifo_dequeue(cbfifo_s *data, void *str, size_t nbytes)
{
	char *buff = (char *) str;
	uint32_t masking_state;
	int i=0;									//error if bytes entered are negative
	if(nbytes < 0)
		{return -1;}

	else
    {
      if(buff == NULL)
      { return -1;}

      else
      {
        if(!(data->len))					//if the buffer is empty, reset pointers
        {
          data->write = 0; data->read = 0; data->is_full=false;//data->len = 0;
          return 0;
        }
        else
        {
        	if(nbytes > (data->len))		//if nbytes > length of buffer
        		{nbytes = (data->len);
        		//data->is_empty = true;
        		}

        	for(i=0;i<nbytes;i++)		//reading from the buffer
        	{
        		buff[i] = data->buffer[data->read];
        		//printf("***len = %zu, read = %u, buff[%u] = %c\r\n", data->len, data->read,i,buff[i]);
        		data->read = (data->read + 1)&(capacity-1);
        		// protect q->Size++ operation from preemption
        						// save current masking state
        						masking_state = __get_PRIMASK();
        						// disable interrupts
        						__disable_irq();
        						// update variable
        		data->len--;
        		// restore  interrupt masking state
        		   			__set_PRIMASK(masking_state);
        	}
        	if(!(data->len))
        	{
        		data->write = 0; data->read = 0; data->is_full = false;
        	}
	  return nbytes;
        }
      }
    }

}

//Returns current size of the buffer
//take fifo instance as argument
size_t cbfifo_length(cbfifo_s *data)
{
  return data->len;
}

//Returns capacity of the buffer
size_t cbfifo_capacity()
{
  return capacity;
}

