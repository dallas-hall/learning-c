#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

/*
 * A self referential structure, which is what linked lists are
 */
struct linkedListNode {
	char data;
	struct linkedListNode *nextListNodePtr;
};

/*
 * Create some synonyms.
 * 1) For the struct linkedListNode
 * 2) For the pointer to the struct linkedListNode
 */
typedef struct linkedListNode LinkedListNode;
typedef LinkedListNode *LinkedListNodePtr;
int DEBUGGING = 1;

void createLinkedList(LinkedListNodePtr *listPtr, int n, int createSorted);
void insert(LinkedListNodePtr *startPtr, char c, int createSorted);
void printLinkedList(LinkedListNodePtr currentPtr);

int main(void)
{
	LinkedListNode list1;
	LinkedListNode list2;
	LinkedListNode list3;

	/*
	 * NULL is an empty list.
	 */ 
	LinkedListNodePtr list1Ptr = NULL; 
	LinkedListNodePtr list2Ptr = NULL; 
	LinkedListNodePtr list3Ptr = NULL; 

	puts("# Concatenate Linked Lists");
	/*
	 * Send the pointer address and create the list
	 */
	createLinkedList(&list1Ptr, 5, 1);	
	printLinkedList(list1Ptr);
	
	puts("\nWaiting 1 second so we get different values for the next list.");
	sleep(1);
	createLinkedList(&list2Ptr, 5, 0);	
	printLinkedList(list2Ptr);

	/*
	 * Dereference the pointer and store it in the struct type
	 */ 
	list1 = *list1Ptr;
	list2 = *list2Ptr;
	
	if(DEBUGGING) {
		printLinkedList(&list1);
		printLinkedList(&list2);
	}

	return EXIT_SUCCESS;
}

void createLinkedList(LinkedListNodePtr *listNodePtr, int n, int createSorted)
{
	int i;
	char c;

	puts("\n## Creating Linked List");
	/*
	 * Random capital letter.
	 */
	srand(time(NULL));

	for(i = 0; i < n; i++) {
		c = 65 + rand() % 25;
		insert(listNodePtr, c, createSorted);
	}

	puts("Done.");
}

void insert(LinkedListNodePtr *startPtr, char c, int createSorted)
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
		newPtr->nextListNodePtr = NULL;

		/*
		 * Used to iterate through the linked list
		 */
		previousPtr = NULL;
		currentPtr = *startPtr;

		if(createSorted) {
			/*
		 	 * Loop through the list from the start to find the correct location.
		 	 * We are making this a sorted listed.
		 	 * If the list is empty we skip this. currentPtr will be NULL if the list is empty.
		 	 * If the list isn't empty, loop through until we find the correct spot (ie the input data is lower than the current linked list node data.
		 	 */
			while (currentPtr != NULL && c > currentPtr->data) {
				previousPtr = currentPtr;
				currentPtr = currentPtr->nextListNodePtr;
			}
		}
		else {
			/*
			 * Loop through the list from the start until to the end.
			 * If the list is empty we skip this as currentPtr will be NULL if the list is empty.
			 */ 
			while (currentPtr != NULL) {
				previousPtr = currentPtr;
				currentPtr = currentPtr->nextListNodePtr;
			}
		}

		/*
		 * The list was empty, make the new node the start
		 */
		if(previousPtr == NULL) {
			/*
			 * The new linked list node's link points to the former first node, which was NULL. Terminating the linked list.
			 */
			newPtr->nextListNodePtr = *startPtr;
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
			previousPtr->nextListNodePtr = newPtr;
			/*
			 * The new linked list node's link points to the next pointer, which is either NULL to terminate or another linked list node.
			 */
			newPtr->nextListNodePtr = currentPtr;
		}
	}
	else {
		fprintf(stderr, "%c couldn't be inserted. No memory available.\n", c);
	}
}

void printLinkedList(LinkedListNodePtr currentPtr)
{
	int printedLinks = 0;

	puts("\n## Printing Linked List Node(s)");

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
			currentPtr = currentPtr->nextListNodePtr;

			++printedLinks;
			if(printedLinks % 3 == 0) {
				printf("\n");
			}
		}
		printf("NULL - the end of the linked list.\n");
	}
}
