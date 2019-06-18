#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_INPUT 10
#define EXTRA_CHARS 2

int getIntFromString(char s[])
{
	int i;
	/* Doesn't detect errors */
	i = atoi(s);
	return i;
}

long getIntFromString2(char s[])
{
	long li;
	char *strPtr;
	/* Does detect errors */
	li = strtol(s, &strPtr, 10);
	if(strlen(strPtr) > 1) {
		printf("Non-integer input found: %s", strPtr);
	}
	return li;
}

int main(void)
{
	char s[MAX_INPUT + EXTRA_CHARS];
	int i;

	puts("Enter an integer: ");
	fgets(s, MAX_INPUT + EXTRA_CHARS, stdin);

	/* If last char isn't a newline then the input overflowed */
	if(s[strlen(s) - 1] != '\n') {
		printf("Buffer exceeded.\n");
		return EXIT_FAILURE;
	}

	/* Need -1 here to cover the newline */
	for(i = 0; i < strlen(s) - 1; i++) {
		putchar(s[i]);
	}
	printf("\n");
	i = getIntFromString(s);
	printf("atoi %d\n", i); 
	i = getIntFromString2(s);
	printf("strtol %d\n", i); 

	return EXIT_SUCCESS;
}
