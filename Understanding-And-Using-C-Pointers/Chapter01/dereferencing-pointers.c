#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i;
	/*
	 * The * here means this variable is a pointer. Read it backs
	 * 1) A variable named iPtr
	 * 2) A variable pointer named iPtr 
	 * 3) A variable pointer of type int named iPtr
	 */ 
	int* iPtr;

	i = 2;
	iPtr = &i;

	puts("# Dereferencing Pointers");
	printf("The value of i is %d\n", i);
	/*
	 * The * here means dereference, which returns the value pointed to by the pointer.
	 */ 
	printf("The value of iPtr is %d\n", *iPtr);
	puts("After *iPtr *= *iPtr");
	/*
	 * First * means dereference.
	 * Second * means multiplication.
	 * Third * means dereference.
	 */ 
	*iPtr *= *iPtr;
	printf("The value of i is %d\n", i);
	printf("The value of iPtr is %d\n", *iPtr);



	return EXIT_SUCCESS;
}
