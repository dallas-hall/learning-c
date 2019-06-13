#include <stdio.h>
#include <stdlib.h>

int maximum(int a, int b, int c);

int main(void)
{
	int n1, n2, n3;

	printf("Enter 3 digits: ");
	scanf("%d%d%d", &n1, &n2, &n3);

	printf("The largest number of %d, %d, and %d is %d\n", n1, n2, n3, maximum(n1, n2, n3));

	return EXIT_SUCCESS;
}

int maximum(int a, int b, int c)
{
	int max = 0;
	/* If there is a tie, the first number entered will returned as the max. */
	if (a >= b && a >= c) {
		max = a;
	}
	else if (b > a && b >= c) {
		max = b;
	}
	else if (c > a && c > b) {
		max = c;
	}
	return max;
}
