#include <stdio.h>
#include <stdlib.h>

#define FILE_PATH "print-file-line-by-line.c"

int main(void)
{
	FILE *filePointer;
	char c;

	puts("# Read Existing Text File Line By Line");
	puts("Printing file line by line...\n");
	/*
	 * r = read only
	 */
	if (NULL == (filePointer = fopen(FILE_PATH, "r"))) {
		fprintf(stderr, "[ERROR] File wasn't opened.");
	}
	else {
		while((c = fgetc(filePointer)) != EOF) {
			putchar(c);
		}
	}
	/*
	 * Close the FILE pointer.
	 */ 
	fclose(filePointer);

	return EXIT_SUCCESS;
}
