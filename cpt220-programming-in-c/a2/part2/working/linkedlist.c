/******************************************************************************
 * Student Name    :  Dallas Hall
 * RMIT Student ID :  s3461243
 * COURSE CODE     :  CPT220 / OLA00
 *
 * Startup code provided by Paul Miller for use in "Programming in C",
 * study period 2, 2019.
 *****************************************************************************/

#include "linkedlist.h"

const int DEBUGGING_LINKEDLIST = 1;

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
		memset(linkedListPtr, 0, sizeof(struct linkedlist));
		/*linkedListPtr->head = NULL;
		linkedListPtr->size = 0;*/
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
	struct node* previousNode;
	struct node* currentNode;

	/*
	 * We set the previous node to NULL so we can check it later. If it is
	 * NULL after the while loop then the list was empty.
	 *
	 * We set current node to the head of the list, if this is NULL then
	 * the list was empty.
	 */
	previousNode = NULL;
	currentNode = linkedListPtr->head;
	/*
	 * Loop through the list, we will stop when:
	 * 1) The list is empty
	 * 2) The current node is no longer larger than the new node
	 * 3) We reach the end of the list.
	 */
	while (currentNode != NULL &&
		   currentNode->data->won_by > newNodePtr->data->won_by) {
		previousNode = currentNode;
		currentNode = currentNode->next;
	}

	/*
	 * List is empty or the new node has a higher value than the head of the
	 * list.
	 */
	if (previousNode == NULL) {
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
		previousNode->next = newNodePtr;
		newNodePtr->next = currentNode;
		++linkedListPtr->size;
	}

	return TRUE;
}

BOOLEAN deleteNode(struct linkedlist* linkedListPtr,
				   struct node* theGameResultNodePtr)
{
	/*
	 * TODO
	 *
	 * Delete a node
	 */
	return FALSE;
}

BOOLEAN findNode(struct linkedlist* linkedListPtr, struct node* nodePtr)
{
	/*
	 * TODO
	 *
	 * find a node
	 */
	return FALSE;
}

/*
 * This is basically a debug print.
 * It prints from the head to the tail, one node per line.
 */
void prettyPrintLinkedList(struct linkedlist* linkedListPtr)
{
	struct node* currentNode;

	if (linkedListPtr == NULL) {
		printf("The list is empty.\n");
	}

	currentNode = linkedListPtr->head;
	if (currentNode == NULL) {
		printf("The list is empty.\n");
	}
	else {
		while (currentNode != NULL) {
			printf("%s,%s,%d -links-with->\n", currentNode->data->winner,
				   currentNode->data->loser,
				   currentNode->data->won_by);
			currentNode = currentNode->next;
		}
		printf("NULL, the end of the list.\n");
	}
}

/*
 * This will be the function to write the linked out to disk in a csv format.
 */
void printCsvLinkedList(struct linkedlist* linkedListPtr, char* delimiter)
{
	struct node* currentNode;

	if (linkedListPtr == NULL) {
		printf("The list is empty.\n");
	}

	currentNode = linkedListPtr->head;
	if (currentNode == NULL) {
		printf("The list is empty.\n");
	}
	else {
		while (currentNode != NULL) {
			printf("%s\t%s\t%d\n", currentNode->data->winner,
				   currentNode->data->loser,
				   currentNode->data->won_by);
			currentNode = currentNode->next;
		}
	}
}

BOOLEAN deleteLinkedListNodes(struct linkedlist* linkedListPtr)
{
	struct node* currentNode;
	struct node* nextNode;

	currentNode = linkedListPtr->head;

	if (currentNode == NULL) {
		fprintf(stderr,
				"[ERROR] Cannot delete linked list nodes as the list as it is empty.\n");
		return FALSE;
	}

	/*
	 * Loop through the list if it isn't empty and free the memory for
	 * each element.
	 */
	while (currentNode != NULL) {
		/*
		 * Update the next node pointer so we don't lose the entire list.
		 */
		nextNode = currentNode->next;
		/*
		 * Delete our memory previously allocated with malloc.
		 */
		free(currentNode->data->winner);
		free(currentNode->data->loser);
		free(currentNode->data);
		free(currentNode);
		currentNode = nextNode;
	}

	linkedListPtr->head = NULL;
	linkedListPtr->size = 0;

	return TRUE;
}

BOOLEAN deleteLinkedList(struct linkedlist* linkedListPtr)
{
	if (linkedListPtr->size > 0) {
		deleteLinkedListNodes(linkedListPtr);
	}

	free(linkedListPtr);
	return TRUE;
}