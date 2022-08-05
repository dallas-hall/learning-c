#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HISTOGRAM_SIZE 10

int main(void)
{
	// Initialise everything to 9
	int frequency[HISTOGRAM_SIZE] = {0};

	puts("# Histogram");

	// Seed the prn rand with the number of seconds since the Unix Epoch
	srand((unsigned) time(NULL));
	for (size_t i = 0; i < HISTOGRAM_SIZE; i++) {
		// Generate a random number between 0 and 9 ( % 10), then shift it by 1 to be 1 and 10 ( + 1)
		frequency[i] = 1 + (rand() % 10);
	}

	printf("%7s%16s%16s\n", "Element", "Value", "Histogram");
	for (size_t i = 0; i < HISTOGRAM_SIZE; i++) {
		printf("%7lu%16d       ", i, frequency[i]);
		for (size_t j = 0; (int) j < frequency[i]; j++) {
			printf("%c", '*');
		}
		puts("");
	}

	return EXIT_SUCCESS;
}

