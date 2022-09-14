#include "llfifo.h"
#include <stdlib.h> //For malloc


struct node //Node with 2 parameters: Data and location of next node
{
	void *value;
	struct node *next;
};

struct llfifo_s //LLFIFO definition
{
	struct node *front;
	struct node *rear;
	struct node *store;
	int length;
	int capacity;
};

typedef struct node node1;

//**************************************LLFIFO create function*******************************************************
llfifo_t *llfifo_create(int capacity)
{
	if (capacity<0) //Invalid capacity
	{
		return NULL; //FIFO is made null
	}
	llfifo_t *newfifo=(llfifo_t*)malloc(sizeof(llfifo_t)); //Creates new LLFIFO
	if(newfifo==NULL)//If malloc doesn't allocate memory
	{
		return NULL;
	}
	newfifo->capacity=capacity;
	newfifo->length=0;
	newfifo->front=NULL;
	newfifo->rear=NULL;
	if(capacity>0)
	{
		node1* temp=(node1*)malloc(sizeof(node1)); //Node creation
		if(temp==NULL)//If malloc doesn't allocate memory
		{
			return NULL;
		}
		newfifo->front=newfifo->rear=temp; //Front and rear pointers of FIFO assigned address of temp
		capacity--; //Decreased capacity as 1 node created
		while(capacity!=0) //Loop to create remaining nodes
		{
			temp=(node1*)malloc(sizeof(node1));
			if(temp==NULL)//If malloc doesn't allocate memory
			{
				return NULL;
			}
			newfifo->rear->next=temp;
			newfifo->rear=temp;
			capacity--;
		}
		newfifo->rear->next=NULL; //Last node's next address pointed to null
		newfifo->rear=newfifo->store=newfifo->front; //Rear pointer set back to start node address
	}
	return newfifo; //LLFIFO returned
}

//**************************************LLFIFO enqueue function*******************************************************
int llfifo_enqueue(llfifo_t *fifo, void *element)
{
	if (element==NULL)
	{
		return -1;
	}
	else if ((fifo->front==NULL)&&(fifo->rear==NULL)) //Condition to create a node and then add element(When capacity=0)
	{
		fifo->capacity=1;
		fifo->length=1;
		node1* newnode=(node1*)malloc(sizeof(node1));
		if(newnode==NULL)//If malloc doesn't allocate memory
		{
			return -1;
		}
		fifo->front=fifo->rear=fifo->store=newnode;
		fifo->rear->value=element;
		fifo->rear->next=NULL;
		return fifo->length; //Returns new length of LLFIFO
	}
	else if ((fifo->length==0)&&(fifo->capacity>0)) //Condition when no data is present in any nodes but capacity is there
	{
		fifo->rear->value=element;
		(fifo->length)++;
		return fifo->length;
	}
	else if(fifo->length==fifo->capacity) //Condition when LLFIFO length =capacity, capacity increased and new node added
	{
		fifo->capacity=(fifo->length)+1;
		node1* temp=(node1*)malloc(sizeof(node1)); //Adding new node
		if(temp==NULL)//If malloc doesn't allocate memory
		{
			return -1;
		}
		fifo->rear->next=temp;
		fifo->rear=temp;
		fifo->rear->value=element;
		fifo->rear->next=NULL;
		(fifo->length)++;
		return fifo->length;
	}
	else if((fifo->length<fifo->capacity)&&((fifo->rear->next)!=NULL)) //Condition when LLFIFO length is less than capacity and the next node address is not null
	{
		fifo->rear=fifo->rear->next; //Rear moved to next address
		fifo->rear->value=element;
		(fifo->length)++;
		return fifo->length;
	}
	else if((fifo->length<fifo->capacity)&&((fifo->rear->next)==NULL)) //Condition when LLFIFO length is less than capacity and the next node address is null
	{
		fifo->rear->next=fifo->store; //Rear pointer's next pointing to address store is pointing at which was dequeued before
		fifo->rear=fifo->store;
		fifo->rear->value=element;
		fifo->store=fifo->store->next; //Store pointer moved to next address
		fifo->rear->next=NULL; //Next address made null as this is last node now
		(fifo->length)++;
		return fifo->length;
	}
	else
		return -1; //For any other case return -1 as all valid conditions are covered above
}


//**************************************LLFIFO dequeue function*******************************************************
void *llfifo_dequeue(llfifo_t *fifo)
{
	void *deqvalue;
	if (fifo->length==0) //Condition if all nodes are empty
	{
		return NULL;
	}
	else if (fifo->front==fifo->rear) //If front and rear pointers are pointing to same address
	{
		deqvalue=fifo->front->value; //Dequeued element stored
		fifo->front->value=NULL; //Value made null in the node
		fifo->rear=fifo->front=fifo->store;
		(fifo->length)--;
		return deqvalue;
	}
	else
	{
		deqvalue=fifo->front->value; //Dequeued element stored
		fifo->front->value=NULL;
		fifo->front=fifo->front->next;
		(fifo->length)--;
		return deqvalue;
	}
}

//**************************************LLFIFO length function*******************************************************
int llfifo_length(llfifo_t *fifo)
{
	return fifo->length; //Returns number of nodes filled in LLFIFO
}

//**************************************LLFIFO Capacity function*******************************************************
int llfifo_capacity(llfifo_t *fifo)
{
	return fifo->capacity; //Returns capacity of LLFIFO
}

//**************************************LLFIFO Destroy function*******************************************************
void llfifo_destroy(llfifo_t *fifo)
{
	node1 *track=fifo->store; //Variable track to get the address of store (which is start address of LLFIFO)
	node1 *temp; //Variable temp used to free the nodes
	while(track!=NULL) //Loop to free nodes till the last node is detected
	{
		temp=track;
		track=track->next;
		temp->next=NULL;
		free(temp);
	}
	//The FIFO is destroyed below
	fifo->length=0;
	fifo->capacity=0;
	fifo->front=NULL;
	fifo->rear=NULL;
	fifo->store=NULL;
	fifo=NULL;
	free(fifo);
}


