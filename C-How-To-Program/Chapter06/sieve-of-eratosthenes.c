#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define LIMIT 100

void initialiseArray(size_t length, bool array[], int value);
void print1dArray(size_t length, bool array[], int valuesToPrintPerLine);
void sieveOfEratosthenes(size_t length, bool array[]);

int main(void)
{
	puts("# Sieve of Eratosthenes");

	// Any number marked as true is prime.
	bool numbers[LIMIT] = {false};
	puts("## Array Setup - All False");
	print1dArray(LIMIT, numbers, 10);

	initialiseArray(LIMIT, numbers, true);
	puts("");
	puts("## Array Setup - All True");
	print1dArray(LIMIT, numbers, 10);

	sieveOfEratosthenes(LIMIT, numbers);
	puts("");
	puts("## Run The Sieve Of Eratosthenes");
	print1dArray(LIMIT, numbers, 10);

	return EXIT_SUCCESS;
}

void initialiseArray(size_t length, bool array[], int value)
{
	for (size_t i = 0; i < length; i++) {
		array[i] = value;
	}
}

void print1dArray(size_t length, bool array[], int numbersToPrintPerLine)
{
	int numbersPrinted = 0;
	unsigned long lastNumberToPrint = length - 1;

	printf("%s", "[");
	for (size_t i = 0; i < length; i++) {
		printf("%ld is %s, ", i, array[i] ? "true" : "false");

		++numbersPrinted;
		if (numbersPrinted % numbersToPrintPerLine == 0 && i != lastNumberToPrint) {
			printf("%s", "\n");
		}
	}
	printf("%s", "\b\b]\n");
}

void sieveOfEratosthenes(size_t length, bool array[])
{
	for (size_t i = 0; i < length; i++) {
		// Make sure 0 and 1 aren't marked as prime
		if (i == 0 || i == 1) {
			array[i] = false;
		}
		else {
			// If the number is marked as prime, find all of its multiples and mark them as not prime
			if (array[i] == true) {
				// Keep adding i to itself to find multiples
				for (size_t j = i ; j < length; j += i) {
					if (j != i) {
						array[j] = false;
					}
				}
			}
		}
	}
}
