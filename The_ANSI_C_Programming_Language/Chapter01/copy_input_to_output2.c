#include <stdio.h>
#include <inttypes.h>

int main(void)
{
	printf("Enter some text via stdin which is read in and printed to stdout.\n");
	printf("Press ctrl+D to send an EOF character.\n");	
	int16_t c;

	/*
	Pur the getchar() call inside the while loop. This needs to be inside parentheses.
	!= has a higher precedence than =, so without the parentheses the relational test
	is done before the assignment statement. This would set the variable to being
	either 0 or 1, depending on if EOF was returned.
	*/
	while((c = getchar() )!= EOF) {
		putchar(c);
	}
	return 0;
}
