#include <stdio.h>
#include <stdlib.h>

// After around 30 this really starts to slow down due to all the function call overhead of all the double recursive calls.
#define LIMIT 40

unsigned long long fibonacci(int n);

int main(void)
{
	unsigned int printCounter = 0;

	puts("# Fibonacci Series - Recursion");

	printf("The fibonacci series up to %d is ", LIMIT);
	for(int i = 0; i <= LIMIT; i++) {
		printf("%llu ", fibonacci(i));
		++printCounter;
		if(printCounter % 10 == 0) {
			puts("");
		}
	}
	printf("\n");
	
	return EXIT_SUCCESS;
}

/*
 * Fibonacci begins with 0 and 1. 0 + 1 = 1.
 * The next number is taken add added to the result, so 1 + 1 = 2. And so on.
 * The recursive formula is fib(n - 1) + fib (n - 2);
 */ 
unsigned long long fibonacci(int n)
{
	unsigned long long recursionResult1, recursionResult2, finalResult;
	
	if (0 == n) {
		finalResult = (unsigned long long) n;
	}
	else if (1 == n) {
		finalResult = 1;
	}
	else {
		recursionResult1 = fibonacci(n - 1);
		recursionResult2 = fibonacci(n - 2);
		finalResult = recursionResult1 + recursionResult2;
	}
	return finalResult;
}
