#include <stdio.h>

int main(void)
{
	printf("Enter some text via stdin which is read in and printed to stdout.\n");
	printf("Press ^D (ctrl + D) to send an EOF character.\n");	
	// int is used so we can hold the character value and EOF.
	int c;

	/*
	Put the getchar() call inside the while loop. This needs to be inside parentheses.
	!= has a higher precedence than =, so without the parentheses the relational test
	is done before the assignment statement. This would set the variable to being
	either 0 or 1, depending on if EOF was returned.
	*/
	while(EOF != (c = getchar())) {
		// https://en.wikipedia.org/wiki/Escape_sequences_in_C#Table_of_escape_sequences
		if ('\t' == c) {
			printf("%s", "\\t");
		}
		else if ('\\' == c) {
			printf("%s", "\\\\");
		}
		else if ('\"' == c) {
			printf("%s", "\\\"");
		}
		else if ('\'' == c) {
			printf("%s", "\\\'");
		}
		else if ('\n' == c) {
			printf("%s\n", "\\n");
		}
		// https://unix.stackexchange.com/questions/371903/why-the-b-do-not-backspace-in-the-end/371908
		else if ('\b' == c) {
			printf("%s", "\\b");
		}
		else {
			putchar(c);
		}
	}
	return 0;
}
