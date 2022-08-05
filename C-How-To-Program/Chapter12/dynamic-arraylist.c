#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>
#include <time.h>

#define START_SIZE 8
#define MULTIPLIER 2
#define MAX_ARGS 2
#define DEBUGBING 1

enum BOOLEAN
{
	FALSE,
	TRUE
};

struct arrayList
{
	int* arrayPtr;
	size_t size;
	size_t capacity;
};

struct arrayList* createArrayList(struct arrayList* theArrayList);

enum BOOLEAN insert(struct arrayList* theArrayList, int n);

enum BOOLEAN resize(struct arrayList* theArrayList, int newSize);

void printArrayList(struct arrayList* theArrayList);

void populateArray(struct arrayList* theArrayList);

int main(void)
{
	struct arrayList* theArrayList;
	theArrayList = NULL;

	puts("# Dynamic Array List");
	theArrayList = createArrayList(theArrayList);
	if (!theArrayList) {
		fprintf(stderr, "[ERROR] %s\n", strerror(errno));
		return EXIT_FAILURE;
	}
	puts("Created.");

	populateArray(theArrayList);
	printArrayList(theArrayList);

	return EXIT_SUCCESS;
}

struct arrayList* createArrayList(struct arrayList* theArrayList)
{
	puts("## Creating Dynamic Array List");
	struct arrayList* newArrayList;
	int* numbersArray = malloc(sizeof(int) * START_SIZE);
	int i;

	newArrayList = malloc(sizeof(struct arrayList));

	for (i = 0; i < START_SIZE; i++) {
		numbersArray[i] = i;
	}

	newArrayList->arrayPtr = numbersArray;
	newArrayList->size = 0;
	newArrayList->capacity = START_SIZE;

	return newArrayList;
}

enum BOOLEAN insert(struct arrayList* theArrayList, int n)
{
	return FALSE;
}

enum BOOLEAN resize(struct arrayList* theArrayList, int newSize)
{
	int i;
	int numbers[newSize];

	for (i = 0; i < newSize; i++) {
		if (i < theArrayList->size) {
			numbers[i] = theArrayList->arrayPtr[i];
		}
		else {
			numbers[i] = 0;
		}

	}

	/*
	 * Don't need to update size as it hasn't changed. We just did 1:1 copy.
	 *
	 */
	theArrayList->arrayPtr = numbers;
	theArrayList->capacity = newSize;

	return FALSE;
}

void printArrayList(struct arrayList* theArrayList)
{
	int i, numbersPrinted;

	puts("## Printing ArrayList");
	numbersPrinted = 0;

	if (theArrayList->size == 0) {
		printf("[]\n");
		return;
	}

	printf("[");
	for (i = 0; i < theArrayList->size; i++) {
		printf("%d, ", theArrayList->arrayPtr[i]);
		++numbersPrinted;

		if (numbersPrinted % 10 == 0) {
			printf("\n");
		}
	}
	/*
	 * Backspace twice to delete the last , and space
	 */
	printf("\b\b]\n");
}

void populateArray(struct arrayList* theArrayList)
{
	int i;

	srand(time(NULL));
	for(i = 0; i < theArrayList->capacity; i++) {
		++theArrayList->size;
		theArrayList->arrayPtr[i] = rand() % 100;
	}
}
