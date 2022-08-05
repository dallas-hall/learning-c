#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int evenSum = 0;
	// Start at 1 otherwise its everything times 0
	long oddProduct = 1;

	for (int i = 1; i <= 30; i++) {
		if(i % 2 == 0) {
			evenSum += i;
		}
		else {
			oddProduct *= i;
		}
	}

	printf("The sum of all even numbers between 1 and 30 is %d\n", evenSum);
	printf("The product of all odd numbers between 1 and 30 is %ld\n", oddProduct);
	return EXIT_SUCCESS;
}
