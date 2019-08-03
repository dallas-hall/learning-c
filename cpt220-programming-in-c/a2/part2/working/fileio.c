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

				/*
				 * TODO
				 * Insert into linked list.
				 */
				/*
				 * TODO I THINK THIS NEEDS TO BE MOVED INSIDE INSERT
				 *
				 */
				if (!insertNode(scorelist, linkedListNodePtr)) {
					error_print("Couldn't insert into the linked list.\n");
					return FALSE;
				}
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
 *
 * The FGETS_EXTRA_CHAR covers the necessarily null control character terminator
 * for the end of the string.
 *
 * This will create a gameResult after validating the line and return it.
 */
struct game_result* parseLineData(char* line)
{
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
	 * TODO
	 *
	 * score must be > 1 and <= 15
	 * name can't have any punctuation or tabs and <=20 characters
	 */

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

struct game_result*
createGameResult(char* winner, char* loser, int winningMargin)
{
	struct game_result* gameResultPtr;

	/*
	 * malloc tries to allocate memory with the specified bytes.
	 * sizeof will return the size of the data structure, platform
	 * dependent. If successful, malloc returns a void * to the
	 * allocated memory, otherwise returns NULL
	 * We are using struct game_result because that is the object
	 * hat will be stored in the pointer.
	 *
	 * Paul tends to cast the void* returned by malloc.
	 */
	gameResultPtr = malloc(sizeof(struct game_result));

	if (!gameResultPtr) {
		perror("malloc");
		return NULL;
	}

	/*
	 * memset copies a byte value for n bytes into a specified object
	 * arg 1) the object to copy into
	 * arg 2) the byte to copy
	 * arg 3) how many bytes in the object to copy into
	 *
	 * We are using struct game_result because that is the object that will
	 * be stored in the pointer.
	 *
	 * This is called zeroing out the memory. I believe this means:
	 * int = 0
	 * ptr = NULL
	 * char = '\0'
	 *
	 * Not sure if this is even necessary at this point? Every time I
	 * inspected these variables there were already zeroed.
	 */
	memset(gameResultPtr, 0, sizeof(struct game_result));

	gameResultPtr->winner = winner;
	gameResultPtr->loser = loser;
	gameResultPtr->won_by = winningMargin;

	return gameResultPtr;
}

BOOLEAN validInputName(const char* name)
{
	int nameLength;
	int i;

	if (name == NULL) {
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
	 *
	 * Paul did mention on the forum that - is probably acceptable as people
	 * can have them in their names. But I am taking the hard line approach of
	 * [^[:punct:]]
	 *
	 * The spec also talked about no tabs, but I am taking the hard line
	 * approach of [^[:space:]]
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

	if (winningMarginPtr == NULL) {
		error_print(
				"Invalid input in the third token, token is missing.\n");
		return -1;
	}

	/*
	 * Extract out the number using strtol.
	 * strtol will
	 *
	 * 1) Try to extract numbers used the supplied number system, in this case
	 * decimal.
	 * 2) Store any non-digits in strtolRemainderPointer, specifically the
	 * pointer to the first non-digit character.
	 *
	 * If there was no numbers at all, strtolRemainderPointer has the original
	 * string and 0 is returned.
	 */
	winningMargin = strtol(winningMarginPtr, &strtolRemainderPointer, BASE_10);

	/*
	 * Invalid characters found in the score.
	 *
	 * This means that an integer wasn't passed in. Could be decimal point or
	 * other non-integer junk.
	 */
	if (strlen(strtolRemainderPointer) > 0) {
		error_print(
				"Invalid input in the third token, should be an integer number only.\n");
		return -1;
	}

	/*
	 * The won by margin must be greater than 0, otherwise it would be a tie.
	 * There are only 15 tokens on the board, so that is the max won by margin.
	 */
	if (winningMargin <= 0 || winningMargin > 15) {
		error_print(
				"Invalid input in the third token, should be between 1 and 15 but was %ld.\n",
				winningMargin);
		return -1;
	}

	return (int) winningMargin;
}