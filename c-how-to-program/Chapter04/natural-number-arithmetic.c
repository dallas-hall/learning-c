#include <stdio.h>
#include <stdlib.h>

#define LIMIT 10

int main(void)
{
	unsigned long sum, sumSquared, sumCubed;

	puts("# Natural Number Arithmetic");
	printf("Sum, sum of squared, and sum of cubed of natural numbers between 1 and %d\n", LIMIT);

	sum = 0;
	sumSquared = 0;
	sumCubed = 0;
	for(unsigned long i = 1; i <= LIMIT; i++) {
		sum += i;
		sumSquared += (i * i);
		sumCubed += (i * i * i);
	}

	printf("The sum of all natural numbers between 1 and %d is %lu\n", LIMIT, sum);
	printf("The sum of all natural numbers squared between 1 and %d is %lu\n", LIMIT, sumSquared);
	printf("The sum of all natural numbers cubed between 1 and %d is %lu\n", LIMIT, sumCubed);

	return EXIT_SUCCESS;
}
