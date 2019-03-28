#include <stdio.h>

int main(void)
{
	printf("Enter some text via stdin which is read in and printed to stdout.\n");
	printf("1 will be printed for each non-EOF char.\n");
	printf("Press ^D (ctrl + D) to send an EOF character.\n");	
	int c;

	/*
	Put the getchar() call inside the while loop. This needs to be inside parentheses.
	!= has a higher precedence than =, so without the parentheses the relational test
	is done before the assignment statement. This would set the variable to being
	either 0 or 1, depending on if EOF was returned.

	*/
	while(EOF != (c = getchar())) {
		// Prints out ASCII code point for non-EOF chars
		printf("%d%s", c, "\n");
	}
	// -1 for EOF chars.
	printf("%d%s", c, "\n");
	return 0;
}
