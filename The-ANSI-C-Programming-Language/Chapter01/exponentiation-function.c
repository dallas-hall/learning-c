#include <stdio.h>
#include <inttypes.h>

int main(void)
{
	printf("Displaying the first 16 powers of 2.\n");
	for (int i = 0; i < 16; i++) {
		printf("2 ** %d\t%d\n", i, power(2, i));
	}
	return 0;
}

int32_t power(int32_t base, int32_t n)
{
	int32_t result = 1;

	for (int i = 1; i <= n; i++) {
		result = result * base;	
	}

	return result;
}
