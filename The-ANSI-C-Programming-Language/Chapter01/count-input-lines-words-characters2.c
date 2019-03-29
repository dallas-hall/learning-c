#include <stdio.h>
#include <inttypes.h>

// controls wordState, which is used to keep track of the start and end of words.
static const int8_t START = 1;
static const int8_t END = 0;

int main(void)
{
	int32_t currentChar, numberLines, numberWords, numberChars, wordState;
	wordState = END;
	numberLines = 0;
	numberWords = 0;
	numberChars = 0;

	printf("This program will count the number of lines, words, and characters of the text you enter.\n");
	printf("Enter some text and press ^D (ctrl + d) to exit\n");
	while(EOF != (currentChar = getchar())) {
		numberChars++;
		if ('\n' ==  currentChar) {
			numberLines++;
		}
		if (' ' == currentChar || '\t' == currentChar || '\n' == currentChar) {
			wordState = END;
		}
		else if (END == wordState) {
			wordState = START;
			numberWords++;
		}
	}

	printf("Lines: %d Words: %d Characters: %d\n", numberLines, numberWords, numberChars);
	return 0;
}
