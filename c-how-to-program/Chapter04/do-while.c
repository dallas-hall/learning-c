#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int counter = 1;
	printf("# Do While Loop\n");
	do {
		printf("%d\t", counter);
	} while (++counter <= 10);

	counter = 1;
	printf("\n# While Loop Equivalent\n");
	while (counter <= 10) {
		printf("%d\t", counter);
		++counter;
	}
	printf("\n");
	return EXIT_SUCCESS;
}
