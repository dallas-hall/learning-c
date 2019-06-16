#include <stdio.h>
#include <stdlib.h>

#define BUFFER 80

int main(void)
{
	char input[BUFFER];
	int i;

	printf("# Reading From stdin & Writing To stdout\n");
	printf("## Read stdin With fgets\nEnter your message:\n");
	/*
	 * Read characters from stdin until a) newline b) EOF or c) buffer exhausted
	 * Store these into an array with the size of BUFFER.
	 */ 
	fgets(input, BUFFER, stdin);

	printf("\n## Write To stdout With putchar\n");
	/*
	 * Use putchar to print each character.
	 */ 
	for(i = 0; i < BUFFER; i++) {
		if(input[i] == EOF || input[i] == '\0') {
			break;
		} else {
			putchar(input[i]);
		}
	}
	printf("\n");

	return EXIT_SUCCESS;
}
