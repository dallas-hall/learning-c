/******************************************************************************
 * Student Name    :  Dallas Hall
 * RMIT Student ID :  s3461243
 * COURSE CODE     :  CPT220 / OLA00
 *
 * Startup code provided by Paul Miller for use in "Programming in C",
 * study period 2, 2019.
 *****************************************************************************/
#include "io.h"
#include "game.h"

const int DEBUGGING_IO = 0;

const char *color_strings[NUM_COLORS] = {"\x1b[31m", "\x1b[37m", "\x1b[0m"};

const char *fontEffectStrings[MAX_FONT_EFFECTS] = {"\x1b[1m"};

/**
 * function that does buffer clearing when there is a buffer overflow on
 * input - only call this function when there is an actual buffer overflow as
 * otherwise you will have additional problems
 **/
void clear_buffer(void)
{
	int ch;
	/* while there are still chars to read and we have not reached
	 * the newline char, keep reading */
	while (ch = getc(stdin), ch != EOF && ch != '\n');
	/* reset the error status on the stdin file pointer */
	clearerr(stdin);
}

/**
 * this function simply calls printf. It is implemented here so that if we
 * wish to change our output target (such as using a gui) we could change our
 * implementation here and it would not affect any other code in our project.
 **/
int normal_print(const char format[], ...)
{
	int char_count;
	va_list vlist;
	va_start(vlist, format);
	char_count = vprintf(format, vlist);
	va_end(vlist);
	return char_count;
}

/**
 * this function prints out error messages to the stderr file pointer. It is
 * standard practice to output all error messages to stderr rather than
 * stdout (where printf sends messages).
 **/
int error_print(const char format[], ...)
{
	int char_count = 0;
	va_list vlist;
	char_count += fprintf(stderr, "[ERROR] ");
	va_start(vlist, format);
	char_count += vfprintf(stderr, format, vlist);

	return char_count;
}

/**
 * defines how to print the board given the orientation passed in. Pleas
 * see the asssignment specifications for further details.
 **/
/**
 * print the heading for the board
 **/
static void print_heading(void)
{
	char *heading = "Backgammon - Current board state";
	puts(heading);
	PUTLINE('-', strlen(heading));
}

/**
 * print the top row based on the orientation of the current player
 **/
static void print_top_row(enum orientation orient)
{
	int xcount;
	/* for clockwise, print the numbers 12 down to 1 */
	if (orient == OR_CLOCKWISE) {
		for (xcount = BOARD_WIDTH; xcount > 0; --xcount) {
			normal_print("| %-2d ", xcount);
		}
	}
	else {
		/* for anticlockwise, print the numbers 13 to 24 */
		for (xcount = BOARD_WIDTH + 1; xcount <= 2 * BOARD_WIDTH;
				++xcount) {
			normal_print("| %-2d ", xcount);
		}
	}
	putchar('\n');
	/* put a line of dashes under the row */
	PUTLINE('-', (CELL_WIDTH + 1) * (BOARD_WIDTH));
}

/**
 * print the bottom row of the table
 **/
static void print_bottom_row(enum orientation orient)
{
	int xcount;
	/* if the player's orientation is clockwise print 13 to 24 */
	if (orient == OR_CLOCKWISE) {
		for (xcount = BOARD_WIDTH + 1; xcount <= BOARD_WIDTH * 2;
				++xcount) {

			normal_print("| %-2d ", xcount);
		}
	}
	else {
		/* if the player's orientation is anticlockwise, print the
		 * numbers 12 down to 1
		 */
		for (xcount = BOARD_WIDTH; xcount > 0; --xcount) {

			normal_print("| %-2d ", xcount);
		}
	}
	putchar('\n');
	PUTLINE('-', (CELL_WIDTH + 1) * (BOARD_WIDTH));
}

/**
 * print a row of the board
 **/
static void print_row(int rownum, board theboard)
{
	int count;
	putchar('|');
	for (count = 0; count < BOARD_WIDTH; ++count) {
		/* for each cell, print the appropriate code for a blank, red or
		 * white token
		 */
		switch (theboard[rownum][count]) {
			case P_EMPTY:
				normal_print(" %2c |", EMPTY_TOKEN);
				break;
			case P_RED:
				normal_print(
						" %s%2c%s |", color_strings[COLOR_RED],
						RED_TOKEN, color_strings[COLOR_RESET]);
				break;
			case P_WHITE:
				normal_print(
						" %s%2c%s |", color_strings[COLOR_WHITE],
						WHITE_TOKEN, color_strings[COLOR_RESET]);
				break;
			default:
				error_print(
						"Oh noes, invalid value in the board!!\n");
				return;
		}
	}
	putchar('\n');
	PUTLINE('-', (CELL_WIDTH + 1) * (BOARD_WIDTH));
}

