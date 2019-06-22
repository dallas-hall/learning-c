/******************************************************************************
 * Student Name    :  Dallas Hall
 * RMIT Student ID :  s3461243
 * COURSE CODE     :  CPT220 / OLA00
 *
 * Startup code provided by Paul Miller for use in "Programming in C",
 * study period 2, 2019.
 *****************************************************************************/
#include "board.h"

const int DEBUGGING_BOARD = 1;

/*
 * Not sure how introducing the structures below would make it any better.
 * In my opinion the nested for loops Would be harder to read and slower
 * with the multiple table lookups.
 */
const int fiveWhiteAt13[5][2] = {
		{0, 0},
		{1, 0},
		{2, 0},
		{3, 0},
		{4, 0}
};

const int threeRedAt17[3][2] = {
		{0, 4},
		{1, 4},
		{2, 4}
};

const int fiveRedAt19[5][2] = {
		{0, 6},
		{1, 6},
		{2, 6},
		{3, 6},
		{4, 6}
};

const int twoWhiteAt24[2][2] = {
		{0, 11},
		{1, 11}
};

const int fiveRedAt12[5][2] = {
		{9,  0},
		{10, 0},
		{11, 0},
		{12, 0},
		{13, 0}
};

const int threeWhiteAt8[3][2] = {
		{11, 4},
		{12, 4},
		{13, 4}
};

const int fiveWhiteAt6[5][2] = {
		{9,  6},
		{10, 6},
		{11, 6},
		{12, 6},
		{13, 6}
};

const int twoRedAt1[2][2] = {
		{12, 11},
		{13, 11}
};

/**
 * init_board() - provide the logic to initialise the board to the same data as
 * shown in the assignment specification. Please note that a naive
 * implementation (eg: one without loops) will not get full marks. For full
 * details of the requirement of this function, please see the assignment
 * requirements
 **/
void board_init(board the_board)
{
	int row, column;

	if (DEBUGGING_BOARD) {
		printf("%s\n", "[DEBUG] board.c - Entering board_init.");
	}

	for (row = 0; row < BOARD_HEIGHT; row++) {
		for (column = 0; column < BOARD_WIDTH; column++) {
			if (DEBUGGING_BOARD) {
				printf("[DEBUG] board.c - Creating piece at row[%d]column[%d]\n",
					   row, column);
			}
			/* setStartPiece(row, column, the_board); */
			setStartPieceArray(row, column, the_board);
		}
	}
}

/**
 * You may provide your own function definitions here for this module
 **/
/*
 * Basic board printing for debugging.
 */
void printBoard(board the_board)
{
	int row, column;
	if (DEBUGGING_BOARD) {
		printf("%s\n", "[DEBUG] board.c - Entering printBoard.");
	}
	for (row = 0; row < BOARD_HEIGHT; row++) {
		for (column = 0; column < BOARD_WIDTH; column++) {
			printf("[%d][%d] %d\t", row, column, the_board[row][column]);
			if (column == BOARD_WIDTH - 1) {
				printf("\n");
			}
		}
	}
}

void printBoardReverse(board the_board)
{
	int row, column;
	if (DEBUGGING_BOARD) {
		printf("%s\n", "[DEBUG] board.c - Entering printBoardReverse.");
	}
	for (row = BOARD_HEIGHT - 1; row >= 0; row--) {
		for (column = 0; column < BOARD_WIDTH; column++) {
			if (DEBUGGING_BOARD) {
				printf("[%d][%d] %d\t", row, column, the_board[row][column]);
				if (column == BOARD_WIDTH - 1) {
					printf("\n");
				}
			}
		}
	}
}

/*
 * Pretty board printing for playing.
 */
