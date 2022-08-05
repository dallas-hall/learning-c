#include <stdio.h>

int main(void)
{
	int currentChar, whitespace, other;
	whitespace = 0;
	other = 0;

	int digit[10];
	for (int i = 0; i < 10; i++) {
		digit[i] = 0;
	}

	printf("Enter some text, press control+d to exit.\n");
	while (EOF != (currentChar = getchar())) {
		if (currentChar >= '0' && currentChar <= '9') {
			/* 
			 * '0' is 40, so when subtracting '0' from '0' to '9' will "convert" the ASCII code point
			 * to its corresponding integer
			 */

			//printf("'0' is %d", '0');
			//printf("without - '0' %d\twith - '0'\t%d\n", currentChar, currentChar - '0');
			digit[currentChar - '0']++;
		}
		else if (' ' == currentChar || '\n' == currentChar || '\t' == currentChar) {
			whitespace++;
		}
		else {
			other++;
		}
	}
	
	printf("Digits:\n");
	for (int i = 0; i < 10; i++) {
		printf("%d has %d\n", i, digit[i]);
	}
	printf("\nWhitespace: %d\nOther: %d\n", whitespace, other);
	
	return 0;
}
