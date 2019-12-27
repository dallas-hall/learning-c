#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

// Standard size is 8 x 8
#define BOARD_SIZE 8
// 64 board locations
#define MAX_MOVES BOARD_SIZE * BOARD_SIZE
/*
 * The knight has a maximum of 8 possible moves.
 * L shaped moves, 2 in one direction and then over 1 in a perpendicular direction.
 */
#define POSSIBLE_MOVES 8
#define MIN_LEGAL_MOVE 0
#define MAX_LEGAL_MOVE 7

void print2dArray(size_t m, size_t n, int a[][n]);

void setHorizontalMovements(int a[]);

void setVerticalMovements(int a[]);

void setAccessibilityMatrix(int accessibilityMatrix[][BOARD_SIZE]);

void print1dArray(size_t m, int a[]);

bool allMovesAttempted(size_t m, const bool a[]);

void resetAttemptedMoves(size_t m, bool a[]);

void
knightsTourPrn(size_t boardSize, int board[][boardSize], const int verticalMovements[], const int horizontalMovements[],
			   int startRow, int startColumn);

void knightsTourAccessibilityMatrix(size_t boardSize, int board[][boardSize], const int verticalMovements[],
									const int horizontalMovements[], int startRow, int startColumn,
									int accessibilityMatrix[][boardSize]);

int main(void)
{
	puts("# Euler's Knight's Tour Problem");
	puts("Can a knight on a chessboard tour every part of the chessboard, once and only once?");

	puts("## Setup");
	/*
	 * An accessibility matrix is a 2D array that has numerical labels attached to it.
	 * These labels indicated how many possible moves can be done by a knight from each given square.
	 * The algorithm should favour going for squares that have the lowest accessibility label, as they are harder to get to.
	 * https://en.wikipedia.org/wiki/Knight%27s_graph
	 */
	int accessibilityMatrix[BOARD_SIZE][BOARD_SIZE];
	memset(accessibilityMatrix, 0, sizeof(accessibilityMatrix));
	setAccessibilityMatrix(accessibilityMatrix);
	puts("Knight your graph accessibility matrix.");
	print2dArray(BOARD_SIZE, BOARD_SIZE, accessibilityMatrix);

	// Initialise to 0. The move number will be added to the board when the knight lands there.
	int chessBoard[BOARD_SIZE][BOARD_SIZE];
	memset(chessBoard, -1, sizeof(chessBoard));
	puts("Chess board starting state.");
	print2dArray(BOARD_SIZE, BOARD_SIZE, chessBoard);

	/*
	 * Not using cartesian x y coordinates. As our 0,0 is the top left, and not in the middle.
	 * Negative numbers in horizontal mean left and positive means right.
	 * Negative numbers in vertical mean up and positive means down.
	 * Combining the values of horizontalMovement[n] and verticalMovement[n] tells us how to move the knight.
	 */
	puts("Possible horizontal and vertical moves. Combine horizontalMovement[n] and verticalMovement[n] to make a possible move.");
	int horizontalMovements[POSSIBLE_MOVES];
	setHorizontalMovements(horizontalMovements);
	print1dArray(POSSIBLE_MOVES, horizontalMovements);

	int verticalMovements[POSSIBLE_MOVES];
	setVerticalMovements(verticalMovements);
	print1dArray(POSSIBLE_MOVES, verticalMovements);

	puts("## Running");
	/*
	 * This is the position of the knight, based on 0,0 being top left of the 8x8 board.
	 * The book positions the K at row 3, column 4
	 * The starting position will be 1.
	 */
	int currentRow = 3;
	int currentColumn = 4;
	puts("Naive PRN logic.");
	knightsTourPrn(BOARD_SIZE, chessBoard, verticalMovements,
				   horizontalMovements, currentRow, currentColumn);

	puts("Chess board final state.");
	print2dArray(BOARD_SIZE, BOARD_SIZE, chessBoard);

	puts("Knights tour graph logic.");
	// 0 out the array.
	memset(chessBoard, -1, sizeof(chessBoard));
	knightsTourAccessibilityMatrix(BOARD_SIZE, chessBoard, verticalMovements, horizontalMovements, currentRow,
								   currentColumn, accessibilityMatrix);

	puts("Chess board final state.");
	print2dArray(BOARD_SIZE, BOARD_SIZE, chessBoard);

	return EXIT_SUCCESS;
}

void print2dArray(size_t m, size_t n, int a[][n])
{
	size_t lastLine = m - 1;
	printf("%s", "[\n");
	for (size_t i = 0; i < m; i++) {
		printf("%s", "\t[");
		for (size_t j = 0; j < n; j++) {
			printf("%2d, ", a[i][j]);
		}
		if (i != lastLine) {
			printf("%s", "\b\b],\n");
		}
		else {
			printf("%s", "\b\b]\n");
		}
	}
	printf("%s", "]\n");
}