/**
 * print out the board according to the orientation of the current player
 **/
void board_print(board theboard, enum orientation orient)
{
	int row_count;
	print_heading();
	print_top_row(orient);

	for (row_count = 0; row_count < BOARD_HEIGHT; ++row_count) {
		print_row(row_count, theboard);
	}
	print_bottom_row(orient);
	printBoardFooterMessage();
}

enum input_result printPromptAndGetInput(char *s)
{
	char input[MAXPROMPTLEN];
	char *result;
	const char *triggerWord = "quit";
	int i;

	normal_print("%s", s);

	/*
	 * Need to account for the '\n' and '\0' that fgets adds.
	 * If the char last isn't '\n' then we know we didn't receive all the input.
	 * We need to remove the '\n' as well.
	 *
	 * Got this idea from Chapter 08 C How To Program 6e and Paul's week 4 sumup.c
	 */
	if (fgets(input, MAXPROMPTLEN + FGETS_EXTRA_CHARS, stdin) == NULL) {
		/*
		 * We want to return true here on ^D (control + D)
		 */
		return IR_QUIT;
	}

	/*
	 * Remember that strlen doesn't include the \0 in its count
	 */
	if (input[strlen(input) - 1] != '\n') {
		error_print("Buffer overflow.\n");
		clear_buffer();
		return printPromptAndGetInput(s);
	}

	/*
	 * Need minus 1 so we exclude reading the \n
	 * Converting the input to lower case and searching for quit with strstr
	 *
	 * Got this idea from Chapter 08 C How To Program 6e
	 */
	for (i = 0; i < strlen(input) - 1; i++) {
		input[i] = tolower(input[i]);
	}

	result = strstr(input, triggerWord);

	if (DEBUGGING_IO) {
		printf("[DEBUG] %s compared to %s is %s\n", triggerWord, input, result);
	}

	if (result != NULL) {
		return IR_QUIT;
	}

	return IR_FAILURE;
}

void printBoardFooterMessage()
{
	/*
	 * Store the pointer to the game object.
	 */
	struct game *theGame = getGame();
	char *name = theGame->current_player->name;
	int score = theGame->current_player->score;
	char *colour;
	char *direction;
	/*char token;*/
	char barCount[6]; /* including the '\0' */
	char output[256];

	if (theGame->current_player->orientation == OR_CLOCKWISE) {
		colour = "white";
		direction = "clockwise";
		/*token = 'X';*/
	}
	else {
		colour = "red";
		direction = "anticlockwise";
		/*token = 'O';*/
	}

	/*
	 * TODO - check what happens with a number
	 */
	if (theGame->current_player->bar_list.token_count == 0) {
		strcpy(barCount, "empty");
	}
	else {
		sprintf(barCount, "%d", theGame->current_player->bar_list.token_count);
	}

	/*
	 * Got the idea to use sprintf from chapter 08, C How To Program 6e
	 */

	if (theGame->current_player->orientation == OR_CLOCKWISE) {
		/*sprintf(output,
				"It is %s%s%s. Your score is %d, your colour is %s%s%s, your token is %s%c%s, your direction is %s%s%s, and your bar list is %s.\n",
				fontEffectStrings[FONT_BOLD], name, color_strings[COLOR_RESET],
				score, color_strings[COLOR_WHITE], colour,
				color_strings[COLOR_RESET], color_strings[COLOR_WHITE], token,
				color_strings[COLOR_RESET], color_strings[COLOR_WHITE],
				direction, color_strings[COLOR_RESET], barCount);*/
		sprintf(output,
				"It is %s%s's%s turn and their score is %d, their colour is %s%s%s, their direction is %s%s%s and their bar list is %s.\n",
				fontEffectStrings[FONT_BOLD], name, color_strings[COLOR_RESET],
				score, color_strings[COLOR_WHITE], colour,
				color_strings[COLOR_RESET], color_strings[COLOR_WHITE],
				direction, color_strings[COLOR_RESET], barCount);
	}
	else {
		/*sprintf(output,
				"It is your turn %s%s%s. Your score is %d, your colour is %s%s%s, your token is %s%c%s, your direction is %s%s%s, and your bar list is %s.\n",
				fontEffectStrings[FONT_BOLD], name, color_strings[COLOR_RESET],
				score, color_strings[COLOR_RED], colour,
				color_strings[COLOR_RESET], color_strings[COLOR_RED], token,
				color_strings[COLOR_RESET], color_strings[COLOR_RED],
				direction, color_strings[COLOR_RESET], barCount);*/
		sprintf(output,
				"It is %s%s's%s turn and their score is %d, their colour is %s%s%s, their direction is %s%s%s and their bar list is %s.\n",
				fontEffectStrings[FONT_BOLD], name, color_strings[COLOR_RESET],
				score, color_strings[COLOR_RED], colour,
				color_strings[COLOR_RESET], color_strings[COLOR_RED],
				direction, color_strings[COLOR_RESET], barCount);
	}
	normal_print(fold(output));


	/*normal_print("It is your turn %s. Your score is %d, your colour is %s",
				 name,
				 score, colour);
	normal_print(
			", your token is %c, your direction is %s, and your bar list is %s.\n",
			token, direction, barCount);*/
}

