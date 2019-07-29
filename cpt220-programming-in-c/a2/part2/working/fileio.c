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
	char absolutePath[PATH_MAX];
	char* absolutePathPtr;
	char buffer[BUFFER_SIZE + FGETS_EXTRA_CHAR];

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
		fprintf(stderr, "[ERROR] %s\n", strerror(errno));
		return FALSE;
	}
	else {
		if (DEBUGGING_FILEIO) {
			while (fgets(buffer, sizeof(buffer), filePointer) != NULL) {
				printf("%s", buffer);
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
	return FALSE;
}
