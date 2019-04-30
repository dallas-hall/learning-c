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

	answer = sumToN(inputNumber);
	printf("The sum of 1 to %d is %d.\n", inputNumber, answer);
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
