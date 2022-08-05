#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>

#define LIMIT UCHAR_MAX

int main(void)
{
	puts("# Printing All Extended ASCII Characters (0-255)");

	for(unsigned char c = 0; c < LIMIT; c++) {
		if(isprint(c)) {
			printf("In ASCII code point %u is %c.\n", c, c);
		}
		else {
			printf("In ASCII code point %u is not printable.\n", c);
		}
	}

	return EXIT_SUCCESS;
}
