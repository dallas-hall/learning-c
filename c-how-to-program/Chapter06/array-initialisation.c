#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INT_ARRAY_LIMIT 10

int main(void)
{
	int intArray[INT_ARRAY_LIMIT];
	int i, size, prn;
	
	printf("# Declaring,Initialising, and Printing An Integer Array\n");
	/* Seed the prn rand with the number of seconds since the Unix Epoch */
	srand((unsigned) time(NULL));
	size = 0;

	for (i = 0; i < INT_ARRAY_LIMIT; i++) {
		/*
		 * Generate a random number between 0 and 99 ( % 100) , then shift it by 1 to be 1 and 100 ( + 1)
		 */
		prn = 1 + (rand() % 100);
		intArray[i] = prn;
		++size;
	}
	
	printf("%s%13s\n", "Element", "Value");
	// c99 onwards allows variables to be declared throughout the code
	// size_t is recommended since its either an unsigned int or long, arrays should never have negative numbers for access
	for (size_t j = 0; j < INT_ARRAY_LIMIT; j++) {
		printf("%7lu%13d\n", j, intArray[j]);
	}

	return EXIT_SUCCESS;
}
