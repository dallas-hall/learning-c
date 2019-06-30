#include <stdio.h>
#include <stdlib.h>

/*
 * This includes the implict argv[0] which is the program's name.
 * So we are expecting 1 user supplied argument here.
 */ 
#define MAX_ARGS 2

/*
 *Same as int main(int argc, char **argv)
 */ 
int main(int argc, char *argv[])
{
	unsigned long fileSizeInBytes;
	FILE *inputFilePointer;

	puts("# Calculate File Size In Bytes");
	/*
	 * Need to minus 1 here to account for the implicit argv[0].
	 */ 
	if(argc == 1) {
		fprintf(stderr, "[ERROR] Not enough arguments supplied. Expected %d but got %d.\n", MAX_ARGS - 1, 0);
		return EXIT_FAILURE;
	}
	if(argc > MAX_ARGS) {
		fprintf(stderr, "[ERROR] Too many arguments supplied. Expected %d but got %d.\n", MAX_ARGS - 1, argc - 1);
		return EXIT_FAILURE;
	}

	puts("## Trying To Open File");
	/*
	 * Open in read only mode.
	 * Remember () for precedence, as assignment is the lowest.
	 */ 
	if((inputFilePointer = fopen(argv[1], "r")) == NULL) {
		fprintf(stderr, "[ERROR] Couldn't open the file %s - does it exist?\n", argv[1]);
		return EXIT_FAILURE;
	}

	puts("## Reading File");
	/*
	 * https://stackoverflow.com/a/8247
	 * 1) The FILE pointer
	 * 2) The start position offset in relation to the FILE pointer, 0 means the first byte.
	 * 3) Finish at the end of the file.
	 */ 
	fseek(inputFilePointer, 0, SEEK_END);
	/*
	 * ftell returns a signed long of the current value of the file position from the FILE pointer.
	 */ 
	fileSizeInBytes = ftell(inputFilePointer);
	printf("The file %s is %lu bytes.\n", argv[1], fileSizeInBytes);

	/*
	 * Close our open resources.
	 */ 
	fclose(inputFilePointer);
	return EXIT_SUCCESS;
}
