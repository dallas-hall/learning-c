#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char c;
	int i;
	long l;
	float f;
	double d;

	/* %ld prints out the number as a long integer, needed here to cover the byte size */
	printf("The size of the ANSI C primitive types on my system is:\n");
	printf("A char is %ld bits or %ld byte(s).\n", sizeof(c) * 8, sizeof(c));
	printf("An int is %ld bits or %ld byte(s).\n", sizeof(i) * 8, sizeof(i));
	printf("A long is %ld bits or %ld byte(s).\n", sizeof(l) * 8, sizeof(l));
	printf("A float is %ld bits or %ld byte(s).\n", sizeof(f) * 8, sizeof(f));
	printf("A double is %ld bits or %ld byte(s).\n", sizeof(d) * 8, sizeof(d));
		
	return EXIT_SUCCESS;
}
