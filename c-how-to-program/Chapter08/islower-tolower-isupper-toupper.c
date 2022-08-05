#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
	printf("# Character Function Examples\n");
	printf("## islower\n");
	printf("%s%s\n", islower('8') ? "8 is" : "8 is not", " lowercase");
	printf("%s%s\n", islower('A') ? "A is" : "A is not", " lowercase");
	printf("%s%s\n", islower('a') ? "a is" : "a is not", " lowercase");
	printf("%s%s\n", islower('!') ? "! is" : "! is not", " lowercase");


	printf("\n## tolower\n");
	printf("%c after tolower is %c\n", '8', tolower('8'));
	printf("%c after tolower is %c\n", 'A', tolower('A'));
	printf("%c after tolower is %c\n", 'a', tolower('a'));
	printf("%c after tolower is %c\n", '!', tolower('!'));

	printf("\n## isupper\n");
	printf("%s%s\n", isupper('8') ? "8 is" : "8 is not", " uppercase");
	printf("%s%s\n", isupper('A') ? "A is" : "A is not", " uppercase");
	printf("%s%s\n", isupper('a') ? "a is" : "a is not", " uppercase");
	printf("%s%s\n", isupper('!') ? "! is" : "! is not", " uppercase");


	printf("\n## tolower\n");
	printf("%c after toupper is %c\n", '8', toupper('8'));
	printf("%c after toupper is %c\n", 'A', toupper('A'));
	printf("%c after toupper is %c\n", 'a', toupper('a'));
	printf("%c after toupper is %c\n", '!', toupper('!'));
	
	return EXIT_SUCCESS;
}
