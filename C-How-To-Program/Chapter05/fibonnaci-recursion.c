#include <stdio.h>
#include <stdlib.h>

long fibonnaci(long n);

int main(void)
{
	int limit, i;
	printf("# Fibonnaci Series - Recursion\nEnter the calculation limit of the Fibonnaci series: ");
	scanf("%d", &limit);

	if(limit < 0) {
		printf("Can only use positive numbers.\n");
	}
	else {
		printf("The fibonnaci series up to %d is ", limit);
		for(i = 0; i <= limit; i++) {
			printf("%ld ", fibonnaci(i));
		}
		printf("\n");
	}
	
	return EXIT_SUCCESS;
}

/*
 * Fibonnaci begins with 0 and 1. 0 + 1 = 1.
 * The next number is taken add added to the result, so 1 + 1 = 2. And so on.
 * The recursive formula is fib(n - 1) + fib (n - 2);
 */ 
long fibonnaci(long n)
{
	long recursionResult1, recursionResult2, finalResult;
	
	if (0 == n) {
		finalResult = n;
	}
	else if (1 == n) {
		finalResult = 1;
	}
	else {
		recursionResult1 = fibonnaci(n - 1);
		recursionResult2 = fibonnaci(n - 2);
		finalResult = recursionResult1 + recursionResult2;
	}
	return finalResult;
}