enum input_result getPlayerName(struct player *currentPlayer)
{
	char input[MAXPROMPTLEN];
	char output[256];
	struct game gamePointer = *getGame();

	int i;

	if (DEBUGGING_IO) {
		normal_print("%s\n", "[DEBUG] player.c - Entering getName.");
	}

	if (strlen(gamePointer.players[0].name) == 0) {
		normal_print("Player 1, enter your name (max 20 characters): ", input);
	}
	else if (strlen(gamePointer.players[1].name) == 0) {
		normal_print("Player 2, enter your name (max 20 characters): ", input);
	}

	/*
	 * Need to account for the '\n' and '\0' that fgets adds.
	 * If the char last isn't '\n' then we know we didn't receive all the input.
	 * We need to remove the '\n' as well.
	 *
	 * Got this idea from Chapter 08 C How To Program 6e and Paul's week 4 sumup.c
	 */
	if (fgets(input, MAXPROMPTLEN + FGETS_EXTRA_CHARS, stdin) == NULL) {
		return IR_FAILURE;
	}

	/*
	 * Remember that strlen doesn't include the \0 in its count
	 */
	if (input[strlen(input) - 1] != '\n') {
		error_print("Buffer overflow.\n");
		clear_buffer();
		return getPlayerName(currentPlayer);
	}

	if (strlen(input) > NAME_LEN + 1) {
		error_print("Input too long, less than 20 only.\n");
		return getPlayerName(currentPlayer);
	}

	if (strlen(input) < MIN_NAME_LEN) {
		error_print("Input too short, greater than 1 only.\n");
		return getPlayerName(currentPlayer);
	}

	/*
	 * Need to do -1 so we ignore the \n that is still there
	 */
	for (i = 0; i < strlen(input) - 1; i++) {
		if (!isalnum(input[i])) {
			sprintf(output,
					"Invalid character(s) found. Please use only letters and numbers.\n");
			error_print(fold(output));
			return getPlayerName(currentPlayer);
		}
	}

	if (DEBUGGING_IO) {
		normal_print(
				"[DEBUG] player.c - strlen(s) before removing \\n is %ld\n",
				strlen(input));
		normal_print("[DEBUG] player.c - s is %s\n", input);
	}

	/*
 	 * Replace \n with \0
 	 */

	input[strlen(input) - 1] = '\0';

	if (DEBUGGING_IO) {
		normal_print("[DEBUG] player.c - strlen(s) after removing \\n is %ld\n",
					 strlen(input));
		normal_print("[DEBUG] player.c - s is %s\n", input);

		normal_print("%s\n", "[DEBUG] player.c - Printing s with for loop.");
		for (i = 0; i < strlen(input); i++) {
			normal_print("%c", input[i]);
		}
		normal_print("\n");
	}

	/*
	 * Copy the input string into the player
	 */
	strcpy(currentPlayer->name, input);


	if (DEBUGGING_IO) {
		normal_print("[DEBUG] player.c - aplayer -> name is %s\n",
					 currentPlayer->name);
		normal_print("%s\n",
					 "[DEBUG] player.c - Printing aplayer -> name with for loop.");
		for (i = 0; i < strlen(input); i++) {
			normal_print("%c", currentPlayer->name[i]);
		}
		normal_print("\n");
	}

