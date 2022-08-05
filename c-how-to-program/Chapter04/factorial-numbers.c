#include <stdio.h>
#include <stdlib.h>

// Seems to overflow with unsigned long int at about 20
#define LIMIT 50

int main(void)
{
	unsigned long int total;

	//https://www.mathsisfun.com/numbers/factorial.html
	puts("# Factorial Numbers");
	printf("Printing all factorials between 0 and %d\n", LIMIT);

	for (unsigned int i = 0; i < LIMIT; i++) {
		total = 1;
		if(i == 0) {
			printf("%d! = %lu\n", i, total);
			continue;
		}
		for(unsigned int j = 1; j <= i; j++) {
			total *= j;
		}
		printf("%d! = %lu\n", i, total);
	}

	return EXIT_SUCCESS;
}
