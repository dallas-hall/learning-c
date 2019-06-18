#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 18
#define EXTRA_CHARS 2

long getIntFromString(char s[])
{
	long li;
	char *strPtr;
	puts("getIntFromString call");

	/* Does detect errors */
	li = strtol(s, &strPtr, 10);
	if(strlen(strPtr) > 1) {
		printf("Non-integer input found: %s", strPtr);
	}
	return li;
}

int sumDelimitedInts(char s[], char delimiter[])
{
	int count;
	char *tokenPtr;

	puts("sumDelimitedInts call");
	tokenPtr = strtok(s, delimiter);
	printf("first token %s\n", tokenPtr);
	count = getIntFromString(tokenPtr);

	while(tokenPtr != NULL) {
		puts("another token");
		/*
		 * The NULL argument tell strtok to keep going.
		 * NULL is returned when there are no more tokens.
		 */

		tokenPtr = strtok(NULL, delimiter);
		printf("next token %s\n", tokenPtr);
		if(tokenPtr == NULL) {
			break;
		}
		count += getIntFromString(tokenPtr);
	}

	return count;
}

int sumDelimitedInts2(char s[], char delimiter)
{
	int count, i, j;
	char currentInt[MAX_INPUT] = {0};

	puts("sumDelimitedInts2 call");
	printf("del is %c\n", delimiter);
	printf("s is %s\n", s);

	count = 0;
	j = 0;
	for(i = 0; i < strlen(s); i++) {
		printf("s[%d] is %c\n", i, s[i]);
		if(s[i] == delimiter || s[i] == '\n') {
			printf("all currentInt is %s\n", currentInt);
			count += getIntFromString(currentInt);
			j = 0;
		}
		else {
			currentInt[j] = s[i];
			printf("currentInt[%d] = %c\n", j, s[i]);
			j++;
		}
	}

	return count;
}

int main(void)
{
	char ints[MAX_INPUT + EXTRA_CHARS];
	char ints2[MAX_INPUT + EXTRA_CHARS];
	char delimiter[1 + EXTRA_CHARS];
	int i, total;

	puts("Enter the delimiter: ");
	fgets(delimiter, 1 + EXTRA_CHARS, stdin);

	/* If last char isn't a newline then the input overflowed */
	if(delimiter[strlen(delimiter) - 1] != '\n') {
		printf("Buffer exceeded.\n");
		return EXIT_FAILURE;
	}

	puts("Enter some delimited integers: ");
	fgets(ints, MAX_INPUT + EXTRA_CHARS, stdin);

	/* If last char isn't a newline then the input overflowed */
	if(ints[strlen(ints) - 1] != '\n') {
		printf("Buffer exceeded.\n");
		return EXIT_FAILURE;
	}

	/* minus 1 for the new line */
	for (i = 0; ints[i] != '\0'; i++) {
		putchar(ints[i]);
		ints2[i] = ints[i];
	}
	ints2[i] = '\0';
	puts("");

	total = sumDelimitedInts(ints, delimiter);
	printf("The total was %d\n", total);

	total = sumDelimitedInts2(ints2, delimiter[0]);
	printf("The total was %d\n", total);

	return EXIT_SUCCESS;

}
