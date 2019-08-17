/******************************************************************************
 * Student Name    :  Dallas Hall
 * RMIT Student ID :  s3461243
 * COURSE CODE     :  CPT220 / OLA00
 *
 * Startup code provided by Paul Miller for use in "Programming in C",
 * study period 2, 2019.
 *****************************************************************************/

#include "scoreboard.h"
#include "io.h"
#include "main.h"

const int DEBUGGING_SCOREBOARD = 1;

/**
 * initialise the scores menu with the text and functions that perform the
 * required functionality.
 **/
void init_scores_menu(struct scores_menu_entry scores_menu[])
{
}

/**
 * manages user input via the scores menu
 **/
void scores_menu(struct game_system* thesystem)
{
}

/**
 * performs the display scores function for the scores menu
 **/
BOOLEAN print_scores(struct game_system* thesystem)
{
	return FALSE;
}

/**
 * adds a score to the system via user input. Please note that in a real
 * game score menu this makes no sense but it's here so you can show you
 * can do it.
 **/
BOOLEAN add_score(struct game_system* thesystem)
{
	return FALSE;
}

/**
 * handles the "delete node" submenu for the system. Again, this would not
 * be a likely part of such a program in the real world but we are getting
 * you do do this so you can show you know how.
 **/
BOOLEAN delete_score(struct game_system* thesystem)
{

	return FALSE;
}

/**
 * clears out the scoreboard to make it an empty list
 **/
BOOLEAN remove_all_scores(struct game_system* thesystem)
{
	BOOLEAN result;

	result = deleteLinkedListNodes(&thesystem->scoreboard);

	return result;
}

/**
 * save scores back to the same file it was loaded from
 **/
BOOLEAN resave_scores(struct game_system* thesystem)
{
	BOOLEAN result;

	result = FALSE;

	return result;
}

/**
 * saves the data file to a new file. The datafile attribute of the game system
 * should now point to the path of the file the data has been saved to. This is
 * similar to "save as" functionality in a word processor.
 **/
BOOLEAN save_scores(struct game_system* thesystem)
{
	return FALSE;
}

struct game_result*
createGameResult(char* winner, char* loser, int winningMargin)
{
	struct game_result* gameResultPtr;

	/*
	 * malloc tries to allocate memory with the specified bytes.
	 * sizeof will return the size of the data structure, platform
	 * dependent. If successful, malloc returns a void * to the
	 * allocated memory, otherwise returns NULL
	 * We are using struct game_result because that is the object
	 * hat will be stored in the pointer.
	 *
	 * Paul tends to cast the void* returned by malloc.
	 */
	gameResultPtr = malloc(sizeof(struct game_result));

	/*
	 * Same as linkedListPtr == NULL. I tend to use both.
	 */
	if (!gameResultPtr) {
		perror("malloc");
		return NULL;
	}

	/*
	 * memset copies a byte value for n bytes into a specified object
	 * arg 1) the object to copy into
	 * arg 2) the byte to copy
	 * arg 3) how many bytes in the object to copy into
	 *
	 * We are using struct game_result because that is the object that will
	 * be stored in the pointer.
	 *
	 * This is called zeroing out the memory. I believe this means:
	 * int = 0
	 * ptr = NULL
	 * char = '\0'
	 *
	 * Not sure if this is even necessary at this point? Every time I
	 * inspected these variables there were already zeroed.
	 */
	memset(gameResultPtr, 0, sizeof(struct game_result));

	gameResultPtr->winner = winner;
	gameResultPtr->loser = loser;
	gameResultPtr->won_by = winningMargin;

	return gameResultPtr;
}

BOOLEAN
updateScoreboardManually(char* winnerName, char* loserName, char* winningMargin,
						 struct game_system* gameSystem)
{
	struct game_result* gameResultPtr;
	struct node* linkedListNodePtr;
	struct linkedlist* linkedListPtr;
	char* validatedWinnersName;
	char* validatedLosersName;
	int validatedWinningMargin = 0;

	linkedListNodePtr = createLinkedListNode();

	if (!linkedListNodePtr) {
		fprintf(stderr, "[ERROR] Couldn't create the linked list node.\n");
		return FALSE;
	}

	if (!validInputName(winnerName)) {
		fprintf(stderr, "[ERROR] Winner's name is invalid.\n");
		return FALSE;
	}

	if (!validInputName(loserName)) {
		fprintf(stderr, "[ERROR] Losers's name is invalid.\n");
		return FALSE;
	}

	validatedWinningMargin = validWinningMargin(winningMargin);
	if (validatedWinningMargin == -1) {
		fprintf(stderr, "[ERROR] Winning margin is invalid.\n");
		return FALSE;
	}

	/*
	 * We need to free this later as strdup has its own malloc call.
	 */
	validatedWinnersName = strdup(winnerName);
	validatedLosersName = strdup(loserName);

	gameResultPtr = createGameResult(validatedWinnersName, validatedLosersName,
									 validatedWinningMargin);

	if (!gameResultPtr) {
		fprintf(stderr, "[ERROR] Couldn't create the game result.\n");
		return FALSE;
	}

	/*
	 * Update the linked list node payload and link members.
	 */
	linkedListNodePtr->data = gameResultPtr;
	linkedListNodePtr->next = NULL;

	/*
	 * Grab the address of the scoreboard from the game_system pointer.
	 * This is the bit that I needed to use the global variable for
	 * game_system.
	 */
	linkedListPtr = &gameSystem->scoreboard;

	/*
	 * Try to update the scoreboard
	 */
	if (!insertNode(linkedListPtr, linkedListNodePtr)) {
		error_print("Couldn't insert into the linked list.\n");
		return FALSE;
	}

	return TRUE;
}