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
	/*
	 * TODO create main menu
	 */
}

/**
 * manages user input via the scores menu
 **/
void scores_menu(struct game_system* thesystem)
{
	/*
	 * TODO create scores menu
	 */
}

/**
 * performs the display scores function for the scores menu
 **/
BOOLEAN print_scores(struct game_system* thesystem)
{
	int lineNumber;
	int i;
	int rowNumberOffset;
	int nameLength;
	int printOffset;
	int totalRowLength;
	struct node* currentNode;

	rowNumberOffset = getNumberOffset(thesystem->scoreboard.size) +
					  ROW_NUMBER_EXTRA_CHARS;
	nameLength = NAME_LEN;
	totalRowLength = rowNumberOffset + NAME_LEN + TABLE_DELIMITER + NAME_LEN +
					 TABLE_DELIMITER + WON_BY_AMOUNT;

	/*
	 * Check if the list is empty.
	 */
	if (thesystem->scoreboard.size <= 0) {
		fprintf(stderr, "%s", "[WARNING] Trying to print an empty scoreboard.");
		return FALSE;
	}

	/*
	 * Print the header.
	 * I was thinking about modularising this but I didn't really see a
	 * point making a function for this.
	 * 
	 * Print the first 2 lines
	 *
	 * 1) The Scoreboard
	 * 2) ==============
	 */
	puts("The Scoreboard");
	PUTCHARS('=', strlen("The Scoreboard"));
	printf("\n");

	/*
	 * Print the Winner heading followed by delimiter.
	 * The offset is how many characters the largest row number will
	 * take up when printing.
	 */
	for (i = 0; i < rowNumberOffset; i++) {
		printf(" ");
	}

	printf("Winner");

	printOffset = strlen("Winner");
	for (i = 0; i < nameLength - printOffset; i++) {
		printf(" ");
	}

	printf("|");

	/*
	 * Print the Loser heading followed by delimiter.
	 */
	printf("Loser");

	printOffset = strlen("Loser");
	for (i = 0; i < nameLength - printOffset; i++) {
		printf(" ");
	}

	printf("|");

	/*
	 * Print the Amount Won By heading.
	 */
	puts("Amount Won By");

	/*
	 * Print the header underline
	 * --------------------------
	 */
	PUTCHARS('-', totalRowLength);
	printf("\n");

	/*
	 * Print the list.
	 */
	currentNode = thesystem->scoreboard.head;
	lineNumber = 1;
	while (currentNode != NULL) {
		/*
		 * Print the
		 * 1) optional preceding space
		 * 2) row number
		 * 3) )
		 * 4) trailing space.
		 */
		printOffset = getNumberOffset(lineNumber);

		/*
		 * The original printing offset only works for single digit numbers.
		 * As the number of digits grows, the offset needs to be adjusted.
		 * Through trial and error, the adjustment that I found that works with
		 * the provided files (10, 100, 1000, 10000) is below.
		 */
		if(lineNumber >= 10) {
			if(lineNumber != thesystem->scoreboard.size) {
				printOffset -= (printOffset - 1);
			}
			else {
				printOffset = 0;
			}
		}

		for (i = 0; i < printOffset; i++) {
			printf(" ");
		}

		printf("%d) ", lineNumber);

		/*
		 * Print
		 * 1) The winner's name
		 * 2) The spaces
		 * 3) The table delimiter
		 */
		printf("%s", currentNode->data->winner);
		printOffset = (int) strlen(currentNode->data->winner);

		for (i = 0; i < nameLength - printOffset; i++) {
			printf(" ");
		}
		printf("|");

		/*
		 * Print
		 * 1) The losers' name
		 * 2) The spaces
		 * 3) The table delimiter
		 */
		printf("%s", currentNode->data->loser);
		printOffset = (int) strlen(currentNode->data->loser);

		for (i = 0; i < nameLength - printOffset; i++) {
			printf(" ");
		}
		printf("|");

		/*
		 * Print winning margin and newline
		 */
		printf("%d\n", currentNode->data->won_by);

		currentNode = currentNode->next;
		++lineNumber;
	}

	/*
	 * Print the bottom of the table underline
	 * ---------------------------------------
	 */
	PUTCHARS('-', totalRowLength);
	printf("\n");

	return TRUE;
}

/**
 * adds a score to the system via user input. Please note that in a real
 * game score menu this makes no sense but it's here so you can show you
 * can do it.
 **/
BOOLEAN add_score(struct game_system* thesystem)
{
	/*
	 * TODO call to updateScoreboardManually
	 */

	return FALSE;
}

/**
 * handles the "delete node" submenu for the system. Again, this would not
 * be a likely part of such a program in the real world but we are getting
 * you do do this so you can show you know how.
 **/
BOOLEAN delete_score(struct game_system* thesystem)
{
	/*
	 * TODO call to deleteNodeViaPosition
	 */

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

	/*
	 * TODO save files to the current known file - call save_data
	 */

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
	BOOLEAN result;

	/*
	 * TODO save files to the new file - get new file name and call save_data
	 */

	result = FALSE;

	return result;
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

int getNumberOffset(int linkedListSize)
{
	int offset;
	int digits;

	offset = 0;
	digits = linkedListSize;

	if (linkedListSize > 0) {
		/*
		 * Need to set it one here in case there is only 1 digit.
		 */
		offset = 1;

		while (digits > 9) {
			/*
			 * Use division by 10 to remove 1 digit at a time.
			 */
			digits /= 10;
			++offset;
		}
	}

	return offset;
}