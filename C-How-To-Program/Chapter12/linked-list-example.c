#include <stdio.h>
#include <stdlib.h>

/*
 * A self referential structure, which is what linked lists are
 */
struct linkedListNode {
	char data;
	struct linkedListNode *nextNodePtr;
};

/*
 * Create some synonyms.
 * 1) For the struct linkedListNode
 * 2) For the pointer to the struct linkedListNode
 */ 
typedef struct linkedListNode LinkedListNode;
typedef LinkedListNode *LinkedListNodePtr;

void insert(LinkedListNodePtr *startPtr, char c);
char delete(LinkedListNodePtr *startPtr, char c);
int isEmpty(LinkedListNodePtr startPtr);
void printLinkedList(LinkedListNodePtr currentPtr);
void printMenu(void);

int main(void)
{
	int done = 0;
	char c;
	/*
	 * The list will start out empty.
	 */ 
	LinkedListNodePtr startPtr = NULL;

	puts("# Linked List Example");
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
				insert(&startPtr, c);
				printLinkedList(startPtr);
				break;
			case '2':
				printf("Enter a character: ");
				/*
				 * Consume the \n
				 */ 
				scanf("\n%c", &c);
				if(!isEmpty(startPtr)) {
					if(delete(&startPtr, c)) {
						printf("Delete linked list node %c\n", c);
						printLinkedList(startPtr);
					}
					else {
						printf("Linked list node %c not found.\n", c);
					}
				}
				else {
					puts("The linked list is empty.");
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

void insert(LinkedListNodePtr *startPtr, char c)
{
	/*
	 * Previous linked list node
	 * Current linked list node
	 * The new linked list node
	 */
	LinkedListNodePtr previousPtr;
	LinkedListNodePtr currentPtr;
	LinkedListNodePtr newPtr;

	/*
	 * mallac tries to allocate memory with the specified bytes.
	 * sizeof will return the size of the data structure, platform dependent.
	 * If successful, malloc returns a void * to the allocated memory, otherwise returns NULL
	 */
	newPtr = malloc(sizeof(LinkedListNode));

	if(newPtr != NULL) {
		/*
		 * Put the data into the node
		 * This is the last node so its link pointer is NULL
		 */ 
		newPtr->data = c;
		newPtr->nextNodePtr = NULL;

		/*
		 * Used to iterate through the linked list
		 */ 
		previousPtr = NULL;
		currentPtr = *startPtr;

		/*
		 * Loop through the list from the start to find the correct location.
		 * We are making this a sorted listed.
		 * If the list is empty we skip this. currentPtr will be NULL if the list is empty.
		 * If the list isn't empty, loop through until we find the correct spot (ie the input data is lower than the current linked list node data.
		 */ 
		while (currentPtr != NULL && c > currentPtr->data) {
			
			previousPtr = currentPtr;
			currentPtr = currentPtr->nextNodePtr;
		}

		/*
		 * The list was empty, make the new node the start
		 */ 
		if(previousPtr == NULL) {
			/*
			 * The new linked list node's link points to the former first node, which was NULL. Terminating the linked list.
			 */ 
			newPtr->nextNodePtr = *startPtr;
			/*
			 * Start pointer is now the new linked list node, replacing NULL.
			 */ 
			*startPtr = newPtr;
		}
		/*
		 * Insert in the correct spot.
		 */ 
		else {
			/*
			 * The new linked list node is placed infront of the previous pointer
			 */
			previousPtr->nextNodePtr = newPtr;
			/*
			 * The new linked list node's link points to the next pointer, which is either NULL to terminate or another linked list node.
			 */ 
			newPtr->nextNodePtr = currentPtr;
		}
	}
	else {
		fprintf(stderr, "%c couldn't be inserted. No memory available.\n", c);
	}
}

char delete(LinkedListNodePtr *startPtr, char c)
{
	/*
	 * Previous linked list node
	 * Current linked list node
	 * The new linked list node
	 */
	LinkedListNodePtr previousPtr;
	LinkedListNodePtr currentPtr;
	LinkedListNodePtr tempPtr;

	/*
	 * If the char to be deleted matches the first linked list node data:
	 * 1) Move the pointer to a temporary variable.
	 * 2) Update the start pointer to point to the next linked list node. This deletes it from the linked list
	 * 3) Free up the memory of the first pointer so it can be used elsewhere.
	 */ 
	if(c == (*startPtr)->data) {
		tempPtr = *startPtr;
		*startPtr = (*startPtr)->nextNodePtr;
		free(tempPtr);
		return c;
	}
	/*
	 * If the first char doesn't match what we want to delete or the list is empty.
	 */
	else {
		/*
		 * Go to the next pointer
		 */ 
		previousPtr = *startPtr;
		currentPtr = (*startPtr)->nextNodePtr;

		/*
		 * Loop through the list to find the correct location.
		 * The correct location is the first linked list node that matches the inputted char.
		 * If the list is empty we skip this.
		 */ 
		while (currentPtr != NULL && c != currentPtr->data) {
			previousPtr = currentPtr;
			currentPtr = currentPtr->nextNodePtr;
		}

		/*
		 * If the list wasn't empty or we found the what we were looking for.
		 * 1) Assign the pointer of interest to a temporary variable
		 * 2) Update the previous linked list node's link to point to the current linked list node's link. This deletes it from the list.
	 	 * 3) Free up the memory of the first pointer so it can be used elsewhere.
		 */ 
		if(currentPtr != NULL) {
			tempPtr = currentPtr;
			previousPtr->nextNodePtr = currentPtr->nextNodePtr;
			free(tempPtr);
			return c;
		}
	}
	
	return '\0';
}

int isEmpty(LinkedListNodePtr startPtr)
{
	return startPtr == NULL;
}

void printLinkedList(LinkedListNodePtr currentPtr)
{
	int printedLinks = 0;

	puts("\n### Printing Linked List Node(s)");
	
	if(currentPtr == NULL) {
		puts("The list is empty.");
	}
	else {
		puts("The linked list is: ");

		/*
		 * Go through each linked list node and get the next pointer.
		 * NULL means we are at the end of the list.
		 */ 
		while(currentPtr != NULL) {
			printf("%c -links-with-> ", currentPtr->data);
			currentPtr = currentPtr->nextNodePtr;
			
			++printedLinks;
			if(printedLinks % 3 == 0) {
				printf("\n");
			}
		}
		printf("NULL\n");
	}
}

void printMenu(void)
{
	puts("\n## Linked List Example Menu");
	puts("Choose from the following options:");
	puts("1) to insert an element into the linked list.");
	puts("2) to delete an element from the linked list.");
	puts("3) to quit.");
	printf("Enter the number for yor choice: ");
}

