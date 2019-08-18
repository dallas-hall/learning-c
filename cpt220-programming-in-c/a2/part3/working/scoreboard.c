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
	 * TODO create scores menu
	 */
	/*
	 * Copy the menu item description's in.
	 */
	strcpy(scores_menu[PRINT].text, "Print the current scoreboard.");
	strcpy(scores_menu[ADD].text, "Add a new score to the scores list.");
	strcpy(scores_menu[DELETE_ONE].text, "Delete a score from the scores list");
	strcpy(scores_menu[DELETE_ALL].text,
		   "Remove all scores from the scores list.");
	strcpy(scores_menu[SAVE].text,
		   "Save Scores back to the file they were loaded from.");
	strcpy(scores_menu[SAVE_NEW].text, "Save scores to a new file name.");

	/*
	 * Assign the function pointers.
	 */
	scores_menu[PRINT].function = print_scores;
	scores_menu[ADD].function = add_score;
	scores_menu[DELETE_ONE].function = delete_score;
	scores_menu[DELETE_ALL].function = remove_all_scores;
	scores_menu[SAVE].function = save_scores;
	scores_menu[SAVE_NEW].function = resave_scores;
	/*
	 * There is no quit function, just call the main menu print function.
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
	int i;
	int choice;
	enum input_result inputResult;
	BOOLEAN menuResult;

	/*
	 * This is an infinite loop but that is okay because the user will exit
	 * this.
	 */
	while (1) {
		puts("Scores Menu");
		PUTCHARS('=', strlen("Scores Menu"));
		printf("\n");

		for (i = 0; i < NUM_SCORES_MENU_ITEMS; i++) {
			printf("%d) %s\n", i + 1, thesystem->the_menus.scores_menu[i].text);
		}
		printf("%d) Quit to the main menu.\n", i + 1);

		inputResult = read_int("Enter the number of your choice", &choice);

		if (inputResult == IR_FAILURE) {
			continue;
		}
		else if (inputResult == IR_SKIP_TURN) {
			printMainMenu(thesystem);
		}
		else if (inputResult == IR_QUIT) {
			printMainMenu(thesystem);
		}
		else {
			switch (choice) {
				case 1:

					/*
					 * We don't care about the result here because a false
					 * is returned when the scoreboard is empty.
					 *
					 * For everything else we care.
					 */
					menuResult = print_scores(thesystem);
					break;
				case 2:
					menuResult = add_score(thesystem);

					if (!menuResult) {
						fprintf(stderr, "Couldn't add score to scoreboard.\n");
					}
					break;
				case 3:
					menuResult = delete_score(thesystem);

					if (!menuResult) {
						fprintf(stderr,
								"Couldn't delete score from scoreboard.\n");
					}
					break;
				case 4:
					menuResult = remove_all_scores(thesystem);

					if (!menuResult) {
						fprintf(stderr,
								"Couldn't delete all scores from scoreboard.\n");
					}
					break;
				case 5:
					menuResult = save_scores(thesystem);

					if (!menuResult) {
						fprintf(stderr, "Couldn't save scoreboard to disk.\n");
					}
					break;
				case 6:
					menuResult = resave_scores(thesystem);

					if (!menuResult) {
						fprintf(stderr,
								"Couldn't resave scoreboard to disk.\n");
					}
					break;
				case 7:
					printMainMenu(thesystem);
					break;
				default:
					fprintf(stderr, "Invalid choice, try again.\n");
			}
		}
		break;
	}
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
		if (lineNumber >= 10) {
			if (lineNumber != thesystem->scoreboard.size) {
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
	char input[MAXPROMPTLEN];
	char winnerName[NAME_LEN + FGETS_EXTRA_CHAR];
	char loserName[NAME_LEN + FGETS_EXTRA_CHAR];
	int winningMargin;
	enum input_result inputResult;

	printf("Add a score\n");
	PUTCHARS('-', strlen("Add a score"));
	printf("\n");

	while (1) {
		/*
		 * Clear the buffer
		 */
		memset(input, 0, MAXPROMPTLEN);

		/*
		 * Using Paul's read_string (io.c) so I don't need to reinvent the wheel.
		 * It handles a lot of things like clearing buffers, input length
		 * validation, etcetera..
		 */
		inputResult = read_string("Please enter the winner of the game", input,
								  20);

		/*
		 * ^D is IR_QUIT
		 * Enter is IR_SKIP_TURN
		 *
		 * Both will exit
		 */
		if (inputResult == IR_QUIT || inputResult == IR_SKIP_TURN) {
			fprintf(stderr,
					"[WARNING] Exit condition met, did not update the scoreboard.\n");
			return FALSE;
		}

		/*
		 * If we got an input failure, try again.
		 */
		if (inputResult == IR_FAILURE) {
			continue;
		}

		if (validInputName(input)) {
			/*
			 * Remove garbage
			 */
			memset(winnerName, 0, NAME_LEN + FGETS_EXTRA_CHAR);
			strcpy(winnerName, input);
			break;
		}
	}

	while (1) {
		memset(input, 0, MAXPROMPTLEN);

		inputResult = read_string("Please enter the loser of the game", input,
								  20);

		if (inputResult == IR_QUIT || inputResult == IR_SKIP_TURN) {
			fprintf(stderr,
					"[WARNING] Exit condition met, did not update the scoreboard.\n");
			return FALSE;
		}

		if (inputResult == IR_FAILURE) {
			continue;
		}

		if (validInputName(input)) {
			memset(loserName, 0, NAME_LEN + FGETS_EXTRA_CHAR);
			strcpy(loserName, input);
			break;
		}
	}

	while (1) {
		inputResult = read_int("Please enter the amount the game was won by",
							   &winningMargin);

		if (inputResult == IR_QUIT || inputResult == IR_SKIP_TURN) {
			fprintf(stderr,
					"[WARNING] Exit condition met, did not update the scoreboard.\n");
			return FALSE;
		}

		if (inputResult == IR_FAILURE) {
			continue;
		}

		/*
		 * Check for invalid numbers, if we got it, try again.
		 * If not, break out of the loop.
		 */
		if (winningMargin <= 0 || winningMargin > 15) {
			error_print(
					"Invalid input in the third token, should be between 1 and 15 but was %ld.\n",
					winningMargin);
			continue;
		}
		else {
			break;
		}
	}

	return TRUE;
}

/**
 * handles the "delete node" submenu for the system. Again, this would not
 * be a likely part of such a program in the real world but we are getting
 * you do do this so you can show you know how.
 **/
BOOLEAN delete_score(struct game_system* thesystem)
{
	enum input_result inputResult;
	int nodeToDelete;

	print_scores(thesystem);
	while (1) {
		inputResult = read_int("What score do you want to delete",
							   &nodeToDelete);

		if (inputResult == IR_QUIT || inputResult == IR_SKIP_TURN) {
			fprintf(stderr,
					"[WARNING] Exit condition met, did not update the scoreboard.\n");
			return FALSE;
		}

		if (inputResult == IR_FAILURE) {
			continue;
		}

		if (nodeToDelete <= 0 || nodeToDelete > thesystem->scoreboard.size) {
			error_print(
					"Invalid input in the third token, should be between 1 and %d but was %ld.\n",
					thesystem->scoreboard.size, nodeToDelete);
			continue;
		}
		else {
			/*
			 * Try to delete the node.
			 */
			if (deleteNodeViaPosition(&thesystem->scoreboard, nodeToDelete)) {
				return TRUE;
			}
			else {
				return FALSE;
			}
		}
	}
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
	 * TODO test this
	 */

	result = save_data(thesystem->datafile, &thesystem->scoreboard);

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
	 * TODO save files to the new file
	 *
	 * get new file name and validate length - os will validate if it exists
	 * call save_data
	 */

	result = save_data(thesystem->datafile, &thesystem->scoreboard);

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

/*
 * Needed this to get around the main_menu_entry function pointer
 * excepting a void return. I don't see the point in duplicating the printing
 * scoreboard function twice, one with a BOOLEAN result and one without.
 * So calling the print_scores function and ignoring its return result.
 */
void printScores(struct game_system* thesystem)
{
	print_scores(thesystem);
}