/******************************************************************************
 * Student Name    :  Dallas Hall
 * RMIT Student ID :  s3461243
 * COURSE CODE     :  CPT220 / OLA00
 *
 * Startup code provided by Paul Miller for use in "Programming in C",
 * study period 2, 2019.
 *****************************************************************************/
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

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

/**
 * the error_move can be returned from any function that returns a struct move
 * and could fail. This represents that an error occured in that function
 **/
extern const struct move error_move;

/**
 * part 2 data structures and constants
 **/

#define NUM_DICE 2
#define DICE_SIDES 6
#define DICE_ROLL() ((rand() % DICE_SIDES) + 1)
/**
 * end of part 2 data structures and constants
 **/

/**
 * part 3 data structures and constants
 **/

#define BARLIST_CHAR 'B'
/**
 * end of part 3 darastructures and constants
 **/

/**
 * assignment 2 data structures
 **/

/**
 * forwards declaration of player so I can have pointers to them in all
 * header file.
 **/
struct player;

/**
 * the game_result structure that represents the result of playing a game
 * of backgammon - ie, who played who and how much did they win by.
 **/
struct game_result
{
	char* winner;
	char* loser;
	int won_by;
};

/**
 * the length of a line in our system
 **/
#define LINE_LEN 80

/**
 * end of assignent 2 data structures
 **/
#endif
