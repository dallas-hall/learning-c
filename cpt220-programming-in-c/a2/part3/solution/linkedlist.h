/******************************************************************************
 * Student Name    :
 * RMIT Student ID :
 * COURSE CODE     :
 *
 * Startup code provided by Paul Miller for use in "Programming in C",
 * study period 2, 2019.
 *****************************************************************************/

#include "shared.h"
#include <stdio.h>
#include <string.h>
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

/**
 * macros that make the use of a linkedlist more readable
 **/
#define LL_BEGIN(list) (list)->head
#define LL_END(list) NULL
#define LL_NEXT(current, prev) (prev) = (current), (current) = (current)->next
#define LL_NEXT_NP(current) (current) = (current)->next
#define LL_DATA(node) (node)->data

#define UNUSED(X) ((void)X)

/**
 * the node for our linked list - just a pointer to the next pointer and a
 * pointer to the data
 **/
struct node
{
        struct node* next;
        struct game_result* data;
};

/**
 * the linked list header structure
 **/
struct linkedlist
{
        struct node* head;
        int size;
};

/**
 * linked list interface functions
 **/
void linkedlist_init(struct linkedlist*);
BOOLEAN linkedlist_add(struct linkedlist*, struct game_result*,
                       int (*)(const struct game_result*,
                               const struct game_result*));
BOOLEAN linkedlist_delete(struct linkedlist*, int);
BOOLEAN linkedlist_print(const struct linkedlist*, FILE*, void*,
                         BOOLEAN (*)(const struct game_result*, FILE*, void*));
void linkedlist_free(struct linkedlist*, void (*)(struct game_result*));
#endif
