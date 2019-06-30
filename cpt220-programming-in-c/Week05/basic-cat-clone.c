#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER 256
/*
 * fgets adds a \0 to the end
 */
#define FGETS_CHAR 1

int closeFilesAndExit(FILE *ptr1, FILE *ptr2);

/*
 * Same as int main(int argc, char **argv)
 */
int main(int argc, char *argv[])
{
	FILE *inputFile1Pointer = NULL;
	FILE *inputFile2Pointer = NULL;
	char buffer[BUFFER + FGETS_CHAR];
	char c = '\0';
	unsigned long lines = 0;
	int lineStart = 1;

	puts("# Unix cat Command Basic Clone");
	/*
	 * Read in from stdin and write to stdout
	 */
	if (argc == 1) {
		puts("## Echo To stdout");
		while ((c = getchar()) != EOF) {
			putchar(c);
		}
		return EXIT_SUCCESS;
	}

	/*
	 * Concatenate 2 files to stdout
 	 */
	if (strcmp(argv[1], "-n") != 0 && argc == 3) {
		puts("## Concatenate 2 Files To stdout");
		if ((inputFile1Pointer = fopen(argv[1], "r")) == NULL) {
			fprintf(stderr, "[ERROR] Input file %s couldn't be opened. Does it exist?\n", argv[1]);
			return EXIT_FAILURE;
		};

		if ((inputFile2Pointer = fopen(argv[2], "r")) == NULL) {
			fprintf(stderr, "[ERROR] Input file %s couldn't be opened. Does it exist?\n", argv[2]);
			return EXIT_FAILURE;
		};

		/*
		 * Keep reading until we get to EOF. The pointer will be NULL when there is no more input.
		 * We are ignoring the \0 at fgets adds to the end.
		 */
		while(fgets(buffer, BUFFER, inputFile1Pointer) != NULL) {
			printf("%s", buffer);
		}
		while(fgets(buffer, BUFFER, inputFile2Pointer) != NULL) {
			printf("%s", buffer);
		}
		return closeFilesAndExit(inputFile1Pointer, inputFile2Pointer);
	}
	
	if (strcmp(argv[1], "-n") == 0 && argc == 3) {
		puts("## Line Count");
		/*
		 * Open in read only mode.
		 * Remember the () for precedence, as assignment is the lower than comparison.
		 */
		if ((inputFile1Pointer = fopen(argv[2], "r")) == NULL) {
			fprintf(stderr, "[ERROR] Input file couldn't be opened. Does it exist?\n");
			return EXIT_FAILURE;
		};

		lines = 0;
		while (fgets(buffer, BUFFER + FGETS_CHAR, inputFile1Pointer) !=  NULL) {
			if(lineStart) {
				++lines;
				printf("%s\t%lu\t", argv[0], lines);
				lineStart = 0;
			}
			/*
			 * strlen doesn't count the trailing \0
			 * So the last character is be a \n if we read the entire line
			 */
			if (buffer[strlen(buffer) - 1] == '\n') {
				printf("%s", buffer);
				lineStart = 1;
			}
			else {
				printf("%s", buffer);
			}
		}
		printf("\n");
		return closeFilesAndExit(inputFile1Pointer, inputFile2Pointer);
	}
	else {
		fprintf(stderr, "[ERROR] The -n option needs 1 file after it.\n");
		return EXIT_FAILURE;
	}
}

int closeFilesAndExit(FILE *ptr1, FILE *ptr2)
{
	/*
 * Close our resources.
 */
	if (ptr1 != NULL) {
		fclose(ptr1);
	}
	if (ptr2 != NULL) {
		fclose(ptr2);
	}

	return EXIT_SUCCESS;
}
