#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i = 2;
	/*
	 * The * here means to delcare a pointer.
	 *
	 * All of these mean the same thing, declaring a pointer.
	 * The whitespace is irrelevant, and is personal preference.
	 */ 
	int* iPtr;
	int * iPtr2;
	int *iPtr3;
	int*iPtr4;

	puts("# Pointer Declaration");
	puts("The * is an overloaded operator, it has 3 meanings in different contexts");
	puts("1) multiplication 2) pointer declaration 3) pointer dereferencing");

	iPtr = &i;
	iPtr2 = &i;
	iPtr3 = &i;
	iPtr4 = &i;

	printf("i is %d\n", i);
	/*
	 * The * here means to dereference, which is get the value inside the memory
	 * address that the pointer is pointing to.
	 */ 
	printf("iPtr is %d\n", *iPtr);
	printf("iPtr2 is %d\n", *iPtr2);
	printf("iPtr3 is %d\n", *iPtr3);
	printf("iPtr4 is %d\n", *iPtr4);

	return EXIT_SUCCESS;
}
