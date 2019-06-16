#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	/*char *s1 = "Hello World!\0";*/
	char s1[] = "Hello World!";
	char s2[15];
	
	puts("# String Copy Functions");
	puts("## strcpy");
	printf("Before strcpy\ns1 is \"%s\"\ns2 is \"%s\"\n", s1, s2);
	strcpy(s2, s1);
	printf("After strcpy\ns1 is \"%s\"\ns2 is \"%s\"\n", s1, s2);

	/* Reset the char array to nothing */
	s2[0] = '\0';
	
	puts("\n## strncpy");
	printf("Before strncpy\ns1 is \"%s\"\ns2 is \"%s\"\n", s1, s2);
	/*
	 * Copy first 6 characters from s1 into s2.
	 * Does not write '\0' into s2..
	 */ 
	strncpy(s2, s1, 6);
	s2[5] = '\0';
	printf("After strncpy\ns1 is \"%s\"\ns2 is \"%s\"\n", s1, s2);

	return EXIT_SUCCESS;
}
