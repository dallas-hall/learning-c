#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	/*char *s1 = "Hello World!\0";*/
	char s1[15] = "Hello ";
	char s2[7] = "World!";
	char s3[7];
	
	puts("# String Concatentation Functions");
	puts("## strcat(s1, s2) = s1 + s2");
	printf("Before strcat\ns1 is \"%s\"\ns2 is \"%s\"\n", s1, s2);
	/*
	 * Concatenate s2 to s1;
	 */ 
	strcat(s1, s2);
	printf("After strcat\ns1 is \"%s\"\ns2 is \"%s\"\n", s1, s2);

	puts("\n## strncat(s3, s1, n) = s1 up to n + s3");
	printf("Before strncat\ns1 is \"%s\"\ns3 is \"%s\"\n", s1, s3);
	/*
	 * Concatenate s1 for n chars to s3;
	 */ 
	strncat(s3, s1, 5);
	printf("After strncat\ns1 is \"%s\"\ns3 is \"%s\"\n", s1, s3);

	return EXIT_SUCCESS;
}