void setHorizontalMovements(int a[])
{
	a[0] = 2; // Move 2 to the right
	a[1] = 1; // Move 1 to the right
	a[2] = -1; // Move 1 to the left
	a[3] = -2; // Move 2 to the left
	a[4] = -2; // Move 2 to the left
	a[5] = -1; // Move 1 to the left
	a[6] = 1; // Move 1 to the right
	a[7] = 2; // Move 2 to the right
}

void setVerticalMovements(int a[])
{
	a[0] = -1; // Move up 1
	a[1] = -2; // Move up 2
	a[2] = -2; // Move up 2
	a[3] = -1; // Move up 1
	a[4] = 1; // Move down 1
	a[5] = 2; // Move down 2
	a[6] = 2; // Move down 2
	a[7] = 1; // Move down 1
}

void print1dArray(size_t m, int a[])
{
	printf("[");
	for (size_t i = 0; i < m; i++) {
		printf("%d, ", a[i]);
	}
	printf("%s", "\b\b]\n");
}

void setAccessibilityMatrix(int accessibilityMatrix[][BOARD_SIZE])
{
	for (size_t i = 0; i < BOARD_SIZE; i++) {
		switch (i) {
			case 0:
			case 7:
				accessibilityMatrix[i][0] = 2;
				accessibilityMatrix[i][1] = 3;
				accessibilityMatrix[i][2] = 4;
				accessibilityMatrix[i][3] = 4;
				accessibilityMatrix[i][4] = 4;
				accessibilityMatrix[i][5] = 4;
				accessibilityMatrix[i][6] = 3;
				accessibilityMatrix[i][7] = 2;
				break;
			case 1:
			case 6:
				accessibilityMatrix[i][0] = 3;
				accessibilityMatrix[i][1] = 4;
				accessibilityMatrix[i][2] = 6;
				accessibilityMatrix[i][3] = 6;
				accessibilityMatrix[i][4] = 6;
				accessibilityMatrix[i][5] = 6;
				accessibilityMatrix[i][6] = 4;
				accessibilityMatrix[i][7] = 3;
				break;
			case 2:
			case 3:
			case 4:
			case 5:
				accessibilityMatrix[i][0] = 4;
				accessibilityMatrix[i][1] = 6;
				accessibilityMatrix[i][2] = 8;
				accessibilityMatrix[i][3] = 8;
				accessibilityMatrix[i][4] = 8;
				accessibilityMatrix[i][5] = 8;
				accessibilityMatrix[i][6] = 6;
				accessibilityMatrix[i][7] = 4;
				break;
		}
	}
}

bool allMovesAttempted(size_t m, bool const a[])
{
	for (size_t i = 0; i < m; i++) {
		if (a[i] != true) {
			return false;
		}
	}
	return true;
}

void resetAttemptedMoves(size_t m, bool a[])
{
	for (size_t i = 0; i < m; i++) {
		a[i] = false;
	}
}

void
knightsTourPrn(size_t boardSize, int board[][boardSize], const int verticalMovements[], const int horizontalMovements[],
			   int startRow, int startColumn)
{
	// Set the start location
	board[startRow][startColumn] = 0;

	// Various variables needed
	int currentRow = startRow;
	int currentColumn = startColumn;
	bool movesAttempted[POSSIBLE_MOVES] = {false};
	bool moveStaysOnBoard = false;
	bool moveHasntBeenDoneYet = false;
	bool validMove = false;
	bool noMorePossibleMoves = false;
	int tempRow;
	int tempColumn;
	int prn = 0;

	for (size_t moveCounter = 1; moveCounter < MAX_MOVES; moveCounter++) {
		while (!validMove) {
			// Reset the variables, needed for the continue statements
			moveHasntBeenDoneYet = false;
			moveStaysOnBoard = false;

			// Copy the current position to use for working out valid moves
			tempRow = currentRow;
			tempColumn = currentColumn;

			// Maximum possible moves is 8, so that is our attempt limit.
			if (allMovesAttempted(POSSIBLE_MOVES, movesAttempted)) {
				noMorePossibleMoves = true;
				break;
			}

			/*
			 * Choose from one of the 8 possible moves.
			 * Must test that every move
			 * a) doesn't land off of the board (outside of 0-7 for x,y)
			 * b) the knight hasn't been there already. (move number is not 0)
			 * Use currentRow += verticalMovement[moveNumber] and currentColumn += horizontalMovement[moveNumber]
			 */
			prn = rand() % 8;
			// Check that we haven't already tried that move
			if (movesAttempted[prn] == true) {
				continue;
			}
			movesAttempted[prn] = true;
			tempRow += verticalMovements[prn];
			tempColumn += horizontalMovements[prn];

			// Test if the move doesn't go off the board
			if ((tempRow >= MIN_LEGAL_MOVE && tempRow <= MAX_LEGAL_MOVE) &&
				(tempColumn >= MIN_LEGAL_MOVE && tempColumn <= MAX_LEGAL_MOVE)) {
				moveStaysOnBoard = true;
			}
			else {
				continue;
			}

			// Test that moved hasn't been done yet
			if (board[tempRow][tempColumn] == -1) {
				moveHasntBeenDoneYet = true;
			}
			else {
				continue;
			}

			if (moveStaysOnBoard && moveHasntBeenDoneYet) {
				validMove = true;
			}
		}
		if (noMorePossibleMoves) {
			break;
		}

		// Make the move
		currentRow += verticalMovements[prn];
		currentColumn += horizontalMovements[prn];
		board[currentRow][currentColumn] = moveCounter;

		// Reset variables
		moveHasntBeenDoneYet = false;
		moveStaysOnBoard = false;
		validMove = false;
		resetAttemptedMoves(POSSIBLE_MOVES, movesAttempted);
	}
}

