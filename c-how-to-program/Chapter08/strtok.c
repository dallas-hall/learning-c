#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DELIMITER " "

int main(void)
{
	char s[] = "This sentence\thas 5\ttokens";
	char *tokenPtr;
	char delimiters[2] = {' ', '\t'};

	puts("# String Token Extraction\n## strtok(string, delimiter)");
	printf("### Splitting up the string \"%s\"\nUsing the delimiter '%s'\n", s, DELIMITER);
	puts("\n### Printing Tokens");	
	/*
	 * Create first token
	 */
	tokenPtr = strtok(s, delimiters);

	/*
	 * Need multiple calls to get all the tokens.
	 */ 
	while (tokenPtr != NULL) {
		printf("%s\n", tokenPtr);
		/*
		 * The NULL argument tell strtok to keep going.
		 * NULL is returned when there are no more tokens.
		 */ 
		tokenPtr = strtok(NULL, delimiters);
	}

	return EXIT_SUCCESS;
}

