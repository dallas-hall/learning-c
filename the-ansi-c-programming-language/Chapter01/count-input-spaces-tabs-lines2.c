#include <stdio.h>
#include <inttypes.h>

int main(void)
{
	int32_t currentChar, spaceCount, tabCount, lineCount;
	spaceCount = 0;
	tabCount = 0;
	lineCount = 0;

	printf("This program will count spaces, tabs, and lines.\n");
	printf("Type some lines and press ^D (ctrl + d) when finished.\n");

	while(EOF != (currentChar = getchar())) {
		if (' ' == currentChar) {
			spaceCount++;
		}
		else if ('\t' == currentChar) {
			tabCount++;
		}
		if ('\n' == currentChar) {
			lineCount++;
		}
	}
	printf("The number of spaces types was %d\n", spaceCount);
	printf("The number of tabs types was %d\n", tabCount);
	printf("The number of lines types was %d\n", lineCount);
	return 0;
}
