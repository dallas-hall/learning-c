#include <stdio.h>
#include <stdlib.h>

// Standard size is 8 x 8
#define BOARD_SIZE 8
// The knight has 8 possible moves
#define POSSIBLE_MOVES 8
// Store the 2 values [x][y] for the move
#define X_Y_MOVES 2

void print2dArray(size_t m, size_t n, int a[][n]);
void setPossibleKnightMoves(size_t totalPossibleMoves, size_t xyMoves, int possibleMoves[][xyMoves]);

int main(void)
{
	puts("# Euler's Knight's Tour Problem");
	puts("Can a knight on a chessboard tour every part of the chessboard, once and only once?");

	int board[BOARD_SIZE][BOARD_SIZE] = {0};
	print2dArray(BOARD_SIZE, BOARD_SIZE, board);

	// [x,y]
	int possibleMoves[POSSIBLE_MOVES][X_Y_MOVES];
	setPossibleKnightMoves(POSSIBLE_MOVES, X_Y_MOVES, possibleMoves);
	print2dArray(POSSIBLE_MOVES, X_Y_MOVES, possibleMoves);

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

void setPossibleKnightMoves(size_t totalPossibleMoves, size_t xyMoves, int possibleMoves[][xyMoves])
{
	for (size_t i = 0; i < totalPossibleMoves; i++) {
		switch (i) {
			// Everything here is [x][y]
			case 0:
				// Move across 2 to the right and 1 up
				possibleMoves[i][0] = 2;
				possibleMoves[i][1] = 1;
				break;
			case 1:
				// Move across 1 to the right and 2 up
				possibleMoves[i][0] = 1;
				possibleMoves[i][1] = 2;
				break;
			case 2:
				// Move across 1 to the left and 2 up
				possibleMoves[i][0] = -1;
				possibleMoves[i][1] = 2;
				break;
			case 3:
				// Move across 2 to the left and 1 up
				possibleMoves[i][0] = -2;
				possibleMoves[i][1] = 1;
				break;
			case 4:
				// Move across 2 to the left and down 1
				possibleMoves[i][0] = -2;
				possibleMoves[i][1] = -1;
				break;
			case 5:
				// Move across 1 to the left and down 2
				possibleMoves[i][0] = -1;
				possibleMoves[i][1] = -2;
				break;
			case 6:
				// Move across 1 to the right and 2 down
				possibleMoves[i][0] = 1;
				possibleMoves[i][1] = -2;
				break;
			case 7:
				// Move across 2 to the right and 1 down
				possibleMoves[i][0] = 2;
				possibleMoves[i][1] = -1;
				break;
		}
	}
}
