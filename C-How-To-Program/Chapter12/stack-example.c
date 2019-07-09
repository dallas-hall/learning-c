#include <stdio.h>
#include <stdlib.h>

/*
 * A self referential structure, which is what stacks are
 */
struct stackNode {
	char data;
	struct stackNode *lowerStackPtr;
};

/*
 * Create some synonyms.
 * 1) For the struct stackNode
 * 2) For the pointer to the struct stackNode
 */ 
typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr;

void push(StackNodePtr *topPtr, char c);
char pop(StackNodePtr *topPtr, char c);
int isEmpty(StackNodePtr startPtr);
void printStack(StackNodePtr topPtr);
void printMenu(void);

int main(void)
{
	int done = 0;
	char c;
	/*
	 * The stack will start out empty.
	 * NULL is the bottom of the stack.
	 */ 
	StackNodePtr topPtr = NULL;

	puts("# Stack Example");
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
				push(&topPtr, c);
				printStack(topPtr);
				break;
			case '2':
				if(!isEmpty(topPtr)) {
					printf("Popped %c from the stack.\n", pop(&topPtr, c));
					printStack(topPtr);
				}
				else {
					puts("The stack is empty.");
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

void push(StackNodePtr *topPtr, char c)
{
	/*
	 * The new stack node
	 */
	StackNodePtr newPtr;

	/*
	 * mallac tries to allocate memory with the specified bytes.
	 * sizeof will return the size of the data structure, platform dependent.
	 * If successful, malloc returns a void * to the allocated memory, otherwise returns NULL
	 */
	newPtr = malloc(sizeof(StackNode));

	puts("\n## Pushing To The Stack");

	if(newPtr != NULL) {
		/*
		 * Push the data onto the stack node
		 * If this is the only stack node then the link to the lower stack node is NULL
		 */ 
		newPtr->data = c;
		newPtr->lowerStackPtr = *topPtr;
		*topPtr = newPtr;
	}
	else {
		fprintf(stderr, "%c couldn't be pushed onto the stack. No memory available.\n", c);
	}
}

char pop(StackNodePtr *topPtr, char c)
{
	StackNodePtr tempPtr;
	char popped;

	puts("\n## Popping Off The Stack");
	
	tempPtr = *topPtr;
	popped = (*topPtr)->data;
	*topPtr = (*topPtr)->lowerStackPtr;
	free(tempPtr);

	return popped;
}

int isEmpty(StackNodePtr topPtr)
{
	return topPtr == NULL;
}

void printStack(StackNodePtr topPtr)
{
	puts("### Printing Stack Node(s)");
	
	if(topPtr == NULL) {
		puts("The stack is empty.");
	}
	else {
		puts("The stack is: ");

		/*
		 * Go through each stack node and get the next pointer.
		 * NULL means we are at the end of the list.
		 */ 
		while(topPtr != NULL) {
			printf("%c - stacks on top of: \n", topPtr->data);
			topPtr = topPtr->lowerStackPtr;
		}
		printf("NULL - the end of the stack.\n");
	}
}

void printMenu(void)
{
	puts("\n## Stack Example Menu");
	puts("Choose from the following options:");
	puts("1) to push an element onto the stack.");
	puts("2) to pop an element off the stack.");
	puts("3) to quit.");
	printf("Enter the number for yor choice: ");
}

