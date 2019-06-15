#include <stdio.h>
#include <stdlib.h>

#define SIZE 7

void updateArrayPlusOne(char *stringPointer, int size);
void printString(char *stringPointer, int size);

int main(void)
{
	char string[] = "ABCDEF";
	/*
	 * Create a constant pointer and point it to the char [].
	 * Notice the & to get the memory address.
	 */ 
	char * const stringPointer = string;

	printf("# Constant Pointer to Non-constant Data - the default for arrays\n");
	printString(stringPointer, SIZE);
	updateArrayPlusOne(stringPointer, SIZE);
	printString(stringPointer, SIZE);

	return EXIT_SUCCESS;
}

void updateArrayPlusOne(char *stringPointer, int size)
{
	/*
	 * We are using pointer arithmetic for iterate.
	 * We are iterating from the first element of the array at the pointer.
	 * Iterating until the null control character is found, which is the end of the string.
	 * We are using point arithmetic to access each element. This is the same as i++
	 * Notice there is not * for the pointer arithmetic. This updates the pointers subscript (aka index)
	 * But there is a * when we are accessing the value inside current element being pointed at.
	 */
	
	printf("\n## Updating Array - elementValue++\n");
	for( ; *stringPointer != '\0'; stringPointer++) {
		/*
		 * The star here is used to directly manipulate the value at this pointer location.
		 * We are incrementing each letter by 1.
		 */ 
		*stringPointer += 1;
	}
	printf("Done.\n");
}

void printString(char *stringPointer, int size)
{
	int i;

	printf("\n## Printing Array\n");
	/*
	 * The counter variable is for printing control only.
	 * We are using pointer arithmetic for iterate.
	 * We are iterating from the first element of the array at the pointer.
	 * Iterating until the null control character is found, which is the end of the string.
	 * We are using point arithmetic to access each element. This is the same as i++
	 * Notice there is not * for the pointer arithmetic. This updates the pointers subscript (aka index)
	 * But there is a * when we are accessing the value inside current element being pointed at.
	 */
	for(i = 0; *stringPointer != '\0'; stringPointer++, i++) {
		if (i == 0) {
			printf("[%c, ", *stringPointer);
		}
		else {
			printf("%c, ", *stringPointer);
		}
	}
	printf("'\\0']\n");
}

