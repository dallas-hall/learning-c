#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	printf("number\tsqare\tcube\n");
	for (int i = 1; i <= 10; i++) {
		// - is right justified
		// 6 is the minimum character width
		printf("%-6d\t%-6d\t%-6d\n", i, i * i, i * i * i);
	}
	return EXIT_SUCCESS;
}
