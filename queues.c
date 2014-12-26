#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

// Data structure for the Queue
// is just like linked list
struct Queue {

	int data;
	struct Queue* next;

};

void enqueue(struct Queue** start, int data)
{
	// allocates memory in the stack
	struct Queue* temp = (struct Queue*) malloc(sizeof(struct Queue));

	// sets the current data to the data given
	temp->data = data;
	temp->next = NULL;

	// if the value that start points to
	// is null, then set it to the
	// memory address of the temp
	if( (*start) == NULL )
		(*start) = temp;

	else {

		struct Queue* copy = *start; // points to the address pointed by start

		// iterates over the linked list
		// until it finds the next as NULL
		while( (*start)->next != NULL )
			(*start) = (*start)->next; 

		// Sets the pointer null as the
		// address of the temp
		(*start)->next = temp;

		// points the starting of the queue
		// back to the top
		(*start) = copy;

	}

}

void dequeue(struct Queue** start)
{
	// if the queue is empty
	// exits
	if( (*start) == NULL )
		printf("The queue is empty!\n");

	else {
		
		// a copy of the current address of the start
		struct Queue* copy = *start;

		// iterator
		if( (*start)->next != NULL )
			(*start) = (*start)->next;

		// freeing the memory allocated in the stack
		free(copy);

		printf("Dequeue success!\n");

	}
}

int main()
{
	struct Queue* start = NULL; // declare as NULL

	enqueue(&start, 10); // add data
	enqueue(&start, 20);

	dequeue(&start); // remove the first data

	getch();
	return 0;
}