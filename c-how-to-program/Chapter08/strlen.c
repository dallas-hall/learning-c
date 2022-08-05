#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char *str1 = "Hello World!";

	puts("# String Length With strlen");
	printf("The string\n\"%s\"\nhas a length of %lu\n", str1, strlen(str1)); 

	return EXIT_SUCCESS;
}
