#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

/*
 * A self referential structure, which is what linked lists are
 */
struct linkedListNode {
	int data;
	struct linkedListNode *nextNodePtr;
};

/*
 * Create some synonyms.
 * 1) For the struct linkedListNode
 * 2) For the pointer to the struct linkedListNode
 */
typedef struct linkedListNode LinkedListNode;
typedef LinkedListNode *LinkedListNodePtr;

void createLinkedList(LinkedListNodePtr *listPtr, int nodeAmount, int createSorted);
void insertNode(LinkedListNodePtr *startPtr, int n, int sortList);
void printLinkedList(LinkedListNodePtr startPtr);
void sumLinkedList(LinkedListNodePtr *startPtr);

int main(void)
{
	LinkedListNodePtr list1Ptr;

	list1Ptr = NULL;

	puts("# Sum Linked Lists");
	createLinkedList(&list1Ptr, 25, 0);
	printLinkedList(list1Ptr);
	sumLinkedList(&list1Ptr);

	return EXIT_SUCCESS;
}

void createLinkedList(LinkedListNodePtr *listPtr, int nodeAmount, int createSorted)
{
	int i;

	puts("\n## Creating Linked List");
	srand(time(NULL));
	for(i = 0; i < nodeAmount; i++) {
		insertNode(listPtr, rand() % 100, createSorted);
	}

	puts("Done.");
}

void insertNode(LinkedListNodePtr *startPtr, int n, int sortList)
{
	/*
	 * Previous linked list node
	 * Current linked list node
	 * The new linked list node
	 */
	LinkedListNodePtr previousPtr;
	LinkedListNodePtr currentPtr;
	LinkedListNodePtr newPtr;

	if(sortList < 0) {
		sortList = -1;
	}
	else if (sortList > 0) {
		sortList = 1;
	}

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
		newPtr->data = n;
		newPtr->nextNodePtr = NULL;

		/*
		 * Used to iterate through the linked list
		 */ 
		previousPtr = NULL;
		currentPtr = *startPtr;

		/*
		 * Loop through the list from the start to find the correct location.
		 * Sorting logic can be added here.
		 * If the list is empty we skip this. currentPtr will be NULL if the list is empty.
		 * If the list isn't empty, loop through until we find the correct spot (ie the input data is lower than the current linked list node data.
		 */ 

		switch (sortList) {
			case 0:
				while (currentPtr != NULL) {
			
				previousPtr = currentPtr;
				currentPtr = currentPtr->nextNodePtr;
				}
				break;
			case 1:
				while (currentPtr != NULL && n > currentPtr->data) {
			
				previousPtr = currentPtr;
				currentPtr = currentPtr->nextNodePtr;
				}
				break;
			case -1:
				while (currentPtr != NULL && n < currentPtr->data) {
			
				previousPtr = currentPtr;
				currentPtr = currentPtr->nextNodePtr;
				}
				break;
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
		fprintf(stderr, "%d couldn't be inserted. No memory available.\n", n);
	}
}

void printLinkedList(LinkedListNodePtr startPtr)
{
	LinkedListNodePtr previousPtr, currentPtr;

	puts("\n## Printing Linked List");
	
	if(startPtr == NULL) {
		printf("The list is empty.");
	}
	else {
		printf("%2d -links-with->\n", startPtr->data);

		previousPtr = startPtr;
		currentPtr = previousPtr->nextNodePtr;
		while(currentPtr != NULL) {
			printf("%2d -links-with->\n", currentPtr->data);
			previousPtr = currentPtr;
			currentPtr = previousPtr->nextNodePtr;
		}
		printf("NULL, the end of the linked list.\n");
	}
}

void sumLinkedList(LinkedListNodePtr *startPtr)
{
	double total = 0;
	LinkedListNodePtr currentPtr;

	puts("\n## Caculating Sum");
	currentPtr = *startPtr;
	while(currentPtr != NULL) {
		total += currentPtr->data;
		currentPtr = currentPtr->nextNodePtr;
	}

	printf("The sum total of the linked list was %.2f\n", total);
}
