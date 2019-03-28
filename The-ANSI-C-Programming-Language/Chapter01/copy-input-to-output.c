#include <stdio.h>

int main(void)
{
	printf("Enter some text via stdin which is read in and printed to stdout.\n");
	printf("Press ^D (ctrl + D) to send an EOF character.\n");	
	int c;
	c = getchar();

	while(EOF != c) {
		putchar(c);
		c = getchar();
	}
	return 0;
}
