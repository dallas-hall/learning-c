#include <stdio.h>
#include <stdlib.h>

/*
 * The #s will be replaced with a string surrounded by double quotes.
 */
#define HELLO(s) printf("Hello there, " #s "\n");

/*
 * The ## will concatenate the values on either side.
 */ 
#define CAT_TOK(x, y) x ## y

int main(void)
{
	puts("# C Preprocessor String Manipulation.");
	puts("## Single Hash - String Conversion");
	HELLO(World!);

	puts("## Double Hash - String Concatenation");
	printf("%d\n", CAT_TOK(1, 2));

	return EXIT_SUCCESS;
}
