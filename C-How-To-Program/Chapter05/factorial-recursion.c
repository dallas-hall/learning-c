#include <stdlib.h>
#include <stdio.h>

int factorial(int n);

int main(void)
{
	int input;

	printf("# Calculating Factorial - Recursion Example\nEnter a positive integer: ");
	scanf("%d", &input);

	if(input <= 0) {
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

	/* Base case, n is 1. So only process when not 1 */
	if (1 != n) {
		recursionResult = factorial(n - 1);
		finalResult *= recursionResult;
	}
	return finalResult;
}
