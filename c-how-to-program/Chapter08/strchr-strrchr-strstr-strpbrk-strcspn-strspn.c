#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	/*
	 * The constr keywords means the character data to this pointer cannot be changed.
	 */ 
	const char *s1 = "This is a test. ABC xyz.";
	const char *s2 = "ABC";
	const char *s3 = "123";
	const char *s4 = "This is";
	char c1 = 'A';
	char c2 = 'Z';
	char c3 = 't';

	puts("# String Searching");
	puts("## strchr(string, char) - search the string for a char and return first occurance, return string pointer or NULL.");
	printf("Searching \"%s\" for %c. %s\n", s1, c1, strchr(s1, c1) ? "Found." : "Not found.");
	printf("Searching \"%s\" for %c. Found: %s\n", s1, c1, strchr(s1, c1));
	printf("Searching \"%s\" for %c. %s\n", s1, c2, strchr(s1, c2) ? "Found." : "Not found.");

	puts("\n## strrchr(string, char) - search the string for a char and return last occurance, return a string pointer or NULL");
	printf("Searching \"%s\" for %c. Found: %s\n", s1, c2, strrchr(s1, c2));
	printf("Searching \"%s\" for %c. Found: %s\n", s1, c3, strrchr(s1, c3));
	printf("Searching \"%s\" for %c. %s\n", s1, c3, strchr(s1, c2) ? "Found." : "Not found.");
	
	puts("\n## strstr(string, string) - search the string for the first occurance of the second, return string pointer with the remainder of the string.");
	printf("Searching \"%s\" for \"%s\". \"%s\" was found\n", s1, s2, strstr(s1, s2));
	printf("Searching \"%s\" for \"%s\". \"%s\" was found\n", s1, s3, strstr(s1, s3));
	
	puts("\n## strpbrk(string, string) - search the string for the first occurance of anything from the second string, return a pointer of NULL");
	printf("Searching \"%s\" for \"%s\". '%c' was found\n", s1, s2, *strpbrk(s1, s2));
	printf("Searching \"%s\" for \"%s\". \"%s\" was found\n", s1, s2, strpbrk(s1, s2));
	
	puts("\n## strcspn(string, string) - search the string for another string and return how many letters didn't match until a match was found.");
	printf("Searching \"%s\" for \"%s\". Characters checked before a match was %lu - the length of the string is %lu\n", s1, s2, strcspn(s1, s2), strlen(s1));
	printf("Searching \"%s\" for \"%s\". Characters checked before a match was %lu - the length of the string is %lu\n", s1, s3, strcspn(s1, s3), strlen(s1));

	puts("\n## strspn(string, string) - search the string for another string and return the length of the string that contains the characters."); 
	printf("Searching \"%s\" for \"%s\". Consecutive characters checked with a match was %lu - the length of the string is %lu\n", s1, s4, strspn(s1, s4), strlen(s1));

	return EXIT_SUCCESS;
}

