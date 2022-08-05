#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MIN 1
#define MAX 1000

int main(void)
{
	int numberToFind, guess, min, max, previous, attempts;
	bool done = false;

	puts("# Number Guessing - binary search");
	puts("Automatically try to guess the number between 1 and 1000.");

	min = MIN;
	max = MAX;
	// Used to compare the previous number, if they are the same the number doesn't exist
	previous = -1;

	// Seed rand with the seconds since the Unix epoch
	srand((unsigned int) time(NULL));

	// pseudo random number between 1 and 1000, inclusive
	numberToFind = rand() % max + min;

	attempts = 0;
	// An intelligent guess would be to start at (min + max + 1) / 2. The plus one is incase the range is an odd number.
	guess = rand() % max + min;

	/*
	1) Number list needs to be sorted
	2) Set initial min and max values
	3) An intelligent search is the middle of min and max
		a) (min + max + 1) / 2
	4) Check the search number and increment attempt number
		a) if current value = search value, return found
		b) if current value > search value, min index is current index
		c) if current value < search value, max index is current index
		d) if current search index = previous search index, return not found
	5)  repeat steps 3 onwards
	 */
	do {
		++attempts;

		printf("The current guess is %d\n", guess);

		if (guess == numberToFind) {
			printf("The number %d was found in %d attempts.\n", numberToFind, attempts);
			done = true;
		}
		else if (guess == previous) {
			printf("The number %d wasn't found in %d attempts.\n", numberToFind, attempts);
			done = true;
		}
		else if (guess > numberToFind) {
			puts("Too high.");
			previous = guess;
			max = guess;
		}
		else if (guess < numberToFind) {
			puts("Too low.");
			previous = guess;
			min = guess;
		}

		// Make an 'intelligent' guess
		guess = (min + max + 1) / 2; 
	}
	while (!done);

	return EXIT_SUCCESS;
}