void knightsTourAccessibilityMatrix(size_t boardSize, int board[][boardSize], const int verticalMovements[],
									const int horizontalMovements[], int startRow, int startColumn,
									int accessibilityMatrix[][boardSize])
{
	// Set the start position
	board[startRow][startColumn] = 0;

	// Various variables needed
	int currentRow = startRow;
	int currentColumn = startColumn;
	bool movesAttempted[POSSIBLE_MOVES] = {false};
	bool moveStaysOnBoard = false;
	bool moveHasntBeenDoneYet = false;
	bool moveFound = false;
	int tempRow;
	int tempColumn;
	int currentBestRow;
	int currentBestColumn;
	int currentBestAccessibilityValue = INT_MAX;

	// Start at 1 as we aren't including the starting position
	for (size_t moveCounter = 1; moveCounter < MAX_MOVES; moveCounter++) {
		currentBestRow = currentRow;
		currentBestColumn = currentColumn;
		/*
		 * Examine all possible moves and pick the one with the lowest accessibility score. Ties not dealt with.
		 * Must test that every move
		 * a) doesn't land off of the board (outside of 0-7 for x,y)
		 * b) the knight hasn't been there already. (move number is not 0)
		 * c) Use the lowest accessibilty score.
		 * Use currentRow += verticalMovement[moveNumber] and currentColumn += horizontalMovement[moveNumber]
		 */
		for (size_t moveNumber = 0; moveNumber < POSSIBLE_MOVES; moveNumber++) {
			// Reset the variables, needed for the continue statements
			moveHasntBeenDoneYet = false;
			moveStaysOnBoard = false;

			// Copy the current position to use for working out valid moves
			tempRow = currentRow;
			tempColumn = currentColumn;

			// Flag the current move number as tested
			movesAttempted[moveNumber] = true;

			// Get the current move number and do the checks
			tempRow += verticalMovements[moveNumber];
			tempColumn += horizontalMovements[moveNumber];

			// Test if the move doesn't go off the board
			if ((tempRow >= MIN_LEGAL_MOVE && tempRow <= MAX_LEGAL_MOVE) &&
				(tempColumn >= MIN_LEGAL_MOVE && tempColumn <= MAX_LEGAL_MOVE)) {
				moveStaysOnBoard = true;
			}
			else {
				continue;
			}

			// Test that moved hasn't been done yet
			if (board[tempRow][tempColumn] == -1) {
				moveHasntBeenDoneYet = true;
			}
			else {
				continue;
			}

			if (moveStaysOnBoard && moveHasntBeenDoneYet) {
				int currentMoveAccessibilityValue = accessibilityMatrix[tempRow][tempColumn];
				if (currentMoveAccessibilityValue < currentBestAccessibilityValue) {
					// Reset back to the move numbers start row
					currentBestRow = currentRow;
					currentBestColumn = currentColumn;

					// Store the best accessibility details
					moveFound = true;
					currentBestAccessibilityValue = currentMoveAccessibilityValue;
					currentBestRow += verticalMovements[moveNumber];
					currentBestColumn += horizontalMovements[moveNumber];
				}
			}
		}
		if (moveFound) {
			// Make the best move after testing all possible moves
			currentRow = currentBestRow;
			currentColumn = currentBestColumn;
			board[currentRow][currentColumn] = moveCounter;

			// Reset variables
			currentBestAccessibilityValue = INT_MAX;
			resetAttemptedMoves(POSSIBLE_MOVES, movesAttempted);
			moveFound = false;

//			printf("moveCounter %ld\n", moveCounter);
//			print2dArray(boardSize, boardSize, board);
		}
		else {
			break;
		}
	}
}