	return IR_SUCCESS;
}

enum input_result
getPlayerInput(struct player *currentPlayer, int diceRolls[2])
{
	/*
	 * Loop control
	 */
	enum input_result done = IR_FAILURE;
	/*
	 * Input prompt and store
	 */
	char *msg = "Please enter moves in the format of 3:4;2:5 where 3 abd 2 are column numbers and 4 and 5 are the number of spaces to move a token at that location. If you want to take a token from your bar list, enter the starting column as B: ";
	char input[MAXPROMPTLEN + FGETS_EXTRA_CHARS];
	/*
	 * Input & move processing
	 */
	char *tokenPointer;
	char *strtolRemainderPointer;
	/*
	 * Got this idea from https://stackoverflow.com/a/26598319
	 */
	char delimiters[3] = {':', ';', '\n'};
	int isColumn;
	int moveNumber;
	long currentNumber;
	struct move currentPlayerMoves[MAX_MOVES];
	int movesSum;
	int numberOfMoves;
	int i;
	BOOLEAN doubleRolled = FALSE;
	struct move_pair movePairs[MAX_MOVES];
	char possibleB;

	if (diceRolls[0] == diceRolls[1]) {
		doubleRolled = TRUE;
	}

	/*
	 * Probably should of done this inside of validate_moves but it made sense
	 * to me to do this here.
	 */
	do {
		/*
		 * Set up our validation checking values.
 		 */
		for (i = 0; i < MAX_MOVES; i++) {
			currentPlayerMoves[i].index = -100;
			currentPlayerMoves[i].count = -100;
		}
		moveNumber = 0;
		isColumn = 1;
		movesSum = 0;
		numberOfMoves = 0;

		normal_print(fold(msg));
		/*
		 * Need to account for the '\n' and '\0' that fgets adds.
		 * If the char last isn't '\n' then we know we didn't receive all the input.
		 * We need to remove the '\n' as well.
		 *
		 * Got this idea from Chapter 08 C How To Program 6e and Paul's week 4 sumup.c
		 */
		if (fgets(input, MAXPROMPTLEN + FGETS_EXTRA_CHARS, stdin) == NULL) {
			/*
			 * We want to return true here on ^D (control + D)
			 */
			return IR_QUIT;
		}

		/*
 		 * Swap players if the input was nothing.
 		 */
		if (strlen(input) == 1 && input[0] == '\n') {
			return IR_SKIP_TURN;
		}

		/*
 		 * Remember that strlen doesn't include the \0 in its count
		 */
		if (input[strlen(input) - 1] != '\n') {
			error_print("Buffer overflow.\n");
			clear_buffer();
			return getPlayerInput(currentPlayer, diceRolls);
		}

		/*
		 * Check each character of the input for a valid input sequence.
		 */
		if (!validMoveInput(input)) {
			error_print(
					"Invalid input. Must be n:n and for multiple input n:n;m:m as well as B;n for getting out of the bar list\n");
			sleep(.5);
			return getPlayerInput(currentPlayer, diceRolls);
		}

		/*
		 * Get the moves columnNumber:moveLength; .... ;columnNumber:moveLength\n
		 */
		tokenPointer = strtok(input, ":");

		while (tokenPointer != NULL) {
			if (DEBUGGING_IO) {
				normal_print("Current token is: %s\n", tokenPointer);
			}

			/*
			 * Need +1 here since moveNumber corresponds to array indices.
			 */
			if (moveNumber + 1 > MAX_MOVES) {
				error_print(
						"Too many moves, you can only have at most %d moves.\n",
						MAX_MOVES);
				sleep(.5);
				return getPlayerInput(currentPlayer, diceRolls);
			}

			currentNumber = strtol(tokenPointer, &strtolRemainderPointer, 0);
			if (DEBUGGING_IO) {
				printf("strlen(strtolRemainderPointer) is %ld\n",
					   strlen(strtolRemainderPointer));
			}

			possibleB = strtolRemainderPointer[0];

			/*
			 * Invalid characters found.
			 */
			if (strlen(strtolRemainderPointer) > 1 &&
				toupper(possibleB) != 'B') {
				error_print(
						"Invalid input. Must be the letter B, numbers : and ; only.\n");
				/*
				 * Sleeping so the error message is printed first.
				 */
				sleep(.5);
				return getPlayerInput(currentPlayer, diceRolls);
			}

			if (strlen(strtolRemainderPointer) == 0) {
				/*
				 * This ensures a valid move, as you can only move forward in
				 * backgammon and between 1 and 24.
				 */
				if (currentNumber <= 0) {
					error_print(
							"Invalid input. Must be whole integers only.\n");
					/*
					  * Sleeping so the error message is printed first.
					  */
					sleep(.5);
					return getPlayerInput(currentPlayer, diceRolls);
				}
				else if (currentNumber > 24) {
					error_print(
							"Invalid input. Integers higher than 24 are invalid.\n");
					/*
					  * Sleeping so the error message is printed first.
					  */
					sleep(.5);
					return getPlayerInput(currentPlayer, diceRolls);
				}
			}

			/*
			 * Store the column index or move amount.
			 */
			if (isColumn == 1) {
				if (toupper(possibleB) == 'B') {
					/*
					 * Store 98, ASCII for uppercase B
					 */
					currentPlayerMoves[moveNumber].index = (int) possibleB;
				}
				else {
					currentPlayerMoves[moveNumber].index = (int) currentNumber;
				}

				isColumn = 0;
			}
			else {
				currentPlayerMoves[moveNumber].count = (int) currentNumber;
				movesSum += (int) currentNumber;
				++moveNumber;
				++numberOfMoves;
				isColumn = 1;
			}

			if (DEBUGGING_IO) {
				normal_print("[DEBUG] currentNumber is %ld\n", currentNumber);
				normal_print("[DEBUG] strtol remainder is %s\n",
							 strtolRemainderPointer);
				normal_print("[DEBUG] isColumn is %d\n", isColumn);
			}

			/*
 			 * The NULL argument tell strtok to keep going.
 			 * NULL is returned when there are no more tokens.
 			 */
			tokenPointer = strtok(NULL, delimiters);
		}

		/*
		 * Check that total moves don't exceed the sum of die rolls.
		 * For doubles, its sum of die rolls * 2
		 */
		if ((movesSum > (diceRolls[0] + diceRolls[1])) && !doubleRolled) {
			error_print(
					"Invalid input for normal roll. Your total amount of moves exceeds your die roll total.\n");
			/*
			  * Sleeping so the error message is printed first.
			  */
			sleep(.5);
			return getPlayerInput(currentPlayer, diceRolls);
		}
		else if ((movesSum > ((diceRolls[0] + diceRolls[1]) * 2)) &&
				 doubleRolled) {
			error_print(
					"Invalid input for double roll. Your total amount of moves exceeds die roll total times 2.\n");
			/*
			  * Sleeping so the error message is printed first.
			  */
			sleep(.5);
			return getPlayerInput(currentPlayer, diceRolls);
		}

		/*
		 * Go through all the stored moves.
		 */
		for (i = 0; i < numberOfMoves; i++) {
			if (DEBUGGING_IO) {
				printf("moves[%d].index is %d\n", i,
					   currentPlayerMoves[i].index);
				printf("moves[%d].count is %d\n", i,
					   currentPlayerMoves[i].count);
			}

			movePairs[i] = getMovePair(currentPlayerMoves[i].index,
									   currentPlayerMoves[i].count,
									   currentPlayer);
		}

		/*
		 * Validate the moves, if invalid get input again.
		 * If valid, apply the moves and adjust game state.
		 *
		 * The check for multiple moves will happen in apply moves. I don't
		 * have enough time to refactor this to make it all work in the right
		 * spots.
		 */
		if (!validate_moves(currentPlayerMoves, numberOfMoves, currentPlayer,
							diceRolls, movePairs)) {
			return getPlayerInput(currentPlayer, diceRolls);
		}

		/*
		 * Tried calling clear_buffer() here as I was having some intermittent
		 * issues with needing to press enter twice after this process. That
		 * didn't help.
		 *
		 * I tried removing the newline before entering strtok and that didn't
		 * help either. Not sure what the problem is, seems to only happen
		 * inside of CLion and not on the command line.
		 */
		/*clear_buffer();*/

		done = IR_SUCCESS;
	} while (!done);

	return done;
}

