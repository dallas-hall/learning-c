#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RESPONSES_SIZE 40
#define FREQ_SIZE 10

/*
 * The const keyword here force the function to not be able to make changes to the array.
 */ 
void printArray(const int a[], int size);
void bubbleSortAsc(int a[], int size);
void bubbleSortDesc(int a[], int size);
void printResponses(const int a[], int size);
void printFrequency(const int a[], int size);
void printMean(const int a[], int size);
void printMedian(int a[], int size);
void printMode(const int a[], int size);

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
	printMean(responses, RESPONSES_SIZE);
	printMode(responses, RESPONSES_SIZE);
	printMedian(responses, RESPONSES_SIZE);
	

	return EXIT_SUCCESS;
}

void printArray(const int a[], int size)
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

void printResponses(const int a[], int size)
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

void printFrequency(const int a[], int size)
{
	int i, j;
	/*
	 * Initialise all values to 0
	 * C90 doesn't like variable sized objects. Using constant.
	 */
	int frequency[FREQ_SIZE] = {0};

	printf("\n## Printing Frequency Of Reponses - how many times they all appear\n");
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

/*
 * Sorting doesn't matter for this.
 */ 
void printMean(const int a[], int size)
{
	int i, total;
	double mean;

	printf("\n## Printing Mean Of Responses - average\n");
	total = 0;
	for (i = 0; i < size; i++) {
		total += a[i];
	}
	mean = (double) total / size;
	printf("The mean of %d response values is %.2f\n", size, mean);
}

/*
 * Sorting does matter for this.
 * Using bubble sorting, ascending.
 */ 
void printMedian(int a[], int size)
{
	int middle;
	double median;

	bubbleSortAsc(a, size);
	printArray(a, 40);
	
	printf("\n## Printing Median Of Responses - middle value\n");
	if (size % 2 != 0) {
		/*
		 * Make an even number, divide by 2.
		 * Add one to get the middle.
		 */
		middle = (size - 1) / 2;
		median = (double) a[middle];
	}
	else {
		/*
		 * Need - 1 because arrays start at 0
		 */ 
		middle =  (size / 2) - 1;
		/*
		 * When the size is even, the median should be the mean (average) of the 2 middle elements.
		 */ 
		median = (a[middle] + a[middle + 1]) / 2.0;
	}
	printf("The median of %d response values is %.2f\n", size, median);
}

/*
 * Sorting doesn't matter for this.
 */ 
void printMode(const int a[], int size)
{
	int i, mode, value;
	/*
	 * Initialise all values to 0
	 * C90 doesn't like variable sized objects. Using constant.
	 */
	int f[FREQ_SIZE] = {0};

	printf("\n## Printing Mode Of Responses - most frequent value \n");
	for (i = 0; i < size; i++) {
		/* 
		 * Increment the number inside of frequency[i]
		 * Remember -1 as arrays start at 0
		 */
		++f[a[i] - 1];
	}

	/*
	 * Assume index is the mode, test that assumption.
	 */ 
	mode = 0;
	value = f[0];
	/*
	 * Skip 0 as we alway got the value.
	 */ 
	for(i = 1; i < FREQ_SIZE; i++) {
		if (f[i] > value) {
			mode = i;
			value = f[i];
		}
	}
	/*
	 * Increment mode by one, because arrays start at 0.
	 * The true value is mode + 1
	 */ 
	++mode;
	printf("The mode of the %d response values is: %d\n", size, mode);
}
