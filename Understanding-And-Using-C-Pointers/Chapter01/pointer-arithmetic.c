#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	/*
	 * On my machine, an int is 4 bytes.
	 */ 
	int vector[] = {28, 41, 7};
	/*
	 * This will be the memory address of the first index
	 */ 
	int* iPtr = vector;

	puts("# Pointer Arithmetic - Using An Array Of Integers");
	/*
	 * Remember that the name of an array is the same as &name[0]
	 * %p needs a (void*) cast
	 */ 
	printf("The address of vector[0] is %p\n", (void*) vector);
	/*
	 * iPtr is the address that the pointer is pointing to.
	 * &iPtr is the address that the pointer is located at.
	 */ 
	printf("The address that iPtr is holding is %p\n", (void*) iPtr);
	printf("The address where &iPtr lives is %p\n", (void*) &iPtr);

	printf("The value of vector[0] is %d\n", vector[0]);
	/*
	 * Need to dereference to see the value of the pointer
	 */
	printf("The value of *iPtr is %d\n", *iPtr);

	puts("## ++iPtr");
	/*
	 * Every time you add one to a pointer, you are adding the size of the data type
	 * that it points to. Since these are integers and my machine has 4 byte ints,
	 * it will add 4 bytes to the pointer address.
	 */
	++iPtr;

	printf("The address of vector[1] is %p\n", (void*) &vector[1]);
	printf("The address that iPtr is holding is %p\n", (void*) iPtr);
	printf("The address where &iPtr lives is %p\n", (void*) &iPtr);

	printf("The value of vector[1] is %d\n", vector[1]);
	printf("The value of *iPtr is %d\n", *iPtr);

	return EXIT_SUCCESS;
}
