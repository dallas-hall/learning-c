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
 * provide the declarations of linked list interface functions
 **/

#endif
