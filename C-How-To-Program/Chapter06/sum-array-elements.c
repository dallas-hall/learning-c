#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INT_ARRAY_SIZE 10

int main(void)
{
	int i, total;
	int intArray[INT_ARRAY_SIZE];

	printf("# Sum All Elements Of An Array\n");
	/* Seed rand() with the seconds since the Unix Epoch */
	srand(time(NULL));


	for(i = 0; i < INT_ARRAY_SIZE; i++) {
		/* Generate a prn between 0 and 99 ( % 100) and shift it by 1 ( + 1) so its between 1 and 100 */
		intArray[i] = 1 + rand() % 100;
	}

	total = 0;
	for(i = 0; i < INT_ARRAY_SIZE; i++) {
		total += intArray[i];
	}

	printf("The total of all intArray elements is %d\n", total);

	return EXIT_SUCCESS;
}
