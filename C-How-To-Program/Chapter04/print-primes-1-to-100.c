#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

bool isPrime(long  n);

int main(void)
{
	unsigned short i, printCounter;

	puts("# Printing All Primes Between 1 & 100");

	printCounter = 0;
	for(i = 0; i <= 100; i++) {
		if(isPrime((long) i)) {
			printf("%hu\t", i);
			++printCounter;

			if(printCounter % 10 ==0) {
				printf("\b\n");
			}
		}
	}
	puts("");

	return EXIT_SUCCESS;
}

bool isPrime(long n)
{
	// Numbers 2 and above can be prime.
	if(n > 1) {
		// 2 is the only even prime
		if (n % 2 == 0 && n != 2) {
			return false;
		}

		// Skip 3 as there is no odd number between 1 and 3 to test for divisibility.
		if(n == 2 || n == 3) {
			return true;
		}
		// Test all numbers between 3 and n - 1. If any can be evenly divided they are not prime.
		else {
			unsigned long i;
			for (i = 3; (long) i < n - 1; i++) {
				if (n % (long) i == 0) {
					return false;
				}
			}
			return true;
		}
	}

	return false;
}
