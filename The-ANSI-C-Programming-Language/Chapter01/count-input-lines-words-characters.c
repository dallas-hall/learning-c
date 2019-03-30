#include <stdio.h>

#define START 1
#define END 0

int main(void)
{
	long currentChar, numberLines, numberWords, numberChars, wordState;
	wordState = END;
	
	/*
	numberLines = 0;
	numberWords = 0;
	numberChars = 0;
	*/
	numberLines = numberWords = numberChars = 0; // Same as above

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

	printf("Lines: %ld Words: %ld Characters: %ld\n", numberLines, numberWords, numberChars);
	return 0;
}
