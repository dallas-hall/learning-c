/******************************************************************************
 * Student Name    :  Dallas Hall
 * RMIT Student ID :  s3461243
 * COURSE CODE     :  CPT220 / OLA00
 *
 * Startup code provided by Paul Miller for use in "Programming in C",
 * study period 2, 2019.
 *****************************************************************************/
#include "board.h"

const int DEBUGGING_BOARD = 0;

/*
 * 2d array holding the starting position coordinates.
 * The arrays are in order as they would be seen on the board according to
 * the spec.
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
		normal_print("%s\n", "[DEBUG] board.c - Entering board_init.");
	}

	for (row = 0; row < BOARD_HEIGHT; row++) {
		for (column = 0; column < BOARD_WIDTH; column++) {
			if (DEBUGGING_BOARD) {
				normal_print(
						"[DEBUG] board.c - Creating piece at row[%d]column[%d]\n",
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
enum piece getStartPiece(int row, int column)
{
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
	int i, x, y;
	if (DEBUGGING_BOARD) {
		normal_print("%s\n", "[DEBUG] board.c - Entering getStartPieceArray.");
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
			normal_print("x is %d. y is %d. row is %d. column is %d.\n", x, y,
						 row, column);
		}
		if (x == row && y == column) {
			return P_WHITE;
		}
	}

	for (i = 0; i < 3; i++) {
		/*
		 * Get the column and row
		 */
		x = threeRedAt17[i][0];
		y = threeRedAt17[i][1];

		if (DEBUGGING_BOARD) {
			normal_print("x is %d. y is %d. row is %d. column is %d.\n", x, y,
						 row, column);
		}
		if (x == row && y == column) {
			return P_RED;
		}
	}

	for (i = 0; i < 5; i++) {
		/*
		 * Get the column and row
		 */
		x = fiveRedAt19[i][0];
		y = fiveRedAt19[i][1];

		if (DEBUGGING_BOARD) {
			normal_print("x is %d. y is %d. row is %d. column is %d.\n", x, y,
						 row, column);
		}
		if (x == row && y == column) {
			return P_RED;
		}
	}

	for (i = 0; i < 2; i++) {
		/*
		 * Get the column and row
		 */
		x = twoWhiteAt24[i][0];
		y = twoWhiteAt24[i][1];

		if (DEBUGGING_BOARD) {
			normal_print("x is %d. y is %d. row is %d. column is %d.\n", x, y,
						 row, column);
		}
		if (x == row && y == column) {
			return P_WHITE;
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
			normal_print("x is %d. y is %d. row is %d. column is %d.\n", x, y,
						 row, column);
		}
		if (x == row && y == column) {
			return P_RED;
		}
	}

	for (i = 0; i < 3; i++) {
		/*
		 * Get the column and row
		 */
		x = threeWhiteAt8[i][0];
		y = threeWhiteAt8[i][1];

		if (DEBUGGING_BOARD) {
			normal_print("x is %d. y is %d. row is %d. column is %d.\n", x, y,
						 row, column);
		}
		if (x == row && y == column) {
			return P_WHITE;
		}

	}

	for (i = 0; i < 5; i++) {

		/*
		 * Get the column and row
		 */
		x = fiveWhiteAt6[i][0];
		y = fiveWhiteAt6[i][1];

		if (DEBUGGING_BOARD) {
			normal_print("x is %d. y is %d. row is %d. column is %d.\n", x, y,
						 row, column);
		}
		if (x == row && y == column) {
			return P_WHITE;
		}

	}

	for (i = 0; i < 2; i++) {
		/*
 		 * Get the column and row
 		 */
		x = twoRedAt1[i][0];
		y = twoRedAt1[i][1];

		if (DEBUGGING_BOARD) {
			normal_print("x is %d. y is %d. row is %d. column is %d.\n", x, y,
						 row, column);
		}
		if (x == row && y == column) {
			return P_RED;
		}
	}

	return P_EMPTY;
}

void setStartPiece(int row, int column, board the_board)
{
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

/*
 * I realised after writing all of the above that I could just replace it with
 * this guy and the guy below. Thanks guys!
 */
void setStartPieceArray(int row, int column, board the_board)
{
	int i, x, y;
	if (DEBUGGING_BOARD) {
		normal_print("%s\n", "[DEBUG] board.c - Entering getStartPieceArray.");
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
			normal_print("x is %d. y is %d. row is %d. column is %d.\n", x, y,
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
			normal_print("x is %d. y is %d. row is %d. column is %d.\n", x, y,
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
			normal_print("x is %d. y is %d. row is %d. column is %d.\n", x, y,
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
			normal_print("x is %d. y is %d. row is %d. column is %d.\n", x, y,
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
			normal_print("x is %d. y is %d. row is %d. column is %d.\n", x, y,
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
			normal_print("x is %d. y is %d. row is %d. column is %d.\n", x, y,
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
			normal_print("x is %d. y is %d. row is %d. column is %d.\n", x, y,
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
			normal_print("x is %d. y is %d. row is %d. column is %d.\n", x, y,
						 row, column);
		}
		if (x == row && y == column) {
			the_board[row][column] = P_RED;
			return;
		}
	}

	the_board[row][column] = P_EMPTY;
}

enum piece getPieceFromBoardState(int x, int y, board the_board)
{
	return the_board[x][y];
}