void prettyPrintStartBoard()
{
	int row, column, topNumber, bottomNumber, rowOffset, columnOffset, currentPiece;

	if (DEBUGGING_BOARD) {
		printf("%s\n", "[DEBUG] board.c - Entering prettyPrintBoard.");
	}

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
					 * TODO - add logic for player printing token
					 */
				else if (column % 3 != 0) {
					printf(" ");
				}
				else {
					if (DEBUGGING_BOARD) {
						printf("x: %d y: %d", rowOffset, columnOffset);
					}
					currentPiece = getStartPiece(rowOffset, columnOffset);
					if (currentPiece == 0) {
						printf(" ");
					}
					else if (currentPiece == 1) {
						printf("%s%c%s", color_strings[COLOR_RED], RED_TOKEN,
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

void prettyPrintStartBoardReverse()
{
	int row, column, topNumber, bottomNumber, rowOffset, columnOffset, currentPiece;

	if (DEBUGGING_BOARD) {
		printf("%s\n", "[DEBUG] board.c - Entering prettyPrintBoard.");
	}

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
					 * TODO - add logic for player printing token
					 */
				else if (column % 3 != 0) {
					printf(" ");
				}
				else {
					if (DEBUGGING_BOARD) {
						printf("x: %d y: %d", rowOffset, columnOffset);
					}
					currentPiece = getStartPiece(rowOffset, columnOffset);
					if (currentPiece == 0) {
						printf(" ");
					}
					else if (currentPiece == 1) {
						printf("%s%c%s", color_strings[COLOR_RED], RED_TOKEN,
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

enum piece getStartPiece(int row, int column)
{
	/*
 	 * TODO - Move this into an array.
 	 */

	/* White's 5 pieces at 13 */
	if (row == 0 && column == 0) {
		return P_WHITE;
	}
	else if (row == 1 && column == 0) {
		return P_WHITE;
	}
	else if (row == 2 && column == 0) {
		return P_WHITE;
	}
	else if (row == 3 && column == 0) {
		return P_WHITE;
	}
	else if (row == 4 && column == 0) {
		return P_WHITE;
	}
		/* Reds's 3 pieces at 8 */
	else if (row == 0 && column == 4) {
		return P_RED;
	}
	else if (row == 1 && column == 4) {
		return P_RED;
	}
	else if (row == 2 && column == 4) {
		return P_RED;
	}
		/* Reds's 5 pieces at 6 */
	else if (row == 0 && column == 6) {
		return P_RED;
	}
	else if (row == 1 && column == 6) {
		return P_RED;
	}
	else if (row == 2 && column == 6) {
		return P_RED;
	}
	else if (row == 3 && column == 6) {
		return P_RED;
	}
	else if (row == 4 && column == 6) {
		return P_RED;
	}
		/* White's 2 pieces at 24 */
	else if (row == 0 && column == 11) {
		return P_WHITE;
	}
	else if (row == 1 && column == 11) {
		return P_WHITE;
	}
		/* Reds's 5 pieces at 12 */
	else if (row == 9 && column == 0) {

		return P_RED;
	}
	else if (row == 10 && column == 0) {
		return P_RED;
	}
	else if (row == 11 && column == 0) {
		return P_RED;
	}
	else if (row == 12 && column == 0) {
		return P_RED;
	}
	else if (row == 13 && column == 0) {
		return P_RED;
	}
		/* White's 3 pieces at 8 */
	else if (row == 11 && column == 4) {
		return P_WHITE;
	}
	else if (row == 12 && column == 4) {
		return P_WHITE;
	}
	else if (row == 13 && column == 4) {
		return P_WHITE;
	}
/* White's 5 pieces at 6 */
	else if (row == 9 && column == 6) {
		return P_WHITE;
	}
	else if (row == 10 && column == 6) {
		return P_WHITE;
	}
	else if (row == 11 && column == 6) {
		return P_WHITE;
	}
	else if (row == 12 && column == 6) {
		return P_WHITE;
	}
	else if (row == 13 && column == 6) {
		return P_WHITE;
	}
/* Reds's 2 pieces at 24 */
	else if (row == 12 && column == 11) {
		return P_RED;
	}
	else if (row == 13 && column == 11) {
		return P_RED;
	}
/* Everything else is blank */
	else {
		return P_EMPTY;
	}
}

enum piece getStartPieceArray(int row, int column)
{
	return P_EMPTY;
}

void setStartPiece(int row, int column, board the_board)
{
	/*
 	 * TODO - Move this into an array.
 	 */

	/* White's 5 pieces at 13 */
	if (row == 0 && column == 0) {
		the_board[row][column] = P_WHITE;
	}
	else if (row == 1 && column == 0) {
		the_board[row][column] = P_WHITE;
	}
	else if (row == 2 && column == 0) {
		the_board[row][column] = P_WHITE;
	}
	else if (row == 3 && column == 0) {
		the_board[row][column] = P_WHITE;
	}
	else if (row == 4 && column == 0) {
		the_board[row][column] = P_WHITE;
	}
		/* Reds's 3 pieces at 8 */
	else if (row == 0 && column == 4) {
		the_board[row][column] = P_RED;
	}
	else if (row == 1 && column == 4) {
		the_board[row][column] = P_RED;
	}
	else if (row == 2 && column == 4) {
		the_board[row][column] = P_RED;
	}
		/* Reds's 5 pieces at 6 */
	else if (row == 0 && column == 6) {
		the_board[row][column] = P_RED;
	}
	else if (row == 1 && column == 6) {
		the_board[row][column] = P_RED;
	}
	else if (row == 2 && column == 6) {
		the_board[row][column] = P_RED;
	}
	else if (row == 3 && column == 6) {
		the_board[row][column] = P_RED;
	}
	else if (row == 4 && column == 6) {
		the_board[row][column] = P_RED;
	}
		/* White's 2 pieces at 24 */
	else if (row == 0 && column == 11) {
		the_board[row][column] = P_WHITE;
	}
	else if (row == 1 && column == 11) {
		the_board[row][column] = P_WHITE;
	}
		/* Reds's 5 pieces at 12 */
	else if (row == 9 && column == 0) {
		the_board[row][column] = P_RED;
	}
	else if (row == 10 && column == 0) {
		the_board[row][column] = P_RED;
	}
	else if (row == 11 && column == 0) {
		the_board[row][column] = P_RED;
	}
	else if (row == 12 && column == 0) {
		the_board[row][column] = P_RED;
	}
	else if (row == 13 && column == 0) {
		the_board[row][column] = P_RED;
	}
		/* White's 3 pieces at 8 */
	else if (row == 11 && column == 4) {
		the_board[row][column] = P_WHITE;
	}
	else if (row == 12 && column == 4) {
		the_board[row][column] = P_WHITE;
	}
	else if (row == 13 && column == 4) {
		the_board[row][column] = P_WHITE;
	}
/* White's 5 pieces at 6 */
	else if (row == 9 && column == 6) {
		the_board[row][column] = P_WHITE;
	}
	else if (row == 10 && column == 6) {
		the_board[row][column] = P_WHITE;
	}
	else if (row == 11 && column == 6) {
		the_board[row][column] = P_WHITE;
	}
	else if (row == 12 && column == 6) {
		the_board[row][column] = P_WHITE;
	}
	else if (row == 13 && column == 6) {
		the_board[row][column] = P_WHITE;
	}
/* Reds's 2 pieces at 24 */
	else if (row == 12 && column == 11) {
		the_board[row][column] = P_RED;
	}
	else if (row == 13 && column == 11) {
		the_board[row][column] = P_RED;
	}
/* Everything else is blank */
	else {
		the_board[row][column] = P_EMPTY;
	}

}

void setStartPieceArray(int row, int column, board the_board)
{
	int i, x, y;
	if (DEBUGGING_BOARD) {
		printf("%s\n", "[DEBUG] board.c - Entering getStartPieceArray.");
	}

	/*
	 * Search the arrays with 5 coordinates
	 * The arrays are organised in starting position order.
	 *
	 * Top half of the board
	 */
	for (i = 0; i < 5; i++) {
		/*
		 * Get the column and row
		 */
		x = fiveWhiteAt13[i][0];
		y = fiveWhiteAt13[i][1];

		if (DEBUGGING_BOARD) {
			printf("x is %d. y is %d. row is %d. column is %d.\n", x, y,
				   row, column);
		}
		if (x == row && y == column) {
			the_board[row][column] = P_WHITE;
			/*
			 * return is used so we don't needlessly search after find the
			 * result.
			 */
			return;
		}
	}

	for (i = 0; i < 3; i++) {
		/*
		 * Get the column and row
		 */
		x = threeRedAt17[i][0];
		y = threeRedAt17[i][1];

		if (DEBUGGING_BOARD) {
			printf("x is %d. y is %d. row is %d. column is %d.\n", x, y,
				   row, column);
		}
		if (x == row && y == column) {
			the_board[row][column] = P_RED;
			return;
		}
	}

	for (i = 0; i < 5; i++) {
		/*
		 * Get the column and row
		 */
		x = fiveRedAt19[i][0];
		y = fiveRedAt19[i][1];

		if (DEBUGGING_BOARD) {
			printf("x is %d. y is %d. row is %d. column is %d.\n", x, y,
				   row, column);
		}
		if (x == row && y == column) {
			the_board[row][column] = P_RED;
			return;
		}
	}

	for (i = 0; i < 2; i++) {
		/*
		 * Get the column and row
		 */
		x = twoWhiteAt24[i][0];
		y = twoWhiteAt24[i][1];

		if (DEBUGGING_BOARD) {
			printf("x is %d. y is %d. row is %d. column is %d.\n", x, y,
				   row, column);
		}
		if (x == row && y == column) {
			the_board[row][column] = P_WHITE;
			return;
		}
	}

	/*
	 * Bottom half of the board
	 */

	for (i = 0; i < 5; i++) {
		/*
		 * Get the column and row
		 */
		x = fiveRedAt12[i][0];
		y = fiveRedAt12[i][1];

		if (DEBUGGING_BOARD) {
			printf("x is %d. y is %d. row is %d. column is %d.\n", x, y,
				   row, column);
		}
		if (x == row && y == column) {
			the_board[row][column] = P_RED;
			return;
		}
	}

	for (i = 0; i < 3; i++) {
		/*
		 * Get the column and row
		 */
		x = threeWhiteAt8[i][0];
		y = threeWhiteAt8[i][1];

		if (DEBUGGING_BOARD) {
			printf("x is %d. y is %d. row is %d. column is %d.\n", x, y,
				   row, column);
		}
		if (x == row && y == column) {
			the_board[row][column] = P_WHITE;
			return;
		}

	}

	for (i = 0; i < 5; i++) {

		/*
		 * Get the column and row
		 */
		x = fiveWhiteAt6[i][0];
		y = fiveWhiteAt6[i][1];

		if (DEBUGGING_BOARD) {
			printf("x is %d. y is %d. row is %d. column is %d.\n", x, y,
				   row, column);
		}
		if (x == row && y == column) {
			the_board[row][column] = P_WHITE;
			return;
		}

	}

	for (i = 0; i < 2; i++) {
		/*
 		 * Get the column and row
 		 */
		x = twoRedAt1[i][0];
		y = twoRedAt1[i][1];

		if (DEBUGGING_BOARD) {
			printf("x is %d. y is %d. row is %d. column is %d.\n", x, y,
				   row, column);
		}
		if (x == row && y == column) {
			the_board[row][column] = P_RED;
			return;
		}
	}

	the_board[row][column] = P_EMPTY;
}