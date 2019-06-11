#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	printf("# For Loop - 1 to 10\n");
	// In this case ++i and i++ are the same
	for (int i = 0; i < 10; i++) {
		printf("%d\t", i + 1);
	}
	printf("\n");

	printf("# While Loop Equivalent- 1 to 10\n");
	int i = 0;
	while (i < 10) {
		printf("%d\t", i + 1);
		++i; // In this case this is faster than i++
	}
	printf("\n");

	return EXIT_SUCCESS;
}
