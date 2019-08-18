/******************************************************************************
 * Student Name    :  Dallas Hall
 * RMIT Student ID :  s3461243
 * COURSE CODE     :  CPT220 / OLA00
 *
 * Startup code provided by Paul Miller for use in "Programming in C",
 * study period 2, 2019.
 *****************************************************************************/

#include "linkedlist.h"
#include "helpers.h"

#ifndef SCOREBOARD_H
#define SCOREBOARD_H
/* forwards declaration of the game_system so we can have pointers
 * to it. We'll import main.h in scoreboard.h
 */
struct game_system;
/* the size of the scoreboard menu */
#define NUM_SCORES_MENU_ITEMS 6

/*
 * enum of all the scores menu items
 */
enum scores_menu_choice
{
	SM_PRINT,
	SM_ADD,
	SM_DELETE_ONE,
	SM_DELETE_ALL,
	SM_SAVE,
	SM_SAVE_NEW,
	SM_QUIT,
	SM_INVALID
};

/*
 * Covers the table delimiter
 */
#define TABLE_DELIMITER 1

/*
 * Covers the ) and trailing space
 */
#define ROW_NUMBER_EXTRA_CHARS 2

/*
 * Covers strlen("Amount Won By");
 */
#define WON_BY_AMOUNT 13

/**
 * a scoreboard menu entry - the text for the scoreboard entry and the function
 * that implements that functionality.
 **/
struct scores_menu_entry
{
	char text[LINE_LEN + 1];

	BOOLEAN (* function)(struct game_system*);
};

void scores_menu(struct game_system*);

void init_scores_menu(struct scores_menu_entry[]);

BOOLEAN print_scores(struct game_system*);

BOOLEAN add_score(struct game_system*);

BOOLEAN delete_score(struct game_system*);

BOOLEAN remove_all_scores(struct game_system*);

BOOLEAN resave_scores(struct game_system*);

BOOLEAN save_scores(struct game_system*);

/*
 * Used to create a game_result from a file or after a game.
 */
struct game_result* createGameResult(char*, char*, int);

/*
 * Used to automatically update the scoreboard.
 */
BOOLEAN updateScoreboardManually(char*, char*, int, struct game_system*);

/*
 * Used to work out how many chars the size of the linked list will take up
 * when printed.
 */
int getDigitAmount(int);


#endif
