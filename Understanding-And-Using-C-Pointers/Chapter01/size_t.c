#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	/*
	 * size_t is an unsigned integer.
	 * It represents the maximum size any object can be in C.
	* It is portable because it always means the size of the memory available on that system.
	 */ 
	size_t st = -5;

	puts("# size_t Examples");
	puts("## Negative Number");
	/*
	 * Interprets this as an integer.
	 * Which means when the high order bit is 1, it is a negative integer.
	 */ 
	printf("A size_t with -5 as %%d is %d\n", st);
	printf("A size_t with -5 as %%ld is %ld\n", st);
	/*
	 * %zu should be used but isn't available in ANSI C.
	 * An alternative to this is %u or %ul, depending on the system.
	 *
	 * The problem with negative numbers and unsigned ints is the high order bit.
	 * When this is set, it is interpretted as a large power of 2.
	 */ 
	printf("A size_t with -5 as %%lu is %lu\n", st);

	puts("## Positive Number");
	st = 5;
	printf("A size_t with -5 as %%d is %d\n", st);
	printf("A size_t with -5 as %%ld is %ld\n", st);
	printf("A size_t with -5 as %%lu is %lu\n", st);

	return EXIT_SUCCESS;
}
