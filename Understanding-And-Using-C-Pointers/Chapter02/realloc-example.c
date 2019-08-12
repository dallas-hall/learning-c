#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define START_STRING "malloc"
#define END_STRING "malloc changed with realloc"

int main(void)
{
	char* stringPtr;

	puts("# realloc Vs malloc");
	puts("## malloc");

	/*
	 * + 1 for the null terminator
	 */ 
	stringPtr = malloc(sizeof(START_STRING) + 1);
	if(!stringPtr) {
		perror("malloc");
	}

	strcpy(stringPtr, START_STRING);
	printf("After strcpy(stringPtr, START_STRING), the value of stringPtr is '%s'\n", stringPtr);
	/*
	 * Need to dereference otherwise we are just getting the size of the pointer, 8 bytes.
	 */ 
	printf("The sizeof(char) * strlen(START_STRING) + 1is %lu bytes.\n", sizeof(char) * strlen(START_STRING) + 1);

	puts("\n## realloc");
	/*
	 * realloc is used to reallocate memory, either increasing or decreasing the original size.
	 *
	 * 1) pointer to the original block.
	 * 2) requested size
	 */
	stringPtr = realloc(stringPtr, sizeof(END_STRING) + 1);
	
	strcpy(stringPtr, END_STRING);
	printf("After strcpy(stringPtr, END_STRING), the value of stringPtr is '%s'\n", stringPtr);
	printf("The sizeof(char) * strlen(END_STRING) + 1is %lu bytes.\n", sizeof(char) * strlen(END_STRING) + 1);

	return EXIT_SUCCESS;
}
