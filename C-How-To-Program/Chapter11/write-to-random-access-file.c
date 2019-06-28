#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define FILE_PATH "./credit.dat"

struct clientData {
	int accountNumber;
	char lastName[32];
	char firstName[32];
	double balance;
};

int main(void)
{
	FILE *filePointer;
	int done = 0;
	char answer;

	puts("# Writing Into A Random Access File That Stores struct");
	struct clientData client = {0, "", "", 0.0};

	/*
	 * Need parentheses as assingment precedence is lower than equality checking.
	 * rb = read binary mode 
	 * rb+ = open and existing binary file for reading and writing.
	 */ 
	if(NULL == (filePointer = fopen(FILE_PATH, "rb+"))) {
		fprintf(stderr, "[ERROR] File couldn't be opened.\n");
	}
	else {
		while(!done) {
			puts("## Enter Client Data");
			/*
			 * Get client details.
			 */ 
			while(1)
			{
				puts("Enter client's account number: ");
				scanf("%d", &client.accountNumber);

				if(!isdigit(client.accountNumber)) {	
					fprintf(stderr, "[ERROR] A number wasn't entered, try again.\n");
					continue;
				}
				else if(client.accountNumber <= 0) {
					fprintf(stderr, "[ERROR] The account number must be greater than or equal to 0.\n");
					continue;
				}
				else if(client.accountNumber > 100) {
					fprintf(stderr, "[ERROR] The account number must be less than or equal to 100.\n");
					continue;
				}
				break;
			}
			

			puts("Enter client's last name:  ");
			/*
			 * Read in from stdin and store into a variable.
			 */ 
			fscanf(stdin, "%s", client.lastName);
			
			puts("Enter client's first name:  ");
			fscanf(stdin, "%s", client.firstName);

			puts("Enter client's balance:  ");
			fscanf(stdin, "%lf", client.balance);

			/*
			 * Write client's details into the correct position in the file, uses the file position pointer to do this.
			 * Thus if accountNumber is 1, it will store it at file position pointer 0 (start of file).
			 */ 

			fscanf(filePointer, (client.accountNumber - 1) * sizeof(struct clientData), SEEK_SET);
			while(1) {
				puts("Are you finished entering client details? (y/n)");
				scanf("%c", &answer);
				if(tolower(c) == 'y') {
					done = 1;
					break;
				}
				else if(tolower(c) != 'y' || tolower(c) != 'n') {
					fprintf(stderr, "[ERROR] The account number must be greater than or equal to 0.\n");
					continue;
				}
			}

	}

	return EXIT_SUCCESS;
}
