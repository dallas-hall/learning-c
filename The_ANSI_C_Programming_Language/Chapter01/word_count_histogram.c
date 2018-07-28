#include <stdio.h>
#include <inttypes.h>

int main(void)
{
	int32_t currentChar;
	int16_t currentWordLength;
	int8_t maximumWordLength;
	maximumWordLength = 16;
	int8_t wordLengths[maximumWordLength];
	
	currentWordLength = 0;
	for (int i = 0; i < 16; i++) {
		wordLengths[i] = 0;
	}
	
	printf("This program will count the length of words and create a horizontal histogram.\nType control+d to exit.\n");

	while (EOF != (currentChar = getchar())) {
		if (' ' == currentChar || '\n' == currentChar || '\t' == currentChar ||
			',' == currentChar || '.' == currentChar) {
			wordLengths[currentWordLength - 1]++;
			currentWordLength = 0;
		}
		else {
			currentWordLength++;	
		}
	}

	printf("[INFO] Word counts.\n");
	for (int i = 0; i < maximumWordLength; i++) {
		printf("Word length %d occured %d times.\n", i + 1, wordLengths[i]); 
	}

	printf("[INFO] Horizontal histtogram.\n");
	for (int i = 0; i < maximumWordLength; i++) {
		printf("%d: ", i + 1); 
		for (int j = 0; j < wordLengths[i]; j++) {
			printf("=");
		}
		printf("\n");
	}

	printf("[INFO] Vertical histogram.\n");
	int8_t length = maximumWordLength - 1;
	// = is needed since the number is 15.
	for (int i = length; i >= 0; i--) {
		for (int j = 0; j <= length; j++) {
			if (0 == wordLengths[j] || i >= wordLengths[j]) {
				printf("   ");
			}
			else {
				printf(" * ");
			}
		}
		printf("\n");
		// if i = 0 print the row
		if (0 == i) {
			for (int k = 0; k < maximumWordLength; k++) {
				printf("%2d ", k + 1);
			}
		}
	}

	printf("\n");
	return 0;
}
