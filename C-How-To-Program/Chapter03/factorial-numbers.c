#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	unsigned long int total;
	int input, number;

	//https://www.mathsisfun.com/numbers/factorial.html
	puts("# Factorial Numbers");
	do {
		printf("Enter an integer greater than or equal to 0: ");
		scanf("%d", &input);
	}
	while (input < 0);

	total = 1;
	if (input != 1) {
		number = 1;
		while (number <= input) {
			total *= (unsigned long int) number;
			++number;
		}
	}
	printf("%d! = %lu\n", input, total);

	return EXIT_SUCCESS;
}
