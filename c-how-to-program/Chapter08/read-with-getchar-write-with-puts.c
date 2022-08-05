#include <stdio.h>
#include <stdlib.h>

#define BUFFER 80

int main(void)
{
	char input[BUFFER];
	char c;
	int i = 0;

	puts("# Reading From stdin & Writing To stdout");
	puts("## Read stdin With getchar\nEnter your message:");
	/*
	 * Read characters from stdin until a) newline b) EOF or c) buffer exhausted
	 * Store these into an array with the size of BUFFER.
	 */ 
	while (EOF != (c = getchar()) || '\n' != (c = getchar())) {
		input[i] = c;
		i++;
		if(i == BUFFER - 2) {
			input[BUFFER - 1] = '\0';
			break;
		}
	}

	puts("\n## Write To stdout With puts");
	puts(input);
	return EXIT_SUCCESS;
}
