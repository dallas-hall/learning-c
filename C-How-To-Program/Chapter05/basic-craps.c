#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * enums are sequential constant values that by default start at 0 and increment by 1.
 * You can make them start at whatever number you like.
 */ 
enum Status {
	CONTINUE,
	WON,
	LOST
};

int rollDice(void);

int main(void)
{
	int sum, myPoint;
	enum Status gameStatus;

	printf("# Basic Craps Game.\n");
	/*
	 * Seed rand() so it doesn't roll consecutive numbers.
	 * Seed it with the number of seconds since the Unix Epoch.
	 */
	srand(time(NULL));
	sum = rollDice();

	switch(sum) {
		/* Win on the first roll*/
		case 7:
		case 11:
			gameStatus = WON;
			break;
		/* Lose on the first roll */
		case 2:
		case 3:
		case 12:
			gameStatus = LOST;
			break;
		/* Re-roll, if you re-roll the same number you win. */
		default:
			gameStatus = CONTINUE;
			myPoint = sum;
			printf("Point is %d\n", myPoint);
			break;
	}

	while (CONTINUE == gameStatus) {
		sum = rollDice();

		if (myPoint == sum) {
			gameStatus = WON;
		}
		else {
			gameStatus = LOST;
		}
	}

	if (WON == gameStatus) {
		printf("You, win!\n");
	}
	else {
		printf("You, lose...\n");
	}

	return EXIT_SUCCESS;
}

int rollDice(void)
{
	int dice1 = 1 + rand() % 6;
	int dice2 = 1 + rand() % 6;
	int dieSum =  dice1 + dice2;

	printf("The player rolled %d and %d which is %d.\n", dice1, dice2, dieSum);
	return dieSum;
}


