#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int limit, counter, number, sum;

	printf("# Sum N Integers\nEnter amount of integers to sum followed by integers: ");
	scanf("%d ", &limit);
	
	sum = 0;
	counter = 1;
	while (counter <= limit) {
		scanf("%d", &number);
		sum += number;
		++counter;
	}

	printf("The sum total of all entered integers was: %d\n", sum);

	return EXIT_SUCCESS;
}
