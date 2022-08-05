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
	struct clientData client = {0, "", "", 0.0};
	FILE *filePointer;

	puts("# Creating Random Access File That Stores struct");
	/*
	 * Need parentheses as assingment precedence is lower than equality checking.
	 * rb = binary read mode. 
	 */ 
	if((filePointer = fopen(FILE_PATH, "rb")) == NULL) {
		fprintf(stderr, "[ERROR] File couldn't be opened.\n");
	}
	else {
		while(!feof(filePointer)) {
			/*
			 * 1) Where to read the data into
			 * 2) How much data to read
			 * 3) How many array elements to read
			 * 4) The FILE pointer to read from.
			 */ 
			fread(&client, sizeof(struct clientData), 1, filePointer);

			if(client.accountNumber != 0) {
				printf("%3d\t%32s\t%32s\t%10.2f\n",
					client.accountNumber,
					client.lastName,
					client.firstName,
					client.balance
				);
			}
		}
		/*
		 * Always close open resources at the end, stops memory leaks and allows other users access to the resource.
		 */ 
		fclose(filePointer);
	}

	return EXIT_SUCCESS;
}
