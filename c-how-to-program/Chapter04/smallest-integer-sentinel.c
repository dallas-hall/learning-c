#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int number, smallest, limit;
	
	printf("# Find Smallest Integer - Sentinel\nEnter integers. First number is how many integers to process.\n");
	scanf("%d", &number);
	limit = number;

	for (int i = 0; i < limit; i++) {
		scanf("%d", &number);
		if(0 == i) {
			smallest = number;
		}
		if (number < smallest) {
			smallest = number;
		}
	}

	printf("The smallest integer entered was: %d\n", smallest);

	return EXIT_SUCCESS;
}
