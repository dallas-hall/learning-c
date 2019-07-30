/******************************************************************************
 * Student Name    :  Dallas Hall
 * RMIT Student ID :  s3461243
 * COURSE CODE     :  CPT220 / OLA00
 *
 * Startup code provided by Paul Miller for use in "Programming in C",
 * study period 2, 2019.
 *****************************************************************************/
#include "fileio.h"

int DEBUGGING_FILEIO = 1;

/**
 * loads the data from the filename specified into the linked list.
 * If the linked list is not empty you should release any data it contains
 * first.
 **/
BOOLEAN load_data(const char fname[], struct linkedlist* scorelist)
{
	/*
	 * I based this code off of C How To Program 6e Chapter 10
	 */
	FILE* filePointer;
	char buffer[MAXRESULTSTRING + FGETS_EXTRA_CHAR];
	char c;
	int i;

	/*
	 * Need the double () because of precedence.
	 * Assignment is lower than equality check.
	 *
	 * Using r to open in read only mode.
	 */
	if ((filePointer = fopen(fname, "r")) == NULL) {
		/*
		 * strerror returns the string of the O/S error number.
		 * errno returns an error number for the current error
		 */
		fprintf(stderr, "[ERROR] %s called %s\n", strerror(errno), fname);
		return FALSE;
	}
	else {
		/*
		 * TODO
		 *
		 * tokenise each line in the file
		 * validate each line in the file
		 * store validate lines in linked list
		 */

		i = 0;
		/*
		 * Initially was going to use fgets but I couldn't think of a way to use
		 * it without having to go through all the chars in the fgets result
		 * anyway. So I figured just a straight call to fgetc was easier.
		 */
		while ((c = fgetc(filePointer)) != EOF) {
			if (c != '\n') {
				if (i > MAXRESULTSTRING) {
					error_print("Input line was too long. Can only be <= %d.\n",
								MAXRESULTSTRING);
					return FALSE;
				}
				buffer[i] = c;
				++i;
			}
			else {
				/*
				 * Terminate the string
				 */
				buffer[i] = '\0';
				i = 0;

				if (DEBUGGING_FILEIO) {
					printf("\n%s\n", buffer);
				}

				/*
				 * Parse the buffer
				 */
				if(!parseLineData(buffer)) {
					return FALSE;
				}


				/*
				 * Reset the buffer.
				 */
				memset(buffer, 0, sizeof(buffer));
			}
		}

	}
	return TRUE;
}

/**
 * saves the linked list to the filename specified and in the format specified
 * in the assignment specification.
 **/
BOOLEAN save_data(const char fname[], const struct linkedlist* thelist)
{
	/*
	 * TODO
	 *
	 * Save the linked list to a file, descending order.
	 */
	return FALSE;
}

/*
 * Parsing a CSV - winner's name, loser's name, points won by
 * Some validation done here. Length is validated before passing it here.
 *
 * I based this off of C How To Program 6e Chapter 8 and the course materials.
 */
BOOLEAN parseLineData(char* line)
{
	char* tokenPtr;
	char winnersName[NAME_LEN + FGETS_EXTRA_CHAR];
	char losersName[NAME_LEN + FGETS_EXTRA_CHAR];
	int winningMargin;
	int tokenCount = 0;

	/*
	 * TODO
	 *
	 * score must be > 1 and <= 15
	 * name can't have any punctuation or tabs and <=20 characters
	 */

	/*
	 * Get the first token
	 */
	tokenPtr = strtok(line, DELIMITER);
	++tokenCount;

	if (!validInputName(tokenPtr)) {
		return FALSE;
	}

	strcpy(winnersName, tokenPtr);

	/*
	 * Need multiple calls to get all the tokens.
	 */
	while (tokenPtr != NULL) {
		++tokenCount;
		/*
		 * The NULL argument tell strtok to keep going.
		 * NULL is returned when there are no more tokens.
		 */
		tokenPtr = strtok(NULL, DELIMITER);

		switch (tokenCount) {
			case 2:
				if (!validInputName(tokenPtr)) {
					return FALSE;
				}

				strcpy(losersName, tokenPtr);
				break;
			case 3:
				winningMargin = validWinningMargin(tokenPtr);
				if (winningMargin == -1) {
					return FALSE;
				}
				break;
			default:
				if(tokenPtr != NULL) {
					error_print(
							"Invalid amount of tokens, 3 required, found %d.\n");
					return FALSE;
				}
		}
	}

	if (DEBUGGING_FILEIO) {
		printf("winnersName is %s\n", winnersName);
		printf("losersName is %s\n", losersName);
		printf("winningMargin is %ld", winningMargin);
	}

	return TRUE;
}

BOOLEAN validInputName(const char* name)
{
	int nameLength;
	int i;

	if(name == NULL) {
		error_print("Name token is missing.\n");
		return FALSE;
	}


	/*
	 * Must be <= 20
	 */
	nameLength = strlen(name);
	if (nameLength > 20) {
		error_print("Name is too long. Must be <= 20 but is %d.\n",
					nameLength);
		return FALSE;
	}

	/*
	 * Must not have any punctuation in it.
	 */
	for (i = 0; i < nameLength; i++) {
		if (ispunct(name[i])) {
			error_print(
					"Invalid character found in the name. Must not contain punctuation but found %c\n",
					name[i]);
			return FALSE;
		}
		if (isspace(name[i])) {
			error_print(
					"Invalid character found in the name. Must not contain white space but found '%c'\n",
					name[i]);
			return FALSE;
		}
	}

	return TRUE;
}

int validWinningMargin(char* winningMarginPtr)
{
	char* strtolRemainderPointer;
	long winningMargin;

	if(winningMarginPtr == NULL) {
		error_print(
				"Invalid input in the third token, token is missing.\n");
		return -1;
	}


	winningMargin = strtol(winningMarginPtr, &strtolRemainderPointer, BASE_10);

	/*
	 * Invalid characters found in the score.
	 */
	if (strlen(strtolRemainderPointer) > 0) {
		error_print(
				"Invalid input in the third token, should be an integer number only.\n");
		return -1;
	}

	if (winningMargin <= 0 || winningMargin > 15) {
		error_print(
				"Invalid input in the third token, should be between 1 and 15 but was %ld.\n", winningMargin);
		return -1;
	}

	return (int) winningMargin;
}