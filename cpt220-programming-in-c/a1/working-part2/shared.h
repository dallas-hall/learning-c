/******************************************************************************
 * Student Name    :  Dallas Hall
 * RMIT Student ID :  s3461243
 * COURSE CODE     :  CPT220 / OLA00
 *
 * Startup code provided by Paul Miller for use in "Programming in C",
 * study period 2, 2019.
 *****************************************************************************/
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef SHARED_H
#define SHARED_H
/**
 * The boolean type - defines values for FALSE (0) and TRUE (1)
 **/
typedef enum
{
	FALSE,
	TRUE
} BOOLEAN;

/**
 * in some places I might want to return FALSE when something fails but
 * also a number when it succeeds
 **/
struct falsible_long
{
	long thelong;
	BOOLEAN success;
};

/**
 * which way around the board do we go? I've provided it here because it
 * was needed in several different places in the program
 **/
enum orientation
{
	OR_CLOCKWISE,
	OR_ANTICLOCKWISE
};

/**
 * a move has an index on the board it starts at and a count of how many
 * places to move the piece
 **/
struct move
{
	int index, count;
};
extern const struct move error_move;

/*
 * The debugging toggle, which is set inside of game.c
 * https://stackoverflow.com/questions/1433204/how-do-i-use-extern-to-share-variables-between-source-files/1433387#1433387
 *
 * Decided to use a dedicated variable per file, otherwise its just pages
 * and pages of [DEBUG] messages when turned on.
 *
 * extern int DEBUGGING;
 */


#endif
