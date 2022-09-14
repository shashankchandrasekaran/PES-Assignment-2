#include <stdio.h>
#include "cbfifo.h"

#define n 128 //capacity of array
char qdata[n]; //Character array of size n
int write=-1; //Write used for enqueuing
int read=-1; //Read used for dequeuing
size_t length=0; //Number of bytes array is filled with

//****************************************CBFIFO Enqueue function****************************************************
size_t cbfifo_enqueue(void *buf, size_t nbyte)
{
	int store=0,enqbytes=0,temp=0,i=0;
	char *input=buf; //Character pointer created to point to buf
	if(input==NULL) //If the buffer is NULL, error condition
	{
		return -1;
	}
	else if((write==-1)&&(read==-1)) //If no bytes is inserted, insert the first byte of data
	{
		temp=-1; //variable used for enqueuing 1st byte in array
		write=read=0; //read and write now at 0th index of array
		qdata[0]=*input; //First byte enqueued in first element of array
		input++;
		length++;
	}
	if (length==n||nbyte==0) //If the array is full or nbyte requested to enqueue is zero
	{
		return 0; //Indicate no bytes enqueued
	}
	else if(nbyte<=(n-length)) //If bytes to enqueue is less or equal to available elements in array
	{
		if(temp==-1) //To enqueue remaining bytes after 1st byte was inserted in array when write and read was -1
		{
			for(i=0;i<nbyte-1;i++)
			{
				write=(write+1)&(n-1); //To update write in such a way that on last index of array, after incrementing goes to start address
				qdata[write]=*input; //1 byte inserted in array
				input++;
				length++;
			}
			temp=0; //Temp changed to zero as now the array has element
			return nbyte; //Returns number of bytes enqueued
		}
		else //To enqueue nbytes when enqueue is not called first time and above if condition is met
		{
			for(i=0;i<nbyte;i++)
			{
				write=(write+1)&(n-1);
				qdata[write]=*input;
				input++;
				length++;
			}
			return nbyte;
		}
	}
	else if(nbyte>(n-length)) //When bytes to enqueue is more than the available space in array
	{
		if(temp==-1) //To enqueue remaining bytes after 1st byte was inserted in array when write and read was -1
		{
			store=n-length-1;
			for(i=0;i<store;i++)
			{
				write=(write+1)&(n-1);
				qdata[write]=*input;
				input++;
				length++;
				enqbytes++;
			}
			temp=0;
			return enqbytes;
		}
		else
		{
			store=n-length;
			for(i=0;i<store;i++)
			{
				write=(write+1)&(n-1);
				qdata[write]=*input;
				input++;
				length++;
				enqbytes++;
			}
			return enqbytes;
		}
	}
	else
		return 0; //If no conditions above met, enqueue operation is not performed

}


//****************************************CBFIFO Dequeue function****************************************************
size_t cbfifo_dequeue(void *buf, size_t nbyte)
{
	int i;
	size_t deqbyte; //Variable is to store the number of bytes dequeued
	char *output=buf; //Character pointer created to point to buf
	if(((write==-1)&&(read==-1))||length==0||buf==NULL||nbyte==0) //If the array is empty , return that 0 bytes were dequeued
	{
		return 0;
	}
	else if (nbyte>length) //If byte to dequeue is more than length, dequeue all bytes available and return that
	{
		deqbyte=length; //Since array contains length elements, all are dequeued
		for(i=0;i<deqbyte;i++)
		{
			*output=qdata[read]; //Dequeued data stored
			read=(read+1)&(n-1); //Read updated to next array index
			length--; //Length reduced
			output++;
		}
		return deqbyte; //Return bytes dequeued
	}
	else if (nbyte<=length) //If byte to dequeue is less than or equal to length, dequeue those bytes
	{
		for(i=0;i<nbyte;i++)
		{
			*output=qdata[read];
			read=(read+1)&(n-1);
			length--;
			output++;
		}
		return nbyte; //Returns bytes dequeued
	}
	else
		return 0; //If no conditions above met, dequeue operation is not performed
}

//****************************************CBFIFO Length function****************************************************
size_t cbfifo_length()
{
	return length; //No. of elements in array returned
}

//****************************************CBFIFO Capacity function****************************************************
size_t cbfifo_capacity()
{
	return n; //Returns size of array i.e. 128
}

