#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>

#define DEBUGGING 0
#define LIST_SIZE 10

enum BOOLEAN
{
	FALSE,
	TRUE
};

struct node
{
	char c;
	int i;
	struct node* next;
};

struct list
{
	struct node* head;
	struct node* tail;
	size_t size;
};

struct list* createList(struct list* theListPtr);

void initialiseList(struct list** theListPtr);

enum BOOLEAN insert(struct list** theListPtr, char c, int sortList);

enum BOOLEAN delete(struct list** theListPtr, char c);

void printLinkedList(const struct list* theListPtr);

void updateTail(struct list** theListPtr);

void destroyList(struct list** theListPtr);

int main(void)
{
	struct list* theListPtr;
	int i;
	char c;
	/*
	 * Controls if inserting into the list is sorted.
	 * 0 is no sorting.
	 * < 0 is descending sort.
	 * > 0 is ascending sort.
	 */
	int sortList = 1;

	puts("# Linked List Example - Separate List & Data structs");

	theListPtr = NULL;

	destroyList(&theListPtr);

	theListPtr = createList(theListPtr);
	if (theListPtr == NULL) {
		return EXIT_FAILURE;
	}
	puts("Linked list created and initialised.");
	destroyList(&theListPtr);

	theListPtr = createList(theListPtr);
	if (theListPtr == NULL) {
		return EXIT_FAILURE;
	}
	puts("Linked list created and initialised.");

	printf("\n## Populating %d Items Into Linked List", LIST_SIZE);
	if (DEBUGGING) {
		printf("sortList is %d\n", sortList);
		puts("0 is not sorted. < 0 is descending sort. > 0 is ascending sort.");
	}

	srand(time(NULL));
	for (i = 0; i < LIST_SIZE; i++) {
		c = 65 + rand() % 25;

		if (DEBUGGING) {
			printf("c is %c and c is %d\n", c, c);
		}
		if (!insert(&theListPtr, c, sortList)) {
			return EXIT_FAILURE;
		}
		else {
			printf("%c inserted.\n", c);
		}
	}
	puts("Linked list populated.");

	printLinkedList(theListPtr);

	c = theListPtr->head->c;
	if(delete(&theListPtr, c)) {
		printf("%c deleted.\n", c);
	}
	printLinkedList(theListPtr);

	c = theListPtr->tail->c;
	if(delete(&theListPtr, c)) {
		printf("%c deleted.\n", c);
	}
	printLinkedList(theListPtr);

	c = theListPtr->head->next->next->next->c;
	if(delete(&theListPtr, c)) {
		printf("%c deleted.\n", c);
	}
	printLinkedList(theListPtr);

	c = '!';
	if(delete(&theListPtr, c)) {
		printf("%c deleted.\n", c);
	}
	printLinkedList(theListPtr);

	destroyList(&theListPtr);

	return EXIT_SUCCESS;
}

struct list* createList()
{
	struct list* theListPtr;

	puts("\n## Creating & Initialising Linked List");
	theListPtr = malloc(sizeof(struct list));

	if (theListPtr != NULL) {
		initialiseList(&theListPtr);

		if (theListPtr->head == NULL && theListPtr->tail == NULL &&
			theListPtr->size == 0) {
			return theListPtr;
		}
	}

	fprintf(stderr, "[ERROR] %s\n", strerror(errno));
	return NULL;
}

void initialiseList(struct list** theListPtr)
{
	/*
	 * Set up a new empty list.
	 */
	(*theListPtr)->head = NULL;
	(*theListPtr)->tail = NULL;
	(*theListPtr)->size = 0;

	/*
	 * 0 out all the memory of the list.
	 */
	memset(*theListPtr, 0, sizeof(struct list));
}

enum BOOLEAN insert(struct list** theListPtr, char c, int sortList)
{
	struct node* newNodePtr;
	struct node* previousNodePtr;
	struct node* currentNodePtr;

	puts("\n### Inserting Into Linked List.");
	printf("Trying to insert %c\n", c);

	/*
	 * mallac tries to allocate memory with the specified bytes.
	 * sizeof will return the size of the data structure, platform dependent.
	 * If successful, malloc returns a void * to the allocated memory, otherwise returns NULL
	 */
	newNodePtr = malloc(sizeof(struct node));

	if (newNodePtr == NULL) {
		fprintf(stderr, "[ERROR] %s\n", strerror(errno));
		return FALSE;
	}
	else {
		newNodePtr->c = c;
		newNodePtr->i = c;
		newNodePtr->next = NULL;
		if (DEBUGGING) {
			puts("[DEBUG] newNodePtr is:");
			printf("newNodePtr->c is %c\n", newNodePtr->c);
			printf("newNodePtr->i is %d\n", newNodePtr->i);
			printf("newNodePtr->next is %p\n", (void *) newNodePtr->next);
		}
	}

	/*
	 * Search the list
	 */
	previousNodePtr = NULL;
	currentNodePtr = (*theListPtr)->head;

