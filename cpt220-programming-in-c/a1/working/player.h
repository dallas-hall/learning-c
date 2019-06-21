/******************************************************************************
 * Student Name    :  Dallas Hall
 * RMIT Student ID :  s3461243
 * COURSE CODE     :  CPT220 / OLA00
 *
 * Startup code provided by Paul Miller for use in "Programming in C",
 * study period 2, 2019.
 *****************************************************************************/
#include "bar_list.h"
#include "board.h"
#include "io.h"
#include "rules.h"

#ifndef PLAYER_H
#define PLAYER_H
/**
 * forwards declaration of the game struct so we can have pointers to a game
 * without knowing the internal details of a game struct.
 **/
struct game;
/**
 * The maximum length of a player name in the game.
 **/
#define NAME_LEN 20
/**
 * maximum prompt length needed for any part of the game
 **/
#define MAXPROMPTLEN 240

/**
 * definition of a player - they have a name, score, token (ie, colour),
 * a bar_list (that's the tokens that have been kicked off the board by
 * the oponent, a pointer to the current game (that just means we have
 * fewer variables to pass around), an orientation (which way around the board
 * that the player goes).
 **/
struct player
{
	char name[NAME_LEN + 1];
	int score;
	enum piece token;
	struct bar_list bar_list;
	struct game *curgame;
	enum orientation orientation;
};

/**
 * you may add your own data structures to this module
 **/
/*
fgets adds a '\n' and '\0' to each string, we need to account for that.
*/
#define FGETS_EXTRA_CHARS 2 /* \n and \0 */
#define MIN_NAME_LEN 2 /* It is really 1, but we add an extra for the \n */

#define MAX_BOARD_LENGTH 24
int pieciesLocation[MAX_BOARD_LENGTH];

BOOLEAN
getName(char s[], int size, struct player *aplayer, struct game *thegame);

void printCurrentPlayer(struct game *thegame);

void printOtherPlayer(struct game *thegame);
/**
 * end of the student's data structures for this module
 **/

/**
 * globally visible functions available and required to be implemented. You
 * may add your own if you see the need.
 **/
BOOLEAN player_init(struct player *, struct game *);

enum input_result player_take_turn(struct player *);

#endif
