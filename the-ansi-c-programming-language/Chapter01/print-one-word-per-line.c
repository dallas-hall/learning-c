#include <stdio.h>

int main(void)
{
	int currentChar;

	printf("This program writes one word per line. A word is everything that isn't a space, tab, or newline.\n");
	printf("Enter input and type ^D (ctrl + d) to exit.\n");
	while (EOF != (currentChar = getchar())) {
		if (' ' == currentChar || '\n' == currentChar || '\t' == currentChar) {
			putchar('\n');
		}
		else {
			putchar(currentChar);
		}
	}
	return 0;
}
