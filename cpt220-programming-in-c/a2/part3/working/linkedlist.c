/******************************************************************************
 * Student Name    :  Dallas Hall
 * RMIT Student ID :  s3461243
 * COURSE CODE     :  CPT220 / OLA00
 *
 * Startup code provided by Paul Miller for use in "Programming in C",
 * study period 2, 2019.
 *****************************************************************************/

#include "linkedlist.h"

/**
 * implement the functions for managing the linked list here
 **/
/*
 * My linked list code comes from week 8 and 9 tutorial code as well
 * as C How To Program 6e chapter 12.
 *
 * I did the tutorials in the textbook for linked list, doubly linked list,
 * stacks, queues, and binary search trees. They were all conceptually similar.
 */
struct linkedlist* createLinkedList()
{
	struct linkedlist* linkedListPtr;
	linkedListPtr = (struct linkedlist*) malloc(sizeof(struct linkedlist));

	if (!linkedListPtr) {
		perror("malloc");
		return NULL;
	}
	else {
		linkedListPtr->head = NULL;
		linkedListPtr->size = 0;

		memset(linkedListPtr, 0, sizeof(struct linkedlist));
	}

	return linkedListPtr;
}

struct node* createLinkedListNode(void)
{
	struct node* linkedListNodePtr;

	linkedListNodePtr = malloc(sizeof(struct node));

	if (linkedListNodePtr == NULL) {
		return NULL;
	}

	memset(linkedListNodePtr, 0, sizeof(struct node));

	return linkedListNodePtr;
}

BOOLEAN insertNode(struct linkedlist* linkedListPtr, struct node* newNodePtr)
{
	struct node* previousNodePtr;
	struct node* currentNodePtr;

	/*
	 * Cannot insert into a NULL list pointer.
	 */
	if (linkedListPtr == NULL) {
		fprintf(stderr, "[ERROR] The linked list pointer is NULL.\n");
		return FALSE;
	}

	/*
	 * We set the previous node to NULL so we can check it later. If it is
	 * NULL after the while loop then the list was empty.
	 *
	 * We set current node to the head of the list, if this is NULL then
	 * the list was empty.
	 */
	previousNodePtr = NULL;
	currentNodePtr = linkedListPtr->head;
	/*
	 * Loop through the list, we will stop when:
	 * 1) The list is empty
	 * 2) The current node is no longer larger than the new node
	 * 3) We reach the end of the list.
	 */
	while (currentNodePtr != NULL &&
		   currentNodePtr->data->won_by > newNodePtr->data->won_by) {
		previousNodePtr = currentNodePtr;
		currentNodePtr = currentNodePtr->next;
	}

	/*
	 * List is empty or the new node has a higher value than the head of the
	 * list.
	 */
	if (previousNodePtr == NULL) {
		/*
		 * 1) We update theGameResultNodePtr link to point to the head of the
		 * list, if the list is empty this will be NULL so the list is
		 * terminated. If the list isn't empty then this will point to the rest
		 * of the list.
		 * 2) Update the head of the list to point to the theGameResultNodePtr,
		 * because of step 1 this correctly covers the list being empty or
		 * populated.
		 * 3) Update the list size to reflect the insertion.
		 */
		newNodePtr->next = linkedListPtr->head;
		linkedListPtr->head = newNodePtr;
		++linkedListPtr->size;
	}
	else {
		/*
		 * Insert the node into the correct place.
		 * We already set the new node's link to NULL, so if it is the last
		 * node it is set correctly, otherwise we update it.
		 */
		previousNodePtr->next = newNodePtr;
		newNodePtr->next = currentNodePtr;
		++linkedListPtr->size;
	}

	return TRUE;
}

