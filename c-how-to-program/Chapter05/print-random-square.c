#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printStuff(int n);
void printSquare(int side, char c);

int main(void)
{
	int i, prn; 
	/*
	 * Read the computer's clock and use that value as the seed.
	 * time returns the number of seconds since the Unix Epoch, midnight of Jan 1st, 1970.
	 * NULL disables the formatting parameter option.
	 */
	srand(time(NULL));

	printf("# Printing Chars Based On rand()\n");
	for (i = 0; i < 20; i++) {
	/*
	 * rand() produces a random number between 0 and at least 32767
	 * We can scale the results by using % (modulo).
	 * In this case % 6 generates a number between 0 and 5.
	 * We want a number between 1 and 6, so we add 1 before returning.
	 */ 
		prn = 1 + (rand() % 6);
		printStuff(prn); 
	}
	printf("\n");
	return EXIT_SUCCESS;
}

void printStuff(int n)
{
	switch(n) {
		case 1:
			printSquare(n, '!');
			break;
		case 2:
			printSquare(n, '@');
			break;

		case 3:
			printSquare(n, '#');
			break;

		case 4:
			printSquare(n, '$');
			break;

		case 5:
			printSquare(n, '%');
			break;

		case 6:
			printSquare(n, '^');
			break;
	}
}

void printSquare(int size, char c)
{
	int i, j;
	printf("\n## Printing Pattern %c With Size %d\n", c, size);
	for(i = 0; i < size; i++) {
		for(j = 0; j < size; j++) {
			printf("%c", c);
		}
		printf("\n");
	}
	printf("\n");
}