	/*
	 * Loop through the list from the start to find the correct location.
	 * We are making this a sorted listed.
	 * If the list is empty we skip this. currentPtr will be NULL if the list is empty.
	 * If the list isn't empty, loop through until we find the correct spot (ie the input data is lower/higher than the current linked list node data.
	 */

	if (sortList < 0) {
		while (currentNodePtr != NULL && c < currentNodePtr->c) {
			previousNodePtr = currentNodePtr;
			currentNodePtr = currentNodePtr->next;
		}
	}
	else if (sortList > 0) {
		while (currentNodePtr != NULL && c > currentNodePtr->c) {
			previousNodePtr = currentNodePtr;
			currentNodePtr = currentNodePtr->next;
		}
	}
	else {
		while (currentNodePtr != NULL) {
			previousNodePtr = currentNodePtr;
			currentNodePtr = currentNodePtr->next;
		}
	}

	/*
	 * The list was empty.
	 */
	if (previousNodePtr == NULL) {
		/*
		 * The new linked list node's link points to the former first node, which was NULL. Terminating the linked list.
 		 */
		newNodePtr->next = (*theListPtr)->head;
		/*
		 * Start pointer is now the new linked list node, replacing NULL.
		 */
		(*theListPtr)->head = newNodePtr;
		updateTail(theListPtr);
		++(*theListPtr)->size;

		if (DEBUGGING) {
			puts("[DEBUG] Inserted into head, theListPtr is:");
			printf("theListPtr->head is %p\n", (void *) (*theListPtr)->head);
			printf("theListPtr->tail is %p\n", (void *) (*theListPtr)->tail);
			printf("theListPtr->size is %lu\n", (*theListPtr)->size);
		}
	}
	else {
		previousNodePtr->next = newNodePtr;
		newNodePtr->next = currentNodePtr;
		++(*theListPtr)->size;
		updateTail(theListPtr);
	}
	return TRUE;
}

void printLinkedList(const struct list* theListPtr)
{
	struct node* currentNodePtr = NULL;

	puts("\n## Printing Linked List Node(s)");

	if (theListPtr == NULL) {
		puts("The list is empty.");
	}
	else {
		puts("The linked list is: ");

		/*
		 * Go through each linked list node and get the next pointer.
		 * NULL means we are at the end of the list.
		 */
		currentNodePtr = theListPtr->head;
		while (currentNodePtr != NULL) {
			printf("%c & %d -links-with->\n", currentNodePtr->c,
				   currentNodePtr->i);
			currentNodePtr = currentNodePtr->next;
		}
		printf("NULL - the end of the linked list.\n");
	}
}

void updateTail(struct list** theListPtr)
{
	struct node* previousNodePtr;
	struct node* currentNodePtr;

	previousNodePtr = NULL;
	currentNodePtr = (*theListPtr)->head;

	while (currentNodePtr != NULL) {
		previousNodePtr = currentNodePtr;
		currentNodePtr = currentNodePtr->next;
	}

	/*
	 * In an empty list the previousNodePtr will be NULL.
	 * At the end of the list the currentNodePtr will be NULL.
	 */
	(*theListPtr)->tail = previousNodePtr;
}

enum BOOLEAN delete(struct list** theListPtr, char c)
{
	struct node* previousNodePtr;
	struct node* currentNodePtr;

	puts("\n## Deleting From List");
	printf("Trying to delete %c\n", c);

	previousNodePtr = NULL;
	currentNodePtr = (*theListPtr)->head;

	/*
	 * List is empty.
	 */
	if(currentNodePtr == NULL) {
		fprintf(stderr, "[ERROR] Cannot delete %c, the list is empty.\n", c);
		return FALSE;
	}

	/*
	 * Head of the list matches the node to delete.
	 *
	 */
	if(currentNodePtr->c == c) {
		(*theListPtr)->head = currentNodePtr->next;
		free(currentNodePtr);
		updateTail(theListPtr);
		return TRUE;
	}

	/*
	 * Search the list
	 */
	while(currentNodePtr != NULL) {
		if(currentNodePtr->c == c) {
			previousNodePtr->next = currentNodePtr->next;
			free(currentNodePtr);
			updateTail(theListPtr);
			return TRUE;
		}
		previousNodePtr = currentNodePtr;
		currentNodePtr = currentNodePtr->next;
	}

	fprintf(stderr, "[ERROR] Couldn't delete %c as it doesn't exist in the list.\n", c);
	return FALSE;
}

void destroyList(struct list** theListPtr)
{
	struct node* currentNodePtr;
	struct node* tmpNodePtr;

	puts("\n## Destroying Linked List and Nodes");

	if(*theListPtr != NULL) {
		currentNodePtr = (*theListPtr)->head;

		if(currentNodePtr) {
			while(currentNodePtr != NULL) {
				tmpNodePtr = currentNodePtr->next;
				// If the node has mallocs, you will need to free them too.
				free(currentNodePtr);
				currentNodePtr = tmpNodePtr;
			}
		}
		free(*theListPtr);
		puts("Done.");
	}
	else {
		puts("NULL pointer passed.");
	}
}

