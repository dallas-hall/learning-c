// Guass trick, add 1 to n
#include <stdio.h> // Has scanf and printf
#include <stdlib.h> // Has EXIT_SUCCESS

// Function prototypes
int sumToN(int n);

int main (int argc, char *argv[])
{
	int inputNumber, answer;

	printf("Enter an integer.\n");
	scanf("%d", &inputNumber);

	// Need to divide last here to not have an integer division happen.
	answer = (inputNumber * (inputNumber + 1)) / 2;
	printf("Equation: The sum of 1 to %d is %d.\n", inputNumber, answer);
	printf("Recursion: The sum of 1 to %d is %d.\n", inputNumber, sumToN(inputNumber));
	return EXIT_SUCCESS;
}

int sumToN(int n)
{
	int sum;

	// Base condition to exit the recursive function
	if(0 == n) {
		sum = 0;
	} else {
		sum = n + sumToN(n - 1);
	}
	return sum;
}
