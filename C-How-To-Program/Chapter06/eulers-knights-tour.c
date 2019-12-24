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

	/*
	 * This is the position of the knight, based on 0,0 being top left of the 8x8 board.
	 * The book positions the K at row 3, column 4
	 */
	int currentRow = 3;
	int currentColumn = 4;

	puts("## Running");
	/*
	 * Choose from one of the 8 possible moves.
	 * Must test that every move
	 * a) doesn't land off of the board (outside of 0-7 for x,y)
	 * b) the knight hasn't been there already. (move number is not 0)
	 * Use currentRow += verticalMovement[moveNumber] and currentColumn += horizontalMovement[moveNumber]
	 */
	// Can't exceed 63, ie 64 moves
	int moveCounter = 0;
	// Must be between 0 and 7 inclusive, ie 8 possible moves
	int moveNumber = 0;
	// Various variables needed
	bool moveStaysOnBoard = false;
	bool moveHasntBeenDoneYet = false;
	bool validMove = false;
	int tempRow = currentRow;
	int tempColumn = currentColumn;
	int prn = 0;
	for (size_t i = 0; i < 10; i++) {
		while(!validMove) {
			// Select a move, between 0 and 7
			prn = rand() % 8;
			tempRow += verticalMovement[prn];
			tempColumn += horizontalMovement[prn];

			// Test if the move doesn't go off the board
			if(currentRow + tempRow >= MIN_LEGAL_MOVE && currentRow + tempRow <= MAX_LEGAL_MOVE &&
			currentColumn + tempColumn >= MIN_LEGAL_MOVE && currentColumn + tempColumn <= MAX_LEGAL_MOVE) {
				moveStaysOnBoard = true;
			}

			// Test that moved hasn't been done yet
			if(board[currentRow][currentColumn] != 0) {
				moveHasntBeenDoneYet = true;
			}

			if (moveStaysOnBoard && moveHasntBeenDoneYet) {
				validMove = true;
			}
			else {
				// Reset the variables
				moveHasntBeenDoneYet = false;
				moveStaysOnBoard = false;
			}
		}
		// Make the move
		++moveCounter;
		currentRow += verticalMovement[prn];
		currentColumn += horizontalMovement[prn];
		board[currentRow][currentColumn] = moveCounter;

		// Reset variables
		++moveCounter;
		moveHasntBeenDoneYet = false;
		moveStaysOnBoard = false;
		validMove = false;
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
			printf("%d, ", a[i][j]);
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
