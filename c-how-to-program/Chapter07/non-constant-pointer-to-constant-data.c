#include <stdio.h>
#include <stdlib.h>

/*
 * The constr keywords means the character data to this pointer cannot be changed.
 */ 
void printString(const char *stringPointer);

int main(void)
{
	char string[] = "Hello world, we are doing string printing in C!";

	printf("# Non-constant Pointer & Constant Data - char [] printing\n");
	printf("The string is:\n");
	/*
	 * Remember that the variable name of an array points to the first element of the array.
	 */ 
	printString(string);
	printf("\n");

	return EXIT_SUCCESS;
}


void printString(const char *stringPointer)
{
	/*
	 * Don't need a counter variable, as we are using pointer arithmetic
	 * We are iterating from the first element of the array at the pointer.
	 * Iterating until the null control character is found, which is the end of the string.
	 * We are using point arithmetic to access each element. This is the same as i++
	 * Notice there is not * for the pointer arithmetic.
	 */

	for( ; *stringPointer != '\0'; stringPointer++) {
		/*
		 * Print the character at the current element of the pointer, this is the same as array[i]
		 */ 
		printf("%c", *stringPointer);
	}
}
