#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	int i;
	puts("# Printing String Errors - sterror");
	for(i = 0; i <= 10; i++) {
		printf("strerror(%d) is %s\n", i, strerror(i));
	}
	return EXIT_SUCCESS;
}
