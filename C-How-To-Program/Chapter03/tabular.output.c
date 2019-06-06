#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	printf("n\t10*n\t100*n\t1000*n\n");
	for(int i = 1; i <= 10; i++) {
		printf("%d\t%d\t%d\t%d\n", i, i * 10, i * 100, i * 1000);
	}

	printf("\na\ta+2\ta+4\ta+6\n");
	for(int i = 3; i <= 15; i+=3) {
		printf("%d\t%d\t%d\t%d\n", i, i + 2, i + 4, i + 6);
	}

	return EXIT_SUCCESS;
}
