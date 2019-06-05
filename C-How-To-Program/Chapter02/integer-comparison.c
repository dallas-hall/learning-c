#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int a, b;
	printf("Enter 2 integers separated by space: ");
	scanf("%d %d", &a, &b);
	if (a > b) {
		printf("%d > %d.\n", a, b);
	}
	else if (a == b) {
		printf("%d = %d.\n", a, b);
	}
	else {
		printf("%d < %d.\n", a, b);
	}

	return EXIT_SUCCESS;
}

