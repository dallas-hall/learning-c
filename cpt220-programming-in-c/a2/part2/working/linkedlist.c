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
 */
struct linkedlist* createLinkedList(struct linkedlist* theLinkedListPtr)
{
	/*
	 * mallac tries to allocate memory with the specified bytes.
	 * sizeof will return the size of the data structure, platform dependent.
	 * If successful, malloc returns a void * to the allocated memory, otherwise
	 * returns NULL
	 *
	 * We are using struct linkedlist because that is the object that will be
	 * stored in the pointer.
	 */
	theLinkedListPtr = malloc(sizeof(struct linkedlist));

	/*
	 * Same as theLinkedListPtr == NULL
	 */
	if(!theLinkedListPtr) {
		return NULL;
	}
	else {
		theLinkedListPtr->head = NULL;
		theLinkedListPtr->size = 0;
	}

	return theLinkedListPtr;
}

BOOLEAN insertNode(struct linkedlist* theLinkedListPtr, struct node* theNodePtr)
{
	return FALSE;
}

BOOLEAN deleteNode(struct linkedlist* theLinkedListPtr, struct node* theNodePtr)
{
	return FALSE;
}

void printLinkedList(struct linkedlist* theLinkedListPtr)
{

}

BOOLEAN saveLinkedList(struct linkedlist*  theLinkedList, FILE* outputFilePtr)
{
	return FALSE;
}

BOOLEAN deleteLinkedList(struct linkedlist* theLinkedListPtr)
{
	return FALSE;
}