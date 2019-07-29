#include <stdio.h>
#include <stdlib.h>

#define FILE_PATH "print-file-line-by-line.c"

int main(void)
{
	FILE *filePointer;
	char buffer[256];

	puts("# Read Existing Text File Line By Line");
	puts("Printing file line by line...\n");
	/*
	 * r = read only
	 */
	if (NULL == (filePointer = fopen(FILE_PATH, "r"))) {
		fprintf(stderr, "[ERROR] File wasn't opened.");
	}
	else {
		/*
		 * feof will only return true AFTER reading a non-existent line of data.
		 */
		while (!feof(filePointer)) {
			/*
			 * Read characters from stdin until a) newline b) EOF or c) buffer exhausted
			 * Store these into an array with the size of BUFFER.
			 */
			fgets(buffer, sizeof(buffer), filePointer);
			printf("%s", buffer);
		}
	}
	/*
	 * Close the FILE pointer.
	 */ 
	fclose(filePointer);

	return EXIT_SUCCESS;
}
