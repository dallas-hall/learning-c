#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int a = 1;
	int b = 2;
	int c = 3;
	int d = 4;
	
	printf("# Printing via literal\n");
	printf("1 2 3 4.\n\n");

	printf("# Printing via variables\n");
	printf("%d %d %d %d.\n", a, b, c, d);
	printf("%d", a);
	printf("%d", b);
	printf("%d", c);
	printf("%d.\n", d);

	return EXIT_SUCCESS;
}
