#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 16

void printArray(int a[], int size);
void bubbleSortAsc(int a[], int size);
void bubbleSortDesc(int a[], int size);

int main(void)
{
	int a[SIZE];
	int i;
	/* Seed rand with the seconds since Unix Epoch, NULL specifies no formatting of seconds */
	srand(time(NULL));

	for (i = 0; i < SIZE; i++) {
		/* Random number between 0 and 99 ( % 100) and shift it 1 and 100 (+ 1) */
		a[i] = 1 + (rand() % 100);
	}

	printf("# Array Bubble Sorting - ascending & descending \n");
	printArray(a, SIZE);
	
	bubbleSortAsc(a, SIZE);
	printArray(a, SIZE);
	
	bubbleSortDesc(a, SIZE);
	printArray(a, SIZE);

	return EXIT_SUCCESS;
}

void printArray(int a[], int size)
{
	int i;

	printf("\n## Printing Array\n");
	for(i = 0; i < SIZE; i++) {
		if (i == 0) {
			printf("[%d, ", a[i]);
		}
		else if ( i != SIZE - 1) {
			printf("%d, ", a[i]);
		}
		else {
			printf("%d]\n", a[i]);
		}
	}
	printf("\n");
}

void bubbleSortAsc(int a[], int size)
{
	int i, j, value, position;
	printf("\n## Bubble Sorting - ascending\n");

	for (i = 0; i < SIZE; i++) {
		/*
		 * The current index is stored as the assumed smallest.
		 * The subsequent search will see if that is true.
		 */ 
		value = a[i];
		position = i;
		for (j = i + 1; j < SIZE; j++) {
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
	printf("## Bubble Sorting - descending\n");

	for (i = 0; i < SIZE; i++) {
		/*
		 * The current index is stored as the assumed largest.
		 * The subsequent search will see if that is true.
		 */ 
		value = a[i];
		position = i;
		for (j = i + 1; j < SIZE; j++) {
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
