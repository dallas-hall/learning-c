/******************************************************************************
 * Student Name    :  Dallas Hall
 * RMIT Student ID :  s3461243
 * COURSE CODE     :  CPT220 / OLA00
 *
 * Startup code provided by Paul Miller for use in "Programming in C",
 * study period 2, 2019.
 *****************************************************************************/
#include "fileio.h"

const int DEBUGGING_FILEIO = 0;

/**
 * loads the data from the filename specified into the linked list.
 * If the linked list is not empty you should release any data it contains
 * first.
 **/
BOOLEAN load_data(const char fname[], struct linkedlist* scorelist)
{
	/*
	 * I based this code off of C How To Program 6e Chapter 10.
	 *
	 * I really enjoyed that book and read all the chapters on C.
	 */
	FILE* filePointer;
	char buffer[MAXRESULTSTRING + FGETS_EXTRA_CHAR];
	char c;
	struct node* linkedListNodePtr;
	struct game_result* gameResultPtr;
	int i;

	/*
	 * Need the double () because of precedence.
	 * Assignment is lower than equality check.
	 *
	 * Using r to open in read only mode.
	 *
	 * We do need to save the file later, might need to update this.
	 */
	if ((filePointer = fopen(fname, "r")) == NULL) {
		/*
		 * strerror returns the string of the O/S error number.
		 * errno returns an error number for the current error
		 *
		 * Combining these prints out the O/S specific error message.
		 */
		fprintf(stderr, "[ERROR] %s called %s\n", strerror(errno), fname);
		return FALSE;
	}
	else {
		i = 0;
		/*
		 * Initially was going to use fgets but I couldn't think of a way to use
		 * it without having to go through all the chars in the fgets result
		 * anyway. So I figured just a straight call to fgetc was easier.
		 *
		 * If I did use fgets the logic would be really similar, except that
		 * I would wrap the below code in another while loop that would run
		 * while !feof and use fgets and store that into a buffer and process
		 * the buffer with the below while loop. That approach seemed much
		 * more complex when I was thinking about it.
		 */
		while ((c = fgetc(filePointer)) != EOF) {
			/*
			 * Assuming no /r/n
			 */
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
				 * Terminate the string. Because everyone knows if you don't
				 * terminate a string C just keeps on going!
				 */
				buffer[i] = '\0';
				i = 0;

				if (DEBUGGING_FILEIO) {
					printf("\n%s\n", buffer);
				}

				/*
				 * Parse the buffer, which means tokenise and validate the line
				 * data. Store it into the game_result if valid.
				 *
				 * By passing in the pointer to game_result we can manipulate it
				 * inside of parseLineData and update it if valid data is found.
				 */
				gameResultPtr = parseLineData(buffer);

				/*
				 * The same as gameResultPtr == NULL. I tend to switch between the two.
				 */
				if (!gameResultPtr) {
					perror("malloc");
					return FALSE;
				}

				linkedListNodePtr = createLinkedListNode();
				if (linkedListNodePtr == NULL) {
					perror("malloc");
					return FALSE;
				}

				/*
				 * Update the linked list node payload and link members.
				 */
				linkedListNodePtr->data = gameResultPtr;
				linkedListNodePtr->next = NULL;

				if (!insertNode(scorelist, linkedListNodePtr)) {
					error_print("Couldn't insert into the linked list.\n");
					return FALSE;
				}
			}
		}

		/*
		 * Close our FILE resource since we no longer need it.
		 */
		fclose(filePointer);
	}
	return TRUE;
}

/**
 * saves the linked list to the filename specified and in the format specified
 * in the assignment specification.
 **/
BOOLEAN save_data(const char fname[], const struct linkedlist* thelist)
{
	FILE* filePointer;
	char outputFile[PATH_MAX + FGETS_EXTRA_CHAR];
	char* strPtr;

	/*
	 * Using strdup to duplicate the string.
	 * Use strcpy to copy the pointer into an array.
	 * Using strcat to make the output file different from the input file. Used
	 * for testing and comparing purposes.
	 */
	strPtr = strdup(fname);
	strcpy(outputFile, strPtr);
	/*
	 * Need to free because strdup calls malloc for us.
	 */
	free(strPtr);
	/*
	 * TODO change is to be the same file again.
	 */
	strcat(outputFile, "-output");

	/*
	 * Using w to open in write mode. Create a new file if it doesn't exist or
	 * overwrite the existing file.
	 */
	if ((filePointer = fopen(outputFile, "w")) == NULL) {
		fprintf(stderr, "[ERROR] %s called %s\n", strerror(errno), fname);
		return FALSE;
	}

	strPtr = getLinesToWrite(thelist);
	if (DEBUGGING_FILEIO) {
		printDebug("The lines to write out to file.\n");
		printf("%s", strPtr);
	}

	fprintf(filePointer, "%s", strPtr);

	/*
	 * Free up the strPtr as we used strdup which has malloc.
	 */
	free(strPtr);

	/*
	 * Close our FILE resource since we no longer need it.
	 */
	fclose(filePointer);

	return TRUE;
}

/*
 * Parsing a CSV - winner's name, loser's name, points won by
 * Some validation done here. Length is validated before passing it here.
 *
 * I based this off of C How To Program 6e Chapter 8 and the course materials.
 *
 * The FGETS_EXTRA_CHAR covers the necessarily null control character terminator
 * for the end of the string.
 *
 * This will create a gameResult after validating the line and return it.
 */
struct game_result* parseLineData(char* line)
{
	/*
	 * TODO fix memory leak
	 */
	char* tokenPtr;
	char* winnersName;
	char* losersName;
	int winningMargin = 0;
	int tokenCount = 0;
	struct game_result* gameResultPtr;

