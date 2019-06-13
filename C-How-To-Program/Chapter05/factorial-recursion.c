#include <stdlib.h>
#include <stdio.h>

int factorial(int n);

int main(void)
{
	int input;

	printf("# Calculating Factorial - Recursion Example\nEnter a positive integer: ");
	scanf("%d", &input);

	if(input < 0) {
		printf("Can only calculate factorials for positve integers.\n");
	}
	else {
		printf("The factorial of %d (%d!) is %d\n", input, input, factorial(input));
	}
	return EXIT_SUCCESS;
}

int factorial(int n)
{
	int recursionResult, finalResult;
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
