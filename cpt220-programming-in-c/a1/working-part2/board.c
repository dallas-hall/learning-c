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
 * !!! THE CODE BELOW IS NOT USED, REPLACED WITH SOLUTION CODE. !!!
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

/*
 * The code below was taken from the sample as I lost marks from my previous
 * code due to hard coding.
 */
/**
 * iterate from the top and botton, filling in the values according to the
 * arrays and values passed in.
 **/
static void fill_column(board the_board, int colno, int token_count,
						enum piece top_piece, enum piece bottom_piece)
{
	int count;
	for (count = 0; count < token_count; ++count) {
		the_board[count][colno] = top_piece;
	}
	for (count = BOARD_HEIGHT - 1; count > BOARD_HEIGHT - (token_count + 1);
			--count) {
		the_board[count][colno] = bottom_piece;
	}
}

/**
 * init_board() - provide the logic to initialise the board to the same data as
 * shown in the assignment specification. Please note that a naive
 * implementation (eg: one without loops) will not get full marks. For full
 * details of the requirement of this function, please see the assignment
 * requirements
 **/
void board_init(board the_board)
{
	/* counter across the columns */
	int xcount;
	/* the number of tokens in each column */
	int token_counts[] = {5, 0, 0, 0, 3, 0, 5, 0, 0, 0, 0, 2};
	/* colour at the top of the column */
	enum piece colors_top[] = {P_WHITE, P_EMPTY, P_EMPTY, P_EMPTY,
							   P_RED, P_EMPTY, P_RED, P_EMPTY,
							   P_EMPTY, P_EMPTY, P_EMPTY, P_WHITE,};
	/* colour at the bottom of the column */
	enum piece colors_bottom[] = {P_RED, P_EMPTY, P_EMPTY, P_EMPTY,
								  P_WHITE, P_EMPTY, P_WHITE, P_EMPTY,
								  P_EMPTY, P_EMPTY, P_EMPTY, P_RED,};
	/* zero out the array */
	memset(the_board, 0, BOARD_WIDTH * BOARD_HEIGHT * sizeof(enum piece));

	/* iterate over the columns, filling them with the spcecified number
	 * and colour of tokens specified in our predeclared arrays */
	for (xcount = 0; xcount < BOARD_WIDTH; ++xcount) {
		fill_column(the_board, xcount, token_counts[xcount],
					colors_top[xcount], colors_bottom[xcount]);
	}
}

/*
 * !!! THE CODE BELOW IS NOT USED, REPLACED WITH SOLUTION CODE. !!!
 * My old code is below. I replaced this with the solution sample as I lost
 * marks due to hard coding.
 */
/**
 * init_board() - provide the logic to initialise the board to the same data as
 * shown in the assignment specification. Please note that a naive
 * implementation (eg: one without loops) will not get full marks. For full
 * details of the requirement of this function, please see the assignment
 * requirements
 **/
void board_init_my_old_code(board the_board)
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

void copyBoardState(board originalBoard, board replicaBoard)
{
	int i, j;

	for(i = 0; i < BOARD_HEIGHT; i++) {
		for(j = 0; j < BOARD_WIDTH; j++) {
			replicaBoard[i][j]= originalBoard[i][j];
		}
	}
}