#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	// Start at 1, because 1 x 1 is 1
	long result = 1;
	int number;

	printf("# Factorial Calculator\nEnter the number to calculate the factorial (n!) to: \n");
	scanf("%d", &number);
	for(int i = 1; i <= number; i++) {
		result *= i;
	}

	printf("%d! is %ld\n", number, result);
	return EXIT_SUCCESS;
}
