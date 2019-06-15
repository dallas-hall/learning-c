#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RESPONSE_SIZE 40
#define FREQ_SIZE 10

int main(void)
{
	/*
	 * frequency = how often each value appears
	 * mean = arithmetic average
	 * mediam = the middle value of the sorted set of values
	 * mode = the value that occurs the most frequently
	 */ 
	
	int responses[RESPONSE_SIZE];
	/* Initialise all values to 0 */
	int frequency[FREQ_SIZE] = {0};
	int i, j, lines;
	double mean, median, mode;

	printf("# Array Statistics - 40 Elements With Values 1-10\n");
	/* seed rand with seconds since Unix Epoch */
	srand(time(NULL));

	for (i = 0; i < RESPONSE_SIZE; i++) {
		/* Random number between 0 and 9 (% 10) and shift it to 1-10 (+ 1) */
		responses[i] = 1 + rand() % 10;
	}

	printf("## Printing Reponses - 10 per line.\n");
	lines = 0;
	for (i = 0; i < RESPONSE_SIZE; i++) {
		lines += 1;
		printf("%d\t", responses[i]);
		if (lines % 10 == 0) {
			printf("\n");
		}
	}

	printf("\n## Printing Frequency Of Reponses\n");
	for (i = 0; i < RESPONSE_SIZE; i++) {
		/* 
		 * Increment the number inside of frequency[i]
		 * Remember -1 as arrays start at 0
		 */
		++frequency[responses[i] - 1];
	}

	for(i = 0; i < FREQ_SIZE; i++) {
		printf("%d had %d response(s).\n", i + 1, frequency[i]);
	
	}
	
	printf("\n## Printing Histogram Of Responses\n");
	for (i = 0;i < FREQ_SIZE; i++) {
		printf("%2d\t", i + 1);
		for(j = 0; j < frequency[i]; j++) {
			printf("*");
		}
		printf("\n");
	}

	return EXIT_SUCCESS;
}