BOOLEAN validMoveInput(char input[])
{
	int i;
	int numberCount = 0;
	int bCount = 0;
	int colonCount = 0;
	int semiColonCount = 0;
	char previousChar;

	/*
	 * The boundary of numbers should only be these 3 characters.
	 * B can only be found before a : and after a ;
	 * Numbers can be found anywhere.
	 */
	for (i = 0; i < strlen(input); i++) {
		if (DEBUGGING_IO) {
			printf("current char is %c\n", input[i]);
		}

		if (i != 0) {
			previousChar = input[i - 1];

			if (input[i] == ':') {
				++colonCount;

				if (isdigit(previousChar)) {
					++numberCount;
				}
				else if (toupper(previousChar) == 'B') {
					++bCount;
				}
			}
			else if (input[i] == ';') {
				++semiColonCount;

				if (isdigit(previousChar)) {
					++numberCount;
				}
				else if (toupper(previousChar) == 'B') {
					++bCount;
				}
			}
			else if (input[i] == '\n') {
				++numberCount;
			}
		}
	}

	/*
	 * For valid input
	 *
	 * Without any Bs
	 * a) numbers should be double the amount of colons.
	 * b) semi-colons should be 0 or 1 less that the amount of colons
	 *
	 * With Bs
	 * a) number count + b count should be double the amount of colons
	 * b) semi-colons should be 0 or 1 less that the amount of colons + Bs
	 */
	if (bCount == 0) {
		if (colonCount != (numberCount / 2)) {
			return FALSE;
		}
		else if (semiColonCount != 0 && semiColonCount != (colonCount - 1)) {
			return FALSE;
		}
	}
	else {
		if (colonCount != ((numberCount + bCount) / 2)) {
			return FALSE;
		}
		else if (semiColonCount != 0 &&
				 semiColonCount != (colonCount + bCount - 1)) {
			return FALSE;
		}
	}

	return TRUE;
}

