#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int product = 3;
	int threshold = 100;

	while(product < threshold) {
		printf("3 * %d = ", product);
		// Splitting across 2 lines to ensure the order of execution, otherwise an unsequenced modification & access is thrown 
		printf("%d.\n", product *= 3);
	}

	return EXIT_SUCCESS;
}
