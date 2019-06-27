#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char x;
	char y[80];
	char z[80];
	char* ptr;
	ptr = z;

	puts("# scanf String & Character Sequences");
	puts("Enter a char: ");
	/*
	 * %c reads a char.
	 * %s reads a string and doesn't need & when its an array or a pointer, i.e. an array name points to the memory address of the first index.
	 * And pointers point to memory anyway, but they need to be initialised first.
	 *
	 */ 
	scanf("%c", &x);
	printf("You entered the char '%c'\n", x);
	
	puts("Enter a string: ");
	scanf("%s", y);
	printf("You entered the string \"%s\"\n", y);

	puts("Enter a string: ");
	/*
	 * Notice the space here to skip the \n from the previous input as its still in teh buffer
	 */ 
	scanf(" %[aieou]", ptr);
	puts("Searching your string for vowels. Will stop when the first non-vowel char is encountered.");
	printf("Your string had the following vowels: %s\n", z); 
	return EXIT_SUCCESS;
}
