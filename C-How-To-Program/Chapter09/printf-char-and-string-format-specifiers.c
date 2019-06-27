#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char c1 = 'A';
	char c2 = 65;
	char s1[] = "String 1";
	const char *s2Ptr = "String 2";


	puts("# Char & String Format Specifiers");
	puts("## Chars");
	printf("%%c 'A' is %c\n", c1);
	printf("%%c 65 is %c\n", c2);
	
	puts("\n## Strings");
	printf("%%s \"String 1\" from an array is %s\n", s1);
	printf("%%s \"String 2\" from a pointer is %s\n", s2Ptr);

	return EXIT_SUCCESS;
}
