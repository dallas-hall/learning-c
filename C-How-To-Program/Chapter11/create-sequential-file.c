#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
	char input;
	int account;
	char name[32];
	double balance;

	/*
	 * FILE a pointer to a file.
	 */ 
	FILE *filePtr;

	/*
	 * w = write mode, delete all if exists and create if doesn't exist. 
	 * a+ = append mode plus created if doesn't exist.
	 */ 
	if(NULL == (filePtr = fopen("clients.dat", "w"))) {
		fprintf(stderr, "[ERROR] File could not be opened.\n");
	}
	else {
		/*
		 * Write the header to the file.
		 */ 
		fprintf(filePtr, "ACCOUNT_NUM;NAME;BALANCE\n");

		while(1) {
			printf("Do you want to enter an account? (y/n): ");
			/*
			 * Space to consume trailing newline from previous loop.
			 */ 
			scanf(" %c", &input);
			if(tolower(input) == 'n') {
				break;
			}

			printf("Enter account number: ");
			scanf("%d", &account);
			

			printf("Enter name: ");
			/*
		 	* Space to consume the trailing newlinle
		 	*/ 
			scanf(" %s", name);

			printf("Enter account balance: ");
			scanf(" %lf", &balance);
			fprintf(filePtr, "%d;%s;%.2f\n", account, name, balance);

		}
	}	

	printf("Program done.\n");
	return EXIT_SUCCESS;
}
