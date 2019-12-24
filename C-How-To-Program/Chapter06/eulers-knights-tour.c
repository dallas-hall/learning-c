#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

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
void setPossibleKnightMoves(size_t totalPossibleMoves, size_t xyMoves, int possibleMoves[][xyMoves]);
void print1dArray(size_t m, int a[]);
bool allMovesAttempted(size_t m, bool a[]);
void resetAttemptedMoves(size_t m, bool a[]);

int main(void)
{
	puts("# Euler's Knight's Tour Problem");
	puts("Can a knight on a chessboard tour every part of the chessboard, once and only once?");

	puts("## Setup");
	// Initialise to 0. The move number will be added to the board when the knight lands there.
	int board[BOARD_SIZE][BOARD_SIZE] = {0};
	puts("Chess board starting state.");
	print2dArray(BOARD_SIZE, BOARD_SIZE, board);

	/*
	 * Not using cartesian x y coordinates. As our 0,0 is the top left, and not in the middle.
	 * Negative numbers in horizontal mean left and positive means right.
	 * Negative numbers in vertical mean up and positive means down.
	 * Combining the values of horizontalMovement[n] and verticalMovement[n] tells us how to move the knight.
	 */
	int horizontalMovement[POSSIBLE_MOVES];
	horizontalMovement[0] = 2; // Move 2 to the right
	horizontalMovement[1] = 1; // Move 1 to the right
	horizontalMovement[2] = -1; // Move 1 to the left
	horizontalMovement[3] = -2; // Move 2 to the left
	horizontalMovement[4] = -2; // Move 2 to the left
	horizontalMovement[5] = -1; // Move 1 to the left
	horizontalMovement[6] = 1; // Move 1 to the right
	horizontalMovement[7] = 2; // Move 2 to the right
	puts("Possible horizontal and vertical moves. Combine horizontalMovement[n] and verticalMovement[n] to make a possible move.");
	print1dArray(POSSIBLE_MOVES, horizontalMovement);

	int verticalMovement[POSSIBLE_MOVES];
	verticalMovement[0] = -1; // Move up 1
	verticalMovement[1] = -2; // Move up 2
	verticalMovement[2] = -2; // Move up 2
	verticalMovement[3] = -1; // Move up 1
	verticalMovement[4] = 1; // Move down 1
	verticalMovement[5] = 2; // Move down 2
	verticalMovement[6] = 2; // Move down 2
	verticalMovement[7] = 1; // Move down 1
	print1dArray(POSSIBLE_MOVES, verticalMovement);

	puts("## Running");
	/*
	 * This is the position of the knight, based on 0,0 being top left of the 8x8 board.
	 * The book positions the K at row 3, column 4
	 * The starting position will be 1.
	 */
	int currentRow = 3;
	int currentColumn = 4;
	int moveCounter = 0;
	bool movesAttempted[POSSIBLE_MOVES] = {false};
	board[currentRow][currentColumn] = ++moveCounter;

	// Various variables needed
	bool moveStaysOnBoard = false;
	bool moveHasntBeenDoneYet = false;
	bool validMove = false;
	bool noMorePossibleMoves = false;
	int tempRow;
	int tempColumn;
	int prn = 0;
	for (size_t i = 0; i < MAX_MOVES; i++) {
		while(!validMove) {
			// Reset the variables
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
			tempRow += verticalMovement[prn];
			tempColumn += horizontalMovement[prn];

			// Test if the move doesn't go off the board
			if(tempRow >= MIN_LEGAL_MOVE && tempRow <= MAX_LEGAL_MOVE &&
			   tempColumn >= MIN_LEGAL_MOVE && tempColumn <= MAX_LEGAL_MOVE) {
				moveStaysOnBoard = true;
			}
			else {
				continue;
			}

			// Test that moved hasn't been done yet
			if(board[tempRow][tempColumn] == 0) {
				moveHasntBeenDoneYet = true;
			}
			else {
				continue;
			}

			if (moveStaysOnBoard && moveHasntBeenDoneYet) {
				validMove = true;
			}
		}
		if(noMorePossibleMoves) {
			break;
		}

		// Make the move
		currentRow += verticalMovement[prn];
		currentColumn += horizontalMovement[prn];
		board[currentRow][currentColumn] = ++moveCounter;

		// Reset variables
		moveHasntBeenDoneYet = false;
		moveStaysOnBoard = false;
		validMove = false;
		resetAttemptedMoves(POSSIBLE_MOVES, movesAttempted);
	}
	print2dArray(BOARD_SIZE, BOARD_SIZE, board);

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

void print1dArray(size_t m, int a[])
{
	printf("[");
	for (size_t i = 0; i < m; i++) {
		printf("%d, ", a[i]);
	}
	printf("%s", "\b\b]\n");
}

bool allMovesAttempted(size_t m, bool a[])
{
	for (size_t i = 0; i < m; i++) {
		if (a[i] !=  true) {
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