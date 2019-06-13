#include <stdlib.h>
#include <stdio.h>

int square(int n);

int main(void)
{
	int i;

	printf("# Square Function\n");
	for (i = 1; i <= 10; i++) {
		printf("The square %d is %d * %d = %d\n", i, i, i, square(i));
	}
	return EXIT_SUCCESS;
}

int square(int n)
{
	return n * n;
}
