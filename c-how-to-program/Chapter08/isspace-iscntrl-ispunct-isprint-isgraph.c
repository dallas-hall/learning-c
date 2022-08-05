#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
	printf("# Character Function Examples\n");
	printf("## isspace\n");
	printf("%s%s\n", isspace('8') ? "8 is a" : "8 is not a", " whitespace");
	printf("%s%s\n", isspace('A') ? "A is a" : "A is not a", " whitespace");
	printf("%s%s\n", isspace('a') ? "8 is a" : "8 is not a", " whitespace");
	printf("%s%s\n", isspace('\t') ? "'\t' is a" : "'\t' is not a", " whitespace");
	printf("%s%s\n", isspace(' ') ? "' ' is a" : "' ' is not a", " whitespace");
	printf("%s%s\n", isspace('!') ? "! is a" : "! is not a", " whitespace");

	printf("\n## iscntrl\n");
	printf("%s%s\n", iscntrl('8') ? "8 is a" : "8 is not a", " control character");
	printf("%s%s\n", iscntrl('A') ? "A is a" : "A is not a", " control character");
	printf("%s%s\n", iscntrl('a') ? "8 is a" : "8 is not a", " control character");
	printf("%s%s\n", iscntrl('\t') ? "'\t' is a" : "'\t' is not a", " control character");
	printf("%s%s\n", iscntrl(' ') ? "' ' is a" : "' ' is not a", " control character");
	printf("%s%s\n", iscntrl('!') ? "! is a" : "! is not a", " control character");

	printf("\n## ispunct\n");
	printf("%s%s\n", ispunct('8') ? "8 is a" : "8 is not a", " punctuation");
	printf("%s%s\n", ispunct('A') ? "A is a" : "A is not a", " punctuation");
	printf("%s%s\n", ispunct('a') ? "8 is a" : "8 is not a", " punctuation");
	printf("%s%s\n", ispunct('\t') ? "'\t' is a" : "'\t' is not a", " punctuation");
	printf("%s%s\n", ispunct(' ') ? "' ' is a" : "' ' is not a", " punctuation");
	printf("%s%s\n", ispunct('!') ? "! is a" : "! is not a", " punctuation");

	printf("\n## isprint\n");
	printf("%s%s\n", isprint('8') ? "8 is a" : "8 is not a", " printable");
	printf("%s%s\n", isprint('A') ? "A is a" : "A is not a", " printable");
	printf("%s%s\n", isprint('a') ? "8 is a" : "8 is not a", " printable");
	printf("%s%s\n", isprint('\t') ? "'\t' is a" : "'\t' is not a", " printable");
	printf("%s%s\n", isprint(' ') ? "' ' is a" : "' ' is not a", " printable");
	printf("%s%s\n", isprint('!') ? "! is a" : "! is not a", " printable");

	printf("\n## isgraph\n");
	printf("%s%s\n", isgraph('8') ? "8 is a" : "8 is not a", " printable without whitspace");
	printf("%s%s\n", isgraph('A') ? "A is a" : "A is not a", " printable without whitspace");
	printf("%s%s\n", isgraph('a') ? "8 is a" : "8 is not a", " printable without whitspace");
	printf("%s%s\n", isgraph('\t') ? "'\t' is a" : "'\t' is not a", " printable without whitspace");
	printf("%s%s\n", isgraph(' ') ? "' ' is a" : "' ' is not a", " printable without whitspace");
	printf("%s%s\n", isgraph('!') ? "! is a" : "! is not a", " printable without whitspace");


	return EXIT_SUCCESS;
}
