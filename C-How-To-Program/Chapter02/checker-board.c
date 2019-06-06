#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	for (int i = 0; i < 8; i++) {
		if (i % 2 != 0) {
			printf(" ");
		}
		printf("* * * * * * * *\n");
	}
	printf("\n");
	return EXIT_SUCCESS;
}
