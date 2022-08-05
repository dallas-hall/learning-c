#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	/* Create empty string */
	char s1[14] = {'\0'};
	char s2[] = "Hello world!1";
	char s3[5] = "ello";
	char c1 = 'w';

	puts("# Character Array Memory Functions");
	puts("## memcpy(string1, string2, n) - copy n of string2 into string1");
	puts("### Before");
	printf("s1 is \"%s\"\ns2 is \"%s\"\n", s1, s2);
	memcpy(s1, s2, 5);
	puts("\n### After memcpy(s1, s2, 5);");
	printf("s1 is \"%s\"\ns2 is \"%s\"\n", s1, s2);

	puts("\n## memmove(string1, string2, n) - move n of string2 into string1");
	puts("### Before");
	printf("s1 is \"%s\"\n", s1);
	/*
	 * Start at the 1st character and copy 7 bytes.
	 * Effectively replacing Hello with ello
	 */ 
	memmove(s1, &s1[1], 5);
	puts("### After memcpy(s1, &s1[1], 5);");
	printf("s1 is \"%s\"\n", s1);

	puts("\n## memcmp(string1, string2, n) - lexicographical comparison");
	puts("### Before");
	printf("s1 is \"%s\"\n", s1);
	printf("s2 is \"%s\"\n", s2);
	printf("s3 is \"%s\"\n", s3);
	printf("Lexicographical comparison of the first 5 chars of s1 and s2 is %d\n", memcmp(s1, s2, 5));
	printf("Lexicographical comparison of the first 5 chars of s2 and s3 is %d\n", memcmp(s2, s3, 5));
	printf("Lexicographical comparison of the first 5 chars of s1 and s3 is %d\n", memcmp(s1, s3, 5));

	puts("\n## memchar(string1, char, n) - Search n bytes of a string for an unsigned char. Return the remainder of the string if found.");
	puts("### Before");
	printf("s1 is \"%s\"\n", s1);
	printf("s2 is \"%s\"\n", s2);
	printf("s3 is \"%s\"\n", s3);
	/*
	 * Search the string for 7 bytes looking for a char.
	 * If found, return a pointer with the remaining chars.
	 * Returns a void pointer (*) so need to cast to the expact char *
	 */ 
	printf("Searching for %c in s2\nThe remainder of characters after finding %c is \"%s\"\n", c1, c1, (char *) memchr(s2, c1, 7));

	puts("\n## memset(string, byte, bytes);");
	puts("### Copy Byte Value To First N Bytes Of String");
	printf("s1 is \"%s\"\n", s1);
	printf("s2 is \"%s\"\n", s2);
	printf("s3 is \"%s\"\n", s3);
	memset(s2, '*', 5);
	puts("### After memset(s2, '*', 5);");
	printf("s2 is \"%s\"\n", s2);

	puts("\nAll of these functions use void * (pointers), so any object pointer can be used. Just using char * for simplicity.");
	
	return EXIT_SUCCESS;
}
