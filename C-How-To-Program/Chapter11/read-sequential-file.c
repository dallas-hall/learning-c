#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_PATH "./clients.csv"
#define DELIMITER ";"

int main(void)
{
	char workingSpace[64];
	int account;
	char name[32];
	double balance;
	FILE *filePointer;
	char *tokenPointer;
	int column = 0;

	puts("# Read Existing Sequential File");
	/*
	 * r = read only
	 */
	if (NULL == (filePointer = fopen(FILE_PATH,	"r"))) {
		fprintf(stderr, "[ERROR] File wasn't opened.");
	}
	else {
		/*
		 * Read the header
		 */
		fscanf(filePointer, "%s", workingSpace);
		/*
		 * Get first header column
		 */
		tokenPointer = strtok(workingSpace, DELIMITER);
		while (tokenPointer != NULL) {
			printf("%s;", tokenPointer);
			/*
			 * Get the rest of the header columns.
		 	 * The NULL argument tell strtok to keep going.
		 	 * NULL is returned when there are no more tokens.
		 	 */
			tokenPointer = strtok(NULL, DELIMITER);
		}
		/*
		 * \b is backspace, so go back one and replace the last ; with a space
		 */
		printf("\b \n");

		/*
		 * feof will only return true AFTER reading a non-existent line of data.
		 */
		while (!feof(filePointer)) {
			column = 1;
			/*
			 * fscanf will only override workingSpace when there are lines to read
			 * This is my hack to get around feof checking a blank line of data, and I couldn't figure out how to do this with a header and delimiter.
			 */
			fscanf(filePointer, "%s", workingSpace);
			if(workingSpace[0] == EOF) {
				break;
			}

			tokenPointer = strtok(workingSpace, DELIMITER);
			account = strtol(workingSpace, &tokenPointer, 10);
			printf("%d;", account);

			while (tokenPointer != NULL) {
				++column;
				tokenPointer = strtok(NULL, DELIMITER);

				if (column == 2 && tokenPointer != NULL) {
					strcpy(name, tokenPointer);
					printf("%s;", name);
				}
				else if (column == 3 && tokenPointer != NULL) {
					balance = strtod(tokenPointer, &tokenPointer);
					printf("%.2f\n", balance);
				}
			}
			/*
			 * We set EOF here, which isn't overridden when the file runs out of lines to read
			 */
			workingSpace[0] = EOF;
		}
	}
	fclose(filePointer);

	return EXIT_SUCCESS;
}