/*
 * !!! THE CODE BELOW IS NOT USED, REPLACED WITH SOLUTION CODE. !!!
 * Replaced this with the sample solution as it would be a time sink to adjust
 * and make it the same as the spec. I had subtle printing differences.
 */
void board_print_my_old_code(board theboard, enum orientation orient)
{
	int row, column, topNumber, bottomNumber, rowOffset, columnOffset, currentPiece;

	if (DEBUGGING_IO) {
		normal_print("%s\n", "[DEBUG] io.c - Entering board_print.");
	}

	printBoardHeaderMessage();
	/*
	 * Use for printing the board numbers.
 	 * These need to be decremented
 	 */

	if (orient == OR_CLOCKWISE) {
		topNumber = 12;
		bottomNumber = 13;
	}
	else if (orient == OR_ANTICLOCKWISE) {
		topNumber = 13;
		bottomNumber = 12;
	}
	/*
	 * Used for printing tokens.
	  * These need to be incremented.
	  */
	rowOffset = 0;
	columnOffset = 0;
	for (row = 0; row < PRINT_HEIGHT; row++) {
		for (column = 0; column < PRINT_WIDTH; column++) {
			/*
			 * Only print the - for the top, bottom, and every even row.
			 */
			if (row == 0 || row % 2 == 0 || row == PRINT_HEIGHT - 1) {
				normal_print("-");
			}
				/*
				 * Only print the board numbers on the second and second last row.
				 */
			else if (row == 1 || row == PRINT_HEIGHT - 2) {
				if (column == 0 || column % 6 == 0 ||
					column == PRINT_WIDTH - 1) {
					normal_print("|");
				}
				/*
				 * Print topNumber only on row 1.
				 * Print bottomNumber only on row 32
				 * Print each number in the first space of each column.
				 */
				switch (column) {
					case 1:
					case 7:
					case 13:
					case 19:
					case 25:
					case 31:
					case 37:
					case 43:
					case 49:
					case 55:
					case 61:
					case 66:
						if (orient == OR_CLOCKWISE) {
							if (row == 1) {
								normal_print("  %2d ", topNumber);
								--topNumber;
							}
							else if (row == PRINT_HEIGHT - 2) {
								normal_print("  %2d ", bottomNumber);
								++bottomNumber;
							}
							break;
						}
						else if (orient == OR_ANTICLOCKWISE) {
							if (row == 1) {
								normal_print("  %2d ", topNumber);
								++topNumber;
							}
							else if (row == PRINT_HEIGHT - 2) {
								normal_print("  %2d ", bottomNumber);
								--bottomNumber;
							}
						}
				}
			}
				/*
				 * Only print the '|', ' ', and tokens on every odd row.
				 */
			else if (row % 2 == 1) {
				if (column == 0 || column % 6 == 0 ||
					column == PRINT_WIDTH - 1) {
					normal_print("|");
				}
					/*
					 * Skip every 3rd spot as this might have a player token.
					 */
				else if (column % 3 != 0) {
					normal_print(" ");
				}
				else {
					if (DEBUGGING_IO) {
						normal_print("x: %d y: %d", rowOffset, columnOffset);
					}
					/*currentPiece = getStartPiece(rowOffset, columnOffset);*/
					/*currentPiece = getStartPieceArray(rowOffset, columnOffset);*/
					currentPiece = getPieceFromBoardState(rowOffset,
														  columnOffset,
														  theboard);
					if (currentPiece == 0) {
						normal_print(" ");
					}
					else if (currentPiece == 1) {
						normal_print("%s%c%s", color_strings[COLOR_RED],
									 RED_TOKEN,
									 color_strings[COLOR_RESET]);

					}
					else if (currentPiece == 2) {
						normal_print("%s%c%s", color_strings[COLOR_WHITE],
									 WHITE_TOKEN, color_strings[COLOR_RESET]);

					}
					++columnOffset;
				}

			}
		}
		/*
		 * Increment the row offset so we have the correct row next run
		 * Reset the column offset so we have the current column next run
		 */
		if (row >= 3 && row % 2 != 0) {
			++rowOffset;
			columnOffset = 0;
		}

		normal_print("\n");
	}

	printBoardFooterMessage();
}

