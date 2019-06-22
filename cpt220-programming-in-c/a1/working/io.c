/******************************************************************************
 * Student Name    :  Dallas Hall
 * RMIT Student ID :  s3461243
 * COURSE CODE     :  CPT220 / OLA00
 *
 * Startup code provided by Paul Miller for use in "Programming in C",
 * study period 2, 2019.
 *****************************************************************************/
#include "io.h"

const int DEBUGGING_IO = 0;

const char *color_strings[NUM_COLORS] = {"\x1b[31m", "\x1b[37m", "\x1b[0m"};

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
	char_count += fprintf(stderr, "Error: ");
	va_start(vlist, format);
	char_count += vfprintf(stderr, format, vlist);

	return char_count;
}

/**
 * defines how to print the board given the orientation passed in. Pleas
 * see the asssignment specifications for further details.
 **/
void board_print(board theboard, enum orientation orient)
{
	int row, column, topNumber, bottomNumber, rowOffset, columnOffset, currentPiece;

	if (DEBUGGING_IO) {
		printf("%s\n", "[DEBUG] io.c - Entering board_print.");
	}

	/*
	 * I feel so dirty doing it this way, but I created my solution in
	 * board.c before seeing this.
	 */
	if (orient == OR_CLOCKWISE) {
		/*
		 * Use for printing the board numbers.
		 * These need to be decremented
		 */
		topNumber = 12;
		bottomNumber = 13;
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
					printf("-");
				}
					/*
					 * Only print the board numbers on the second and second last row.
					 */
				else if (row == 1 || row == PRINT_HEIGHT - 2) {
					if (column == 0 || column % 6 == 0 ||
						column == PRINT_WIDTH - 1) {
						printf("|");
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
							if (row == 1) {
								printf("  %2d ", topNumber);
								--topNumber;
							}
							else if (row == PRINT_HEIGHT - 2) {
								printf("  %2d ", bottomNumber);
								++bottomNumber;
							}
							break;
					}
				}
					/*
					 * Only print the '|', ' ', and tokens on every odd row.
					 */
				else if (row % 2 == 1) {
					if (column == 0 || column % 6 == 0 ||
						column == PRINT_WIDTH - 1) {
						printf("|");
					}
						/*
						 * Skip every 3rd spot as this might have a player token.
						 * TODO - add logic for printing from the saved state
						 */
					else if (column % 3 != 0) {
						printf(" ");
					}
					else {
						if (DEBUGGING_IO) {
							printf("x: %d y: %d", rowOffset, columnOffset);
						}
						/*currentPiece = getStartPiece(rowOffset, columnOffset);*/
						/*currentPiece = getStartPieceArray(rowOffset, columnOffset);*/
						currentPiece = getPieceFromBoardState(rowOffset,
															  columnOffset,
															  theboard);
						if (currentPiece == 0) {
							printf(" ");
						}
						else if (currentPiece == 1) {
							printf("%s%c%s", color_strings[COLOR_RED],
								   RED_TOKEN,
								   color_strings[COLOR_RESET]);

						}
						else if (currentPiece == 2) {
							printf("%s%c%s", color_strings[COLOR_WHITE],
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

			printf("\n");
		}
	}
	else if (orient == OR_ANTICLOCKWISE) {
		/*
 * These need to be decremented
 * Use for printing the board numbers.
 */
		topNumber = 12;
		bottomNumber = 13;
		/*
		 * Used for printing tokens.
		 * rowOffset need to be decremented for reverse printing.
		  * columnOffset need to be incremented.
		  */
		rowOffset = 13;
		columnOffset = 0;
		for (row = 0; row < PRINT_HEIGHT; row++) {
			for (column = 0; column < PRINT_WIDTH; column++) {
				/*
				 * Only print the - for the top, bottom, and every even row.
				 */
				if (row == 0 || row % 2 == 0 || row == PRINT_HEIGHT - 1) {
					printf("-");
				}
					/*
					 * Only print the board numbers on the second and second last row.
					 */
				else if (row == 1 || row == PRINT_HEIGHT - 2) {
					if (column == 0 || column % 6 == 0 ||
						column == PRINT_WIDTH - 1) {
						printf("|");
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
							if (row == 1) {
								printf("  %2d ", topNumber);
								--topNumber;
							}
							else if (row == PRINT_HEIGHT - 2) {
								printf("  %2d ", bottomNumber);
								++bottomNumber;
							}
							break;
					}
				}
					/*
					 * Only print the '|', ' ', and tokens on every odd row.
					 */
				else if (row % 2 == 1) {
					if (column == 0 || column % 6 == 0 ||
						column == PRINT_WIDTH - 1) {
						printf("|");
					}
						/*
						 * Skip every 3rd spot as this might have a player token.
						 * TODO - add logic for printing from the saved state
						 */
					else if (column % 3 != 0) {
						printf(" ");
					}
					else {
						if (DEBUGGING_IO) {
							printf("x: %d y: %d", rowOffset, columnOffset);
						}
						/*currentPiece = getStartPiece(rowOffset, columnOffset);*/
						/*currentPiece = getStartPieceArray(rowOffset, columnOffset);*/
						currentPiece = getPieceFromBoardState(rowOffset,
															  columnOffset,
															  theboard);
						if (currentPiece == 0) {
							printf(" ");
						}
						else if (currentPiece == 1) {
							printf("%s%c%s", color_strings[COLOR_RED],
								   RED_TOKEN,
								   color_strings[COLOR_RESET]);

						}
						else if (currentPiece == 2) {
							printf("%s%c%s", color_strings[COLOR_WHITE],
								   WHITE_TOKEN, color_strings[COLOR_RESET]);

						}
						++columnOffset;
					}

				}
			}
			/*
			 * Decrement row offset so we have the correct row next run - reverse
			 * Reset the column offset so we have the current column next run
			 */
			if (row >= 3 && row % 2 != 0) {
				--rowOffset;
				columnOffset = 0;
			}

			printf("\n");
		}
	}
}

