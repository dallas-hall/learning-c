#include <stdio.h>
#include <stdlib.h>

int globalInt = 0;

int main(void)
{
	fprintf(stdout, "[DEBUG] Entering main();\n");
	printf("The value of globalInt is currently %d\n", globalInt);
	++globalInt;

	if (globalInt != 10) {
		main();
	}
	return EXIT_SUCCESS;
}
