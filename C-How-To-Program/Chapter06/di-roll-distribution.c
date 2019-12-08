#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DICE_SIDES 6
#define MAX_ROLLS 36000

int rollDice(void);
void printDiRollTable();

int main(void)
{
	puts("# 2 x Di Distribution");
	printDiRollTable();

	// Minus 1 because rolls are between 2 and 12, 11 combinations.
	size_t rollsLength = (DICE_SIDES * 2) - 1;
	int rolls[rollsLength];
	for (size_t i = 0; i < rollsLength; i++) {
		rolls[i] = 0;
	}

	int di1;
	int di2;
	for (size_t i = 0; i < MAX_ROLLS; i++) {
		// Increment each roll by once when its rolled.
		int rollTotal = rollDice() + rollDice();
		// 0 is 1 + 1 = 2 ... 11 is 6 + 6 = 12
		switch (rollTotal) {
			case 2:
				++rolls[0];
				break;
			case 3:
				++rolls[1];
				break;
			case 4:
				++rolls[2];
				break;
			case 5:
				++rolls[3];
				break;
			case 6:
				++rolls[4];
				break;
			case 7:
				++rolls[5];
				break;
			case 8:
				++rolls[6];
				break;
			case 9:
				++rolls[7];
				break;
			case 10:
				++rolls[8];
				break;
			case 11:
				++rolls[9];
				break;
			case 12:
				++rolls[10];
				break;

		}
	}

	int total = 0;
	int totalRolled = 0;
	for (size_t i = 0; i < rollsLength; i++) {
		switch (i) {
			case 0:
				total = 2;
				totalRolled += rolls[0];
				break;
			case 1:
				total = 3;
				totalRolled += rolls[1];
				break;
			case 2:
				total = 4;
				totalRolled += rolls[2];
				break;
			case 3:
				total = 5;
				totalRolled += rolls[3];
				break;
			case 4:
				total = 6;
				totalRolled += rolls[4];
				break;
			case 5:
				total = 7;
				totalRolled += rolls[5];
				break;
			case 6:
				total = 8;
				totalRolled += rolls[6];
				break;
			case 7:
				total = 9;
				totalRolled += rolls[7];
				break;
			case 8:
				total = 10;
				totalRolled += rolls[8];
				break;
			case 9:
				total = 11;
				totalRolled += rolls[9];
				break;
			case 10:
				total = 12;
				totalRolled += rolls[10];
				break;
		}

		printf("The amount of %d's rolled was %d.\n", total, totalRolled);
		// Reset the sum
		totalRolled = 0;
	}


	return EXIT_SUCCESS;
}

int rollDice(void)
{
	/*
	 * rand() produces a random number between 0 and at least 32767
	 * We can scale the results by using % (modulo).
	 * In this case % 6 generates a number between 0 and 5.
	 * We want a number between 1 and 6, so we add 1 before returning.
	 * After the first execution, rand will produce the same results over and over again. This is useful for debugging.
	 */
	return 1 + (rand() % 6);
}

void printDiRollTable()
{
	// About 1/6th of all rolls should be a 7
	puts("There 6 x 6 combinations when rolling two di.");
	// Printer header
	printf("+%3s", " ");
	for (size_t i = 1; i <= DICE_SIDES; i++) {
		printf("[%d] ", (int) i);
	}
	puts("");

	// Print body
	int sideToPrint = 1;
	for (size_t i = 1; i <= DICE_SIDES; i++) {
		// Print sides
		printf("[%-1d]", (int) i);
		// Print values
		for (size_t j = 1; j <= DICE_SIDES; j++) {
			printf("%3d ", (int) i + (int) j);
		}
		puts("");
	}
}