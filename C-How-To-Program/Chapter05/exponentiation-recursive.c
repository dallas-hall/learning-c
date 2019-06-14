#include <stdio.h>
#include <stdlib.h>

long powerRecursive(int n, int m);

int main(void)
{
	int i, n;

	printf("# Exponentiation - Recursive\nEnter an integer: ");
	scanf("%d", &n);

	for(i = 0; i < 16; i++) {
		printf("%d ^ %d is %ld\n", n, i, powerRecursive(n, i)); 
	}

	return EXIT_SUCCESS;
}

long powerRecursive(int n, int m)
{
	if (0 == m) {
		return 1;
	}
	else if (1 == m) {
		return n;
	}
	else {
		/* The recurisve algorithm is base * base ^ (exponent - 1 */
		long recursionResult = n * powerRecursive(n, m - 1);
		/* printf("result %ld\n", recursionResult); */
		return recursionResult;
	}
}
