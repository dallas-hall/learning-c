#include <stdio.h>
#include <stdlib.h>

#define START_PEG 'A'
#define SWAP_PEG 'B'
#define END_PEG 'C'

void towerOfHanoi(int towerOfHanoi, char fromPeg, char ToPeg, char swapPeg);

int main(void)
{
	puts("# Towers Of Hanoi - Recursive");
	for(unsigned int i = 2; i <= 5; i++) {
		printf("## %u Disks\n", i);
		towerOfHanoi((int) i, START_PEG, END_PEG, SWAP_PEG);
	}

	return EXIT_SUCCESS;
}

/* # Towers Of Hanoi
 *
 * Rule 1) Only one disk can be moved at a time.
 * Rule 2) No disk can be placed on top of the smaller disk.
 *
 * ## Recursive Pattern
 *
 * Shift n - 1 disks from A to B.
 * Shift last disk from A to C.
 * Shift n - 1 disks from B to C.
 *
 * Base case is n = 1, this is swapping the smallest disk. This needs to happen every second turn.
 *
 * ## Resources
 *
 * https://www.mathsisfun.com/games/towerofhanoi.html
 * https://www.hackerearth.com/blog/developers/tower-hanoi-recursion-game-algorithm-explained/
 * https://www.geeksforgeeks.org/c-program-for-tower-of-hanoi/
 */
void towerOfHanoi(int disksToMove, char fromPeg, char ToPeg, char swapPeg)
{
	// Base case, move the smallest disk. Every second move is moving this disk.
	if (disksToMove == 1) {
		printf("Move disk 1 from peg %c to peg %c.\n", fromPeg, ToPeg);
		return;
	}
	// Move n - 1 disks from A to B
	towerOfHanoi(disksToMove - 1, fromPeg, swapPeg, ToPeg);
	printf("Move disk %d from peg %c to peg %c.\n", disksToMove, fromPeg, ToPeg);

	// Move n - 1 disks from B to C
	towerOfHanoi(disksToMove - 1, swapPeg, ToPeg, fromPeg);
}
