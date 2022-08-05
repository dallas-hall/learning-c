#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	/*char *s1 = "Hello World!\0";*/
	char s1[] = "Hello World!";
	char s2[] = "hello world!";
	
	puts("# String Comparison Functions");
	puts("## strcmp(s1, s2) - lexicographically compare s1 to s2");
	printf("s1 is \"%s\"\ns2 is \"%s\"\nLexicographically comparison result is %d\n", s1, s2, strcmp(s1, s2));
	
	puts("\n## strcmp(s2, s1) - lexicographically compare s2 to s1");
	printf("s1 is \"%s\"\ns2 is \"%s\"\nLexicographical comparison result is %d\n", s1, s2, strcmp(s2, s1));
	
	puts("\n## strcmp(s1, s1) - lexicographically compare s1 to s1");
	printf("s1 is \"%s\"\nLexicographical comparison result is %d\n", s1, strcmp(s1, s1));
	
	puts("\n## strncmp(s1, s2, 5) - lexicographically compare s1 to s2 with first 5 chars");
	printf("s1 is \"%s\"\ns2 is \"%s\"\nLexicographical comparison result is %d\n", s1, s2, strncmp(s1, s2, 5));
	
	puts("\n## strncmp(s2, s1, 5) - lexicographically compare s2 to s1 with first 5 chars");
	printf("s1 is \"%s\"\ns2 is \"%s\"\nLexicographical comparison result is %d\n", s1, s2, strncmp(s2, s1, 5));
	
	puts("\n## strncmp(s1, s1, 5) - lexicographically compare s1 to s1 with first 5 chars");
	printf("s1 is \"%s\"\nLexicographical comparison result is %d\n", s1, strncmp(s1, s1, 5));



	return EXIT_SUCCESS;
}
