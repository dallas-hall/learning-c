#include <stdio.h>
#include <stdlib.h>

/*
 * A self referential structure, which is what stacks are
 */
struct queueNode {
	char data;
	struct queueNode *nextInLinePtr;
};

/*
 * Create some synonyms.
 * 1) For the struct queueNode
 * 2) For the pointer to the struct queueNode
 */ 
typedef struct queueNode QueueNode;
typedef QueueNode *QueueNodePtr;

void enqueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, char c);
char dequeue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr);
int isEmpty(QueueNodePtr headPtr);
void printQueue(QueueNodePtr headPtr);
void printMenu(void);

int main(void)
{
	int done = 0;
	char c;
	/*
	 * The queue will start out empty.
	 * NULL is the end of the queue.
	 */ 
	QueueNodePtr headPtr = NULL;
	QueueNodePtr tailPtr = NULL;

	puts("# Queue Example");
	do {
		printMenu();
		scanf("\n%c", &c);

		switch (c) {
			case '1':
				printf("Enter a character: ");
				/*
				 * Consume the \n
				 */ 
				scanf("\n%c", &c);
				enqueue(&headPtr, &tailPtr, c);
				printQueue(headPtr);
				break;
			case '2':
				if(!isEmpty(headPtr)) {
					printf("Dequeued %c from the stack.\n", dequeue(&headPtr, &tailPtr));
					printQueue(headPtr);
				}
				else {
					puts("The queue is empty.");
				}
				break;
			case '3':
				done = 1;
				break;
			default:
				puts("\nInvalid input.");
				break;
		}
	}
	while (!done);
	
	puts("Program exiting.");
	return EXIT_SUCCESS;
}

void enqueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, char c)
{
	/*
	 * The new queue node
	 */
	QueueNodePtr newPtr;

	/*
	 * mallac tries to allocate memory with the specified bytes.
	 * sizeof will return the size of the data structure, platform dependent.
	 * If successful, malloc returns a void * to the allocated memory, otherwise returns NULL
	 */
	newPtr = malloc(sizeof(QueueNode));

	puts("\n## Enqueuing Onto The Queue End");

	if(newPtr != NULL) {
		/*
		 * Push the data onto the stack node
		 * The new queue item will always have NULL at the end, since it is at the end of the queue.
		 */ 
		newPtr->data = c;
		newPtr->nextInLinePtr = NULL;

		/*
		 * If the queue is empty, enqueue to the start of the queue.
		 * Else enqueue on the end.
		 */ 
		if(isEmpty(*headPtr)) {
			*headPtr = newPtr;
		}
		else {
			(*tailPtr)->nextInLinePtr = newPtr;
		}
		*tailPtr = newPtr;
	}
	else {
		fprintf(stderr, "%c couldn't be enqueued into the queue. No memory available.\n", c);
	}
}

char dequeue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr)
{
	QueueNodePtr tempPtr;
	char dequeued;

	puts("\n## Dequeuing From The Queue");
	
	tempPtr = *headPtr;
	dequeued = (*headPtr)->data;
	*headPtr = (*headPtr)->nextInLinePtr;

	if(isEmpty(*headPtr)) {
		*tailPtr = NULL;
	}

	free(tempPtr);

	return dequeued;
}

int isEmpty(QueueNodePtr headPtr)
{
	return headPtr == NULL;
}

void printQueue(QueueNodePtr headPtr)
{
	puts("### Printing Queue Node(s)");
	
	if(headPtr == NULL) {
		puts("The queue is empty.");
	}
	else {
		puts("The queue is: ");

		/*
		 * Go through each stack node and get the next pointer.
		 * NULL means we are at the end of the list.
		 */ 
		while(headPtr != NULL) {
			printf("%c -is-infront-of: \n", headPtr->data);
			headPtr = headPtr->nextInLinePtr;
		}
		printf("NULL - the end of the queue.\n");
	}
}

void printMenu(void)
{
	puts("\n## Queue Example Menu");
	puts("Choose from the following options:");
	puts("1) to enqueue an element onto the end of the queue.");
	puts("2) to dequeue an element out of the front of the queue.");
	puts("3) to quit.");
	printf("Enter the number for yor choice: ");
}

