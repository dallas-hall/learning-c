#include <stdio.h>
#include <stdlib.h>

long integerPower(int n, int m);

int main(void)
{
	int n, i;

	printf("# Exponentiation - Iterative\nEnter an integer: ");
	scanf("%d", &n);
	
	for (i = 0; i < 16; i++) {
		printf("%d ^ %d is %ld\n", n, i, integerPower(n, i)); 
	}

	return EXIT_SUCCESS;
}

long integerPower(int n, int m)
{
	if (m == 0) {
		return 1;
	}
	else if (m == 1) {
		return n;
	}
	else {
		long result = n;
		int i;
	
		/* m - 1 is needed because we already assigned n to result */
		for (i = 0; i < m - 1; i++) {
			result *= n;
		}
		return result;
	}
}
