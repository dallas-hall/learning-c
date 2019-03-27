#include <stdio.h>
#include <inttypes.h>

int main(void)
{
	printf("Enter some text via stdin which is read in and printed to stdout.\n");
	printf("1 will be printed for each non-EOF char.\n");
	printf("Press ctrl+D to send an EOF character.\n");	
	int16_t c;

	/*
	Put the getchar() call inside the while loop. This needs to be inside parentheses.
	!= has a higher precedence than =, so without the parentheses the relational test
	is done before the assignment statement. This would set the variable to being
	either 0 or 1, depending on if EOF was returned.

	*/
	while(c = getchar() != EOF) {
		// 1 for non-EOF chars
		printf("%d%s", c, "\n");
	}
	// 0 for EOF chars.	
	printf("%d%s", c, "\n");
	return 0;
}
