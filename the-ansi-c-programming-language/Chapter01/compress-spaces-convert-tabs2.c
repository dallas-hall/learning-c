#include <stdio.h>
#include <inttypes.h>

int main(void)
{
	int32_t previousChar, currentChar, index;
	previousChar = '\0';
	index = 0;

	printf("This program will accept input and compress multiple spaces and tabs into 1 space.\n");
	printf("It will also replace a tab with a single space. Press ^D (ctrl + d) to exit.\n");
	while (EOF != (currentChar = getchar())) {
		if (0 == index) { 
			if (currentChar == '\t') {
				currentChar = ' ';
			}
			putchar(currentChar);
			previousChar = currentChar;
		}
		else {
			if ('\t' == currentChar && ' ' != previousChar) {
				putchar(' ');
				previousChar = ' ';
			}
			else if ((' ' == previousChar && ' ' == currentChar) ||
					 (' ' == previousChar && '\t' == currentChar) ||
					 ('\t' == previousChar && ' ' == currentChar) ||
					 ('\t' == previousChar && '\t' == currentChar)) 
			{
				// Null statement as we don't want to do anything here.
				;
			}
			else {
				previousChar = currentChar;
				putchar(currentChar);
			}
		}
		index++;
	}
	return 0;
}
