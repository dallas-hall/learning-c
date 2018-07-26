#include <stdio.h>
#include <inttypes.h>

int main(void)
{
	int32_t currentChar, lineCount;
	lineCount = 0;

	printf("This program will count lines using the newline character.\n");
	printf("Type some lines and press control+d when finished.\n");

	while(EOF != (currentChar = getchar())) {
		if ('\n' == currentChar) {
			lineCount++;
		}
	}
	printf("The number of lines types was %d\n", lineCount);
	return 0;
}
