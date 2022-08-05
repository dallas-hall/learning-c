#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a, b;

	puts("# scanf Field Width Reading");
	puts("Enter an integer greater than 100: ");
	scanf("%2d%d", &a, &b);
	printf("The first 2 digits were %d and the rest were %d\n", a, b);

	return EXIT_SUCCESS;
}
