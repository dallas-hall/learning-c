#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	puts("# Precision Width Format Specifiers");
	printf("%%4d 1 after \\t is\t%4d\n", 1);
	printf("%%4d 12 after \\t is\t%4d\n", 12);
	printf("%%4d 123 after \\t is\t%4d\n", 123);
	printf("%%4d 1234 after \\t is\t%4d\n", 1234);
	printf("%%4d 12345 after \\t is\t%4d\n", 12345);
	printf("%%4d -1 after \\t is\t%4d\n", -1);
	printf("%%4d -12 after \\t is\t%4d\n", -12);
	printf("%%4d -123 after \\t is\t%4d\n", -123);
	printf("%%4d -1234 after \\t is\t%4d\n", -1234);
	printf("%%4d -12345 after \\t is\t%4d\n", -12345);

	return EXIT_SUCCESS;
}
