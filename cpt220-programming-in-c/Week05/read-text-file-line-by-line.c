#include <stdio.h>
#include <stdlib.h>

/*
 * Includes the implicit argv[0] which is the programs name.
 * So we are only expecting 1 user passed argument.
 */ 
#define MAX_ARGS 2
#define BUFFER 256
/*
 * fgets adds a \0 to the end of the input.
 */ 
#define FGETS_EXTRA_CHAR 1

/*
 * This is the same as int main(int argc, char **argv)
 */ 
int main(int argc, char *argv[])
{
	char s[BUFFER + FGETS_EXTRA_CHAR];
	FILE *inputFilePointer;

	puts("# Read Text File Line By Line");
	if(argc < MAX_ARGS) {
		/*
		 * Minus 1 off the count here to remove the implicit argv[0], which is the program's name.
		 */ 
		fprintf(stderr, "[ERROR] Not enough arguments supplied. Found %d but require %d.\n", argc - 1, MAX_ARGS - 1);
		return EXIT_FAILURE;
	}
	if(argc > MAX_ARGS) {
		fprintf(stderr, "[ERROR] Too many arguments supplied. Found %d but require only %d.\n", argc - 1, MAX_ARGS - 1);
		return EXIT_FAILURE;
	}
	/*
	 * Try to open the supplied file in read only mode.
	 * Remember the parentheses here because assignment has the lowest precedence.
	 */ 
	if( (inputFilePointer = fopen(argv[1], "r")) == NULL) {
		fprintf(stderr, "[ERROR] Input file couldn't be opened. Does it exist?\n");
		return EXIT_FAILURE;
	}
	puts("## Reading File Char By Char");
	/*
	 * Keep reading until we get to EOF. The pointer will be NULL when there is no more input.
	 */ 
	while(fgets(s, BUFFER, inputFilePointer) != NULL) {
		printf("%s", s);	
	}

	puts("\n## Closing Open Resources");
	fclose(inputFilePointer);
	printf("Program done.\n");

	return EXIT_SUCCESS;
}
