#include <stdio.h>
#include <stdlib.h>

/*
 * Includes the implicit argv[0] which is the programs name.
 * So we are only expecting 1 user passed argument.
 */ 
#define MAX_ARGS 2

/*
 * This is the same as int main(int argc, char **argv)
 */ 
int main(int argc, char *argv[])
{
	char c;
	FILE *inputFilePointer;

	puts("# Read Text File Char By Char");
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
	/* https://www.geeksforgeeks.org/fgetc-fputc-c/ */
	do {
		c = fgetc(inputFilePointer);
		if(feof(inputFilePointer)) {
			break;
		}
		fputc(c, stdout);		
	} while (1);

	puts("\n## Closing Open Resources");
	fclose(inputFilePointer);
	printf("Program done.\n");

	return EXIT_SUCCESS;
}
