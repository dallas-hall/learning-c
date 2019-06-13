#include <stdlib.h>
#include <stdio.h>

int rollDice(void);
void testDiceFrequency(int rolls);

int main(void)
{
	int rolls;
	/*
	 * srand can be used to randomize the output of rand, since rand produces the same results after the first execution.
	 * The seed number must be an unsigned int and this number makes rand produce different results.
	 * unsigned is a short cut for unsigned int, a 2 byte unsigned integer. So 0 to around 65,000.
	 */
	unsigned int seed;



	printf("# Roll 6 Sided Dice N Times & Show Frequency (without seeding)\nEnter how many rolls: ");
	scanf("%d", &rolls);
	testDiceFrequency(rolls);

	printf("\n# Roll 6 Sided Dice N Times & Show Frequency (with seeding)\nEnter a seed number: ");
	scanf("%u", &seed);
	/* Seed the random number generator */
	srand(seed);
	testDiceFrequency(rolls);

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

void testDiceFrequency(int rolls)
{
	int i, result, freq1, freq2, freq3, freq4, freq5, freq6;
	/* Lazy way of assigning everything to 0 */
	freq1 = freq2 = freq3 = freq4 = freq5 = freq6 = 0;
	
	/*
	 * Each number should have an equal chance (frequency) of being rolled.
	 * This should roughly be rolls / 6 (number of sides)
	 */
	for (i = 1; i <= rolls; i++) {
		result = rollDice();
		switch (result) {
			case 1:
				++freq1;
				break;
			case 2:
				++freq2;
				break;
			case 3:
				++freq3;
				break;
			case 4:
				++freq4;
				break;
			case 5:
				++freq5;
				break;
			case 6:
				++freq6;
				break;
		}
	}
	printf("The frequency for 1 is %d\n", freq1);
	printf("The frequency for 2 is %d\n", freq2);
	printf("The frequency for 3 is %d\n", freq3);
	printf("The frequency for 4 is %d\n", freq4);
	printf("The frequency for 5 is %d\n", freq5);
	printf("The frequency for 6 is %d\n", freq6);
}