BOOLEAN
deleteNode(struct linkedlist* linkedListPtr, struct node* nodeToDeletePtr)
{
	struct node* tempNodePtr;
	struct node* previousNodePtr;
	struct node* currentNodePtr;

	/*
	 * Cannot delete from a NULL pointer or delete a NULL pointer.
	 */
	if (linkedListPtr == NULL) {
		fprintf(stderr, "[ERROR] The linked list pointer is NULL.\n");
		return FALSE;
	}

	if (nodeToDeletePtr == NULL) {
		fprintf(stderr, "[ERROR] The linked list node pointer is NULL.\n");
		return FALSE;
	}

	previousNodePtr = NULL;
	currentNodePtr = linkedListPtr->head;

	/*
	 * The list is empty.
	 */
	if (currentNodePtr == NULL) {
		return FALSE;
	}

	/*
	 * Match found at the head of the list.
	 */
	if (currentNodePtr->data->winner == nodeToDeletePtr->data->winner &&
		currentNodePtr->data->loser == nodeToDeletePtr->data->loser &&
		currentNodePtr->data->won_by == nodeToDeletePtr->data->won_by) {

		/*
		 * Update the head of list by
		 * 1) Storing the current head in a temporary variable
		 * 2) Update the head to point to the next node
		 * 3) Update the size of the list.
		 * 4) Free the old head node.
		 */
		tempNodePtr = currentNodePtr;
		linkedListPtr->head = currentNodePtr->next;
		--linkedListPtr->size;
		free(tempNodePtr);

		return TRUE;
	}

	while (currentNodePtr != NULL) {
		/*
		 * Update the list by
		 * 1) Storing the current node in a temporary variable
		 * 2) Update the previous node link to point to the current node link
		 * 3) Update the size of the list.
		 * 4) Free the old node.
		 *
		 * This works because we have already dealt with the head of the list.
		 */
		if (currentNodePtr->data->winner == nodeToDeletePtr->data->winner &&
			currentNodePtr->data->loser == nodeToDeletePtr->data->loser &&
			currentNodePtr->data->won_by == nodeToDeletePtr->data->won_by) {
			tempNodePtr = currentNodePtr;
			previousNodePtr->next = currentNodePtr->next;
			--linkedListPtr->size;
			free(tempNodePtr);

			return TRUE;
		}

		previousNodePtr = currentNodePtr;
		currentNodePtr = currentNodePtr->next;
	}

	return FALSE;
}

BOOLEAN
deleteNodeViaPosition(struct linkedlist* linkedListPtr,
					  int nodeToDeletePosition)
{
	/*
	 * TODO Delete a node - test this
	 */
	struct node* tempNodePtr;
	struct node* previousNodePtr;
	struct node* currentNodePtr;
	int currentNodePosition;

	/*
	 * Cannot delete from a NULL pointer or delete a NULL pointer.
	 */
	if (linkedListPtr == NULL) {
		fprintf(stderr, "[ERROR] The linked list pointer is NULL.\n");
		return FALSE;
	}

	if (nodeToDeletePosition < 0) {
		fprintf(stderr,
				"[ERROR] The node position %d is too small. Must be greater than 0\n",
				nodeToDeletePosition);
		return FALSE;
	}
	else if (nodeToDeletePosition > linkedListPtr->size) {
		fprintf(stderr,
				"[ERROR] The node position %d is too large. Must be less than %d\n",
				nodeToDeletePosition, linkedListPtr->size);
		return FALSE;
	}

	previousNodePtr = NULL;
	currentNodePtr = linkedListPtr->head;

	/*
	 * The list is empty.
	 */
	if (currentNodePtr == NULL) {
		return FALSE;
	}

	currentNodePosition = 1;

	/*
	 * Match found at the head of the list.
	 */
	if (currentNodePosition == nodeToDeletePosition) {

		/*
		 * Update the head of list by
		 * 1) Storing the current head in a temporary variable
		 * 2) Update the head to point to the next node
		 * 3) Update the size of the list.
		 * 4) Free the old head node.
		 */
		tempNodePtr = currentNodePtr;
		linkedListPtr->head = currentNodePtr->next;
		--linkedListPtr->size;
		free(tempNodePtr);

		return TRUE;
	}
	else {
		++currentNodePosition;
		previousNodePtr = currentNodePtr;
		currentNodePtr = currentNodePtr->next;
	}

	while (currentNodePtr != NULL) {
		/*
		 * Update the list by
		 * 1) Storing the current node in a temporary variable
		 * 2) Update the previous node link to point to the current node link
		 * 3) Update the size of the list.
		 * 4) Free the old node.
		 *
		 * This works because we have already dealt with the head of the list.
		 */
		if (currentNodePosition == nodeToDeletePosition) {
			tempNodePtr = currentNodePtr;
			previousNodePtr->next = currentNodePtr->next;
			--linkedListPtr->size;
			free(tempNodePtr);

			return TRUE;
		}

		previousNodePtr = currentNodePtr;
		currentNodePtr = currentNodePtr->next;
		++currentNodePosition;
	}

	return FALSE;
}

