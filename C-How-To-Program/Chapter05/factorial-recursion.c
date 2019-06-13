#include <stdlib.h>
#include <stdio.h>

long factorial(long n);

int main(void)
{
	long input;
	int i;

	printf("# Calculating Factorial - Recursion Example\nEnter a positive integer: ");
	scanf("%ld", &input);

	if(input < 0) {
		printf("Can only calculate factorials for positve integers.\n");
	}
	else {
		printf("The factorial of %ld (%ld!) is %ld\n", input, input, factorial(input));
	}

	printf("\n## Calculating First 20 Factorials\n");
	for(i = 1; i <= 20; i++) {
		printf("The factorial of %d (%d!) is %ld\n", i, i, factorial(i));
	}
	return EXIT_SUCCESS;
}

long factorial(long n)
{
	long recursionResult, finalResult;
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
