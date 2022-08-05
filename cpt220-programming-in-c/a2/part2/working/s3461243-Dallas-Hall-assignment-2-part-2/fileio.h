/******************************************************************************
 * Student Name    :  Dallas Hall
 * RMIT Student ID :  s3461243
 * COURSE CODE     :  CPT220 / OLA00
 *
 * Startup code provided by Paul Miller for use in "Programming in C",
 * study period 2, 2019.
 *****************************************************************************/
#include "io.h"
#include <errno.h>
#include <string.h>
#include "linkedlist.h"
#include "scoreboard.h"

/*
 * Added player.h so I could get NAME_LEN
 */
#include "player.h"

/**
 * The maximum length a result string can be - that is the game results stored
 * in the data file that is read in.
 **/
#define MAXRESULTSTRING 60

/* the maximum length of a file path you are expected to handle */
#define PATH_MAX 4096

/*
 * Input buffer size
 */
#define BUFFER_SIZE 1024

/*
 * fgets adds a \0 to the end of the input.
 * Also used for the null terminator in other cases.
 */
#define FGETS_EXTRA_CHAR 1

/*
 * CSV delimiter
 */
#define DELIMITER ","

/*
 * strtol conversion number system
 */
#define BASE_10 10

#ifndef FILEIO_H
#define FILEIO_H

BOOLEAN load_data(const char[], struct linkedlist*);

BOOLEAN save_data(const char[], const struct linkedlist*);

struct game_result* parseLineData(char*);

BOOLEAN validInputName(const char*);

int validWinningMargin(char* winningMargin);

#endif
