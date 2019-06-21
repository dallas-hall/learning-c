/******************************************************************************
 * Student Name    :  Dallas Hall
 * RMIT Student ID :  s3461243
 * COURSE CODE     :  CPT220 / OLA00
 *
 * Startup code provided by Paul Miller for use in "Programming in C",
 * study period 2, 2019.
 *****************************************************************************/
#include "board.h"

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

	const int white5At13[5][2] = {
			{0, 0},
			{1, 0},
			{2, 0},
			{3, 0},
			{4, 0}
	};

	const int white2At24[2][2] = {
			{0, 11},
			{1, 11}
	};

	const int white2At8[3][2] = {
			{11, 4},
			{12, 4},
			{13, 4}
	};

	const int white5At6[5][2] = {
			{9,  6},
			{10, 6},
			{11, 6},
			{12, 6},
			{13, 6}
	};

	const int red3At17[3][2] = {
			{0, 4},
			{1, 4},
			{2, 4}
	};

	const int red5At19[5][2] = {
			{0, 6},
			{1, 6},
			{2, 6},
			{3, 6},
			{4, 6}
	};

	const int red5At12[5][2] = {
			{9,  0},
			{10, 0},
			{11, 0},
			{12, 0},
			{13, 0}
	};

	const int red2At1[2][2] = {
			{12, 11},
			{13, 11}
	};


	if (DEBUGGING) {
		printf("%s\n", "[DEBUG] board.c - Entering board_init.");
	}

	for (
			row = 0;
			row < BOARD_HEIGHT; row++) {
		for (
				column = 0;
				column < BOARD_WIDTH; column++) {
			if (DEBUGGING) {
				printf("[DEBUG] board.c - Creating piece at row[%d]column[%d]\n",
					   row, column);
/*
 * TODO - Move this into an array.
 */

/*
 * White's 5 pieces at 13
 */
				if (row == 0 && column == 0) {
					the_board[row][column] =
							P_WHITE;
				} else if (row == 1 && column == 0) {
					the_board[row][column] =
							P_WHITE;
				} else if (row == 2 && column == 0) {
					the_board[row][column] =
							P_WHITE;
				} else if (row == 3 && column == 0) {
					the_board[row][column] =
							P_WHITE;
				} else if (row == 4 && column == 0) {
					the_board[row][column] =
							P_WHITE;
				}
/*
 * Reds's 3 pieces at 8
 */
				else if (row == 0 && column == 4) {
					the_board[row][column] =
							P_RED;
				} else if (row == 1 && column == 4) {
					the_board[row][column] =
							P_RED;
				} else if (row == 2 && column == 4) {
					the_board[row][column] =
							P_RED;
				}
/*
 * Reds's 5 pieces at 6
 */
				else if (row == 0 && column == 6) {
					the_board[row][column] =
							P_RED;
				} else if (row == 1 && column == 6) {
					the_board[row][column] =
							P_RED;
				} else if (row == 2 && column == 6) {
					the_board[row][column] =
							P_RED;
				} else if (row == 3 && column == 6) {
					the_board[row][column] =
							P_RED;
				} else if (row == 4 && column == 6) {
					the_board[row][column] =
							P_RED;
				}
/*
 * White's 2 pieces at 24
 */
				else if (row == 0 && column == 11) {
					the_board[row][column] =
							P_WHITE;
				} else if (row == 1 && column == 11) {
					the_board[row][column] =
							P_WHITE;
				}
/*
 * Reds's 5 pieces at 12
 */
				else if (row == 9 && column == 0) {
					the_board[row][column] =
							P_RED;
				} else if (row == 10 && column == 0) {
					the_board[row][column] =
							P_RED;
				} else if (row == 11 && column == 0) {
					the_board[row][column] =
							P_RED;
				} else if (row == 12 && column == 0) {
					the_board[row][column] =
							P_RED;
				} else if (row == 13 && column == 0) {
					the_board[row][column] =
							P_RED;
				}
/*
 * White's 3 pieces at 8
 */
				else if (row == 11 && column == 4) {
					the_board[row][column] =
							P_WHITE;
				} else if (row == 12 && column == 4) {
					the_board[row][column] =
							P_WHITE;
				} else if (row == 13 && column == 4) {
					the_board[row][column] =
							P_WHITE;
				}
/*
 * White's 5 pieces at 6
 */
				else if (row == 9 && column == 6) {
					the_board[row][column] =
							P_WHITE;
				} else if (row == 10 && column == 6) {
					the_board[row][column] =
							P_WHITE;
				} else if (row == 11 && column == 6) {
					the_board[row][column] =
							P_WHITE;
				} else if (row == 12 && column == 6) {
					the_board[row][column] =
							P_WHITE;
				} else if (row == 13 && column == 6) {
					the_board[row][column] =
							P_WHITE;
				}
/*
 * Reds's 2 pieces at 24
 */
				else if (row == 12 && column == 11) {
					the_board[row][column] =
							P_RED;
				} else if (row == 13 && column == 11) {
					the_board[row][column] =
							P_RED;
				}
/*
 * Everything else is blank
 */
				else {
					the_board[row][column] =
							P_EMPTY;
				}
			}
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
	if (DEBUGGING) {
		printf("%s\n", "[DEBUG] board.c - Entering printBoard.");
	}
	for (row = 0; row < BOARD_HEIGHT; row++) {
		for (column = 0; column < BOARD_WIDTH; column++) {
			if (DEBUGGING) {
				printf("[%d][%d] %d\t", row, column, the_board[row][column]);
				if (column == BOARD_WIDTH - 1) {
					printf("\n");
				}
			}
		}
	}
}

void printBoardReverse(board the_board)
{
	int row, column;
	if (DEBUGGING) {
		printf("%s\n", "[DEBUG] board.c - Entering printBoardReverse.");
	}
	for (row = BOARD_HEIGHT - 1; row >= 0; row--) {
		for (column = 0; column < BOARD_WIDTH; column++) {
			if (DEBUGGING) {
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
void prettyPrintBoard(board the_board)
{
	int row, column, topNumber, bottomNumber;

	if (DEBUGGING) {
		printf("%s\n", "[DEBUG] board.c - Entering prettyPrintBoard.");
	}

	/*
	 * These need to be decremented
	 */
	topNumber = 12;
	bottomNumber = 13;
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
						} else if (row == PRINT_HEIGHT - 2) {
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
				else if (column % 3 == 0) {
					printf("*");
				} else {
					printf(" ");
				}
			}
		}
		printf("\n");
	}
}

void prettyPrintBoardReverse(board the_board)
{
	/*
	 * TODO reverse pretty print above
	 */
}

