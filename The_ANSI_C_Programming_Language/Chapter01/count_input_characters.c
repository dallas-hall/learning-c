#include <stdio.h>
#include <inttypes.h>

int main(void)
{
	int32_t charCount;
	charCount = 0;

	printf("Enter some text. The characeters will be counted and displayed at the end.\n");
	while(EOF != (getchar())) {
		++charCount;
	}
	printf("You typed %1d characters including the newline(s).\n", charCount);
	return 0;
}
