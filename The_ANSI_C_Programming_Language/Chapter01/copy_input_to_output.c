#include <stdio.h>
#include <inttypes.h>

int main(void)
{
	printf("Enter some text via stdin which is read in and printed to stdout.\n");
	printf("Press ctrl+D to send an EOF character.\n");	
	int16_t c;
	c = getchar();

	while(EOF != c) {
		putchar(c);
		c = getchar();
	}
	return 0;
}
