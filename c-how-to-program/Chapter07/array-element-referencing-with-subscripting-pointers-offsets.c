#include <stdio.h>
#include <stdlib.h>

#define SIZE 4

int main(void)
{
	int a[] = {10, 20, 30, 40};
	int *arrayPointer = a;
	/*
	 * Counter variables.
	 * i for traditional subscripting.
	 * offset for pointer offset notation
	 */ 
	int i, offset;

	printf("# Arrays & Pointers\n");
	printf("\n## Printing Array Via Array Subscript\n");
	for (i = 0; i < SIZE; i++) {
		printf("The value of a[%d] is %d\n", i, a[i]);
	}

	printf("\n## Printing Array Via Array Name & Pointer Offset Notation\n");
	for (offset = 0; offset < SIZE; offset++) {
		/*
		 * The parentheses for *(arrayName + offset) is needed because * has a higher precedence than +
		 */ 
		printf("The value of *(a + %d) is %d\n", offset, *(a + offset));
	}

	printf("\n## Printing Array Via Array Pointer & Subscript\n");
	for (i = 0; i < SIZE; i++) {
		/*
		 * *pointerName is the pointer.
		 *	pointerName is the value.
		 */ 
		printf("The value of arrayPointer[%d] is %d\n", i, arrayPointer[i]);
	}

	printf("\n## Printing Array Via Array Pointer & Pointer Offset Notation\n");
	for (offset = 0; offset < SIZE; offset++) {
		/*
		 * The parentheses for *(arrayPointer + offset) is needed because * has a higher precedence than +
		 */ 
		printf("The value of *(arrayPointer + %d) is %d\n", offset, *(arrayPointer + offset));
	}

	return EXIT_SUCCESS;
}
