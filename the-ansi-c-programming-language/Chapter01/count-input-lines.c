#include <stdio.h>

int main(void)
{
	long currentChar, lineCount;
	lineCount = 0;

	printf("This program will count lines using the newline character.\n");
	printf("Type some lines and press ^D (ctrl + d) when finished.\n");

	while(EOF != (currentChar = getchar())) {
		if ('\n' == currentChar) {
			lineCount++;
		}
	}
	printf("The number of lines types was %ld\n", lineCount);
	return 0;
}
