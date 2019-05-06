#include <stdio.h>
#include <stdbool.h>

int main()
{
	printf("Enter some numbers. These will be displayed in a histogram. Everything else will be ignored. Press ^D (control + d) to exit.\n");
	int currentChar;
	_Bool debugging = true;

	while((currentChar = getchar()) != EOF) {
		// Ignore ASCII code point 10 which is the enter key.
		if(debugging && currentChar != 10) {
			printf("currentChar ASCII code point is %d\n", currentChar);
			printf("currentChar decimal number is %d\n", currentChar - '0');
		}
	}
	return 0;
}
