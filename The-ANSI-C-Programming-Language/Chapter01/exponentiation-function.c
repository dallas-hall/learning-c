#include <stdio.h>

int power(int base, int n);

int main(void)
{
	printf("Displaying the first 16 powers of 2.\n");
	for (int i = 0; i < 16; i++) {
		printf("2 ** %d\t%d\n", i, power(2, i));
	}
	return 0;
}

int power(int base, int n)
{
	int result = 1;

	for (int i = 1; i <= n; i++) {
		result = result * base;	
	}

	return result;
}
