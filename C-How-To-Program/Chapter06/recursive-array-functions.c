#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <limits.h>

#define LIMIT 10

void initialiseArrayInt(size_t length, int array[]);
void printIntArray(size_t length, int array[]);
void printIntArrayBackwards(size_t length, int array[]);
int getMinimumNumber(size_t length, int array[]);
int getMaximumNumber(size_t length, int array[]);
void initialiseArrayChar(size_t length, char array[]);
char printArrayChar(size_t length, char array[]);

int main(void)
{
	puts("# Recursive Array Functions");
	int numbers[LIMIT] = {0};
	initialiseArrayInt(LIMIT, numbers);

	puts("## Recursive Array Printing");
	printIntArray(LIMIT, numbers);
	puts("");
	printIntArrayBackwards(LIMIT, numbers);

	puts("\n## Recursive Element Comparison");
	printf("The minimum number is %d.\n", getMinimumNumber(LIMIT, numbers));
	printf("The maximum number is %d.\n", getMaximumNumber(LIMIT, numbers));

	return EXIT_SUCCESS;
}

void initialiseArrayInt(size_t length, int array[])
{
	for (size_t i = 0; i < length; i++) {
		// A number between 0 and 99
		array[i] = rand() % 100;
	}
}

void printIntArray(size_t length, int array[])
{
	// Base case
	if (length == 1) {
		// Need minus 1 here to print the previous element, e.g. 0
		printf("%d\t", array[--length]);
	}
	else {
		// Use minus 1 for recursion to get the previous element in the array
		printIntArray(--length, array);
		// Don't need minus 1 for printing because we are already on the correct element
		printf("%d\t", array[length]);
	}
}

void printIntArrayBackwards(size_t length, int array[])
{
	// Base case
	if (length == 1) {
		// Need minus 1 here to print the previous element, e.g. 0
		printf("%d\t", array[--length]);
	}
	else {
		// Use minus 1 for printing to get the previous element in the array
		printf("%d\t", array[length - 1]);
		// Use minus 1 for recursion to get the previous element in the array
		printIntArrayBackwards(--length, array);
	}
}

int getMinimumNumber(size_t length, int array[])
{
	// User minus 1 to get current number based on length
	int currentNumber  = array[length - 1];
	int min = INT_MAX;
	int recursiveResult;

	// Base case
	if (length == 1) {
		// Return the first element, as by default this is the minimum number until we check other numbers.
		return currentNumber;
	}
	else {
		// Use minus 1 for recursion to get the previous element in the array
		recursiveResult = getMinimumNumber(--length, array);
	}

	// Get the smallest number
	if (recursiveResult < currentNumber) {
		min = recursiveResult;
	}
	else {
		min = currentNumber;
	}

	return min;
}

int getMaximumNumber(size_t length, int array[])
{
	// User minus 1 to get current number based on length
	int currentNumber  = array[length - 1];
	int max = INT_MIN;
	int recursiveResult;

	// Base case
	if (length == 1) {
		// Return the first element, as by default this is the maximum number until we check other numbers.
		return currentNumber;
	}
	else {
		// Use minus 1 for recursion to get the previous element in the array
		recursiveResult = getMaximumNumber(--length, array);
	}

	// Get the largest number
	if (recursiveResult > currentNumber) {
		max = recursiveResult;
	}
	else {
		max = currentNumber;
	}

	return max;
}
