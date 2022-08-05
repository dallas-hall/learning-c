/******************************************************************************
 * Student Name    :
 * RMIT Student ID :
 * COURSE CODE     :
 *
 * Startup code provided by Paul Miller for use in "Programming in C",
 * study period 2, 2019.
 *****************************************************************************/
#include "io.h"
#include <errno.h>
#include <string.h>
#include "linkedlist.h"
#include "scoreboard.h"

/**
 * The maximum length a result string can be - that is the game results stored
 * in the data file that is read in.
 **/
#define MAXRESULTSTRING 60

/* the maximum length of a file path you are expected to handle */
#define PATH_MAX 4096

#ifndef FILEIO_H
#define FILEIO_H
BOOLEAN load_data(const char[], struct linkedlist*);
BOOLEAN save_data(const char[], const struct linkedlist*);
#endif
