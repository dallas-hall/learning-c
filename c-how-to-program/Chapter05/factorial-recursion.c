#include <stdlib.h>
#include <stdio.h>

// Even with unsigned long long it will overflow after 21
#define LIMIT 22

unsigned long long factorial(unsigned int n);

int main(void)
{
	printf("# Calculating First %d Factorials\n", LIMIT);
	for(unsigned int i = 0; i <= LIMIT; i++) {
		printf("The factorial of %u (%u!) is %llu\n", i, i, factorial(i));
	}
	return EXIT_SUCCESS;
}

unsigned long long factorial(unsigned int n)
{
	unsigned long long recursionResult, finalResult;
	finalResult = n;

	/*
	 * Base case, n is 1 or 0. So only process when not 1 or 0
	 */
	if (0 == n || 1 == n) {
		finalResult = 1;
	}
	else {
		/*
		 * Make a recursive call with n - 1.
		 * This means we will eventually get to n == 1, the base case.
		 * Once the base case is reached, the stack is unwound and each stack frame returns its result.
		 * The results are continually multiplied together to produce the final product, which is the last value returned.
		 */ 
		recursionResult = factorial(n - 1);
		finalResult *= recursionResult;
	}
	return finalResult;
}
