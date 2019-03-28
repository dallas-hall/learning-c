#include <stdio.h>

int main(void)
{
	double charCount;
	charCount = 0;

	printf("Enter some text. The characeters will be counted and displayed at the end.\n");
	printf("Type ^D (ctrl + d) to finish.\n");

	for (int c = 0; EOF != (getchar()); ) {
		// Increment before assignment and leave the post loop bit blank as its done here
		charCount = ++c;
	}

	printf("You typed %.1f characters including the newline(s).\n", charCount);
	return 0;
}