	/*
	 * I wasn't using malloc here and this was a bug for me that took hours
	 * to figure out. I really only figured it out after reading a heap online,
	 * particularly https://stackoverflow.com/questions/37549594/crash-or-segmentation-fault-when-data-is-copied-scanned-read-to-an-uninitializ
	 * and https://stackoverflow.com/questions/41830461/allocating-string-with-malloc
	 * Once I read those and processed the information, I used malloc
	 * here and my bug went away.
	 *
	 * I refactored my code many different times and basically had the same bug
	 * until I used malloc here.
	 *
	 * I now see this is why you included stdup in helper.*, so I could just
	 * call that instead of doing this myself.
	 */
	winnersName = malloc(sizeof(char*) * NAME_LEN + FGETS_EXTRA_CHAR);
	losersName = malloc(sizeof(char*) * NAME_LEN + FGETS_EXTRA_CHAR);

	if (!winnersName) {
		perror("malloc");
		return NULL;
	}

	if (!losersName) {
		perror("malloc");
		return NULL;
	}

	/*
	 * Get the first token and validate it. Store it if it is valid.
	 */
	tokenPtr = strtok(line, DELIMITER);
	++tokenCount;

	if (!validInputName(tokenPtr)) {
		return NULL;
	}

	strcpy(winnersName, tokenPtr);

	/*
	 * Need multiple calls to get all the tokens.
	 *
	 * The while loop is how we do this.
	 */
	while (tokenPtr != NULL) {
		++tokenCount;
		/*
		 * The NULL argument tell strtok to keep going.
		 * NULL is returned when there are no more tokens.
		 *
		 * But even when NULL is returned, it will loop over one more time.
		 * That is why there is an if statement in the default block.
		 */
		tokenPtr = strtok(NULL, DELIMITER);

		/*
		 * Get the next 2 tokens and validate them. Store them if they're valid.
		 */
		switch (tokenCount) {
			case 2:
				if (!validInputName(tokenPtr)) {
					return NULL;
				}

				strcpy(losersName, tokenPtr);
				break;
			case 3:
				winningMargin = validWinningMargin(tokenPtr);

				if (winningMargin == -1) {
					return NULL;
				}

				break;
			default:
				if (tokenPtr != NULL) {
					error_print(
							"Invalid amount of tokens, 3 required, found %d.\n");
					return NULL;
				}
		}
	}

	gameResultPtr = createGameResult(winnersName, losersName, winningMargin);

	if (DEBUGGING_FILEIO) {
		printf("winnersName is %s\n", winnersName);
		printf("losersName is %s\n", losersName);
		printf("winningMargin is %d\n", winningMargin);
		printf("gameResultPtr->winner is %s\n", gameResultPtr->winner);
		printf("gameResultPtr->loser is %s\n", gameResultPtr->loser);
		printf("gameResultPtr->won_by is %d\n", gameResultPtr->won_by);
	}

	return gameResultPtr;
}

/*
 * Using the file path in the linked, it opens the file and reads the entire
 * contents in a string. The string is passed back.
 */
char* getLinesToWrite(const struct linkedlist* linkedlist)
{
	char* strPtr;
	struct node* currentNodePtr;
	char* currentLinePtr;
	char* winningMarginPtr;

	currentNodePtr = linkedlist->head;

	if (currentNodePtr == NULL) {
		/*
		 * We will create space for an empty string, so we can overwrite an
		 * existing file with nothing (i.e truncate it). This is for a
		 * scoreboard that has been deleted.
		 *
		 * Remember to free later since strdup has malloc
		 */
		strPtr = strdup("");

		return strPtr;
	}
	else {
		/*
		 * Using malloc to create a string that hold the maximum allowed data
		 * for the amount of stored game_results.
		 */
		strPtr = malloc(sizeof(char) * ((MAXRESULTSTRING + FGETS_EXTRA_CHAR) *
										linkedlist->size));
		memset(strPtr, 0, sizeof(char) * ((MAXRESULTSTRING + FGETS_EXTRA_CHAR) *
										  linkedlist->size));
	}

	/*
	 * Loop through the list and write it out using our predetermined
	 * delimiter. The list is already sorted so this will be saved in
	 * sorted order.
	 *
	 */
	while (currentNodePtr != NULL) {
		/*
		 * Using malloc to create strings for the current line and winning
		 * margin buffers
		 */
		currentLinePtr = malloc(
				sizeof(char) * (MAXRESULTSTRING + FGETS_EXTRA_CHAR));
		memset(currentLinePtr, 0, MAXRESULTSTRING + FGETS_EXTRA_CHAR);

		winningMarginPtr = malloc(
				sizeof(char) * (MAX_WINNING_MARGIN_DIGITS + FGETS_EXTRA_CHAR));
		memset(winningMarginPtr, 0,
			   MAX_WINNING_MARGIN_DIGITS + FGETS_EXTRA_CHAR);

		strcat(currentLinePtr, currentNodePtr->data->winner);
		strcat(currentLinePtr, DELIMITER);
		strcat(currentLinePtr, currentNodePtr->data->loser);
		strcat(currentLinePtr, DELIMITER);
		/*
		 * Based this on C How To Program 6e chapter 8
		 */
		sprintf(winningMarginPtr, "%d", currentNodePtr->data->won_by);
		strcat(currentLinePtr, winningMarginPtr);

		currentNodePtr = currentNodePtr->next;

		/*
		 * Only print the newline if there is another line to print.
		 */
		if (currentNodePtr != NULL) {
			strcat(currentLinePtr, "\n");
		}

		strcat(strPtr, currentLinePtr);

		/*
		 * Reset our buffers.
		 */
		free(currentLinePtr);
		free(winningMarginPtr);
	}

	return strPtr;
}