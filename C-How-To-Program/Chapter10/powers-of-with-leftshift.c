#include <stdlib.h>
#include <stdio.h>

void printPowers(unsigned base, int limit);

int main(void)
{
	unsigned n;
	int m;

	puts("# n ^ m With <<=1");

	puts("Enter the number to calculate the powers of: ");
	scanf("%u", &n);
	
	puts("Enter the limit to print to: ");
	scanf("%d", &m);
	
	printPowers(n, m);

	return EXIT_SUCCESS;
}

void printPowers(unsigned base, int limit)
{
	int i;
	unsigned long n;

	n = base;
	for(i = 0; i <= limit; i++) {
		if(i == 0) {
			printf("%u ^ %d = 1\n", base, i);
		}
		else if(i == 1) {
			printf("%u ^ %d = %u\n", base, i, base);
		}
		else {
			/*
			 * Left shifting by 1 bit is the equivalent to multiplying by 2.
			 */  
			printf("%u ^ %d = %ld\n", base, i, n <<= 1);
		}
	}
}
