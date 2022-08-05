#include <stdio.h>

int main(void)
{
	long charCount;
	charCount = 0;

	printf("Enter some text. The characters will be counted and displayed at the end.\n");
	printf("Type ^D (ctrl + d) to finish.\n");

	while(EOF != (getchar())) {
		++charCount;
	}
	printf("You typed %1d characters including the newline(s).\n", charCount);
	return 0;
}
