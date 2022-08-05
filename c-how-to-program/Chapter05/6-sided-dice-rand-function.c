#include <stdlib.h>
#include <stdio.h>

int rollDice(void);

int main(void)
{
	int rolls, dice1, dice2, i;

	printf("# Roll 2 x 6 Sided Dice\nEnter how many rolls: ");
	scanf("%d", &rolls);

	for (i = 1; i <= rolls; i++) {
		dice1 = rollDice();
		dice2 = rollDice();
		printf("Roll %d, dice 1 was %d and dice 2 was %d. The total was %d\n", i, dice1, dice2, dice1 + dice2);
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
	 */ 
	return 1 + (rand() % 6);
}
