#include <stdio.h>
#include <stdlib.h>

#define FILE_PATH "./credit.dat"

struct clientData {
	int accountNumber;
	char lastName[32];
	char firstName[32];
	double balance;
};


int main(void)
{
	int i;
	struct clientData blankClient = {0, "", "", 0.0};
	FILE *filePointer;

	puts("# Creating Random Access File That Stores struct");
	/*
	 * Need parentheses as assingment precedence is lower than equality checking.
	 * wb = binary write mode. Create a new file or overwrite an existing file.
	 */ 
	if((filePointer = fopen(FILE_PATH, "wb")) == NULL) {
		fprintf(stderr, "[ERROR] File couldn't be opened.\n");
	}
	else {
		for(i = 0; i < 100; i++) {
			/*
			 * Save in binary a fixed amount of data, enough to hold the clientData struct.
			 * fwrite transfers the specified number of bytes from the specified location to the file position in the file pointer.
			 * 1) copy from 2) size to copy 3) array elements to copy 4) file pointer
			 */ 
			fwrite(&blankClient, sizeof(struct clientData), 1, filePointer);
		}
		/*
		 * Always close open resources at the end, stops memory leaks and allows other users access to the resource.
		 */ 
		fclose(filePointer);
	}
	puts("100 shell client records copied.");

	return EXIT_SUCCESS;
}