/*
 * Basic board printing for debugging.
 */
void printBoard(board the_board)
{
	int row, column;
	if (DEBUGGING_IO) {
		normal_print("%s\n", "[DEBUG] board.c - Entering printBoard.");
	}
	for (row = 0; row < BOARD_HEIGHT; row++) {
		for (column = 0; column < BOARD_WIDTH; column++) {
			normal_print("[%d][%d] %d\t", row, column, the_board[row][column]);
			if (column == BOARD_WIDTH - 1) {
				normal_print("\n");
			}
		}
	}
	normal_print("\n");
}

void printBoardReverse(board the_board)
{
	int row, column;

	if (DEBUGGING_IO) {
		normal_print("%s\n", "[DEBUG] board.c - Entering printBoardReverse.");
	}
	for (row = BOARD_HEIGHT - 1; row >= 0; row--) {
		for (column = 0; column < BOARD_WIDTH; column++) {
			normal_print("[%d][%d] %d\t", row, column, the_board[row][column]);
			if (column == BOARD_WIDTH - 1) {
				normal_print("\n");
			}
		}
	}
	normal_print("\n");
}

void printBoardHeaderMessage()
{
	normal_print("\nCPT220 Backgammon - Current Board State\n");
}


/*
 * The next 2 functions are used during debugging, so we can see which pointer
 * is currently inside of current_player or other_player.
 */
void printCurrentPlayer(struct game *thegame)
{
	normal_print("[DEBUG] player.c - printCurrentPlayer\n");
	normal_print("thegame->current_player.name is %s\n",
				 thegame->current_player->name);
	normal_print("thegame->current_player.score is %d\n",
				 thegame->current_player->score);
	normal_print("thegame->current_player.token is %d\n",
				 thegame->current_player->token);
	normal_print("thegame->current_player.orientation is %d\n",
				 thegame->current_player->orientation);
	normal_print("thegame->current_player.bar_list.token_count is %d\n\n",
				 thegame->current_player->bar_list.token_count);
}

void printOtherPlayer(struct game *thegame)
{
	normal_print("[DEBUG] player.c - printOtherPlayer\n");
	normal_print("thegame->other_player.name is %s\n",
				 thegame->other_player->name);
	normal_print("thegame->other_player.score is %d\n",
				 thegame->other_player->score);
	normal_print("thegame->other_player.token is %d\n",
				 thegame->other_player->token);
	normal_print("thegame->other_player.orientation is %d\n",
				 thegame->other_player->orientation);
	normal_print("thegame->current_player.bar_list.token_count is %d\n\n",
				 thegame->current_player->bar_list.token_count);
}

void printWinningMessage(struct player *currentPlayer)
{
	normal_print("\nCongratulations! %s has won the game with a score of %d\n",
				 currentPlayer->name, currentPlayer->score);
}

void printDrawMessage()
{
	normal_print("\nThe game was a draw!\n");
}