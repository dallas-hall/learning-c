#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

struct linkedListNode
{
    char data;
    struct linkedListNode *nextNodePtr;
};

typedef struct linkedListNode LinkedListNode;
typedef LinkedListNode *LinkedListNodePtr;

void insert(LinkedListNodePtr *startPtr, char c, int sortList);
char delete(LinkedListNodePtr *startPtr, char c);
int isEmpty(LinkedListNodePtr startPtr);
void printLinkedList(LinkedListNodePtr currentPtr);
void createLinkedList(LinkedListNodePtr *listPtr, int nodeAmount, int createSorted);
void reverseList(LinkedListNodePtr *originalListPtr, LinkedListNodePtr *newListPtr)
;

int main(void) {
	int sortList = 1;
    LinkedListNodePtr list1Ptr, list2Ptr;
    list1Ptr = NULL;
    list2Ptr = NULL;

    puts("# Reversing A Linked List");
    createLinkedList(&list1Ptr, 10, sortList);
    printLinkedList(list1Ptr);

    reverseList(&list1Ptr, &list2Ptr);
    printLinkedList(list2Ptr);

    return EXIT_SUCCESS;
}

void insert(LinkedListNodePtr *startPtr, char c, int sortList) {
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

    if (newPtr != NULL) {
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
        if (sortList < 0) {
            while (currentPtr != NULL && c < currentPtr->data) {

                previousPtr = currentPtr;
                currentPtr = currentPtr->nextNodePtr;
            }
        } else if (sortList > 0) {
            while (currentPtr != NULL && c > currentPtr->data) {

                previousPtr = currentPtr;
                currentPtr = currentPtr->nextNodePtr;
            }
        } else {
            while (currentPtr != NULL) {

                previousPtr = currentPtr;
                currentPtr = currentPtr->nextNodePtr;
            }
        }

        /*
         * The list was empty, make the new node the start
         */
        if (previousPtr == NULL) {
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
    } else {
        fprintf(stderr, "%c couldn't be inserted. No memory available.\n", c);
    }
}

char delete(LinkedListNodePtr *startPtr, char c) {
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
    if (c == (*startPtr)->data) {
        tempPtr = *startPtr;
        *startPtr = (*startPtr)->nextNodePtr;
        free(tempPtr);
        return c;
    }
        /*
         * If the first char doesn't match what we want to delete.
         * The list isn't empty because we already checked that before calling this function.
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
         */
        while (currentPtr != NULL && c != currentPtr->data) {
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextNodePtr;
        }

        /*
         * If we found the what we were looking for.
         * 1) Assign the pointer of interest to a temporary variable
         * 2) Update the previous linked list node's link to point to the current linked list node's link. This deletes it from the list.
          * 3) Free up the memory of the first pointer so it can be used elsewhere.
         */
        if (currentPtr != NULL) {
            tempPtr = currentPtr;
            previousPtr->nextNodePtr = currentPtr->nextNodePtr;
            free(tempPtr);
            return c;
        }
    }

    return '\0';
}

int isEmpty(LinkedListNodePtr startPtr) {
    return startPtr == NULL;
}

void printLinkedList(LinkedListNodePtr currentPtr) {

    puts("\n### Printing Linked List Node(s)");

    if (currentPtr == NULL) {
        puts("The list is empty.");
    } else {
        puts("The linked list is: ");

        /*
         * Go through each linked list node and get the next pointer.
         * NULL means we are at the end of the list.
         */
        while (currentPtr != NULL) {
            printf("%c -links-with->\n", currentPtr->data);
            currentPtr = currentPtr->nextNodePtr;
        }
        printf("NULL - the end of the linked list.\n");
    }
}

void createLinkedList(LinkedListNodePtr *listPtr, int nodeAmount, int createSorted)
{
    int i;

    puts("\n## Creating Linked List");
    srand(time(NULL));
    for(i = 0; i < nodeAmount; i++) {
        insert(listPtr, 65 + rand() % 25, createSorted);
    }

    puts("Done.");
}

/*
 * https://www.geeksforgeeks.org/reverse-a-linked-list/
 */
void reverseList(LinkedListNodePtr *originalListPtr, LinkedListNodePtr *newListPtr)
{
    LinkedListNodePtr previousPtr, currentPtr, nextPtr;

    previousPtr = NULL;
    currentPtr = *originalListPtr;
    nextPtr = NULL;

    puts("\n## Reversing Linked List");

    while(currentPtr != NULL) {
        /*
         * Store next link
         */
        nextPtr = currentPtr->nextNodePtr;
        /*
         * Reverse current node's pointer.
         * First time around, will be NULL.
         * Every other time will be the pointer to the previous node.
         */
        currentPtr->nextNodePtr = previousPtr;

        /*
         * Move pointers ahead one
         */
        previousPtr = currentPtr;
        currentPtr = nextPtr;
    }
    /*
     * Assign start address to the list, which is the last valid link in the linked list.
     */
    *newListPtr = previousPtr;
}
