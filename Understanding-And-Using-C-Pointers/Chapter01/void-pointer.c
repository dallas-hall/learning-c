#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i = 2;
	/*
	 * A variable named iPtr
	 * Is a pointer to an int
	 * And is assigned the memory address of i
	 */ 
	int* iPtr = &i;
	void* voidPtr;

	puts("# Void Pointer");
	printf("The value of i is %d\n", i);
	/*
	 * Dereference the pointer so we can get its value.
	 */ 
	printf("The value of iPtr is %d\n", *iPtr);
	/*
	 * ANSI C doesn't support %ls
	 * Need to cast to (void *) to silence compiler warning
	 */ 
	printf("The address of iPtr is %p\n", (void*) iPtr);
	puts("Casting int* iPtr to void* voidPtr");
	voidPtr = iPtr;
	/*
	 * Cannot dereference a void pointer.
	 * Even if you casted it to (int*) it would still be illegal
	 */
	printf("The address of voidPtr is %p\n", voidPtr);
	puts("Casting void* voidPtr to int* iPtr");
	iPtr = (int*) voidPtr;
	printf("The value of iPtr is %d\n", *iPtr);

	return EXIT_SUCCESS;
}
