#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	/*
	 * Using char c; is wrong. Because the EOF character, a -1, is returned. A char isn't signed or unsigned in C.
	 * So you are returning a signed number into an unsigned data type.
	 * The compiler won't tell you that this is an error.
	 * Use int instead to address this problem.
	 */
	char c;
	int i;

	printf("# EOF Stored Incorrectly As Char\n");
	printf("Type some characters and press ^D to send the EOF character to finish input:\n");
	while( EOF != ( c = getchar())) {
		putchar(c);
	}
	/* https://stackoverflow.com/questions/51194821/how-to-restart-stdin-after-ctrld */
	clearerr(stdin);
	
	printf("\n# EOF Stored Correctly As Int\n");
	printf("Type some characters and press ^D to send the EOF character to finish input: \n");
	while( EOF != ( i = getchar())) {
		putchar(i);
	}

	return EXIT_SUCCESS;
}

