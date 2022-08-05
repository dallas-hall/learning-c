#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
	printf("# Character Function Examples\n");
	printf("## isdigit\n");
	printf("%s%s\n", isdigit('8') ? "8 is a" : "8 is not a", " digit");
	printf("%s%s\n", isdigit('A') ? "A is a" : "A is not a", " digit");

	printf("\n## isalpha\n");
	printf("%s%s\n", isalpha('8') ? "8 is a" : "8 is not a", " letter");
	printf("%s%s\n", isalpha('A') ? "A is a" : "A is not a", " letter");
	printf("%s%s\n", isalpha('a') ? "a is a" : "a is not a", " letter");
	printf("%s%s\n", isalpha('!') ? "! is a" : "! is not a", " letter");

	printf("\n## isalnum\n");
	printf("%s%s\n", isalnum('8') ? "8 is a" : "8 is not a", " letter or number");
	printf("%s%s\n", isalnum('A') ? "A is a" : "A is not a", " letter or number");
	printf("%s%s\n", isalnum('a') ? "a is a" : "a is not a", " letter or number");
	printf("%s%s\n", isalnum('!') ? "! is a" : "! is not a", " letter or number");

	printf("\n## isxdigit\n");
	printf("%s%s\n", isxdigit('8') ? "8 is a" : "8 is not a", " hex digit");
	printf("%s%s\n", isxdigit('A') ? "A is a" : "A is not a", " hex digit");
	printf("%s%s\n", isxdigit('a') ? "a is a" : "a is not a", " hex digit");
	printf("%s%s\n", isxdigit('!') ? "! is a" : "! is not a", " hex digit");



	return EXIT_SUCCESS;
}