BOOLEAN findNode(struct linkedlist* linkedListPtr, struct node* nodeToFindPtr)
{
	/*
	 * TODO find a node - test this
	 */
	struct node* currentNodePtr;

	if (linkedListPtr == NULL) {
		fprintf(stderr, "[ERROR] The linked list pointer is NULL.\n");
		return FALSE;
	}

	if (nodeToFindPtr == NULL) {
		fprintf(stderr, "[ERROR] The linked list node pointer is NULL.\n");
		return FALSE;
	}

	currentNodePtr = linkedListPtr->head;

	/*
	 * The list is empty.
	 */
	if (currentNodePtr == NULL) {
		return FALSE;
	}

	while (currentNodePtr != NULL) {

		if (currentNodePtr->data->winner == nodeToFindPtr->data->winner &&
			currentNodePtr->data->loser == nodeToFindPtr->data->loser &&
			currentNodePtr->data->won_by == nodeToFindPtr->data->won_by) {
			return TRUE;
		}

		currentNodePtr = currentNodePtr->next;
	}

	return FALSE;
}

/*
 * This is basically a debug print.
 * It prints from the head to the tail, one node per line.
 */
void prettyPrintLinkedList(struct linkedlist* linkedListPtr)
{
	struct node* currentNodePtr;

	if (linkedListPtr == NULL) {
		fprintf(stderr, "[ERROR] The linked list pointer is NULL.\n");
	}

	currentNodePtr = linkedListPtr->head;
	if (currentNodePtr == NULL) {
		printf("The list is empty.\n");
	}
	else {
		while (currentNodePtr != NULL) {
			printf("%s,%s,%d -links-with->\n", currentNodePtr->data->winner,
				   currentNodePtr->data->loser,
				   currentNodePtr->data->won_by);
			currentNodePtr = currentNodePtr->next;
		}
		printf("NULL, the end of the list.\n");
	}
}

/*
 * This will be the function to write the linked out to disk in a csv format.
 */
void printCsvLinkedList(struct linkedlist* linkedListPtr, char* delimiter)
{
	struct node* currentNodePtr;

	if (linkedListPtr == NULL) {
		fprintf(stderr, "[ERROR] The linked list pointer is NULL.\n");
	}

	currentNodePtr = linkedListPtr->head;
	if (currentNodePtr == NULL) {
		printf("The list is empty.\n");
	}
	else {
		while (currentNodePtr != NULL) {
			printf("%s\t%s\t%d\n", currentNodePtr->data->winner,
				   currentNodePtr->data->loser,
				   currentNodePtr->data->won_by);
			currentNodePtr = currentNodePtr->next;
		}
	}
}

void deleteLinkedListNodes(struct linkedlist* linkedListPtr)
{
	struct node* currentNodePtr;
	struct node* nextNodePtr;

	/*
	 * No point trying to free if the pointer is NULL
	 */
	if (linkedListPtr == NULL) {
		fprintf(stderr,
				"[ERROR] Cannot delete linked list nodes as the pointer is NULL.\n");
		return;
	}

	currentNodePtr = linkedListPtr->head;

	if (currentNodePtr == NULL) {
		fprintf(stderr,
				"[WARNING] Cannot delete linked list nodes as the list as it is empty.\n");
		return;
	}

	/*
	 * Loop through the list if it isn't empty and free the memory for
	 * each element.
	 */
	while (currentNodePtr != NULL) {
		/*
		 * Update the next node pointer so we don't lose the entire list.
		 */
		nextNodePtr = currentNodePtr->next;
		/*
		 * Delete our memory previously allocated with malloc.
		 */
		free(currentNodePtr->data->winner);
		free(currentNodePtr->data->loser);
		free(currentNodePtr->data);
		free(currentNodePtr);
		currentNodePtr = nextNodePtr;
	}

	linkedListPtr->head = NULL;
	linkedListPtr->size = 0;
}

void deleteLinkedList(struct linkedlist* linkedListPtr)
{
	/*
	 * No point trying to free if the pointer is NULL
	 */
	if (linkedListPtr == NULL) {
		fprintf(stderr,
				"[ERROR] Cannot delete linked list as the pointer is NULL.\n");
		return;
	}

	/*
	 * If the linked list still has entries, we need to delete them first to
	 * stop memory leaks.
	 */
	if (linkedListPtr->size > 0) {
		deleteLinkedListNodes(linkedListPtr);
	}

	/*
	 * Currently causing a free(): invalid pointer error.
	 * Not sure why.
	 */
	free(linkedListPtr);
}