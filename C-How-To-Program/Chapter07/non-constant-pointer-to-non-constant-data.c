/*
 * This is the highest level of data access in C.
 * The non-constant pointer means that the pointer can be updated to point to anything.
 * The non-constant data means that the data can be changed to anything.
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> /* has islower, isupper, tolower, and toupper functions */

void convertToUppercase(char *stringPointer);
void convertToLowercase(char *stringPointer);

int main(void)
{
	char string[] = "Some alpha-characters, numbers, and symbols. $32.98 dollary-doos!";

	printf("# Non-constant Pointer & Non-constant Data - strings aka char[]\n");
	printf("## Updating non-constant data\n");\
	/*
	 * An array name is actually the pointer to the memory address.
	 * So direct array manipulation occurs this way.
	 */ 
	printf("The string before conversion is:\n%s\n\n", string);
	convertToLowercase(string);
	printf("The string after lowercase conversion is:\n%s\n\n", string);
	convertToUppercase(string);
	printf("The string after UPPERCASE conversion is:\n%s\n", string);


	return EXIT_SUCCESS;
}

void convertToUppercase(char *stringPointer)
{
	/*
	 * Process the data that the pointer is referencing.
	 * Because it is a string, process until null control character is found.
	 * The pointer is referencing the first character in the array.
	 * We will use pointer arithmetic to advance it.
	 */
	while(*stringPointer != '\0') {
		if(islower(*stringPointer)) {
			*stringPointer = toupper(*stringPointer);
		}
		/*
		 * The equivalent of i++ in a for loop processing the array.
		 * Notice the lack of * here.
		 */ 
		++stringPointer;
	}
}

void convertToLowercase(char *stringPointer)
{
	/*
	 * Process the data that the pointer is referencing.
	 * Because it is a string, process until null control character is found.
	 * The pointer is referencing the first character in the array.
	 * We will use pointer arithmetic to advance it.
	 */
	while(*stringPointer != '\0') {
		if(isupper(*stringPointer)) {
			*stringPointer = tolower(*stringPointer);
		}
		/*
		 * The equivalent of i++ in a for loop processing the array.
		 * Notice the lack of * here.
		 */ 
		++stringPointer;
	}
}
