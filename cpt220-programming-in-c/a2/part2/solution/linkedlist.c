#include "linkedlist.h"
/******************************************************************************
 * Student Name    :
 * RMIT Student ID :
 * COURSE CODE     :
 *
 * Startup code provided by Paul Miller for use in "Programming in C",
 * study period 2, 2019.
 *****************************************************************************/

/**
 * zero out the linked list structure
 **/
void linkedlist_init(struct linkedlist* thelist)
{
        memset(thelist, 0, sizeof *thelist);
}

/**
 * add scores in the order specified by the cmp function to the linked list
 **/
BOOLEAN
linkedlist_add(struct linkedlist* thelist, struct game_result* result,
               int (*cmp)(const struct game_result*, const struct game_result*))
{
        /**
         * allocate space for the node and validate that the memory allocation
         * was successful.
         **/
        struct node* new = malloc(sizeof(struct node));
        struct node* prev = NULL, *current;
        assert(thelist);
        assert(result);
        if (!new)
        {
                perror("malloc failed");
                return FALSE;
        }
        /* initialise the node with the data. set next to NULL so we don't
         * forget to do that later
         */
        new->next = NULL;
        new->data = result;
        /**
         * if the list is empty, just add to the head
         **/
        if (!thelist->head)
        {
                thelist->head = new;
                ++thelist->size;
                return TRUE;
        }
        /**
         * iterate over the list to find the insertion point in the list
         **/
        for (current = LL_BEGIN(thelist);
             current != LL_END(thelist) && cmp(current->data, result) < 0;
             LL_NEXT(current, prev))
                ;
        /**
         * insert into beginning of the list
         **/
        if (!prev)
        {
                new->next = thelist->head;
                thelist->head = new;
        }
        else
        {
                /**
                 * insert elsewhere in the list
                 **/
                assert(prev);
                prev->next = new;
                new->next = current;
        }
        /**
         * success! increment the size of the list
         **/
        ++thelist->size;
        return TRUE;
}

/**
 * iterate over the list, print out the data for each line using the
 * printfunc() function pointer passed in
 **/
BOOLEAN
linkedlist_print(const struct linkedlist* thelist, FILE* out, void* payload,
                 BOOLEAN (*printfunc)(const struct game_result*, FILE*, void*))
{
        struct node* current;
        /* iterate over the list */
        for (current = LL_BEGIN(thelist); current != LL_END(thelist);
             LL_NEXT_NP(current))
        {
                /* print the node */
                if (!printfunc(LL_DATA(current), out, payload))
                {
                        return FALSE;
                }
        }
        return TRUE;
}

/* You need to free the linked list but this function prototype might be a bit
 * complicated for some of you. You don't have to use it and implementing the
 * same fucntionality in another way is fine */
void linkedlist_free(struct linkedlist* thelist,
                     void (*free_func)(struct game_result*))
{
        /* left unimplemented as this is something you still need to do */
}
