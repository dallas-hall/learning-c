#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RESPONSES_SIZE 40
#define FREQUENCY_SIZE 10

int main(void)
{
	// Initialise everything to 9
	int frequency[FREQUENCY_SIZE] = {0};
	int responses[RESPONSES_SIZE] = {0};

	// Seed the prn rand with the number of seconds since the Unix Epoch
	srand((unsigned) time(NULL));
	for (size_t i = 0; i < RESPONSES_SIZE; i++) {
		// Generate a random number between 0 and 9 ( % 10), then shift it by 1 to be 1 and 10 ( + 1)
		responses[i] = 1 + (rand() % 10);
	}

	for (size_t i = 0; i < RESPONSES_SIZE; i++) {
		/*
		 * Loop through all the responses, and record their frequencies.
		 */
		++frequency[responses[i - 1]];
	}

	printf("There were %d responses between 1 and 10 in the survey.\n", RESPONSES_SIZE);
	for (size_t i = 0; i < FREQUENCY_SIZE; i++) {
		printf("Rating %lu: %d\n", i + 1, frequency[i]);
	}

	return EXIT_SUCCESS;
}

