#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	/* Can hold 12 chars plus null control character '\0' */
	char string1[13];
	/* Holds 13 chars, the string literal + '\0' */
	char string2[] = "Hello world!";
	/* Holds 13 chars - can use ASCII code points or Unicode code points also */
	char string3[] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '!', '\0'};
	int i;


	printf("# Strings Are Really Character Arrays\nEnter a string <= 12 characters: ");
	/*
	 * Limit scanf to reading in only 12 characters.
	 * Store the scanf data into the variable string1.
	 * Because this variable is an array, we don't need &.
	 * This is because the array name has the pointer pointing to the memory address.
	 * scanf stops reading when it finds a space, tab, or EOF character.
	 * Thus entering "Hello World!" will only store "Hello"
	 */ 
	scanf("%12s", string1);

	printf("## string1 - scanf\n### Printing For Loop\n");
	/* Output characters until '\0' is encountered */
	for (i = 0; string1[i] != '\0'; i++) {
		printf("%c", string1[i]);
	}
	/*
	 * Don't need & here because we are using an array variable.
	 * The array variable has the pointer containing the memory address.
	 */ 
	printf("\n### Printing printf\n%s\n", string1);

	printf("\n## string2 - String Literal\n### Printing For Loop\n");	
	for (i = 0; string2[i] != '\0'; i++) {
		printf("%c", string2[i]);
	}
	/*
	 * Using & to directly get the pointer.
	 * In ANSI C, this produces a compiler warning though, need to cast to remove it.
	 */ 
	printf("\n### Printing printf\n%s\n", (char *) &string2);

	printf("\n## string3 - Character List\n### Printing For Loop\n");	
	for (i = 0; string3[i] != '\0'; i++) {
		printf("%c", string3[i]);
	}
	printf("\n### Printing printf\n%s\n", string3);


	return EXIT_SUCCESS;
}
