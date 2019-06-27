#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int *ptr;
	int x = 12345;
	int y;
	
	ptr = &x;

	puts("# Miscellaneous Format Specifiers");
	puts("## Memory Addresses %p After (void *) Cast");
	printf("%%p *ptr is %p\n", (void *) ptr);
	printf("%%p &x is %p\n", (void *) &x);

	puts("\n## Printing Total Characters Per Line %n");
	printf("%%n counts and stores into an int how many characers are in a line.%n", &y);
	printf("\nThe total amount of characters on the previous line was %d\n", y);

	puts("\n## Printing Literals");
	printf("To print a literal percent sign (%%) you need two percents.\n");
	printf("To print other literalls you need to double escape (\\\\) with 2 backslashes before your literal. E.g. \\t and \\n.\n");

	return EXIT_SUCCESS;
}
