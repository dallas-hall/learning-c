#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RESPONSES_SIZE 40
#define FREQ_SIZE 10

void printArray(int a[], int size);
void bubbleSortAsc(int a[], int size);
void bubbleSortDesc(int a[], int size);
void printResponses(int a[], int size);
void printFrequency(int a[], int size);

int main(void)
{
	/*
	 * frequency = how often each value appears
	 * mean = arithmetic average
	 * mediam = the middle value of the sorted set of values
	 * mode = the value that occurs the most frequently
	 */ 
	
	int responses[RESPONSES_SIZE];
	int i;

	printf("# Array Statistics - 40 Elements With Values 1-10\n");
	/* seed rand with seconds since Unix Epoch */
	srand(time(NULL));

	for (i = 0; i < RESPONSES_SIZE; i++) {
		/* Random number between 0 and 9 (% 10) and shift it to 1-10 (+ 1) */
		responses[i] = 1 + rand() % 10;
	}

	printArray(responses, RESPONSES_SIZE);
	printResponses(responses, RESPONSES_SIZE);
	printFrequency(responses, RESPONSES_SIZE);
	

	return EXIT_SUCCESS;
}

void printArray(int a[], int size)
{
	int i;

	printf("\n## Printing Array\n");
	for(i = 0; i < size; i++) {
		if (i == 0) {
			printf("[%d, ", a[i]);
		}
		else if ( i != size - 1) {
			printf("%d, ", a[i]);
		}
		else {
			printf("%d]\n", a[i]);
		}
	}
}

void bubbleSortAsc(int a[], int size)
{
	int i, j, value, position;
	printf("\n## Bubble Sorting - ascending\n");

	for (i = 0; i < size; i++) {
		/*
		 * The current index is stored as the assumed smallest.
		 * The subsequent search will see if that is true.
		 */
		value = a[i];
		position = i;
		for (j = i + 1; j < size; j++) {
			/*
			 * Keep testing to see if any values are smaller.
			 * Replace if they are.
			 */
			if (a[j] < value) {
				value = a[j];
				position = j;
			}
		}
		/*
		 * Check to see if we found a smaller value in a different position.
		 * Swap them if we did.
		 */
		if (value != a[i] && position != i) {
			a[position] = a[i];
			a[i] = value;
		}
	}
	printf("Done.\n");
}

void bubbleSortDesc(int a[], int size)
{
	int i, j, value, position;
	printf("\n## Bubble Sorting - descending\n");

	for (i = 0; i < size; i++) {
		/*
		 * The current index is stored as the assumed largest.
		 * The subsequent search will see if that is true.
		 */
		value = a[i];
		position = i;
		for (j = i + 1; j < size; j++) {
			/*
			 * Keep testing to see if any values are larger.
			 * Replace if they are.
			 */
			if (a[j] > value) {
				value = a[j];
				position = j;
			}
		}
		/*
		 * Check to see if we found a larger value in a different position.
		 * Swap them if we did.
		 */
		if (value != a[i] && position != i) {
			a[position] = a[i];
			a[i] = value;
		}
	}
	printf("Done.\n");
}

void printResponses(int a[], int size)
{
	int i, lines;

	printf("\n## Printing Reponses - 10 per line.\n");
	lines = 0;
	for (i = 0; i < RESPONSES_SIZE; i++) {
		lines += 1;
		printf("%d\t", a[i]);
		if (lines % 10 == 0) {
			printf("\n");
		}
	}


}

void printFrequency(int a[], int size)
{
	int i, j;
	/*
	 * Initialise all values to 0
	 * C90 doesn't like variable sized objects. Using constant.
	 */
	int frequency[FREQ_SIZE] = {0};

	printf("\n## Printing Frequency Of Reponses\n");
	for (i = 0; i < size; i++) {
		/* 
		 * Increment the number inside of frequency[i]
		 * Remember -1 as arrays start at 0
		 */
		++frequency[a[i] - 1];
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
}
