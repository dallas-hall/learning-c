#include <stdio.h>
#include <inttypes.h>

int main(void)
{
	int32_t charCount;
	charCount = 0;

	printf("Enter some text. The characeters will be counted and displayed at the end.\n");
	printf("Type ctrl+d to finish.\n");

	for (int c = 0; EOF != (getchar()); ) {
		// Increment before assignment and leave the post loop bit blank as its done here
		charCount = ++c;
	}

	printf("You typed %1d characters including the newline(s).\n", charCount);
	return 0;
}
